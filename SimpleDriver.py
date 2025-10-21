import sys
import os
from antlr4 import *
from antlr4.error.ErrorListener import ErrorListener

from generated.StatCompLexer import StatCompLexer
from generated.StatCompParser import StatCompParser


 MyErrorListener(ErrorListener):
    def syntaxError(self,recognizer, offendingSymbol, line, col, msg, e):
        print(f"[Warning] Error de sintaxis en linea {line}, columna {col}: {msg}")

def main(argv):
    if len(argv) < 2:
        print("Uso: python SimpleDriver.py archivo.scp")
        return

    filename = argv[1]

    # Validar extensión
    if not filename.endswith(".scp"):
        print("[Error] Solo se permiten archivos con extensión .scp")
        return

    if not os.path.exists(filename):
        print(f"[Error] El archivo {filename} no existe")
        return

    # Crear flujo de entrada
    input_stream = FileStream(filename, encoding="utf-8")

    # Lexer y parser
    lexer = StatCompLexer(input_stream)
    stream = CommonTokenStream(lexer)
    parser = StatCompParser(stream)

    # Reemplazar el listener de errores por el nuestro
    parser.removeErrorListeners()
    parser.addErrorListener(MyErrorListener())

    # Punto de entrada de tu gramática (ajusta si tu regla inicial no se llama "program")
    tree = parser.prog()

    # Imprimir el árbol de parseo en formato LISP
    print(tree.toStringTree(recog=parser))

if __name__ == "__main__":
    main(sys.argv)
