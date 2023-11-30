
// Generated from KQL.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "KQLParser.h"


namespace kql {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by KQLParser.
 */
class  KQLVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by KQLParser.
   */
    virtual std::any visitStart(KQLParser::StartContext *context) = 0;

    virtual std::any visitExpr(KQLParser::ExprContext *context) = 0;

    virtual std::any visitNestedQuery(KQLParser::NestedQueryContext *context) = 0;

    virtual std::any visitNotQuery(KQLParser::NotQueryContext *context) = 0;

    virtual std::any visitSubQuery(KQLParser::SubQueryContext *context) = 0;

    virtual std::any visitOrAndQuery(KQLParser::OrAndQueryContext *context) = 0;

    virtual std::any visitExpression(KQLParser::ExpressionContext *context) = 0;

    virtual std::any visitColumn_range_expression(KQLParser::Column_range_expressionContext *context) = 0;

    virtual std::any visitColumn_value_expression(KQLParser::Column_value_expressionContext *context) = 0;

    virtual std::any visitColumn(KQLParser::ColumnContext *context) = 0;

    virtual std::any visitValue_expression(KQLParser::Value_expressionContext *context) = 0;

    virtual std::any visitList_of_values(KQLParser::List_of_valuesContext *context) = 0;


};

}  // namespace kql
