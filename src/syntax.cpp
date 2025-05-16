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
    void program() {
        // Skip preprocessor directives
        while (check(preprocessor)) preprocessorDirective();
        // Parse external declarations
        while (!isAtEnd()) externalDeclaration();
    }

    void externalDeclaration() {
        if (check(keyword) && (peek().value == "int" || peek().value == "float" || peek().value == "char" || peek().value == "bool" || peek().value == "void")) {
            if (checkNext(identifier) && checkNextNext(separator, "(")) {
                functionDefinition(); return;
            }
        }
        declaration();
        expect(separator, ";", "Expected ';' after declaration.");
    }

    void functionDefinition() {
        advance(); // return type
        expect(identifier, "", "Expected function name.");
        expect(separator, "(", "Expected '(' after function name.");
        parameterList();
        expect(separator, ")", "Expected ')' after parameters.");
        compoundStatement();
    }

    void parameterList() {
        if (check(separator, ")")) return;
        do {
            expect(keyword, "", "Expected parameter type.");
            expect(identifier, "", "Expected parameter name.");
        } while (match(separator, ","));
    }

    void compoundStatement() {
        expect(separator, "{", "Expected '{' to start block.");
        while (!check(separator, "}")) {
            if (isAtEnd()) error("Expected '}' to close block.");
            statement();
        }
        expect(separator, "}", "Expected '}' after block.");
    }

    void preprocessorDirective() {
        advance(); // '#'
        int lineNo = tokens[current-1].line;
        while (!isAtEnd() && peek().line == lineNo) advance();
    }

    void statement() {
        if (check(separator, "{")) { compoundStatement(); return; }
        if (check(keyword, "int") || check(keyword, "float") || check(keyword, "char") || check(keyword, "bool")) {
            declaration(); expect(separator, ";", "Expected ';' after declaration."); return;
        }
        if (check(keyword, "if")) { ifStatement(); return; }
        if (check(keyword, "while")) { whileStatement(); return; }
        if (check(keyword, "for")) { forStatement(); return; }
        if (check(keyword, "return")) { returnStatement(); return; }
        if (check(identifier) && checkNext(operaTor, "=")) {
            assignment(); expect(separator, ";", "Expected ';' after assignment."); return;
        }
        expression(); expect(separator, ";", "Expected ';' after expression.");
    }

    void returnStatement() {
        advance(); // return
        if (!check(separator, ";")) expression();
        expect(separator, ";", "Expected ';' after return.");
    }

    void declaration() {
        advance(); // type
        expect(identifier, "", "Expected identifier in declaration.");
        if (match(operaTor, "=")) expression();
    }

    void assignment() {
        advance(); // identifier
        advance(); // '='
        expression();
    }

    void ifStatement() {
        advance(); expect(separator, "(", "Expected '(' after 'if'.");
        expression(); expect(separator, ")", "Expected ')' after condition.");
        statement(); if (match(keyword, "else")) statement();
    }

    void whileStatement() {
        advance(); expect(separator, "(", "Expected '(' after 'while'.");
        expression(); expect(separator, ")", "Expected ')' after condition.");
        statement();
    }

    void forStatement() {
        advance(); expect(separator, "(", "Expected '(' after 'for'.");
        if (!check(separator, ";")) expression(); expect(separator, ";", "Expected ';' after init.");
        if (!check(separator, ";")) expression(); expect(separator, ";", "Expected ';' after condition.");
        if (!check(separator, ")")) expression(); expect(separator, ")", "Expected ')' after increment.");
        statement();
    }

    void expression() { logicalOr(); }
    void logicalOr()     { logicalAnd(); while (match(operaTor, "||")) logicalAnd(); }
    void logicalAnd()    { equality(); while (match(operaTor, "&&")) equality(); }
    void equality()      { relational(); while (match(operaTor,"==")||match(operaTor,"!=")) relational(); }
    void relational()    { additive(); while (match(operaTor,">")||match(operaTor,"<")||match(operaTor,">=")||match(operaTor,"<=")) additive(); }
    void additive()      { term(); while (match(operaTor,"+")||match(operaTor,"-")) term(); }
    void term()          { factor(); while (match(operaTor,"*")||match(operaTor,"/")) factor(); }
    void factor() {
        if (match(number)||match(identifier)) return;
        if (match(separator,"(")) { expression(); expect(separator,")","Expected ')' after expression."); return; }
        error("Expected number, identifier, or '('.");
    }

    token peek() { return !isAtEnd() ? tokens[current] : token{unknown,"",-1,-1}; }
    bool isAtEnd()                 { return current>=tokens.size(); }
    token advance()                { return tokens[current++]; }
    bool match(tokenType t,const string&v="") { if(check(t,v)){current++;return true;}return false; }
    bool check(tokenType t,const string&v="") { return !isAtEnd() && tokens[current].type==t && (v.empty()||tokens[current].value==v);}  
    bool checkNext(tokenType t)                { return current+1<tokens.size() && tokens[current+1].type==t; }
    bool checkNext(tokenType t,const string&v) { return current+1<tokens.size() && tokens[current+1].type==t && tokens[current+1].value==v; }
    bool checkNextNext(tokenType t,const string&v) { return current+2<tokens.size()&&tokens[current+2].type==t&&tokens[current+2].value==v; }
    void expect(tokenType t,const string&v,const string&msg){ if(!match(t,v)) error(msg);}    
    void error(const string&msg){ token t=peek(); cerr<<"Syntax Error at line "<<t.line<<", column "<<t.col<<": "<<msg<<"\n"; exit(1);} 
};

int main(){
    ifstream file("input.cpp"); if(!file){cerr<<"Error opening input file\n";return 1;}
    string code((istreambuf_iterator<char>(file)),{});
    auto tokens=tokenize(code);
    for(auto &tk:tokens){ cout<<tokenToString(tk.type)<<" ('"<<tk.value<<"') line "<<tk.line<<", col "<<tk.col<<"\n";}  
    Parser parser(tokens);
    parser.parse();
    return 0;
}
