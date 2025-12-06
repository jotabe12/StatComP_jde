#ifndef DRIVER_H
#define DRIVER_H

#include "StatCompBaseVisitor.h"
#include "StatCompParser.h"
#include "StatCompLexer.h"

// Headers de LLVM
#include "llvm/ADT/APFloat.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

// Headers para JIT
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/Utils/Cloning.h"

#include <any>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace antlr4;
using namespace llvm;
using namespace std;

class Driver : public StatCompBaseVisitor {
private:
    std::unique_ptr<LLVMContext> context;
    std::unique_ptr<Module> module;
    std::unique_ptr<IRBuilder<>> irBuilder;
    
    Value* formatStr;
    FunctionCallee printfFunc;
    
    Value* tableHeaderFormat;
    Value* tableLineFormat;
    Value* tableRelFreqFormat;
    Value* tableFooterFormat;
    
    std::map<std::string, AllocaInst*> namedValues;
    std::map<std::string, std::pair<AllocaInst*, int>> namedArrays;

    // ============================================
    // HELPER: Obtener valores de un array completo
    // ============================================
    vector<Value*> getArrayValues(const string& arrayName) {
        vector<Value*> values;
        
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] Array '" << arrayName << "' no encontrado" << endl;
            return values;
        }
        
        AllocaInst *arrayAlloca = namedArrays[arrayName].first;
        int arraySize = namedArrays[arrayName].second;
        Type *DoubleTy = Type::getDoubleTy(*context);
        
        for (int i = 0; i < arraySize; i++) {
            Value *indexValue = ConstantInt::get(Type::getInt32Ty(*context), i);
            Value *elementPtr = irBuilder->CreateGEP(DoubleTy, arrayAlloca, indexValue);
            Value *loadedValue = irBuilder->CreateLoad(DoubleTy, elementPtr);
            values.push_back(loadedValue);
        }
        
        return values;
    }

    // ============================================
    // HELPER: Suma de un array
    // ============================================
    Value* calculateSum(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        
        Value *sum = ConstantFP::get(*context, APFloat(0.0));
        for (Value *val : values) {
            sum = irBuilder->CreateFAdd(sum, val, "sum");
        }
        return sum;
    }

      // ============================================
      // HELPER: Media de un array
      // ============================================
      Value* calculateMean(const vector<Value*>& values) {
          if (values.empty()) return nullptr;
          
          Value *sum = calculateSum(values);
          Value *count = ConstantFP::get(*context, APFloat((double)values.size()));
          return irBuilder->CreateFDiv(sum, count, "mean");
      }

      // ============================================
      // HELPER: Mínimo de un array
      // ============================================
      Value* calculateMin(const vector<Value*>& values) {
          if (values.empty()) return nullptr;
          
          Value *minVal = values[0];
          for (size_t i = 1; i < values.size(); i++) {
              Value *cmp = irBuilder->CreateFCmpOLT(minVal, values[i], "cmp");
              minVal = irBuilder->CreateSelect(cmp, minVal, values[i], "min");
          }
          return minVal;
      }

      // ============================================
      // HELPER: Máximo de un array
      // ============================================
      Value* calculateMax(const vector<Value*>& values) {
          if (values.empty()) return nullptr;
          
          Value *maxVal = values[0];
          for (size_t i = 1; i < values.size(); i++) {
              Value *cmp = irBuilder->CreateFCmpOGT(maxVal, values[i], "cmp");
              maxVal = irBuilder->CreateSelect(cmp, maxVal, values[i], "max");
          }
          return maxVal;
      }

      // ============================================
      // HELPER: Varianza de un array
      // ============================================
      Value* calculateVariance(const vector<Value*>& values) {
          if (values.empty()) return nullptr;
          
          Value *mean = calculateMean(values);
          Value *sumSquares = ConstantFP::get(*context, APFloat(0.0));
          
          for (Value *val : values) {
              Value *diff = irBuilder->CreateFSub(val, mean, "diff");
              Value *square = irBuilder->CreateFMul(diff, diff, "square");
              sumSquares = irBuilder->CreateFAdd(sumSquares, square, "sumSquares");
          }
          
          Value *count = ConstantFP::get(*context, APFloat((double)values.size()));
          Value *variance = irBuilder->CreateFDiv(sumSquares, count, "variance");
          
          return variance;
      }

    // ============================================
    // HELPER: Desviación estándar de un array
    // ============================================
    Value* calculateStdev(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        
        Value *variance = calculateVariance(values);
        auto sqrtFunc = Intrinsic::getOrInsertDeclaration(
            module. get(), 
            Intrinsic::sqrt, 
            {Type::getDoubleTy(*context)}
        );
        
        Value *stdev = irBuilder->CreateCall(sqrtFunc, {variance}, "stdev");
        return stdev;
    }

    // ============================================
    // HELPER: Mediana de un array (aproximada)
    // ============================================
    Value* calculateMedian(const vector<Value*>& values) {
        if (values. empty()) return nullptr;
        
        Value *minVal = calculateMin(values);
        Value *maxVal = calculateMax(values);
        Value *sum = irBuilder->CreateFAdd(minVal, maxVal, "sum_minmax");
        Value *two = ConstantFP::get(*context, APFloat(2.0));
        Value *median = irBuilder->CreateFDiv(sum, two, "median_approx");
        
        return median;
    }

    // ============================================
    // HELPER: Moda de un array (aproximada)
    // ============================================
    Value* calculateMode(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        return values[0];
    }

    // ============================================
    // HELPER: Imprimir tabla de frecuencias (valores únicos)
    // ============================================
    void printFrequencyTable(const string& arrayName, const string& tableType) {
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] Array '" << arrayName << "' no encontrado" << endl;
            return;
        }
        
        int arraySize = namedArrays[arrayName].second;
        Type *Int32Ty = Type::getInt32Ty(*context);
        Type *Int1Ty = Type::getInt1Ty(*context);
        Type *DoubleTy = Type::getDoubleTy(*context);
        
        vector<Value*> values = getArrayValues(arrayName);
        
        irBuilder->CreateCall(printfFunc, {tableHeaderFormat});
        
        for (int i = 0; i < arraySize; i++) {
            Value *currentValue = values[i];
            
            Value *alreadyPrinted = ConstantInt::get(Int1Ty, 0);
            
            for (int j = 0; j < i; j++) {
                Value *previousValue = values[j];
                Value *isEqual = irBuilder->CreateFCmpOEQ(currentValue, previousValue, "check_duplicate");
                alreadyPrinted = irBuilder->CreateOr(alreadyPrinted, isEqual, "already_printed");
            }
            
            Function *currentFunc = irBuilder->GetInsertBlock()->getParent();
            
            BasicBlock *printBlock = BasicBlock::Create(*context, "print_value_" + to_string(i), currentFunc);
            BasicBlock *skipBlock = BasicBlock::Create(*context, "skip_value_" + to_string(i), currentFunc);
            
            Value *shouldPrint = irBuilder->CreateNot(alreadyPrinted, "should_print");
            irBuilder->CreateCondBr(shouldPrint, printBlock, skipBlock);
            
            irBuilder->SetInsertPoint(printBlock);
            
            Value *count = ConstantInt::get(Int32Ty, 0);
            
            for (int j = 0; j < arraySize; j++) {
                Value *compareValue = values[j];
                Value *isEqual = irBuilder->CreateFCmpOEQ(currentValue, compareValue, "cmp_eq");
                Value *increment = irBuilder->CreateSelect(isEqual, ConstantInt::get(Int32Ty, 1), ConstantInt::get(Int32Ty, 0), "increment");
                count = irBuilder->CreateAdd(count, increment, "count");
            }
            
            if (tableType == "Freq" || tableType == "AbsFreq") {
                irBuilder->CreateCall(printfFunc, {tableLineFormat, currentValue, count});
            }
            else if (tableType == "RelFreq") {
                Value *countDouble = irBuilder->CreateSIToFP(count, DoubleTy, "count_double");
                Value *total = ConstantFP::get(*context, APFloat((double)arraySize));
                Value *relFreq = irBuilder->CreateFDiv(countDouble, total, "relfreq");
                irBuilder->CreateCall(printfFunc, {tableRelFreqFormat, currentValue, relFreq});
            }
            
            irBuilder->CreateBr(skipBlock);
            irBuilder->SetInsertPoint(skipBlock);
        }
        
        irBuilder->CreateCall(printfFunc, {tableFooterFormat});
    }

public:
    Driver() {
        context = std::make_unique<LLVMContext>();
        module = std::make_unique<Module>("StatCompModule", *context);
        irBuilder = std::make_unique<IRBuilder<>>(*context);
    }

    Module* getModule() {
        return module.get();
    }

    Value* getVal(std::any v) {
        try {
            if (v.has_value()) {
                return std::any_cast<Value*>(v);
            }
        } catch (...) {}
        return nullptr;
    }

    // ============================================
    // VISITOR: Programa Principal
    // ============================================
    virtual std::any visitProg(StatCompParser::ProgContext *ctx) override {
        Type *Int32Ty = Type::getInt32Ty(*context);
        FunctionType *mainFuncType = FunctionType::get(Int32Ty, false);
        Function *mainFunc = Function::Create(mainFuncType, Function::ExternalLinkage, "main", module.get());

        BasicBlock *entryBB = BasicBlock::Create(*context, "entry", mainFunc);
        irBuilder->SetInsertPoint(entryBB);
        
        Constant *s = ConstantDataArray::getString(*context, "Result: %f\n");
        GlobalVariable *gVar = new GlobalVariable(*module, s->getType(), true, GlobalValue::PrivateLinkage, s, ". str");
        formatStr = irBuilder->CreateInBoundsGEP(s->getType(), gVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *headerStr = ConstantDataArray::getString(*context, "\n===== TABLA DE FRECUENCIAS =====\n");
        GlobalVariable *headerVar = new GlobalVariable(*module, headerStr->getType(), true, GlobalValue::PrivateLinkage, headerStr, ".str_header");
        tableHeaderFormat = irBuilder->CreateInBoundsGEP(headerStr->getType(), headerVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *lineStr = ConstantDataArray::getString(*context, "  %. 2f    %d\n");
        GlobalVariable *lineVar = new GlobalVariable(*module, lineStr->getType(), true, GlobalValue::PrivateLinkage, lineStr, ".str_line");
        tableLineFormat = irBuilder->CreateInBoundsGEP(lineStr->getType(), lineVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *relFreqStr = ConstantDataArray::getString(*context, "  %.2f    %. 4f\n");
        GlobalVariable *relFreqVar = new GlobalVariable(*module, relFreqStr->getType(), true, GlobalValue::PrivateLinkage, relFreqStr, ".str_relfreq");
        tableRelFreqFormat = irBuilder->CreateInBoundsGEP(relFreqStr->getType(), relFreqVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *footerStr = ConstantDataArray::getString(*context, "================================\n\n");
        GlobalVariable *footerVar = new GlobalVariable(*module, footerStr->getType(), true, GlobalValue::PrivateLinkage, footerStr, ".str_footer");
        tableFooterFormat = irBuilder->CreateInBoundsGEP(footerStr->getType(), footerVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        std::vector<Type*> printfArgs = {PointerType::getUnqual(*context)};
        FunctionType *printfType = FunctionType::get(Int32Ty, printfArgs, true);
        printfFunc = module->getOrInsertFunction("printf", printfType);

        // Visitar cada statement del programa explícitamente
        for (auto stmt : ctx->stmt()) {
            visit(stmt);
        }

        irBuilder->CreateRet(ConstantInt::get(Int32Ty, 0));
        verifyFunction(*mainFunc);
        return std::any();
    }

    // ============================================
    // VISITOR: Imprimir
    // ============================================
    virtual std::any visitPrintExpr(StatCompParser::PrintExprContext *ctx) override {
        Value *val = getVal(visit(ctx->expr()));
        if (val) {
            std::vector<Value*> args;
            
            // Detectar si es string (puntero a i8) o número
            if (val->getType()->isPointerTy()) {
                // Es un string - usar formato %s
                Constant *strFormat = ConstantDataArray::getString(*context, "%s\n", true);
                GlobalVariable *formatVar = new GlobalVariable(
                    *module, 
                    strFormat->getType(), 
                    true, 
                    GlobalValue::PrivateLinkage, 
                    strFormat, 
                    ".str_fmt"
                );
                Type *Int32Ty = Type::getInt32Ty(*context);
                Value *zero = ConstantInt::get(Int32Ty, 0);
                Value *formatPtr = irBuilder->CreateInBoundsGEP(
                    strFormat->getType(), 
                    formatVar, 
                    {zero, zero}
                );
                args.push_back(formatPtr);
                args.push_back(val);
            } else {
                // Es un número - usar formato %f
                if (val->getType()->isIntegerTy()) {
                    val = irBuilder->CreateSIToFP(val, Type::getDoubleTy(*context), "cast_to_double");
                }
                args.push_back(formatStr);
                args.push_back(val);
            }
            
            irBuilder->CreateCall(printfFunc, args);
        }
        return std::any();
    }

    // ============================================
    // VISITOR: Literales
    // ============================================
    virtual std::any visitExprLiteral(StatCompParser::ExprLiteralContext *ctx) override {
        string text = ctx->getText();
        double value = std::stod(text);
        return (Value*)ConstantFP::get(*context, APFloat(value));
    }

    virtual std::any visitExprPar(StatCompParser::ExprParContext *ctx) override {
        return visit(ctx->expr());
    }

    virtual std::any visitExprNeg(StatCompParser::ExprNegContext *ctx) override {
        Value *val = getVal(visit(ctx->expr()));
        if (! val) return nullptr;
        return (Value*)irBuilder->CreateFNeg(val, "negtmp");
    }

    // ============================================
    // VISITOR: Operaciones aritméticas
    // ============================================
    virtual std::any visitExprAddSub(StatCompParser::ExprAddSubContext *ctx) override {
        Value *L = getVal(visit(ctx->expr(0)));
        Value *R = getVal(visit(ctx->expr(1)));
        if (!L || !R) return nullptr;
        if (ctx->ADD()) return (Value*)irBuilder->CreateFAdd(L, R, "addtmp");
        if (ctx->SUB()) return (Value*)irBuilder->CreateFSub(L, R, "subtmp");
        return nullptr;
    }

    virtual std::any visitExprMulDiv(StatCompParser::ExprMulDivContext *ctx) override {
        Value *L = getVal(visit(ctx->expr(0)));
        Value *R = getVal(visit(ctx->expr(1)));
        if (!L || !R) return nullptr;
        string op = ctx->children[1]->getText();
        if (op == "*") return (Value*)irBuilder->CreateFMul(L, R, "multmp");
        if (op == "/") return (Value*)irBuilder->CreateFDiv(L, R, "divtmp");
        if (op == "//") {
            Value *divResult = irBuilder->CreateFDiv(L, R, "fdivtmp");
            auto truncFunc = Intrinsic::getOrInsertDeclaration(module.get(), Intrinsic::trunc, {Type::getDoubleTy(*context)});
            return (Value*)irBuilder->CreateCall(truncFunc, {divResult}, "inttmp");
        }
        if (op == "%") return (Value*)irBuilder->CreateFRem(L, R, "modtmp");
        return nullptr;
    }

    virtual std::any visitExprPow(StatCompParser::ExprPowContext *ctx) override {
        Value *base = getVal(visit(ctx->expr(0)));
        Value *exp = getVal(visit(ctx->expr(1)));
        if (!base || !exp) return nullptr;
        auto powFunc = Intrinsic::getOrInsertDeclaration(module.get(), Intrinsic::pow, {Type::getDoubleTy(*context)});
        return (Value*)irBuilder->CreateCall(powFunc, {base, exp}, "powtmp");
    }

    // ============================================
    // VISITOR: Variables
    // ============================================
    virtual std::any visitUpdateSymbol(StatCompParser::UpdateSymbolContext *ctx) override {
        string varName = ctx->ID()->getText();
        Value *initValue = getVal(visit(ctx->expr()));
        if (!initValue) {
            cerr << "[ERROR] No se pudo evaluar la expresión para " << varName << endl;
            return nullptr;
        }
        Function *currentFunc = irBuilder->GetInsertBlock()->getParent();
        IRBuilder<> tmpBuilder(&currentFunc->getEntryBlock(), currentFunc->getEntryBlock(). begin());
        AllocaInst *alloca = tmpBuilder.CreateAlloca(Type::getDoubleTy(*context), nullptr, varName);
        namedValues[varName] = alloca;
        irBuilder->CreateStore(initValue, alloca);
        return initValue;
    }

    virtual std::any visitExprVar(StatCompParser::ExprVarContext *ctx) override {
        string varName = ctx->ID()->getText();
        if (namedValues.find(varName) == namedValues.end()) {
            cerr << "[ERROR] Variable '" << varName << "' no definida" << endl;
            return nullptr;
        }
        AllocaInst *alloca = namedValues[varName];
        Value *loadedValue = irBuilder->CreateLoad(Type::getDoubleTy(*context), alloca, varName + "_val");
        return (Value*)loadedValue;
    }

    // ============================================
    // VISITOR: Arrays
    // ============================================
    virtual std::any visitArrayDecl(StatCompParser::ArrayDeclContext *ctx) override {
        string arrayName = ctx->ID()->getText();
        vector<double> numbers;
        if (ctx->arrayInit() && ctx->arrayInit()->numlist()) {
            auto numlist = ctx->arrayInit()->numlist();
            for (auto numCtx : numlist->num()) {
                string text = numCtx->getText();
                double value = std::stod(text);
                numbers.push_back(value);
            }
        }
        int arraySize = numbers.size();
        if (arraySize == 0) {
            cerr << "[ERROR] Array '" << arrayName << "' está vacío" << endl;
            return nullptr;
        }
        Function *currentFunc = irBuilder->GetInsertBlock()->getParent();
        IRBuilder<> tmpBuilder(&currentFunc->getEntryBlock(), currentFunc->getEntryBlock().begin());
        Type *DoubleTy = Type::getDoubleTy(*context);
        AllocaInst *arrayAlloca = tmpBuilder.CreateAlloca(DoubleTy, ConstantInt::get(Type::getInt32Ty(*context), arraySize), arrayName);
        namedArrays[arrayName] = {arrayAlloca, arraySize};
        for (int i = 0; i < arraySize; i++) {
            Value *indexValue = ConstantInt::get(Type::getInt32Ty(*context), i);
            Value *elementPtr = irBuilder->CreateGEP(DoubleTy, arrayAlloca, indexValue, arrayName + "[" + to_string(i) + "]");
            Value *valueToStore = ConstantFP::get(*context, APFloat(numbers[i]));
            irBuilder->CreateStore(valueToStore, elementPtr);
        }
        cout << "[INFO] Array '" << arrayName << "' declarado con " << arraySize << " elementos" << endl;
        return nullptr;
    }

    virtual std::any visitExprArrayAccess(StatCompParser::ExprArrayAccessContext *ctx) override {
        string arrayName = ctx->ID()->getText();
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] Array '" << arrayName << "' no definido" << endl;
            return nullptr;
        }
        Value *indexValue = getVal(visit(ctx->expr()));
        if (!indexValue) {
            cerr << "[ERROR] Índice inválido para array '" << arrayName << "'" << endl;
            return nullptr;
        }
        if (indexValue->getType()->isDoubleTy()) {
            indexValue = irBuilder->CreateFPToSI(indexValue, Type::getInt32Ty(*context), "index_int");
        }
        AllocaInst *arrayAlloca = namedArrays[arrayName]. first;
        Type *DoubleTy = Type::getDoubleTy(*context);
        Value *elementPtr = irBuilder->CreateGEP(DoubleTy, arrayAlloca, indexValue, arrayName + "_elem");
        Value *loadedValue = irBuilder->CreateLoad(DoubleTy, elementPtr, arrayName + "_val");
        return (Value*)loadedValue;
    }

    // ============================================
    // VISITOR: Funciones estadísticas
    // ============================================
    virtual std::any visitExprStatFunc(StatCompParser::ExprStatFuncContext *ctx) override {
        string funcName = ctx->statFunc()->getText();
        if (! ctx->arglist() || ctx->arglist()->expr(). empty()) {
            cerr << "[ERROR] Función '" << funcName << "' requiere argumentos" << endl;
            return nullptr;
        }
        auto firstExpr = ctx->arglist()->expr(0);
        if (funcName == "Square_root") {
            Value *val = getVal(visit(firstExpr));
            if (val) {
                auto sqrtFunc = Intrinsic::getOrInsertDeclaration(module.get(), Intrinsic::sqrt, {Type::getDoubleTy(*context)});
                Value *result = irBuilder->CreateCall(sqrtFunc, {val}, "sqrt");
                cout << "[INFO] Calculando Square_root" << endl;
                return (Value*)result;
            }
            cerr << "[ERROR] No se pudo evaluar argumento de Square_root" << endl;
            return nullptr;
        }
        string arrayName = firstExpr->getText();
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] '" << arrayName << "' no es un array definido" << endl;
            return nullptr;
        }
        vector<Value*> values = getArrayValues(arrayName);
        if (values. empty()) {
            cerr << "[ERROR] Array vacío en función '" << funcName << "'" << endl;
            return nullptr;
        }
        Value *result = nullptr;
        if (funcName == "Mean") {
            result = calculateMean(values);
            cout << "[INFO] Calculando Mean(" << arrayName << ")" << endl;
        } 
        else if (funcName == "Sum") {
            result = calculateSum(values);
            cout << "[INFO] Calculando Sum(" << arrayName << ")" << endl;
        }
        else if (funcName == "Min") {
            result = calculateMin(values);
            cout << "[INFO] Calculando Min(" << arrayName << ")" << endl;
        }
        else if (funcName == "Max") {
            result = calculateMax(values);
            cout << "[INFO] Calculando Max(" << arrayName << ")" << endl;
        }
        else if (funcName == "Count") {
            result = ConstantFP::get(*context, APFloat((double)values.size()));
            cout << "[INFO] Calculando Count(" << arrayName << ")" << endl;
        }
        else if (funcName == "Var") {
            result = calculateVariance(values);
            cout << "[INFO] Calculando Var(" << arrayName << ")" << endl;
        }
        else if (funcName == "Stdev") {
            result = calculateStdev(values);
            cout << "[INFO] Calculando Stdev(" << arrayName << ")" << endl;
        }
        else if (funcName == "Median") {
            result = calculateMedian(values);
            cout << "[INFO] Calculando Median(" << arrayName << ") [aproximación]" << endl;
        }
        else if (funcName == "Mode") {
            result = calculateMode(values);
            cout << "[INFO] Calculando Mode(" << arrayName << ") [aproximación]" << endl;
        }
        else if (funcName == "Range") {
            Value *minVal = calculateMin(values);
            Value *maxVal = calculateMax(values);
            result = irBuilder->CreateFSub(maxVal, minVal, "range");
            cout << "[INFO] Calculando Range(" << arrayName << ")" << endl;
        }
        else {
            cerr << "[ERROR] Función '" << funcName << "' no implementada aún" << endl;
            return nullptr;
        }
        return (Value*)result;
    }

    // ============================================
    // VISITOR: Tablas de frecuencia
    // ============================================
    virtual std::any visitExprTableFunc(StatCompParser::ExprTableFuncContext *ctx) override {
        string funcName = ctx->tableFunc()->getText();
        if (!ctx->arglist() || ctx->arglist()->expr().empty()) {
            cerr << "[ERROR] Función '" << funcName << "' requiere argumentos" << endl;
            return nullptr;
        }
        auto firstExpr = ctx->arglist()->expr(0);
        string arrayName = firstExpr->getText();
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] '" << arrayName << "' no es un array definido" << endl;
            return nullptr;
        }
        cout << "[INFO] Generando tabla: " << funcName << "(" << arrayName << ")" << endl;
        if (funcName == "Freq" || funcName == "AbsFreq") {
            printFrequencyTable(arrayName, funcName);
        }
        else if (funcName == "RelFreq") {
            printFrequencyTable(arrayName, funcName);
        }
        else if (funcName == "AbsFreqCum" || funcName == "RelFreqCum") {
            cerr << "[WARN] " << funcName << " no implementada aún" << endl;
        }
        else {
            cerr << "[ERROR] Función de tabla '" << funcName << "' no implementada" << endl;
        }
        return nullptr;
    }

    // ============================================
    // FUNCIONES NO IMPLEMENTADAS
    // ============================================
    virtual std::any visitExprString(StatCompParser::ExprStringContext *ctx) override {
        string text = ctx->getText();
        // Remover comillas del inicio y final
        if (text.length() >= 2 && text.front() == '"' && text.back() == '"') {
            text = text.substr(1, text.length() - 2);
        }
        
        // Procesar secuencias de escape
        string processed;
        for (size_t i = 0; i < text.length(); ++i) {
            if (text[i] == '\\' && i + 1 < text.length()) {
                switch (text[i + 1]) {
                    case 'n': processed += '\n'; i++; break;
                    case 't': processed += '\t'; i++; break;
                    case 'r': processed += '\r'; i++; break;
                    case '\\': processed += '\\'; i++; break;
                    case '"': processed += '"'; i++; break;
                    default: processed += text[i]; break;
                }
            } else {
                processed += text[i];
            }
        }
        
        // Crear string constante global
        Constant *strConstant = ConstantDataArray::getString(*context, processed, true);
        GlobalVariable *strGlobal = new GlobalVariable(
            *module, 
            strConstant->getType(), 
            true, 
            GlobalValue::PrivateLinkage, 
            strConstant, 
            ".str"
        );
        
        // Retornar puntero al string
        Type *Int32Ty = Type::getInt32Ty(*context);
        Value *zero = ConstantInt::get(Int32Ty, 0);
        return (Value*)irBuilder->CreateInBoundsGEP(
            strConstant->getType(), 
            strGlobal, 
            {zero, zero}
        );
    }
    virtual std::any visitStatFunc(StatCompParser::StatFuncContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitTableFunc(StatCompParser::TableFuncContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitArglist(StatCompParser::ArglistContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitArrayInit(StatCompParser::ArrayInitContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitNumlist(StatCompParser::NumlistContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitDecltype(StatCompParser::DecltypeContext *ctx) override { return visitChildren(ctx); }

    // ============================================
    // EJECUTAR CÓDIGO GENERADO CON JIT
    // ============================================
    void executeCode() {
        InitializeNativeTarget();
        InitializeNativeTargetAsmPrinter();
        InitializeNativeTargetAsmParser();

        std::unique_ptr<Module> clonedModule = CloneModule(*module);

        string errorStr;
        EngineBuilder builder(std::move(clonedModule));
        builder.setErrorStr(&errorStr);
        builder.setEngineKind(EngineKind::JIT);
        
        ExecutionEngine *executionEngine = builder.create();
        
        if (!executionEngine) {
            cerr << "[ERROR] No se pudo crear ExecutionEngine: " << errorStr << endl;
            return;
        }

        executionEngine->finalizeObject();

        Function *mainFunc = executionEngine->FindFunctionNamed("main");
        
        if (!mainFunc) {
            cerr << "[ERROR] No se encontró la función main" << endl;
            delete executionEngine;
            return;
        }

        vector<GenericValue> noargs;
        executionEngine->runFunction(mainFunc, noargs);

        delete executionEngine;
    }
};

#endif // DRIVER_H