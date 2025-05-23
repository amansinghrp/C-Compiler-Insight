#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <regex>

using namespace std;

enum VarType { INT, FLOAT, CHAR, VOID, UNKNOWN };

VarType parseType(const string& s) {
    if (s == "int") return INT;
    if (s == "float") return FLOAT;
    if (s == "char") return CHAR;
    if (s == "void") return VOID;
    return UNKNOWN;
}

bool isTypeKeyword(const string& s) {
    return s == "int" || s == "float" || s == "char" || s == "void";
}

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t");
    size_t end = s.find_last_not_of(" \t");
    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: ./a.out input.c\n";
        return 1;
    }

    ifstream fin(argv[1]);
    if (!fin) {
        cerr << "Cannot open file: " << argv[1] << endl;
        return 1;
    }

    // Stack of scopes; each scope is map varName -> VarType
    vector<unordered_map<string, VarType>> scopes;
    scopes.emplace_back();  // global scope

    stack<bool> loopStack;

    bool inFunction = false;
    string currentFunc;
    VarType currentFuncRetType = VOID;
    bool hasReturn = false;

    string line;
    int lineNum = 0;

    // Regex patterns to identify code constructs
    regex funcDeclRegex(R"(\b(int|float|char|void)\s+([a-zA-Z_]\w*)\s*\([^)]*\)\s*\{?)");
    regex varDeclRegex(R"(\b(int|float|char)\s+([a-zA-Z_]\w*)\b)");
    regex assignRegex(R"(([a-zA-Z_]\w*)\s*=)");
    regex breakRegex(R"(\bbreak\s*;)");
    regex continueRegex(R"(\bcontinue\s*;)");
    regex returnRegex(R"(\breturn\b)");

    while (getline(fin, line)) {
        lineNum++;
        string originalLine = line;

        // Remove single-line comments
        size_t cpos = line.find("//");
        if (cpos != string::npos) {
            line = line.substr(0, cpos);
        }
        line = trim(line);
        if (line.empty()) continue;

        // Track opening and closing braces and update scopes
        for (char ch : line) {
            if (ch == '{') {
                scopes.emplace_back();
            }
            if (ch == '}') {
                if (!scopes.empty()) scopes.pop_back();

                // If function scope ended
                if (inFunction && scopes.size() == 1) {
                    if (currentFuncRetType != VOID && !hasReturn) {
                        cout << "Line " << lineNum << ": Missing return statement in function '" << currentFunc << "'\n";
                    }
                    inFunction = false;
                    currentFunc = "";
                    currentFuncRetType = VOID;
                    hasReturn = false;
                }
            }
        }

        smatch m;

        // Detect function declaration
        if (regex_search(line, m, funcDeclRegex)) {
            inFunction = true;
            currentFuncRetType = parseType(m[1]);
            currentFunc = m[2];
            hasReturn = false;
            scopes.clear();
            scopes.emplace_back(); // function scope
            continue;
        }

        // Detect variable declaration
        if (regex_search(line, m, varDeclRegex)) {
            string varName = m[2];
            // Check redeclaration in current scope
            if (scopes.back().count(varName)) {
                cout << "Line " << lineNum << ": Variable '" << varName << "' already declared in current scope\n";
            } else {
                scopes.back()[varName] = parseType(m[1]);
            }
            continue;
        }

        // Detect variable assignment (check if variable declared)
        if (regex_search(line, m, assignRegex)) {
            string varName = m[1];
            bool found = false;
            for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
                if (it->count(varName)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Line " << lineNum << ": Variable '" << varName << "' used but not declared\n";
            }
            continue;
        }

        // Detect break and continue outside loops
        if (regex_search(line, breakRegex)) {
            if (loopStack.empty()) {
                cout << "Line " << lineNum << ": 'break' used outside loop\n";
            }
            continue;
        }
        if (regex_search(line, continueRegex)) {
            if (loopStack.empty()) {
                cout << "Line " << lineNum << ": 'continue' used outside loop\n";
            }
            continue;
        }

        // Detect loop start (simple detection of for/while)
        if (line.find("for") != string::npos || line.find("while") != string::npos) {
            loopStack.push(true);
            continue;
        }
        // Detect loop end on closing brace (simplified)
        if (line.find("}") != string::npos && !loopStack.empty()) {
            loopStack.pop();
            continue;
        }

        // Detect return statement
        if (inFunction && regex_search(line, returnRegex)) {
            hasReturn = true;
            continue;
        }
    }

    fin.close();
    return 0;
}
