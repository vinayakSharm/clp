
// Generated from KQL.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "KQLVisitor.h"


namespace kql {

/**
 * This class provides an empty implementation of KQLVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  KQLBaseVisitor : public KQLVisitor {
public:

  virtual std::any visitStart(KQLParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(KQLParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNestedQuery(KQLParser::NestedQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotQuery(KQLParser::NotQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubQuery(KQLParser::SubQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrAndQuery(KQLParser::OrAndQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(KQLParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumn_range_expression(KQLParser::Column_range_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumn_value_expression(KQLParser::Column_value_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumn(KQLParser::ColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_expression(KQLParser::Value_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitList_of_values(KQLParser::List_of_valuesContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace kql
