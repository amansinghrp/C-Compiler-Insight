#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
#include "lexical.h"  // for Token and TokenType

class SemanticAnalyzer {
public:
    // Analyze tokens to check semantic errors
    void analyze(const std::vector<Token>& tokens);

private:
    std::unordered_set<std::string> symbolTable;

    void declareVariable(const std::string& var);
    bool isDeclared(const std::string& var);
};

#endif
