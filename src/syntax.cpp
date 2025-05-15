#include <bits/stdc++.h>
using namespace std;

#include "lexical.cpp" // Include your lexer

class Parser {
    vector<token> tokens;
    int current = 0;

public:
    Parser(const vector<token>& t) : tokens(t) {}

    void parse() {
        while (!isAtEnd()) {
            statement();
        }
        cout << "Syntax Analysis Successful.\n";
    }

private:
    token peek() {
        return current < tokens.size() ? tokens[current] : token{unknown, "", -1, -1};
    }

    token advance() {
        return tokens[current++];
    }

    bool match(tokenType type, const string& val = "") {
        if (current >= tokens.size()) return false;
        if (tokens[current].type == type && (val.empty() || tokens[current].value == val)) {
            current++;
            return true;
        }
        return false;
    }

    bool check(tokenType type, const string& val = "") {
        if (isAtEnd()) return false;
        return tokens[current].type == type && (val.empty() || tokens[current].value == val);
    }

    bool isAtEnd() {
        return current >= tokens.size();
    }

    void error(const string& msg) {
        token t = peek();
        cerr << "Syntax Error at line " << t.line << ", column " << t.col << ": " << msg << "\n";
        exit(1);
    }

    // <statement> → <declaration> ; | <assignment> ; | <if_stmt> | <while_stmt> | <for_stmt>
    void statement() {
        if (check(keyword, "int") || check(keyword, "float") || check(keyword, "char") || check(keyword, "bool")) {
            declaration();
            expect(";", "Expected ';' after declaration.");
        }
        else if (check(keyword, "if")) {
            if_stmt();
        }
        else if (check(keyword, "while")) {
            while_stmt();
        }
        else if (check(keyword, "for")) {
            for_stmt();
        }
        else if (check(identifier)) {
            assignment();
            expect(";", "Expected ';' after assignment.");
        }
        else {
            error("Unknown statement");
        }
    }

    // <declaration> → <type> ID [= <expression>]
   // <declaration> → <type> ID [= <expression>]
    void declaration() {
        type();
        if (!match(identifier)) error("Expected identifier in declaration.");
        if (match(operaTor, "=")) {
            expression();
        }
    }

    // <assignment> → ID = <expression>
    void assignment() {
        if (!match(identifier)) error("Expected identifier in assignment.");
        expect("=", "Expected '=' in assignment.");
        expression();
    }

    // <type> → int | float | char | bool
    void type() {
        if (!(match(keyword, "int") || match(keyword, "float") ||
              match(keyword, "char") || match(keyword, "bool"))) {
            error("Expected type (int, float, char, bool).");
        }
    }

    // <if_stmt> → if ( <expression> ) <statement> [else <statement>]
    void if_stmt() {
        match(keyword, "if");
        expect("(", "Expected '(' after 'if'.");
        comparison();
        expect(")", "Expected ')' after condition.");
        statement();
        if (match(keyword, "else")) {
            statement();
        }
    }

    // <while_stmt> → while ( <expression> ) <statement>
    void while_stmt() {
        match(keyword, "while");
        expect("(", "Expected '(' after 'while'.");
        comparison();
        expect(")", "Expected ')' after condition.");
        statement();
    }

    // <for_stmt> → for ( <assignment> ; <expression> ; <assignment> ) <statement>
    void for_stmt() {
        match(keyword, "for");
        expect("(", "Expected '(' after 'for'.");
        assignment();
        expect(";", "Expected ';' after init assignment.");
        comparison();
        expect(";", "Expected ';' after loop condition.");
        assignment();
        expect(")", "Expected ')' after increment.");
        statement();
    }

    // <comparison> → <expression> [ ("<" | ">" | "<=" | ">=" | "==" | "!=") <expression> ]
    void comparison() {
        expression();
        while (match(operaTor, "<") || match(operaTor, ">") ||
            match(operaTor, "==") || match(operaTor, "!=") ||
            match(operaTor, "<=") || match(operaTor, ">=")) {
            expression(); // right-hand side
        }
    }


    // <expression> → <term> { (+|-) <term> }
    void expression() {
        term();
        while (match(operaTor, "+") || match(operaTor, "-")) {
            term();
        }
    }

    // <term> → <factor> { (*|/) <factor> }
    void term() {
        factor();
        while (match(operaTor, "*") || match(operaTor, "/")) {
            factor();
        }
    }

    // <factor> → NUMBER | ID | ( <expression> )
    void factor() {
        if (match(number) || match(identifier)) {
            return;
        }
        if (match(separator, "(")) {
            expression();
            expect(")", "Expected ')' after expression.");
            return;
        }
        error("Expected number, identifier or '('");
    }

    void expect(const string& symbol, const string& errMsg) {
        if (!match(operaTor, symbol) && !match(separator, symbol)) {
            error(errMsg);
        }
    }
};

int main() {
    ifstream file("input.cpp");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string code((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    vector<token> tokens = tokenize(code);

    Parser parser(tokens);
    parser.parse();

    return 0;
}
