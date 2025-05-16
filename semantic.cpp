#include "semantic.h"

void SemanticAnalyzer::declareVariable(const std::string& var) {
    if (symbolTable.find(var) != symbolTable.end()) {
        std::cerr << "Semantic Error: Variable '" << var << "' already declared.\n";
    } else {
        symbolTable.insert(var);
    }
}

bool SemanticAnalyzer::isDeclared(const std::string& var) {
    return symbolTable.find(var) != symbolTable.end();
}
// semantic.cpp
#include "semantic.h"
#include <fstream>
#include <unordered_set>
#include <iostream>

void SemanticAnalyzer::analyze(const std::vector<Token>& tokens) {
    std::unordered_set<std::string> declaredVariables;
    std::ofstream outFile("semantic_output.txt");

    if (!outFile) {
        std::cerr << "Error: Could not open semantic_output.txt for writing.\n";
        return;
    }

    for (size_t i = 0; i < tokens.size(); ++i) {
        const Token& token = tokens[i];

        if (token.type == TokenType::Keyword && token.value == "int") {
            // Variable declaration
            if (i + 1 < tokens.size() && tokens[i + 1].type == TokenType::Identifier) {
                declaredVariables.insert(tokens[i + 1].value);
                i++; // Skip the identifier
            }
        } else if (token.type == TokenType::Identifier) {
            // Variable usage
            if (declaredVariables.find(token.value) == declaredVariables.end()) {
                outFile << "Semantic Error: Variable '" << token.value << "' used before declaration\n";
            }
        }
    }

    outFile.close();
}
