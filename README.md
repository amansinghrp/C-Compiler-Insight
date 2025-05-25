to compile Semantic Folder code
    1. lex lexer.l
    2. yacc -d parser.y -o parser.tab.c
    3. gcc parser.tab.c lex.yy.c 

these commands will give you ./a.out executable file which can be then used to test the input code like:
    ./a.out input.c



To run the parse tree generation code:
    1.lex lexer.l
    2. yacc -d parser.y -o parser.tab.c
    3. gcc lex.yy.c parser.tab.c -o treeNew
to run
    >> ./treeNew input.c


To Activate the virtual environment: inside the src folder run:
    >> source myenv/bin/activate
To deactivate the python environment:
    >> deactivate