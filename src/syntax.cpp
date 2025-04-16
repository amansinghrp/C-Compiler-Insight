#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <memory>

using namespace std;

// AST Node
struct ASTNode {
    string label;
    vector<shared_ptr<ASTNode>> children;

    ASTNode(string lbl) : label(lbl) {}

    void print(string indent = "", bool last = true) const {
        cout << indent << (last ? "└─" : "├─") << label << endl;
        for (size_t i = 0; i < children.size(); ++i) {
            children[i]->print(indent + (last ? "  " : "│ "), i == children.size() - 1);
        }
    }
};

// Token structure
struct Token {
    string type;
    string value;

    Token(string t, string v) : type(t), value(v) {}
};

// Parser class
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

        while (tryReduce());

        if (parseStack.size() == 1 && parseStack.top()->label == "S") {
            cout << "\n✅ Parsing successful. Abstract Syntax Tree:\n";
            parseStack.top()->print();
            return true;
        } else {
            cout << "\n❌ Parsing failed.\n";
            return false;
        }
    }

private:
    bool tryReduce() {
        if (reduceDecl()) return true;
        if (reduceAssign()) return true;
        if (reduceExpr()) return true;
        if (reduceSS()) return true;
        return false;
    }

    bool reduceDecl() {
        if (parseStack.size() >= 3) {
            auto third = parseStack.top(); parseStack.pop();
            auto second = parseStack.top(); parseStack.pop();
            auto first = parseStack.top(); parseStack.pop();

            if (first->label.find("KEYWORD(") == 0 &&
                second->label.find("IDENTIFIER(") == 0 &&
                third->label == "DELIMITER(;)") {
                auto node = make_shared<ASTNode>("DECL");
                node->children = {first, second, third};
                parseStack.push(node);
                parseStack.push(make_shared<ASTNode>("S"));
                return true;
            }

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

            if (first->label.find("IDENTIFIER(") == 0 &&
                second->label == "OPERATOR(=)" &&
                third->label == "EXPR" &&
                fourth->label == "DELIMITER(;)") {
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
        // EXPR + EXPR or EXPR * EXPR
        if (parseStack.size() >= 3) {
            auto third = parseStack.top(); parseStack.pop();
            auto second = parseStack.top(); parseStack.pop();
            auto first = parseStack.top(); parseStack.pop();

            if (first->label == "EXPR" &&
                (second->label == "OPERATOR(+)" || second->label == "OPERATOR(*)") &&
                third->label == "EXPR") {
                auto node = make_shared<ASTNode>("EXPR");
                node->children = {first, second, third};
                parseStack.push(node);
                return true;
            }

            parseStack.push(first); parseStack.push(second); parseStack.push(third);
        }

        // NUMBER or IDENTIFIER → EXPR
        if (!parseStack.empty()) {
            auto top = parseStack.top(); parseStack.pop();

            if (top->label.find("NUMBER(") == 0 || top->label.find("IDENTIFIER(") == 0) {
                auto node = make_shared<ASTNode>("EXPR");
                node->children = {top};
                parseStack.push(node);
                return true;
            }

            parseStack.push(top);
        }

        return false;
    }

    bool reduceSS() {
        if (parseStack.size() >= 2) {
            auto second = parseStack.top(); parseStack.pop();
            auto first = parseStack.top(); parseStack.pop();

            if (first->label == "S" && second->label == "S") {
                auto node = make_shared<ASTNode>("S");
                node->children = {first, second};
                parseStack.push(node);
                return true;
            }

            parseStack.push(first); parseStack.push(second);
        }
        return false;
    }
};

// Reads tokens.txt
vector<Token> readTokens(const string& filename) {
    ifstream file(filename);
    vector<Token> tokens;
    string line;
    while (getline(file, line)) {
        size_t open = line.find('(');
        size_t close = line.find(')');
        if (open != string::npos && close != string::npos && close > open) {
            string type = line.substr(0, open);
            string value = line.substr(open + 1, close - open - 1);
            tokens.emplace_back(type, value);
        }
    }
    return tokens;
}

int main() {
    string filename = "tokens.txt";
    vector<Token> tokens = readTokens(filename);

    cout << "Tokens read from " << filename << ":\n";
    for (const auto& t : tokens) {
        cout << t.type << " (" << t.value << ")\n";
    }

    BottomUpParser parser(tokens);
    parser.parse();

    return 0;
}
