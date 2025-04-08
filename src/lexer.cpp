#include <iostream>
#include <fstream>
#include <cctype>
#include <unordered_set>
#include <vector>
using namespace std;

const unordered_set<string> keywords = {
    "int", "float", "char", "double", "if", "else", "for", "while", "do",
    "return", "switch", "case", "break", "continue", "void", "class", "public", 
    "private", "protected", "static", "struct", "typedef", "using", "namespace"
};

const unordered_set<string> operators = {
    "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||"
};

const unordered_set<char> delimiters = {
    ';', '(', ')', '{', '}', '[', ']', ',', '.'
};

bool isKeyword(const string &word) {
    return keywords.find(word) != keywords.end();
}

bool isOperator(char ch) {
    return operators.find(string(1, ch)) != operators.end();
}

bool isDelimiter(char ch) {
    return delimiters.find(ch) != delimiters.end();
}

vector<pair<string, string>> tokenize(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return {};
    }
    vector<pair<string, string>> tokens;
    string word;
    char ch;
    bool inComment = false;
    while (file.get(ch)) {
        if (ch == '#') {
            string directive;
            directive += ch;
            while (file.get(ch) && (isalnum(ch) || ch == '<' || ch == '>' || ch == '.'))
                directive += ch;
            tokens.emplace_back("PREPROCESSOR", directive);
            continue;
        }

        if (ch == '"') {
            string strLit;
            strLit += ch;
            while (file.get(ch) && ch != '"')
                strLit += ch;
            strLit += ch;
            tokens.emplace_back("STRING_LITERAL", strLit);
            continue;
        }

        if (ch == '\'') {
            string charLit;
            charLit += ch;
            if (file.get(ch) && file.peek() == '\'') {
                charLit += ch;
                file.get(ch);
                charLit += ch;
                tokens.emplace_back("CHAR_LITERAL", charLit);
            }
            continue;
        }

        if (ch == '/' && file.peek() == '/') {
            while (file.get(ch) && ch != '\n');
            continue;
        }

        if (ch == '/' && file.peek() == '*') {
            inComment = true;
            file.get(ch);
            continue;
        }
        if (inComment) {
            if (ch == '*' && file.peek() == '/') {
                inComment = false;
                file.get(ch);
            }
            continue;
        }

        if (isalnum(ch) || ch == '_') {
            word += ch;
        } else {
            if (!word.empty()) {
                if (isKeyword(word)) {
                    tokens.emplace_back("KEYWORD", word);
                } else if (isdigit(word[0])) {
                    tokens.emplace_back("NUMBER", word);
                } else {
                    tokens.emplace_back("IDENTIFIER", word);
                }
                word.clear();
            }

            if (isOperator(ch)) {
                string op(1, ch);
                if (isOperator(file.peek())) {
                    file.get(ch);
                    op += ch;
                }
                tokens.emplace_back("OPERATOR", op);
            } else if (isDelimiter(ch)) {
                tokens.emplace_back("DELIMITER", string(1, ch));
            }
        }
    }
    file.close();
    return tokens;
}

int main() {
    string filename = "input.c";
    vector<pair<string, string>> tokens = tokenize(filename);
    ofstream out("tokens.txt");
    for (const auto &token : tokens) {
        out << token.first << " " << token.second << endl;
    }
    out.close();
    cout << "Tokens written to tokens.txt" << endl;
    return 0;
}
