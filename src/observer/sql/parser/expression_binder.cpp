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
// Created by Wangyunlai on 2024/05/29.
//

#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/expression_binder.h"
#include "sql/expr/expression_iterator.h"

using namespace std;
using namespace common;

Table *BinderContext::find_table(const char *table_name) const {
  auto pred = [table_name](Table *table) { return 0 == strcasecmp(table_name, table->name()); };
  auto iter = ranges::find_if(query_tables_, pred);
  if (iter == query_tables_.end()) {
    return nullptr;
  }
  return *iter;
}

////////////////////////////////////////////////////////////////////////////////
static void wildcard_fields(Table *table, vector<unique_ptr<Expression>> &expressions) {
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    Field field(table, table_meta.field(i));
    FieldExpr *field_expr = new FieldExpr(field);
    field_expr->set_name(field.field_name());
    expressions.emplace_back(field_expr);
  }
}

RC ExpressionBinder::bind_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (nullptr == expr) {
    return RC::SUCCESS;
  }

  switch (expr->type()) {
    case ExprType::STAR: {
      return bind_star_expression(expr, bound_expressions);
    } break;

    case ExprType::UNBOUND_FIELD: {
      return bind_unbound_field_expression(expr, bound_expressions);
    } break;

    case ExprType::UNBOUND_AGGREGATION: {
      return bind_aggregate_expression(expr, bound_expressions);
    } break;

    case ExprType::FIELD: {
      return bind_field_expression(expr, bound_expressions);
    } break;

    case ExprType::VALUE: {
      return bind_value_expression(expr, bound_expressions);
    } break;

    case ExprType::CAST: {
      return bind_cast_expression(expr, bound_expressions);
    } break;

    case ExprType::COMPARISON: {
      return bind_comparison_expression(expr, bound_expressions);
    } break;

    case ExprType::CONJUNCTION: {
      return bind_conjunction_expression(expr, bound_expressions);
    } break;

    case ExprType::ARITHMETIC: {
      return bind_arithmetic_expression(expr, bound_expressions);
    } break;

    case ExprType::AGGREGATION: {
      ASSERT(false, "shouldn't be here");
    } break;

    case ExprType::FUNC: {
      return bind_func_expression(expr, bound_expressions);
    } break;

    case ExprType::VECFUNC: {
      return bind_vec_func_expression(expr, bound_expressions);
    } break;

    case ExprType::ALIAS: {
      return bind_alias_expression(expr, bound_expressions);
    }

    default: {
      LOG_WARN("unknown expression type: %d", static_cast<int>(expr->type()));
      return RC::INTERNAL;
    }
  }
  return RC::INTERNAL;
}

RC ExpressionBinder::bind_star_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (nullptr == expr) {
    return RC::SUCCESS;
  }

  auto star_expr = static_cast<StarExpr *>(expr.get());

  vector<Table *> tables_to_wildcard;

  string table_name = star_expr->table_name();

  // ? 还原表格名称
  context_.try_revert_t(table_name);

  if (!is_blank(table_name.c_str()) && 0 != strcmp(table_name.c_str(), "*")) {
    Table *table = context_.find_table(table_name.c_str());
    if (nullptr == table) return RC::SCHEMA_TABLE_NOT_EXIST;

    tables_to_wildcard.push_back(table);
  } else {
    const vector<Table *> &all_tables = context_.query_tables();
    tables_to_wildcard.insert(tables_to_wildcard.end(), all_tables.begin(), all_tables.end());
  }

  for (Table *table : tables_to_wildcard) {
    wildcard_fields(table, bound_expressions);
  }

  return RC::SUCCESS;
}

RC ExpressionBinder::bind_unbound_field_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (nullptr == expr) {
    return RC::SUCCESS;
  }

  auto unbound_field_expr = static_cast<UnboundFieldExpr *>(expr.get());

  string table_name = unbound_field_expr->table_name();
  string field_name = unbound_field_expr->field_name();

  string field_alias = unbound_field_expr->field_alias();
  string table_alias = table_name;

  // ? 如果有属性别名
  if (unbound_field_expr->has_field_alias()) context_.add_f_alias(std::make_pair(field_alias, field_name));

  // ? 如果有表格别名
  RC rc = context_.try_revert_t(table_alias);
  if (rc == RC::SUCCESS) {
    unbound_field_expr->set_table_alias(unbound_field_expr->table_name());
    unbound_field_expr->set_table_name(table_alias);
    table_name = table_alias;
  }

  Table *table = nullptr;
  if (is_blank(table_name.c_str())) {
    if (context_.query_tables().size() != 1) return RC::SCHEMA_TABLE_NOT_EXIST;

    table = context_.query_tables()[0];
  } else {
    table = context_.find_table(table_name.c_str());
    if (nullptr == table) return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  if (0 == strcmp(field_name.c_str(), "*")) {
    wildcard_fields(table, bound_expressions);
  } else {
    const FieldMeta *field_meta = table->table_meta().field(field_name.c_str());
    if (nullptr == field_meta) return RC::SCHEMA_FIELD_MISSING;

    Field field(table, field_meta);
    if (unbound_field_expr->has_field_alias()) field.set_field_alias(unbound_field_expr->field_alias());
    if (unbound_field_expr->has_table_alias()) field.set_table_alias(unbound_field_expr->table_alias());

    FieldExpr *field_expr = new FieldExpr(field);

    // ? 表头的输出 -- 有别名输出别名
    // ? 表格多于一个，输出表格.属性
    // ? 表格只有一个，输出属性
    if ((int)context_.query_tables().size() > 1) {
      string result;
      result += field.has_table_alias() ? string(field.table_alias()) : string(field.table_name());
      result += '.';
      result += field.has_field_alias() ? string(field.field_alias()) : string(field.field_name());
      field_expr->set_name(result.c_str());
    } else {
      string result;
      result += field.has_field_alias() ? string(field.field_alias()) : string(field.field_name());
      field_expr->set_name(result.c_str());
    }
    bound_expressions.emplace_back(field_expr);
  }

  return RC::SUCCESS;
}

RC ExpressionBinder::bind_field_expression(unique_ptr<Expression> &field_expr, vector<unique_ptr<Expression>> &bound_expressions) {
  bound_expressions.emplace_back(std::move(field_expr));
  return RC::SUCCESS;
}

RC ExpressionBinder::bind_value_expression(unique_ptr<Expression> &value_expr, vector<unique_ptr<Expression>> &bound_expressions) {
  bound_expressions.emplace_back(std::move(value_expr));
  return RC::SUCCESS;
}

RC ExpressionBinder::bind_cast_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (nullptr == expr) {
    return RC::SUCCESS;
  }

  auto cast_expr = static_cast<CastExpr *>(expr.get());

  vector<unique_ptr<Expression>> child_bound_expressions;
  unique_ptr<Expression> &child_expr = cast_expr->child();

  RC rc = bind_expression(child_expr, child_bound_expressions);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  if (child_bound_expressions.size() != 1) {
    LOG_WARN("invalid children number of cast expression: %d", child_bound_expressions.size());
    return RC::INVALID_ARGUMENT;
  }

  unique_ptr<Expression> &child = child_bound_expressions[0];
  if (child.get() == child_expr.get()) {
    return RC::SUCCESS;
  }

  child_expr.reset(child.release());
  bound_expressions.emplace_back(std::move(expr));
  return RC::SUCCESS;
}

RC ExpressionBinder::bind_comparison_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (nullptr == expr) {
    return RC::SUCCESS;
  }

  auto comparison_expr = static_cast<ComparisonExpr *>(expr.get());

  vector<unique_ptr<Expression>> child_bound_expressions;
  unique_ptr<Expression> &left_expr = comparison_expr->left();
  unique_ptr<Expression> &right_expr = comparison_expr->right();

  RC rc = bind_expression(left_expr, child_bound_expressions);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  if (child_bound_expressions.size() != 1) {
    LOG_WARN("invalid left children number of comparison expression: %d", child_bound_expressions.size());
    return RC::INVALID_ARGUMENT;
  }

  unique_ptr<Expression> &left = child_bound_expressions[0];
  if (left.get() != left_expr.get()) {
    left_expr.reset(left.release());
  }

  child_bound_expressions.clear();
  rc = bind_expression(right_expr, child_bound_expressions);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  if (child_bound_expressions.size() != 1) {
    LOG_WARN("invalid right children number of comparison expression: %d", child_bound_expressions.size());
    return RC::INVALID_ARGUMENT;
  }

  unique_ptr<Expression> &right = child_bound_expressions[0];
  if (right.get() != right_expr.get()) {
    right_expr.reset(right.release());
  }

  bound_expressions.emplace_back(std::move(expr));
  return RC::SUCCESS;
}

RC ExpressionBinder::bind_conjunction_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (nullptr == expr) {
    return RC::SUCCESS;
  }

  auto conjunction_expr = static_cast<ConjunctionExpr *>(expr.get());

  vector<unique_ptr<Expression>> child_bound_expressions;
  vector<unique_ptr<Expression>> &children = conjunction_expr->children();

  for (unique_ptr<Expression> &child_expr : children) {
    child_bound_expressions.clear();

    RC rc = bind_expression(child_expr, child_bound_expressions);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    if (child_bound_expressions.size() != 1) {
      LOG_WARN("invalid children number of conjunction expression: %d", child_bound_expressions.size());
      return RC::INVALID_ARGUMENT;
    }

    unique_ptr<Expression> &child = child_bound_expressions[0];
    if (child.get() != child_expr.get()) {
      child_expr.reset(child.release());
    }
  }

  bound_expressions.emplace_back(std::move(expr));

  return RC::SUCCESS;
}

RC ExpressionBinder::bind_alias_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (expr == nullptr) return RC::SUCCESS;

  AliasExpr *alias_expr = static_cast<AliasExpr *>(expr.get());
  string alias = alias_expr->alias_name();

  unique_ptr<Expression> &child_expr = alias_expr->child();

  switch (child_expr->type()) {
    case ExprType::UNBOUND_FIELD: {
      UnboundFieldExpr *field_expr = static_cast<UnboundFieldExpr *>(child_expr.get());
      field_expr->set_field_alias(alias);
    } break;
    case ExprType::UNBOUND_TABLE: {
      UnboundTableExpr *table_expr = static_cast<UnboundTableExpr *>(child_expr.get());
      table_expr->set_table_alias(alias);
    } break;
    case ExprType::UNBOUND_AGGREGATION: {
      UnboundAggregateExpr *aggre_expr = static_cast<UnboundAggregateExpr *>(child_expr.get());
      aggre_expr->set_aggre_alias(alias);
    } break;
    case ExprType::STAR: {
      return RC::INVALID_ARGUMENT;
      StarExpr *star_expr = static_cast<StarExpr *>(child_expr.get());
      star_expr->set_star_alias(alias);
    } break;
    case ExprType::ARITHMETIC: {
      ArithmeticExpr *arithmetic_expr = static_cast<ArithmeticExpr *>(child_expr.get());
      arithmetic_expr->set_alias(alias);
    } break;
    default:
      return RC::INVALID_ARGUMENT;
      break;
  }
  vector<unique_ptr<Expression>> child_bound_expressions;
  RC rc = bind_expression(child_expr, child_bound_expressions);
  if (rc != RC::SUCCESS) return rc;

  for (auto &it : child_bound_expressions) bound_expressions.emplace_back(std::move(it));
  return RC::SUCCESS;
}

RC ExpressionBinder::bind_arithmetic_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (nullptr == expr) {
    return RC::SUCCESS;
  }

  auto arithmetic_expr = static_cast<ArithmeticExpr *>(expr.get());

  vector<unique_ptr<Expression>> child_bound_expressions;
  unique_ptr<Expression> &left_expr = arithmetic_expr->left();
  unique_ptr<Expression> &right_expr = arithmetic_expr->right();
  string op = arithmetic_expr->type_to_string();

  RC rc = bind_expression(left_expr, child_bound_expressions);
  if (OB_FAIL(rc)) {
    return rc;
  }

  if (left_expr != nullptr && child_bound_expressions.size() != 1) {
    LOG_WARN("invalid left children number of comparison expression: %d", child_bound_expressions.size());
    return RC::INVALID_ARGUMENT;
  }

  unique_ptr<Expression> &left = child_bound_expressions[0];
  if (left.get() != left_expr.get()) {
    left_expr.reset(left.release());
  }

  child_bound_expressions.clear();
  rc = bind_expression(right_expr, child_bound_expressions);
  if (OB_FAIL(rc)) {
    return rc;
  }

  if (right_expr != nullptr && child_bound_expressions.size() != 1) {
    LOG_WARN("invalid right children number of comparison expression: %d", child_bound_expressions.size());
    return RC::INVALID_ARGUMENT;
  }

  unique_ptr<Expression> &right = child_bound_expressions[0];
  if (right.get() != right_expr.get()) {
    right_expr.reset(right.release());
  }

  string left_name = left_expr == nullptr ? "" : string(left_expr->name()) + " ";
  string right_name = right_expr == nullptr ? "" : " " + string(right_expr->name());
  expr->set_name(left_name + op + right_name);

  bound_expressions.emplace_back(std::move(expr));
  return RC::SUCCESS;
}

RC check_aggregate_expression(AggregateExpr &expression) {
  // 必须有一个子表达式
  Expression *child_expression = expression.child().get();
  if (nullptr == child_expression) {
    LOG_WARN("child expression of aggregate expression is null");
    return RC::INVALID_ARGUMENT;
  }

  // 校验数据类型与聚合类型是否匹配
  AggregateExpr::Type aggregate_type = expression.aggregate_type();
  AttrType child_value_type = child_expression->value_type();
  switch (aggregate_type) {
    case AggregateExpr::Type::SUM:
    case AggregateExpr::Type::AVG: {
      // 仅支持数值类型
      if (child_value_type != AttrType::INTS && child_value_type != AttrType::FLOATS) {
        LOG_WARN("invalid child value type for aggregate expression: %d", static_cast<int>(child_value_type));
        return RC::INVALID_ARGUMENT;
      }
    } break;

    case AggregateExpr::Type::COUNT:
    case AggregateExpr::Type::MAX:
    case AggregateExpr::Type::MIN: {
      // 任何类型都支持
    } break;
  }

  // 子表达式中不能再包含聚合表达式
  function<RC(std::unique_ptr<Expression> &)> check_aggregate_expr = [&](unique_ptr<Expression> &expr) -> RC {
    RC rc = RC::SUCCESS;
    if (expr->type() == ExprType::AGGREGATION) {
      LOG_WARN("aggregate expression cannot be nested");
      return RC::INVALID_ARGUMENT;
    }
    rc = ExpressionIterator::iterate_child_expr(*expr, check_aggregate_expr);
    return rc;
  };

  RC rc = ExpressionIterator::iterate_child_expr(expression, check_aggregate_expr);

  return rc;
}

RC ExpressionBinder::bind_aggregate_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (nullptr == expr) {
    return RC::SUCCESS;
  }

  // 拿到聚合表达式 UnboundAggregateExpr
  auto unbound_aggregate_expr = static_cast<UnboundAggregateExpr *>(expr.get());

  // 拿到聚合表达式中的聚合函数名
  const char *aggregate_name = unbound_aggregate_expr->aggregate_name();

  // 聚合函数名转换为聚合类型
  AggregateExpr::Type aggregate_type;
  RC rc = AggregateExpr::type_from_string(aggregate_name, aggregate_type);
  if (OB_FAIL(rc)) {
    LOG_WARN("invalid aggregate name: %s", aggregate_name);
    return rc;
  }

  // 拿到聚合表达式中的子表达式
  unique_ptr<Expression> &child_expr = unbound_aggregate_expr->child();
  vector<unique_ptr<Expression>> child_bound_expressions;

  // 如果子表达式为空指针，返回错误结果
  if (child_expr == nullptr) return RC::INVALID_ARGUMENT;

  // 如果子表达式为通配符并且聚合函数为 COUNT
  if (child_expr->type() == ExprType::STAR && aggregate_type == AggregateExpr::Type::COUNT) {
    ValueExpr *value_expr = new ValueExpr(Value(1));
    child_expr.reset(value_expr);
  }
  // 其他情况
  else {
    // 递归绑定其他子表达式
    rc = bind_expression(child_expr, child_bound_expressions);
    if (OB_FAIL(rc)) {
      return rc;
    }

    // 如果子表达式过多或过少，返回错误信息
    if (child_bound_expressions.size() != 1) {
      LOG_WARN("invalid children number of aggregate expression: %d", child_bound_expressions.size());
      return RC::INVALID_ARGUMENT;
    }

    // 如果子表达式不为原子表达式，重置子表达式并释放原子表达式对应部分
    if (child_bound_expressions[0].get() != child_expr.get()) {
      child_expr.reset(child_bound_expressions[0].release());
    }
  }

  // 创建聚合表达式
  auto aggregate_expr = make_unique<AggregateExpr>(aggregate_type, std::move(child_expr));
  aggregate_expr->set_name(unbound_aggregate_expr->name());
  aggregate_expr->set_aggre_alias(unbound_aggregate_expr->aggre_alias());

  // 校验聚合表达式
  rc = check_aggregate_expression(*aggregate_expr);
  if (OB_FAIL(rc)) {
    return rc;
  }

  // 将聚合表达式添加到输出参数
  bound_expressions.emplace_back(std::move(aggregate_expr));
  return RC::SUCCESS;
}

RC ExpressionBinder::bind_func_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  // 将 FUNC 表达式计算出来，生成 Value 表达式
  FuncExpr *func_expr = static_cast<FuncExpr *>(expr.get());
  Value target;
  RC rc = func_expr->try_get_value(target);
  if (rc != RC::SUCCESS) return rc;

  unique_ptr<Expression> value_expr(new ValueExpr(target));
  value_expr.get()->set_name(target.to_string());

  return bind_value_expression(value_expr, bound_expressions);
}

RC ExpressionBinder::bind_vec_func_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions) {
  if (nullptr == expr) {
    return RC::SUCCESS;
  }
  VecFuncExpr *vec_func_expr = static_cast<VecFuncExpr *>(expr.get());

  vector<unique_ptr<Expression>> child_bound_expressions;
  unique_ptr<Expression> &left_expr = vec_func_expr->child_left();
  unique_ptr<Expression> &right_expr = vec_func_expr->child_right();

  // left
  RC rc = bind_expression(left_expr, child_bound_expressions);
  if (rc != RC::SUCCESS) return rc;
  if (left_expr != nullptr && child_bound_expressions.size() != 1) return RC::INVALID_ARGUMENT;

  unique_ptr<Expression> &left = child_bound_expressions[0];
  if (left.get() != left_expr.get()) left_expr.reset(left.release());

  // right
  child_bound_expressions.clear();
  rc = bind_expression(right_expr, child_bound_expressions);
  if (rc != RC::SUCCESS) return rc;

  if (right_expr != nullptr && child_bound_expressions.size() != 1) return RC::INVALID_ARGUMENT;

  unique_ptr<Expression> &right = child_bound_expressions[0];
  if (right.get() != right_expr.get()) right_expr.reset(right.release());

  bound_expressions.emplace_back(std::move(expr));
  return RC::SUCCESS;
}
