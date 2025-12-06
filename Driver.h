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
    llvm::Type *DoubleTy = llvm::Type::getDoubleTy(context);
    llvm::Type *VoidTy = llvm::Type::getVoidTy(context);
    llvm::Type *Int32Ty = llvm::Type::getInt32Ty(context);
    llvm::PointerType *DoublePtrTy = llvm::PointerType::getUnqual(DoubleTy); // puntero a double
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
    std::string varName = ctx->ID()->getText();
    llvm::Type *varType = getLLVMType(ctx->decltype());
	
    llvm::Value *RHSValue = std::any_cast<llvm::Value*>(visit(ctx->expr()));

    llvm::AllocaInst *AllocaPtr = nullptr;

    if (namedValues.find(varName) == namedValues.end()) {
	// Primera declaración de la variable
	llvm::Function *mainFunc = irBuilder->GetInsertBlock()->getParent();
	llvm::BasicBlock  *currentBB = irBuilder->GetInsertBlock();
	AllocaPtr = irBuilder->CreateAlloca(varType, nullptr, varName);
	namedValues[varName] = AllocaPtr;
	irBuilder->SetInsertPoint(currentBB);
    } else {
	// Referencia a variable existente
	AllocaPtr = namedValues[varName];
    }
    irBuilder->CreateStore(RHSValue, AllocaPtr);

    return std::any();
  }

  virtual std::any visitArrayDecl(StatCompParser::ArrayDeclContext *ctx) override {

    // Paso 1: Obtener metadatos sobre la declaración
    std::string arrayName = ctx->ID()->getText();
    llvm::Type *ElementType = getLLVMType(ctx->decltype());

    // Paso 2.a: Verificar/procesar la inicialización del array.
    std::vector<llvm::Constant*> Initializers;
    
    if (ctx->arrayInit()) {
        // Evaluar todas las expresiones de inicialización constante.
        // Esto debe devolver un vector de constantes (llvm::Constant*).
        try {
            Initializers = std::any_cast<std::vector<llvm::Constant*>>(visit(ctx->arrayInit()));
        } catch (const std::bad_any_cast& e) {
            std::cerr << "Error: Inicialización de array debe producir constantes." << std::endl;
            return std::any();
        }
    } else {
        // No hay inicialización explícita (array vacío).
        // ¿Permitiremos esto? Podemos emitir error o usar un valor por defecto.
    }


    size_t arraySize = Initializers.size();

    // Necesitamos el tipo entero para contar e indexar (i32).
    llvm::Type *Int32Ty = llvm::Type::getInt32Ty(context);
    llvm::ConstantInt *ZeroIndex = llvm::ConstantInt::get(Int32Ty, 0);

    llvm::ArrayType *ArrayTy = llvm::ArrayType::get(ElementType, arraySize); // [3]

    // Paso 2.b: Crear la asignación de memoria.

    // Guardar la posición actual del IRBuilder.
    llvm::BasicBlock *currentBlock = irBuilder->GetInsertBlock();
    // Necesitamos el bloque de entrada (entry block) de la función actual.
    llvm::Function *mainFunc = currentBlock->getParent();
    llvm::IRBuilder<> tmpBuilder(&mainFunc->getEntryBlock()->front());

    // Crear la instrucción alloca en el inicio del bloque de entrada.
    // Esta asigna espacio para el array en la pila.
    llvm::AllocaInst *ArrayPtr = tmpBuilder.CreateAlloca(ArrayTy, nullptr, arrayName);
    
    // Añadir a la tabla de símbolos.
    namedValues[arrayName] = ArrayPtr;

    // Restaurar la posición del IRBuilder.
    irBuilder->SetInsertPoint(currentBlock);

    // Paso 3: Realizar la inicialización elemento por elemento.
    // Compilar cada inicializador y almacenarla en su índice correspondiente.
    
    for (size_t i = 0; i < Initializers.size(); ++i) {
    	llvm::ConstantInt *IndexI = llvm::ConstantInt::get(Int32Ty, i);
    	
    	std::vector<llvm::Value*> indices = {ZeroIndex, IndexI};
    	
    	// Calcular la dirección del elemento [0][i] usando GEP.
    	llvm::Value *ElementPtr = irBuilder->CreateGEP(ArrayTy, ArrayPtr, indices, "arrayidx");
    	
    	// Almacenar el valor inicializado en esa dirección.
    	irBuilder->CreateStore(Initializers[i], ElementPtr);
    }
    

    return std::any();
  }

  virtual std::any visitExprTableFunc(StatCompParser::ExprTableFuncContext *ctx) override {
    // 1. Nombre de la función de tabla que se quiere llamar
    std::string funcName = std::any_cast<std::string>(visit(ctx->tableFunc()));
    
    // 2. Argumentos: una expresión que debe ser un array
    llvm::Value *dataPtr = std::any_cast<llvm::Value*>(visit(ctx->arglist()));
    
    // 3. Tamaño del array
    llvm::Value *sizeValue = retrieveArraySize(dataPtr);
    
    // 4. Configurar la llamada externa
    std::vector<llvm::Type*> argTypes = {DoublePtrTy, Int32Ty};
    llvm::FunctionType *funcType = llvm::FunctionType::get(VoidTy, argTypes, false);
    
    // 5. Función completa con prefijo
    std::string fullFuncName = "StatComp_" + funcName;
    llvm::FunctionCallee funcCallee = module->getOrInsertFunction(fullFuncName, funcType);
    
    // 6. Preparar argumentos para la llamada
    std::vector<llvm::Value*> args = {dataPtr, sizeValue};
    
    // 7. Generar la llamada
    irBuilder->CreateCall(funcCallee, args, "table_call");
    
    return std::any(); // Las funciones de tabla no retornan valores
  }

  virtual std::any visitExprAddSub(StatCompParser::ExprAddSubContext *ctx) override {
    // Evaluar los operandos izquierdo y derecho.
    Value *L = std::any_cast<Value*>(visit(ctx->expr(0)));
    Value *R = std::any_cast<Value*>(visit(ctx->expr(1)));

    if (!L || !R) return nullptr

    return nullptr;
  }

  virtual std::any visitExprString(StatCompParser::ExprStringContext *ctx) override {
    Value *L = std::any_cast<Value*>(visit(ctx->expr(0)));
    Value *R = std::any_cast<Value*>(visit(ctx->expr(1)))
    if (!L || !R) return nullptr
    if (ctx->MUL()) return (Value*)irBuilder->CreateFMul(L, R, "multmp");
    if (ctx->DIV()) return (Value*)irBuilder->CreateFDiv(L, R, "divtmp");
    return nullptr;
  }

  virtual std::any visitExprVar(StatCompParser::ExprVarContext *ctx) override {
    // 1. Obtener el nombre de la variable que se está referenciando.
    std::string varName = ctx->ID()->getText(); 

    // 2. Buscar el puntero de alloca en la tabla de símbolos.
    llvm::Value *varPtr = SymbolTable.lookup(varName);

    if (!varPtr) {
        // Error de compilación: variable no declarada.
        std::cerr << "Error: variable '" << varName << "' no declarada." << std::endl;
        return nullptr; 
    }

    // 3. Cargar el valor de la variable desde la memoria.
    //    Esto produce la instrucción `load` de LLVM IR.

    // Necesitamos especificar el tipo a cargar. En LLVM moderno, `load` requiere el tipo.
    llvm::Type *loadedType = varPtr->getType()->getPointerElementType(); 

    llvm::Value *loadedValue = irBuilder->CreateLoad(loadedType, varPtr, varName + "_load");

    return loadedValue; 
  }

  virtual std::any visitExprLiteral(StatCompParser::ExprLiteralContext *ctx) override {
    llvm::Type *DoubleTy = llvm::Type::getDoubleTy(context);

    if (ctx->INT_LITERAL()) {
        // Manejar literal entero como constante flotante para uniformidad LLVM.
        // (esto asume que int se promueve a double dentro del compilador)
        std::string text = ctx->INT_LITERAL()->getText();
        double intValue = std::stod(text);

        // Crear una constante LLVM con valor double.
        return llvm::ConstantFP::get(DoubleTy, intValue);
        
    } else if (ctx->FLOAT_LITERAL()) {
        // Literal flotante directo.
        // Es el caso más directo y natural.
        std::string text = ctx->FLOAT_LITERAL()->getText();
        double floatValue = std::stod(text);

        // Crear una constante de doble precisión (f64).
        return llvm::ConstantFP::get(DoubleTy, floatValue);
        
    } else {
        // Error: no es ni entero ni flotante (puede ser string u otro tipo).
        std::cerr << "Error: literal no soportado en este contexto." << std::endl;
        return nullptr;
    }
  }

  virtual std::any visitExprArrayAccess(StatCompParser::ExprArrayAccessContext *ctx) override {
    // 1. Obtener el nombre del array.
    std::string arrayName = ctx->ID()->getText();

    // 2. Resolver el puntero base del array desde la tabla de símbolos.
    llvm::Value *arrayPtr = SymbolTable.lookup(arrayName);

    if (!arrayPtr) {
        std::cerr << "Error: array '" << arrayName << "' no declarado." << std::endl;
        return nullptr;
    }

    // 3. Evaluar el índice.
    // El índice es una expresión que debe resolverse a un entero (o convertirse a entero).
    llvm::Value *indexValue = std::any_cast<llvm::Value*>(visit(ctx->expr()));

    if (!indexValue) {
        std::cerr << "Error: índice de array inválido." << std::endl;
        return nullptr; 
    }

    // 4. Calcular la dirección del elemento usando GEP (GetElementPtr).
    
    // Necesitamos los tipos para GEP. El tipo del array debe extraerse desde el puntero.
    llvm::Type *arrayType = arrayPtr->getType()->getPointerElementType(); 
    
    // Un array típicamente requiere dos índices para GEP:
    // - El primer índice (0) para "atravesar" el puntero al array.
    // - El segundo índice (dinámico) para seleccionar el elemento.
    
    llvm::Type *Int32Ty = llvm::Type::getInt32Ty(context);
    llvm::Value *zeroIndex = llvm::ConstantInt::get(Int32Ty, 0);
    
    std::vector<llvm::Value*> indices = {zeroIndex, indexValue};
    
    // Generar la instrucción GEP.
    llvm::Value *elementPtr = irBuilder->CreateGEP(arrayType, arrayPtr, indices, "arrayidx");
    
    // 5. Cargar el valor del elemento.
    // En muchos contextos, queremos el valor, no el puntero al valor.
    llvm::Type *elementType = elementPtr->getType()->getPointerElementType();
    llvm::Value *elementValue = irBuilder->CreateLoad(elementType, elementPtr, "arrayelement");

    return elementValue;
  }

  virtual std::any visitExprMulDiv(StatCompParser::ExprMulDivContext *ctx) override {
    Value *L = std::any_cast<Value*>(visit(ctx->expr(0)));
    Value *R = std::any_cast<Value*>(visit(ctx->expr(1)));
    if (!L || !R) return nullptr;
    
    if (ctx->op->getText() == "*") {
        return (Value*)irBuilder->CreateFMul(L, R, "multmp");
    
    } else if (ctx->op->getText() == "/") {
        return (Value*)irBuilder->CreateFDiv(L, R, "divtmp");
    }
    
    return nullptr;
  }

  virtual std::any visitExprStatFunc(StatCompParser::ExprStatFuncContext *ctx) override {
    // 1. Nombre de la función estadística
    std::string funcName = std::any_cast<std::string>(visit(ctx->statFunc()));
    
    // 2. Argumentos: expresión que debe ser un array
    llvm::Value *dataPtr = std::any_cast<llvm::Value*>(visit(ctx->arglist()));
    
    // 3. Tamaño del array
    llvm::Value *sizeValue = retrieveArraySize(dataPtr);
    
    // 4. Configurar la llamada externa (las funciones estadísticas retornan double)
    std::vector<llvm::Type*> argTypes = {DoublePtrTy, Int32Ty};
    llvm::Type *DoubleTy = llvm::Type::getDoubleTy(context);
    llvm::FunctionType *funcType = llvm::FunctionType::get(DoubleTy, argTypes, false);
    
    // 5. Función completa con prefijo
    std::string fullFuncName = "StatComp_" + funcName;
    llvm::FunctionCallee funcCallee = module->getOrInsertFunction(fullFuncName, funcType);
    
    // 6. Preparar argumentos para la llamada
    std::vector<llvm::Value*> args = {dataPtr, sizeValue};
    
    // 7. Generar la llamada (retorna el valor calculado)
    llvm::Value *result = irBuilder->CreateCall(funcCallee, args, "stat_call");
    
    return result; // Las funciones estadísticas retornan valores
  }

  virtual std::any visitStatFunc(StatCompParser::StatFuncContext *ctx) override {
    return ctx->ID()->getText();
  }

  virtual std::any visitTableFunc(StatCompParser::TableFuncContext *ctx) override {
    return ctx->ID()->getText();
  }

  virtual std::any visitArglist(StatCompParser::ArglistContext *ctx) override {
    // La lista debe contener exactamente una expresión que resuelve un array.
    llvm::Value *arrayAccessValue = std::any_cast<llvm::Value*>(visit(ctx->expr())); 
    
    // Si el array fue declarado, su puntero de alloca está en la tabla de símbolos.
    // Además, necesita la lógica para obtener el tamaño (size_value).
    // Asumiendo que el resultado de 'visit(ctx->expr())' es el puntero base del array
    // y que tiene una forma de obtener el tamaño (p. ej., de metadatos o tabla de símbolos).

    // Convertir a puntero a los datos (primer elemento).
    llvm::Value *dataPtr = arrayAccessValue; // Simplificado: asume que ya es puntero a datos.

    // Obtener el tamaño del array.
    llvm::Value *sizeValue = retrieveArraySize(dataPtr); // <--- Función de ayuda necesaria

    // Devolver el puntero a los datos. 
    // El tamaño se maneja en las funciones caller (visitExprTableFunc, visitExprStatFunc).
    return dataPtr;
  }

  virtual std::any visitArrayInit(StatCompParser::ArrayInitContext *ctx) override {
    std::vector<llvm::Constant*> array_elements;
    
    if (!ctx->numlist()) {
        // Array vacío {} - retornar vector vacío
        return array_elements;
    }

    // Paso 1: Iterar sobre cada número en la lista.
    for (auto numCtx : ctx->numlist()->num()) {
        // Paso 2: Usar visitNum para convertir cada literal en una constante LLVM.
        std::any result = visit(numCtx); 

        // Paso 3: Intentar convertir el resultado a llvm::Constant*.
        llvm::Constant *constant_value = nullptr;
        try {
            constant_value = std::any_cast<llvm::Constant*>(result);
        } catch (const std::bad_any_cast& e) {
            // Si visitNum no devolvió una constante, falló la evaluación.
            constant_value = nullptr;
        }

        // Paso 4: Si la conversión fue exitosa, agregamos la constante a la lista.
        if (constant_value) {
            array_elements.push_back(constant_value);
        } else {
            // Manejo de error si la expresión dentro del array no es constante 
            // o falló la traducción (esto rompería la semántica de inicialización).
            // Aquí se podría lanzar un error.
            std::cerr << "Error: Inicializador de array debe usar constantes." << std::endl;
            return nullptr; 
        }
    }

    // Paso 5: Devolver el vector de constantes.
    // El método padre (probablemente visitVarDecl o similar) utilizará este vector
    // para: a) determinar el tamaño del array (3) y b) construir el inicializador LLVM.
    return array_elements;
  }

  virtual std::any visitNumlist(StatCompParser::NumlistContext *ctx) override {
    std::vector<llvm::Constant*> elements;
    for (auto numCtx : ctx->num()) {
        // Asumiendo que visitNum devuelve llvm::ConstantFP*
        elements.push_back(std::any_cast<llvm::Constant*>(visit(numCtx))); 
    }
    // Retorna el vector de constantes. El nodo padre (declaración) lo usará para crear
    // el inicializador LLVM Aggregate.
    return elements;
  }

  virtual std::any visitNum(StatCompParser::NumContext *ctx) override {
     // Asume que el literal es un FLOAT_LITERAL (o que debe manejar INT_LITERAL 
    // y convertirlo a double si se usa en contexto de inicialización flotante).
    std::string text = ctx->FLOAT_LITERAL()->getText(); 
    double value = std::stod(text);

    // Crea una constante de doble precisión (f64).
    return llvm::ConstantFP::get(DoubleTy, value); 
  }

  virtual std::any visitDecltype(StatCompParser::DecltypeContext *ctx) override {
    // Si la gramática es simple (solo double):
    llvm::Type *baseType = DoubleTy; 

    if (ctx->array_specifier()) {
        // Es un array, extraer el tamaño [N]
        int arraySize = /* ... lógica para calcular el tamaño N ... */; 
        
        // Crear el tipo de array LLVM: [N x baseType]
        return llvm::ArrayType::get(baseType, arraySize);
    } 

    // Si es un escalar simple.
    return baseType;
  }


};


