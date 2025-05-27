🧠 Compiler Phases Visualizer (Up to Parse Tree)

📝 Description
    This project is a Compiler Phases Visualizer, developed as an educational tool to illustrate how a compiler processes a source program through various phases up to Parse Tree Generation.

It covers the following compilation stages:

    Lexical Analysis
    Syntax Analysis
    Parse Tree Construction
    Semantic Analysis (basic)

This helps users understand how raw source code is tokenized, parsed, semantically checked, and structured into a visual parse tree.

💡 Features
    ✅ Lexical Analysis: Generates tokens from source code and builds a symbol table.
    ✅ Syntax Analysis: Uses grammar rules to check for syntactical correctness.
    ✅ Parse Tree Visualization: Generates .dot and .png files to represent the parse tree.
    ✅ Semantic Analysis: Checks for undeclared variables and type mismatches.
    🧾 Symbol Table Export: Outputs to .csv and .json.

🧰 Technologies Used
    Languages: C/C++, Python, Javascript
    Tools:
        Lex (Lexical Analyzer)
        bison or yacc (Parser Generator)
        Graphviz (Parse Tree Visualization)
        File Formats: .json, .dot, .png

    🛠 Installation Instructions
        Prerequisites:
            GCC Compiler
            flex and bison installed
            graphviz (for generating parse tree images)
            OS: Linux

    Example Install Commands (Ubuntu)
        sudo apt update
        sudo apt install flex bison graphviz gcc
⚙ Usage
    Each phase is inside the src directory, structured as follows:

📁 1_Lexical/
    cd src/1_Lexical
    flex iflex.l
    gcc lex.yy.c symbol_table.c -o a.out
    ./a.out < test.c

    Outputs:
        tokens.txt
        symbol_table.csv
        symbol_table.json


📁 2_Syntax/
    cd src/2_Syntax
    bison -d parser.y
    flex parser.l
    gcc lex.yy.c y.tab.c -o a.out
    ./a.out < test.c

    Outputs:
        Syntax validity confirmation

📁 3_ParseTree/
    cd src/4_ParseTree
    bison -d parser.y
    flex lexer.l
    gcc lex.yy.c parser.tab.c -o a.out
    ./a.out < input.c
    # Convert dot to image
    dot -Tpng parse_tree.dot -o parse_tree.png

    Outputs:
        parse_tree.dot (Graphviz)
        parse_tree.png (Visual Parse Tree)

📁 4_Semantic/
    cd src/3_Semantic
    bison -d parser.y
    flex lexer.l
    gcc lex.yy.c parser.tab.c -o compiler
    ./compiler < input.c

    Outputs:
        semantic.txt for errors
        symbol_table_semantic.json

🗃 Project Structure
    src/
    ├── 1_Lexical/
    │   ├── iflex.l
    │   ├── symbol_table.c/.h/.json
    │   ├── test.c
    │   └── tokens.txt
    ├── 2_Syntax/
    │   ├── parser.y
    │   ├── parser.l
    │   └── test.c
    ├── 3_Semantic/
    │   ├── parser.y
    │   ├── lexer.l
    │   ├── input.c
    │   └── semantic.txt
    ├── 4_ParseTree/
    │   ├── parser.y
    │   ├── lexer.l
    │   ├── parse_tree.dot/.png
    │   └── input.c

📄 Example Input / Output
Example Input (test.c):
    int a = 10;
    int b = 5;
    int c = a + b;
Lexical Output (tokens.txt):
    Keyword: int
    Identifier: a
    ...
Syntax Analysis Phase output:
    Parsing Complete.
Parse Tree Output:
    parse_tree.dot → visualized as parse_tree.png (using Graphviz)
Semantic Analysis Output:
    No Semantic Error Reported


🛠️ Running the Visualizer:
    From the Root directory of the project, run the below command:
        >>python3 server.py