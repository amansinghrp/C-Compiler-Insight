#include "lexical.h"
#include <cctype>
#include <unordered_set>

char Lexer::peek() {
    if (pos < source.size()) return source[pos];
    return '\0';
}

char Lexer::get() {
    if (pos < source.size()) return source[pos++];
    return '\0';
}

void Lexer::skipWhitespace() {
    while (isspace(peek())) get();
}

void Lexer::skipComment() {
    // Single-line comment
    if (peek() == '/' && pos + 1 < source.size() && source[pos + 1] == '/') {
        while (peek() != '\n' && peek() != '\0') get();
        return;
    }

    // Multi-line comment
    if (peek() == '/' && pos + 1 < source.size() && source[pos + 1] == '*') {
        pos += 2;
        while (pos + 1 < source.size() && !(source[pos] == '*' && source[pos + 1] == '/')) pos++;
        pos += 2; // skip "*/"
    }
}

void Lexer::skipStringLiteral() {
    if (peek() == '"') {
        get(); // skip opening quote
        while (peek() != '"' && peek() != '\0') {
            get();
        }
        if (peek() == '"') get(); // skip closing quote
    }
}

Token Lexer::getNextToken() {
    while (true) {
        skipWhitespace();

        // End of input
        char current = peek();
        if (current == '\0') return Token(TokenType::EndOfFile, "");

        // Skip comments
        if (current == '/' && pos + 1 < source.size()) {
            if (source[pos + 1] == '/' || source[pos + 1] == '*') {
                skipComment();
                continue;
            }
        }

        // Skip string literals
        if (current == '"') {
            skipStringLiteral();
            continue;
        }

        // Skip preprocessor directives (e.g., #include)
        if (current == '#') {
            while (peek() != '\n' && peek() != '\0') get();
            continue;
        }

        // Keywords or identifiers
        if (isalpha(current) || current == '_') {
            std::string word;
            while (isalnum(peek()) || peek() == '_') word += get();

            static std::unordered_set<std::string> keywords = {
                "int", "float", "char", "double", "return", "if", "else", "while", "for", "void"
            };
            if (keywords.count(word)) return Token(TokenType::Keyword, word);
            return Token(TokenType::Identifier, word);
        }

        // Numbers
        if (isdigit(current)) {
            std::string number;
            while (isdigit(peek())) number += get();
            return Token(TokenType::Number, number);
        }

        // Multi-character operators
        if ((current == '=' || current == '!' || current == '<' || current == '>') && source[pos + 1] == '=') {
            std::string op;
            op += get(); // e.g. '='
            op += get(); // '='
            return Token(TokenType::Operator, op);
        }

        // Single-character operators
        if (current == '+' || current == '-' || current == '*' || current == '/' ||
            current == '=' || current == '<' || current == '>' || current == '!') {
            std::string op(1, get());
            return Token(TokenType::Operator, op);
        }

        // Delimiters
        if (current == ';' || current == ',' || current == '(' || current == ')' ||
            current == '{' || current == '}') {
            std::string del(1, get());
            return Token(TokenType::Delimiter, del);
        }

        // Unknown character
        get();
        return Token(TokenType::Unknown, std::string(1, current));
    }
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    Token tok = getNextToken();
    while (tok.type != TokenType::EndOfFile) {
        tokens.push_back(tok);
        tok = getNextToken();
    }
    tokens.push_back(tok);  // Add EOF token
    return tokens;
}