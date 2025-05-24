%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char *node_type;
    char *value;
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *third;
}ASTNode;

ASTNode *create_node(const char *type, const char *val, ASTNode *l, ASTNode *r, ASTNode *t);
void print_ast(ASTNode *node, int depth);
void yyerror(const char *s);

extern int yylex(void);
extern FILE *yyin;
extern int yylineno;

ASTNode *ast_root = NULL;
%}

%union {
    char *strval;
    struct ASTNode *node;
}

%token <strval> INT RETURN PRINTFF IDENTIFIER NUMBER
%token SEMICOLON ASSIGN LPAREN RPAREN LBRACE RBRACE COMMA
%type <node> program function_declaration declaration statement statement_list

%%

program:
    function_declaration { ast_root = $1; }
    ;

function_declaration:
    INT IDENTIFIER LPAREN RPAREN LBRACE declaration statement_list RBRACE {
        $$ = create_node("FUNCTION", $2, $6, $7, NULL);
    }
    ;

declaration:
    INT IDENTIFIER ASSIGN NUMBER SEMICOLON {
        $$ = create_node("DECLARATION", $2, create_node("LITERAL", $4, NULL, NULL, NULL), NULL, NULL);
    }
    ;

statement_list:
    statement { $$ = $1; }
    | statement_list statement { $$ = create_node("STATEMENT_LIST", NULL, $1, $2, NULL); }
    ;

statement:
    PRINTFF LPAREN IDENTIFIER RPAREN SEMICOLON {
        $$ = create_node("PRINTF", NULL, create_node("IDENTIFIER", $3, NULL, NULL, NULL), NULL, NULL);
    }
    | RETURN NUMBER SEMICOLON {
        $$ = create_node("RETURN", NULL, create_node("LITERAL", $2, NULL, NULL, NULL), NULL, NULL);
    }
    ;

%%

ASTNode *create_node(const char *type, const char *val, ASTNode *l, ASTNode *r, ASTNode *t) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->node_type = strdup(type);
    node->value = val ? strdup(val) : NULL;
    node->left = l;
    node->right = r;
    node->third = t;
    return node;
}

void print_ast(ASTNode *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; ++i) printf("  ");
    printf("%s", node->node_type);
    if (node->value) printf(" (%s)", node->value);
    printf("\n");
    print_ast(node->left, depth + 1);
    print_ast(node->right, depth + 1);
    print_ast(node->third, depth + 1);
}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyparse()) {
        printf("\nGenerated AST:\n");
        print_ast(ast_root, 0);
    }
    fclose(yyin);
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
    exit(1);
}