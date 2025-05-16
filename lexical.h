#pragma once
#include <string>
#include <vector>

enum class TokenType {
    Keyword,
    Identifier,
    Number,
    Operator,
    Delimiter,
    Unknown,
    EndOfFile
};

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType t, const std::string& v) : type(t), value(v) {}
};

class Lexer {
    std::string source;
    size_t pos;

public:
    Lexer(const std::string& src) : source(src), pos(0) {}

    Token getNextToken();
    std::vector<Token> tokenize();

private:
    char peek();
    char get();
    void skipWhitespace();
    void skipComment();
    void skipStringLiteral();
};