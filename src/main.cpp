#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "StatCompLexer.h"
#include "StatCompParser.h"
#include "tree/ParseTree.h"
#include "Driver.h"

using namespace std;
using namespace antlr4;

int main(int argc, char *argv[]) {
    // Verificación de argumentos
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <archivo. scp>" << endl;
        return 1;
    }

    string fileName = argv[1];
    
    // Verificar extensión
    if (fileName.length() < 4 || fileName.substr(fileName.length() - 4) != ".scp") {
        cout << "[ERROR] El archivo debe tener extension .scp" << endl;
        return 1;
    }

    // Abrir archivo
    ifstream stream;
    stream.open(argv[1]);
    
    if (!stream.is_open()) {
        cout << "[ERROR] No se pudo abrir el archivo: " << fileName << endl;
        return 1;
    }

    try {
        ANTLRInputStream input(stream);
        StatCompLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        StatCompParser parser(&tokens);
        tree::ParseTree *tree = parser.prog();
        
        if (parser.getNumberOfSyntaxErrors() > 0) {
            cerr << "Error: Errores de sintaxis encontrados" << endl;
            return 1;
        }

        Driver driver;
        driver.visit(tree);
        driver.executeCode();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    stream.close();
    return 0;
}