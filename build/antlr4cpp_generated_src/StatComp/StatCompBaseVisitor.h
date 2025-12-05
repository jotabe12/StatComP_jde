
// Generated from /home/mayta/projects/CompilersTheory/StatComP/src/StatComp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "StatCompVisitor.h"


/**
 * This class provides an empty implementation of StatCompVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  StatCompBaseVisitor : public StatCompVisitor {
public:

  virtual std::any visitProg(StatCompParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintExpr(StatCompParser::PrintExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUpdateSymbol(StatCompParser::UpdateSymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayDecl(StatCompParser::ArrayDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprNeg(StatCompParser::ExprNegContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprTableFunc(StatCompParser::ExprTableFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprPar(StatCompParser::ExprParContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprAddSub(StatCompParser::ExprAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprString(StatCompParser::ExprStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprVar(StatCompParser::ExprVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprPow(StatCompParser::ExprPowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprLiteral(StatCompParser::ExprLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprArrayAccess(StatCompParser::ExprArrayAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprMulDiv(StatCompParser::ExprMulDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStatFunc(StatCompParser::ExprStatFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatFunc(StatCompParser::StatFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableFunc(StatCompParser::TableFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArglist(StatCompParser::ArglistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayInit(StatCompParser::ArrayInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumlist(StatCompParser::NumlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNum(StatCompParser::NumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecltype(StatCompParser::DecltypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

