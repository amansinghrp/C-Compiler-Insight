#include <bits/stdc++.h>
using namespace std;

#include "lexical.cpp" // Include your lexer definitions

class Parser {
    vector<token> tokens;
    int current = 0;

public:
    Parser(const vector<token>& t) : tokens(t) {}

    void parse() {
        program();
        cout << "Parsing completed successfully.\n";
    }

private:
    // Entry point for parsing
    void program() {
        // Skip any preprocessor directives
        while (check(preprocessor)) {
            preprocessorDirective();
        }
        // Parse a series of external declarations
        while (!isAtEnd()) {
            externalDeclaration();
        }
    }

    // Handle either function definitions or global declarations
    void externalDeclaration() {
        if (check(keyword) && (peek().value == "int" || peek().value == "float" || peek().value == "char" || peek().value == "bool" || peek().value == "void")) {
            // Look ahead: type ID (
            if (checkNext(identifier) && checkNextNext(separator, "(")) {
                functionDefinition();
                return;
            }
        }
        // Otherwise treat as a global variable declaration
        declaration();
        expect(separator, ";", "Expected ';' after declaration.");
    }

    // Parse a function definition: returnType name(params) { ... }
    void functionDefinition() {
        advance(); // return type
        if (!match(identifier)) error("Expected function name.");
        expect(separator, "(", "Expected '(' after function name.");
        parameterList();
        expect(separator, ")", "Expected ')' after parameters.");
        compoundStatement();
    }

    // Parse function parameters
    void parameterList() {
        if (check(separator, ")")) return; // no parameters
        do {
            // Expect a type then an identifier
            if (!(match(keyword, "int") || match(keyword, "float") || match(keyword, "char") || match(keyword, "bool") || match(keyword, "void")))
                error("Expected parameter type.");
            if (!match(identifier)) error("Expected parameter name.");
        } while (match(separator, ","));
    }

    // Parse a block { ... }
    void compoundStatement() {
        expect(separator, "{", "Expected '{' to start block.");
        while (!check(separator, "}")) {
            if (isAtEnd()) error("Expected '}' to close block.");
            statement();
        }
        expect(separator, "}", "Expected '}' after block.");
    }

    // Skip a preprocessor directive
    void preprocessorDirective() {
        advance(); // '#' token
        // Skip all tokens on this line
        int startLine = tokens[current - 1].line;
        while (!isAtEnd() && peek().line == startLine) advance();
    }

    // Parse a statement
    void statement() {
        if (check(separator, "{")) {
            compoundStatement();
            return;
        }
        if (check(keyword, "int") || check(keyword, "float") || check(keyword, "char") || check(keyword, "bool")) {
            declaration();
            expect(separator, ";", "Expected ';' after declaration.");
        }
        else if (check(keyword, "if")) {
            ifStatement();
        }
        else if (check(keyword, "while")) {
            whileStatement();
        }
        else if (check(keyword, "for")) {
            forStatement();
        }
        else if (check(keyword, "return")) {
            returnStatement();  
        }
        else {
            expression();
            expect(separator, ";", "Expected ';' after expression.");
        }
    }

    void returnStatement() {
        advance(); // consume 'return'
        // Allow empty return (like in void functions) or return with expression
        if (!check(separator, ";")) {
            expression();
        }
        expect(separator, ";", "Expected ';' after return statement.");
    }


    void declaration() {
        advance(); // type
        if (!match(identifier)) error("Expected identifier in declaration.");
        if (match(operaTor, "=")) {
            expression();
        }
    }

    void ifStatement() {
        advance(); // 'if'
        expect(separator, "(", "Expected '(' after 'if'.");
        expression();
        expect(separator, ")", "Expected ')' after condition.");
        statement();
        if (match(keyword, "else")) statement();
    }

    void whileStatement() {
        advance(); // 'while'
        expect(separator, "(", "Expected '(' after 'while'.");
        expression();
        expect(separator, ")", "Expected ')' after condition.");
        statement();
    }

    void forStatement() {
        advance(); // 'for'
        expect(separator, "(", "Expected '(' after 'for'.");
        if (!check(separator, ";")) expression();
        expect(separator, ";", "Expected ';' after init in 'for'.");
        if (!check(separator, ";")) expression();
        expect(separator, ";", "Expected ';' after condition in 'for'.");
        if (!check(separator, ")")) expression();
        expect(separator, ")", "Expected ')' after increment in 'for'.");
        statement();
    }

    // Expression grammar (recursive descent)
    void expression() { logicalOr(); }
    void logicalOr() { logicalAnd(); while (match(operaTor, "||")) logicalAnd(); }
    void logicalAnd() { equality(); while (match(operaTor, "&&")) equality(); }
    void equality() { relational(); while (match(operaTor, "==") || match(operaTor, "!=")) relational(); }
    void relational() { additive(); while (match(operaTor, ">") || match(operaTor, "<") || match(operaTor, ">=") || match(operaTor, "<=")) additive(); }
    void additive() { term(); while (match(operaTor, "+") || match(operaTor, "-")) term(); }
    void term() { factor(); while (match(operaTor, "*") || match(operaTor, "/")) factor(); }
    void factor() {
        if (match(number) || match(identifier)) return;
        if (match(separator, "(")) { expression(); expect(separator, ")", "Expected ')' after expression."); return; }
        error("Expected number, identifier, or '('.");
    }

    // Utility methods
    token peek() { return !isAtEnd() ? tokens[current] : token{unknown, "", -1, -1}; }
    bool isAtEnd() { return current >= tokens.size(); }
    token advance() { return tokens[current++]; }
    bool match(tokenType t, const string& v = "") { if (check(t, v)) { current++; return true; } return false; }
    bool check(tokenType t, const string& v = "") { return !isAtEnd() && tokens[current].type == t && (v.empty() || tokens[current].value == v); }
    bool checkNext(tokenType t) { return current + 1 < tokens.size() && tokens[current + 1].type == t; }
    bool checkNextNext(tokenType t, const string& v) { return current + 2 < tokens.size() && tokens[current + 2].type == t && tokens[current + 2].value == v; }
    void expect(tokenType t, const string& v, const string& msg) { if (!match(t, v)) error(msg); }
    void error(const string& msg) { token t = peek(); cerr << "Syntax Error at line " << t.line << ", column " << t.col << ": " << msg << "\n"; exit(1); }
};

int main() {
    ifstream file("input.cpp");
    if (!file) { cerr << "Error opening input file\n"; return 1; }
    string code((istreambuf_iterator<char>(file)), {});
    // vector<token> tokens = tokenize(code);
    auto tokens = tokenize(code);
    for (auto &tk : tokens) {
        cout << tokenToString(tk.type) 
            << " ('" << tk.value << "')  "
            << "line " << tk.line 
            << ", col " << tk.col 
            << '\n';
    }

    Parser parser(tokens);
    parser.parse();
    return 0;
}