/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL
v2. You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by wangyunlai.wyl on 2021/5/19.
//

#include "storage/index/bplus_tree_index.h"
#include "common/log/log.h"
#include "common/type/attr_type.h"
#include "storage/field/field_meta.h"
#include "storage/table/table.h"
#include "storage/db/db.h"

BplusTreeIndex::~BplusTreeIndex() noexcept { close(); }

RC BplusTreeIndex::create(Table *table, const char *file_name, const IndexMeta &index_meta, const std::vector<FieldMeta> &field_metas,
                          bool is_unique) {
  if (inited_) {
    LOG_WARN(
        "Failed to create index due to the index has been created before. "
        "file_name:%s, index:%s, field:%s",
        file_name, index_meta.name(), index_meta.field().c_str());
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, field_metas);

  std::vector<AttrType> field_meta_types;
  std::vector<int> field_meta_lens;

  for (const FieldMeta &field_meta : field_metas) {
    field_meta_types.push_back(field_meta.type());
    field_meta_lens.push_back(field_meta.len());
  }

  BufferPoolManager &bpm = table->db()->buffer_pool_manager();
  RC rc = index_handler_.create(table->db()->log_handler(), bpm, file_name, field_meta_types, field_meta_lens, is_unique);
  if (RC::SUCCESS != rc) {
    LOG_WARN(
        "Failed to create index_handler, file_name:%s, index:%s, field:%s, "
        "rc:%s",
        file_name, index_meta.name(), index_meta.field().c_str(), strrc(rc));
    return rc;
  }

  inited_ = true;
  table_ = table;
  LOG_INFO("Successfully create index, file_name:%s, index:%s, field:%s", file_name, index_meta.name(), index_meta.field().c_str());
  return RC::SUCCESS;
}

RC BplusTreeIndex::open(Table *table, const char *file_name, const IndexMeta &index_meta, const vector<FieldMeta> &field_metas) {
  if (inited_) {
    LOG_WARN(
        "Failed to open index due to the index has been initedd before. "
        "file_name:%s, index:%s, field:%s",
        file_name, index_meta.name(), index_meta.field().c_str());
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, field_metas);

  BufferPoolManager &bpm = table->db()->buffer_pool_manager();
  RC rc = index_handler_.open(table->db()->log_handler(), bpm, file_name);
  if (RC::SUCCESS != rc) {
    LOG_WARN("Failed to open index_handler, file_name:%s, index:%s, field:%s, rc:%s", file_name, index_meta.name(), index_meta.field().c_str(),
             strrc(rc));
    return rc;
  }

  inited_ = true;
  table_ = table;
  LOG_INFO("Successfully open index, file_name:%s, index:%s, field:%s", file_name, index_meta.name(), index_meta.field().c_str());
  return RC::SUCCESS;
}

RC BplusTreeIndex::close() {
  if (inited_) {
    LOG_INFO("Begin to close index, index:%s, field:%s", index_meta_.name(), index_meta_.field().cbegin());
    index_handler_.close();
    inited_ = false;
  }
  LOG_INFO("Successfully close index.");
  return RC::SUCCESS;
}

RC BplusTreeIndex::insert_entry(const char *record, const RID *rid) {
  // 支持一次插入多字段的偏移量，即multi-index
  vector<const char *> user_keys;
  vector<const char *> null_flags;
  for (const FieldMeta &field_meta : field_metas_) {
    user_keys.push_back(record + field_meta.offset());
  }
  for (int i = 0; i < (int)field_metas_.size(); i++) {
    null_flags.push_back(record + i);
  }
  return index_handler_.insert_entry(user_keys, rid, null_flags);
}

RC BplusTreeIndex::delete_entry(const char *record, const RID *rid) {
  // 支持一次删除多字段的偏移量，即multi-index
  vector<const char *> user_keys;
  for (const FieldMeta &field_meta : field_metas_) {
    user_keys.push_back(record + field_meta.offset());
  }
  return index_handler_.delete_entry(user_keys, rid);
}

IndexScanner *BplusTreeIndex::create_scanner(const std::vector<const char *> left_keys, std::vector<int> left_lens, bool left_inclusive,
                                             const std::vector<const char *> right_keys, std::vector<int> right_lens, bool right_inclusive) {
  BplusTreeIndexScanner *index_scanner = new BplusTreeIndexScanner(index_handler_);
  RC rc = index_scanner->open(left_keys, left_lens, left_inclusive, right_keys, right_lens, right_inclusive);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open index scanner. rc=%d:%s", rc, strrc(rc));
    delete index_scanner;
    return nullptr;
  }
  return index_scanner;
}

IndexScanner *BplusTreeIndex::create_scanner(const char *left_key, int left_len, bool left_inclusive, const char *right_key, int right_len,
                                             bool right_inclusive) {
  // 创建左键和右键的 vector
  std::vector<const char *> left_keys = {left_key};
  std::vector<const char *> right_keys = {right_key};

  // 创建左键长度和右键长度的 vector
  std::vector<int> left_lens = {left_len};
  std::vector<int> right_lens = {right_len};

  return create_scanner(left_keys, left_lens, left_inclusive, right_keys, right_lens, right_inclusive);
}

RC BplusTreeIndex::sync() { return index_handler_.sync(); }

////////////////////////////////////////////////////////////////////////////////
BplusTreeIndexScanner::BplusTreeIndexScanner(BplusTreeHandler &tree_handler) : tree_scanner_(tree_handler) {}

BplusTreeIndexScanner::~BplusTreeIndexScanner() noexcept { tree_scanner_.close(); }

RC BplusTreeIndexScanner::open(const std::vector<const char *> left_keys, std::vector<int> left_lens, bool left_inclusive,
                               const std::vector<const char *> right_keys, std::vector<int> right_lens, bool right_inclusive) {
  return tree_scanner_.open(left_keys, left_lens, left_inclusive, right_keys, right_lens, right_inclusive);
}

RC BplusTreeIndexScanner::next_entry(RID *rid) { return tree_scanner_.next_entry(*rid); }

RC BplusTreeIndexScanner::destroy() {
  delete this;
  return RC::SUCCESS;
}
