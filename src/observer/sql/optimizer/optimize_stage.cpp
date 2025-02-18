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
// Created by Longda on 2021/4/13.
//

#include <string.h>
#include <string>

#include "optimize_stage.h"

#include "common/conf/ini.h"
#include "common/io/io.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "sql/operator/logical_operator.h"
#include "sql/optimizer/logical_plan_generator.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/stmt.h"

using namespace std;
using namespace common;

unordered_map<string, unique_ptr<LogicalOperator>> OptimizeStage::sub_expr_and_logical_oper = unordered_map<string, unique_ptr<LogicalOperator>>();
unordered_map<string, unique_ptr<PhysicalOperator>> OptimizeStage::sub_expr_and_physical_oper = unordered_map<string, unique_ptr<PhysicalOperator>>();

RC OptimizeStage::handle_request(SQLStageEvent *sql_event) {
  // 创建逻辑算子
  unique_ptr<LogicalOperator> logical_operator;

  RC rc = create_logical_plan(sql_event, logical_operator);

  // 查错
  if (rc != RC::SUCCESS) {
    if (rc != RC::UNIMPLEMENTED) {
      LOG_WARN("failed to create logical plan. rc=%s", strrc(rc));
    }
    return rc;
  }
  ASSERT(logical_operator, "logical operator is null");

  // rc = rewrite(logical_operator);

  // 查错
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to rewrite plan. rc=%s", strrc(rc));
    return rc;
  }

  rc = optimize(logical_operator);

  // 查错
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to optimize plan. rc=%s", strrc(rc));
    return rc;
  }

  unique_ptr<PhysicalOperator> physical_operator;
  rc = generate_physical_plan(logical_operator, physical_operator, sql_event->session_event()->session());

  // 查错
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to generate physical plan. rc=%s", strrc(rc));
    return rc;
  }

  // 设置物理算子
  sql_event->set_operator(std::move(physical_operator));

  return rc;
}

RC OptimizeStage::optimize(unique_ptr<LogicalOperator> &oper) {
  // do nothing
  return RC::SUCCESS;
}

RC OptimizeStage::generate_physical_plan(unique_ptr<LogicalOperator> &logical_operator, unique_ptr<PhysicalOperator> &physical_operator,
                                         Session *session) {
  RC rc = RC::SUCCESS;
  if (session->get_execution_mode() == ExecutionMode::CHUNK_ITERATOR && LogicalOperator::can_generate_vectorized_operator(logical_operator->type())) {
    LOG_INFO("use chunk iterator");
    session->set_used_chunk_mode(true);
    rc = PhysicalPlanGenerator::create_vec(*logical_operator, physical_operator);
  } else {
    LOG_INFO("use tuple iterator");
    session->set_used_chunk_mode(false);
    rc = PhysicalPlanGenerator::create(*logical_operator, physical_operator);
  }
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create physical operator. rc=%s", strrc(rc));
  }
  return rc;
}

RC OptimizeStage::rewrite(unique_ptr<LogicalOperator> &logical_operator) {
  RC rc = RC::SUCCESS;

  bool change_made = false;
  do {
    change_made = false;
    rc = Rewriter::rewrite(logical_operator, change_made);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to do expression rewrite on logical plan. rc=%s", strrc(rc));
      return rc;
    }
  } while (change_made);

  return rc;
}

RC OptimizeStage::create_logical_plan(SQLStageEvent *sql_event, unique_ptr<LogicalOperator> &logical_operator) {
  Stmt *stmt = sql_event->stmt();
  if (nullptr == stmt) {
    return RC::UNIMPLEMENTED;
  }

  return LogicalPlanGenerator::create(stmt, logical_operator);
}

//////////////////////////////////////////////////////////////////////////////////////////////

RC OptimizeStage::handle_sub_stmt(Stmt *stmt, std::vector<std::vector<Value>> &tuple_list, TupleSchema &tuple_schema, const Tuple *main_tuple) {
  SelectStmt *select_stmt = static_cast<SelectStmt *>(stmt);
  vector<Table *> tables = select_stmt->tables();
  string table_names;
  for (auto it : tables) table_names += it->name();

  RC rc = RC::SUCCESS;

  // ? 不存在创建好的逻辑算子
  if (!sub_expr_and_logical_oper.contains(table_names)) {
    unique_ptr<LogicalOperator> logical_oper;
    rc = create_logical_plan(stmt, logical_oper);

    if (rc != RC::SUCCESS && rc != RC::UNIMPLEMENTED) return rc;
    ASSERT(logical_oper, "logical operator is null");

    sub_expr_and_logical_oper.insert(make_pair(table_names, std::move(logical_oper)));
  }

  // ? 不存在创建好的物理算子
  if (!sub_expr_and_physical_oper.contains(table_names)) {
    unique_ptr<PhysicalOperator> physical_oper;
    rc = generate_physical_plan(sub_expr_and_logical_oper[table_names], physical_oper);

    if (rc != RC::SUCCESS) return rc;

    sub_expr_and_physical_oper.insert(make_pair(table_names, std::move(physical_oper)));
  }

  PhysicalOperator *physical_oper = sub_expr_and_physical_oper[table_names].get();
  rc = get_tuple_schema(physical_oper, tuple_schema);
  if (rc != RC::SUCCESS) return rc;

  rc = get_tuple_list(physical_oper, tuple_list, main_tuple);
  return rc;
}

RC OptimizeStage::create_logical_plan(Stmt *stmt, unique_ptr<LogicalOperator> &logical_operator) {
  if (nullptr == stmt) {
    return RC::UNIMPLEMENTED;
  }

  return LogicalPlanGenerator::create(stmt, logical_operator);
}

RC OptimizeStage::generate_physical_plan(unique_ptr<LogicalOperator> &logical_operator, unique_ptr<PhysicalOperator> &physical_operator) {
  RC rc = PhysicalPlanGenerator::create(*logical_operator, physical_operator);

  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create physical operator. rc=%s", strrc(rc));
  }
  return rc;
}

RC OptimizeStage::get_tuple_schema(PhysicalOperator *physical_operator, TupleSchema &tuple_schema) {
  return physical_operator->tuple_schema(tuple_schema);
}

RC OptimizeStage::get_tuple_list(PhysicalOperator *physical_operator, std::vector<std::vector<Value>> &tuple_list, const Tuple *main_tuple) {
  RC rc = physical_operator->open(nullptr, main_tuple);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open sub physical operator. rc=%s", strrc(rc));
    return rc;
  }

  // 将查表结果放入value_list
  while (RC::SUCCESS == (rc = physical_operator->next(main_tuple))) {
    Tuple *tuple = physical_operator->current_tuple();
    std::vector<Value> single_tuple;
    for (int i = 0; i < tuple->cell_num(); i++) {
      Value value;
      tuple->cell_at(i, value);
      single_tuple.push_back(value);
    }
    tuple_list.push_back(single_tuple);
  }

  if (rc != RC::RECORD_EOF) return rc;

  rc = physical_operator->close();
  if (rc != RC::SUCCESS) return rc;

  return RC::SUCCESS;
}