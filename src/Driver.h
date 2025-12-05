#include "StatCompBaseVisitor.h"
#include "StatCompParser.h"
#include "StatCompLexer.h"
#include "llvm/ADT/APInt.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/raw_ostream.h"
#include <any>

using namespace antlr4;
using namespace llvm;
using namespace std;

class  StatCompBaseVisitor : public StatCompVisitor {
private:
	std::map<std::string, AllocaInst*> namedValues;
public:

  virtual std::any visitProg(StatCompParser::ProgContext *ctx) override {
    // Tipos principales de StatComp
    Type *DoubleTy = Type::getDoubleTy(context);   // 64-bit precision
    Type *Int32Ty  = Type::getInt32Ty(context);    // Retorno estándar de main

    // Definición de la función principal: i32 @main()
    Function *mainFunc =
        Function::Create(FunctionType::get(Int32Ty, false), Function::ExternalLinkage, "main", *module);

    // Bloque de entrada (entry): aquí van las allocas
    BasicBlock *entryBB = BasicBlock::Create(context, "entry", mainFunc);
    irBuilder->SetInsertPoint(entryBB);
    
    formatStr = irBuilder->CreateGlobalString("Result: %f\n", "str_printf_fmt");
    llvm::FunctionType *printfType = llvm::FunctionType::get(
        Int32Ty,                                // Retorna int
        {PointerType::getUnqual(context)},      // Primer argumento: cadena de formato
        true                                    // Variádica
    );
    printfFunc = module->getOrInsertFunction("printf", printfType);

    // Bloque de código (code): cuerpo del programa
    BasicBlock *codeBB = BasicBlock::Create(context, "code", mainFunc);
    irBuilder->CreateBr(codeBB); // salto desde entry a code
    irBuilder->SetInsertPoint(codeBB);

    // Generación del código de ejecución
    visitChildren(ctx);

    // Bloque final (end): retorno al sistema operativo
    BasicBlock *endBB = BasicBlock::Create(context, "end", mainFunc);
    irBuilder->CreateBr(endBB);
    irBuilder->SetInsertPoint(endBB);
    irBuilder->CreateRet(ConstantInt::get(Int32Ty, 0));

    // Dump del módulo LLVM IR
    outs() << *module;

    return std::any();
  }

  virtual std::any visitPrintExpr(StatCompParser::PrintExprContext *ctx) override {
    llvm::Value *exprResult = nullptr;
    try{
	exprResult = std::any_cast<llvm::Value*>(visit(ctx->expr()));
    } catch (const std::bad_any_cast& e){
	return std::any();
    }
   
    if(!exprResult){
	return std::any();
    }

    if(exprResult->getType()->isPointerTy()){
	llvm::Type *DoubleTy = llvm::Type::getDoubleTy(context);
	exprResult = irBuilder->CreateLoad(DoubleTy, exprResult, "load_for_print");
    }

    std::vector<llvm::Value*> args;
    args.push_back(formatStr);
    args.push_back(exprResult);
    
    irBuilder->CreateCall(printfFunc, args, "print_call");

    return std::any();
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


