
// Generated from /home/mayta/projects/CompilersTheory/StatComP/src/StatComp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "StatCompParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by StatCompParser.
 */
class  StatCompVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by StatCompParser.
   */
    virtual std::any visitProg(StatCompParser::ProgContext *context) = 0;

    virtual std::any visitPrintExpr(StatCompParser::PrintExprContext *context) = 0;

    virtual std::any visitUpdateSymbol(StatCompParser::UpdateSymbolContext *context) = 0;

    virtual std::any visitArrayDecl(StatCompParser::ArrayDeclContext *context) = 0;

    virtual std::any visitExprNeg(StatCompParser::ExprNegContext *context) = 0;

    virtual std::any visitExprTableFunc(StatCompParser::ExprTableFuncContext *context) = 0;

    virtual std::any visitExprPar(StatCompParser::ExprParContext *context) = 0;

    virtual std::any visitExprAddSub(StatCompParser::ExprAddSubContext *context) = 0;

    virtual std::any visitExprString(StatCompParser::ExprStringContext *context) = 0;

    virtual std::any visitExprVar(StatCompParser::ExprVarContext *context) = 0;

    virtual std::any visitExprPow(StatCompParser::ExprPowContext *context) = 0;

    virtual std::any visitExprLiteral(StatCompParser::ExprLiteralContext *context) = 0;

    virtual std::any visitExprArrayAccess(StatCompParser::ExprArrayAccessContext *context) = 0;

    virtual std::any visitExprMulDiv(StatCompParser::ExprMulDivContext *context) = 0;

    virtual std::any visitExprStatFunc(StatCompParser::ExprStatFuncContext *context) = 0;

    virtual std::any visitStatFunc(StatCompParser::StatFuncContext *context) = 0;

    virtual std::any visitTableFunc(StatCompParser::TableFuncContext *context) = 0;

    virtual std::any visitArglist(StatCompParser::ArglistContext *context) = 0;

    virtual std::any visitArrayInit(StatCompParser::ArrayInitContext *context) = 0;

    virtual std::any visitNumlist(StatCompParser::NumlistContext *context) = 0;

    virtual std::any visitNum(StatCompParser::NumContext *context) = 0;

    virtual std::any visitDecltype(StatCompParser::DecltypeContext *context) = 0;


};

