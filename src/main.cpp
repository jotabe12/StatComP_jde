#include "CommonTokenStream.h"
#include "StatCompLexer.h"
#include "StatCompParser.h"
#include "antlr4-runtime.h"
#include "tree/ParseTree.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using namespace antlr4;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "[Error] falta un archivo";
    return 0;
  }

  string fileName = argv[1];
  string filePath = fileName.substr(fileName.length() - 3);

  if (filePath != "scp") {
    cout << "[ERROR] extension del archivo erronea, solo se admite .scp";
    return 0;
  }

  ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  StatCompLexer *lexer = new StatCompLexer(&input);
  CommonTokenStream *tokens = new CommonTokenStream(lexer);
  StatCompParser *parser = new StatCompParser(tokens);
  tree::ParseTree *tree = parser->prog();

  cout << tree->toStringTree(parser) << endl;

  return 0;
}
