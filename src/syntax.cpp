// parser.cpp
#include <iostream>
#include <vector>
#include <stack>
#include <memory>
#include "lexer.cpp" // Assumes lexer.cpp provides vector<Token> tokenize(string filename);

using namespace std;

// AST Node structure
struct ASTNode {
    string label;
    vector<shared_ptr<ASTNode>> children;

    ASTNode(string lbl) : label(lbl) {}

    void print(string indent = "", bool last = true) const {
        cout << indent;
        if (last) {
            cout << "└─";
        } else {
            cout << "├─";
        }
        cout << label << endl;
        for (size_t i = 0; i < children.size(); ++i) {
            children[i]->print(indent + (last ? "  " : "│ "), i == children.size() - 1);
        }
    }
};

// Grammar:
// S → DECL | ASSIGN | EXPR
// DECL → TYPE ID ;
// ASSIGN → ID = EXPR ;
// EXPR → EXPR + TERM | TERM
// TERM → TERM * FACTOR | FACTOR
// FACTOR → ( EXPR ) | ID | NUMBER

class BottomUpParser {
public:
    vector<Token> tokens;
    stack<shared_ptr<ASTNode>> parseStack;

    BottomUpParser(const vector<Token>& toks) : tokens(toks) {}

    bool parse() {
        size_t pos = 0;
        while (pos < tokens.size()) {
            Token token = tokens[pos];
            auto node = make_shared<ASTNode>(token.type + "(" + token.value + ")");
            parseStack.push(node);
            ++pos;

            bool reduced;
            do {
                reduced = tryReduce();
            } while (reduced);
        }

        // Final reductions
        while (tryReduce());

        if (parseStack.size() == 1 && parseStack.top()->label == "S") {
            cout << "\n✅ Parsing successful. Abstract Syntax Tree:\n";
            parseStack.top()->print();
            return true;
        } else {
            cout << "\n❌ Parsing failed." << endl;
            return false;
        }
    }

private:
    bool tryReduce() {
        if (reduceDecl()) return true;
        if (reduceAssign()) return true;
        if (reduceExpr()) return true;
        return false;
    }

    bool reduceDecl() {
        if (parseStack.size() >= 3) {
            auto third = parseStack.top(); parseStack.pop();
            auto second = parseStack.top(); parseStack.pop();
            auto first = parseStack.top(); parseStack.pop();

            if (first->label.find("KEYWORD(") == 0 && second->label.find("IDENTIFIER(") == 0 && third->label == "DELIMITER(;)" ) {
                auto node = make_shared<ASTNode>("DECL");
                node->children = {first, second, third};
                parseStack.push(node);
                parseStack.push(make_shared<ASTNode>("S"));
                return true;
            }
            // Push back in reverse if not reduced
            parseStack.push(first); parseStack.push(second); parseStack.push(third);
        }
        return false;
    }

    bool reduceAssign() {
        if (parseStack.size() >= 4) {
            auto fourth = parseStack.top(); parseStack.pop();
            auto third = parseStack.top(); parseStack.pop();
            auto second = parseStack.top(); parseStack.pop();
            auto first = parseStack.top(); parseStack.pop();

            if (first->label.find("IDENTIFIER(") == 0 && second->label == "OPERATOR(=)" && third->label == "EXPR" && fourth->label == "DELIMITER(;)" ) {
                auto node = make_shared<ASTNode>("ASSIGN");
                node->children = {first, second, third, fourth};
                parseStack.push(node);
                parseStack.push(make_shared<ASTNode>("S"));
                return true;
            }
            parseStack.push(first); parseStack.push(second); parseStack.push(third); parseStack.push(fourth);
        }
        return false;
    }

    bool reduceExpr() {
        // Reduce ( EXPR )
        if (parseStack.size() >= 3) {
            auto third = parseStack.top(); parseStack.pop();
            auto second = parseStack.top(); parseStack.pop();
            auto first = parseStack.top(); parseStack.pop();

            if (first->label == "DELIMITER(()" && second->label == "EXPR" && third->label == "DELIMITER())") {
                auto node = make_shared<ASTNode>("EXPR");
                node->children = {first, second, third};
                parseStack.push(node);
                return true;
            }
            parseStack.push(first); parseStack.push(second); parseStack.push(third);
        }
        // Reduce ID or NUMBER to EXPR
        if (!parseStack.empty()) {
            auto top = parseStack.top(); parseStack.pop();
            if (top->label.find("IDENTIFIER(") == 0 || top->label.find("NUMBER(") == 0) {
                auto node = make_shared<ASTNode>("EXPR");
                node->children = {top};
                parseStack.push(node);
                return true;
            }
            parseStack.push(top);
        }
        // Reduce EXPR + EXPR or EXPR * EXPR
        if (parseStack.size() >= 3) {
            auto third = parseStack.top(); parseStack.pop();
            auto second = parseStack.top(); parseStack.pop();
            auto first = parseStack.top(); parseStack.pop();

            if (first->label == "EXPR" && (second->label == "OPERATOR(+)" || second->label == "OPERATOR(*)") && third->label == "EXPR") {
                auto node = make_shared<ASTNode>("EXPR");
                node->children = {first, second, third};
                parseStack.push(node);
                return true;
            }
            parseStack.push(first); parseStack.push(second); parseStack.push(third);
        }
        return false;
    }
};

int main() {
    string filename = "input.c";
    vector<Token> tokens = tokenize(filename);

    cout << "Tokens:" << endl;
    for (const auto& t : tokens) {
        cout << t.type << " (" << t.value << ")" << endl;
    }

    BottomUpParser parser(tokens);
    parser.parse();

    return 0;
}
