#include <iostream>
#include "lexical.h"

class Parser {
public:
    Parser(const std::vector<Token>& toks) : tokens(toks), pos(0), currentToken(toks[0]) {}

    void parse() {
        while (currentToken.type != TokenType::EndOfFile) {
            std::cout << "Token: " << tokenTypeToString(currentToken.type)
                      << " , value: " << currentToken.value << "\n";
            advance();
        }
    }

private:
    std::vector<Token> tokens;
    size_t pos;
    Token currentToken;

    void advance() {
        if (pos < tokens.size() - 1) {
            currentToken = tokens[++pos];
        }
    }

    std::string tokenTypeToString(TokenType t) {
        switch (t) {
            case TokenType::Keyword: return "Keyword";
            case TokenType::Identifier: return "Identifier";
            case TokenType::Number: return "Number";
            case TokenType::Operator: return "Operator";
            case TokenType::EndOfFile: return "EOF";
            case TokenType::Unknown: return "Unknown";
        }
        return "Unknown";
    }
};

int main() {
    std::string code = "int x = 5 + 3;";
    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    parser.parse();

    return 0;
}
