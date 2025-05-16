// Token.h
#pragma once
#include <string>
enum class TokenType {
    Keyword,
    Identifier,
    Number,
    Operator,
    Separator,
    EndOfFile,
    Unknown
};

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType t, const std::string& val) : type(t), value(val) {}
};
