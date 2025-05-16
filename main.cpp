#include <iostream>
#include <fstream>
#include <sstream>
#include "lexical.h"
#include "semantic.h"
using namespace std;
int main() {
    ifstream infile("input.c");
    if (!infile) {
        std::cerr << "Error: Could not open input.cpp\n";
        return 1;
    }

    stringstream buffer;
    buffer << infile.rdbuf();  // Read the whole file into a string
    string code = buffer.str();

    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();

    SemanticAnalyzer semantic;
    semantic.analyze(tokens);

    return 0;
}
