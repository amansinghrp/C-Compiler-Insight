#include <bits/stdc++.h>
using namespace std;

enum tokenType {
    keyword,        // 0
    identifier,     // 1
    number,         // 2
    operaTor,       // 3
    separator,      // 4
    stringtype,     // 5  (your old string-literal for "foo")
    preprocessor,   // 6  (#include, #define, etc.)
    string_literal, // 7  (<foo.h> or "foo.h")
    unknown         // 8
};

struct token {
    tokenType type;
    string value;
    int line;
    int col;
};

unordered_set<string> keywords = {
    "int","float","double","long long","char","bool","string",
    "if","else","for","while","true","false","return",
    "void","break","continue","switch","case","default",
    "cout","cin"
};
unordered_set<char> operators = {
    '+','-','*','/','=','%','&','|','<','>','!','^'
};
unordered_set<char> separators = {
    '{','}','[',']','(',')',',',':',';'
};

bool isNumber(const string &str) {
    return regex_match(str, regex("-?([0-9]+(\\.[0-9]+)?|\\.[0-9]+)"));
}
bool isIdentifier(const string& str) {
    return regex_match(str, regex("[_a-zA-Z]+[_a-zA-Z0-9]*"));
}

vector<token> tokenize(const string &code) {
    vector<token> tokens;
    int i = 0, len = code.size();
    int line = 1, col = 1;

    while (i < len) {
        char c = code[i];

        // Whitespace
        if (isspace(c)) {
            if (c == '\n') { line++; col = 1; }
            else col++;
            i++;
            continue;
        }

        // Preprocessor directive
        if (c == '#') {
            int startCol = col;
            // consume '#'
            string dir = "#";
            i++; col++;
            // directive name
            while (i < len && isalpha(code[i])) {
                dir += code[i++];
                col++;
            }
            tokens.push_back({preprocessor, dir, line, startCol});

            // skip whitespace
            while (i < len && isspace(code[i])) {
                if (code[i] == '\n') break;
                i++; col++;
            }

            // header <...> or "..."
            if (i < len && code[i] == '<') {
                string hdr = "<"; i++; col++;
                while (i < len && code[i] != '>') {
                    hdr += code[i++]; col++;
                }
                if (i < len && code[i] == '>') { hdr += '>'; i++; col++; }
                tokens.push_back({string_literal, hdr, line, col - hdr.size()});
            }
            else if (i < len && code[i] == '"') {
                string hdr = "\""; i++; col++;
                while (i < len && code[i] != '"') {
                    hdr += code[i++]; col++;
                }
                if (i < len && code[i] == '"') { hdr += '"'; i++; col++; }
                tokens.push_back({string_literal, hdr, line, col - hdr.size()});
            }
            // skip to end of line
            while (i < len && code[i] != '\n') { i++; }
            continue;
        }

        // Single-line comment
        if (c == '/' && i+1<len && code[i+1]=='/') {
            while (i<len && code[i]!='\n') i++;
            continue;
        }
        // Multi-line comment
        if (c=='/' && i+1<len && code[i+1]=='*') {
            i+=2; 
            while (i+1<len && !(code[i]=='*'&&code[i+1]=='/')) {
                if (code[i]=='\n') { line++; col=1; }
                else col++;
                i++;
            }
            i+=2; 
            continue;
        }

        // String literal (old style "foo")
        if (c == '"') {
            int startCol = col;
            string lit = "\""; i++; col++;
            while (i<len && code[i]!='"') { lit += code[i++]; col++; }
            if (i<len && code[i]=='"') { lit += '"'; i++; col++; }
            tokens.push_back({stringtype, lit, line, startCol});
            continue;
        }

        // Operators
        if (operators.count(c)) {
            tokens.push_back({operaTor, string(1, c), line, col});
            i++; col++;
            continue;
        }
        // Separators
        if (separators.count(c)) {
            tokens.push_back({separator, string(1, c), line, col});
            i++; col++;
            continue;
        }

        // Numbers, identifiers, keywords
        if (isalnum(c) || c=='_' || c=='.') {
            int start = i, startCol = col;
            while (i<len && (isalnum(code[i])||code[i]=='_'||code[i]=='.')) {
                i++; col++;
            }
            string tok = code.substr(start, i-start);
            tokenType t;
            if (keywords.count(tok))                 t = keyword;
            else if (isNumber(tok))                  t = number;
            else if (isIdentifier(tok))              t = identifier;
            else                                      t = unknown;
            tokens.push_back({t, tok, line, startCol});
            continue;
        }

        // Anything else
        tokens.push_back({unknown, string(1, c), line, col});
        i++; col++;
    }

    return tokens;
}

string tokenToString(tokenType t) {
    switch (t) {
        case keyword:      return "Keyword   ";
        case identifier:   return "Identifier";
        case number:       return "Number    ";
        case operaTor:     return "Operator  ";
        case separator:    return "Separator ";
        case stringtype:   return "String    ";
        case preprocessor: return "Preproc   ";
        case string_literal: return "HdrLit   ";
        default:           return "Unknown   ";
    }
}