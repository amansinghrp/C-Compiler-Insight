%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>

    typedef struct ASTNode {
        char *node_type;
        char *value;                
        struct ASTNode *left;
        struct ASTNode *right;
        struct ASTNode *third;  
    } ASTNode;

    ASTNode *create_node(const char *type, const char *val, ASTNode *l, ASTNode *r, ASTNode *t);
    void print_ast(ASTNode *node, int depth);
    void yyerror(const char *s);

    extern FILE *yyin;          
    extern int yylineno;

    ASTNode *ast_root = NULL;    

%}

%expect 24

%define parse.error verbose
%nonassoc NO_ELSE
%nonassoc  ELSE 
%left '<' '>' '=' GE_OP LE_OP EQ_OP NE_OP 
%left  '+'  '-'
%left  '*'  '/' '%'
%left  '|'
%left  '&'
%token <strval> 
    PRINTFF SCANFF INT FLOAT CHAR VOID RETURN FOR IF ELSE INCLUDE 
    TRUE FALSE NUMBER FLOAT_NUM IDENTIFIER  UNARY LE GE EQ NE GT LT AND OR 
    ADD SUBTRACT DIVIDE MULTIPLY STRING_LITERAL CONSTANT TYPE_NAME DEF 
    SHORT LONG SIGNED UNSIGNED DOUBLE CONST VOLATILE STRUCT UNION ENUM 
    ELLIPSIS CASE DEFAULT SWITCH WHILE DO GOTO CONTINUE BREAK

    SIZEOF PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
    AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
    LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
    TYPEDEF EXTERN STATIC AUTO REGISTER LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA ASSIGN;


%type <node> 
    translation_unit external_declaration function_definition Define
    statement expression assignment_expression primary_expression
    postfix_expression argument_expression_list unary_expression
    unary_operator cast_expression multiplicative_expression
    additive_expression shift_expression relational_expression
    equality_expression and_expression exclusive_or_expression
    inclusive_or_expression logical_and_expression logical_or_expression
    conditional_expression assignment_operator constant_expression
    declaration declaration_specifiers init_declarator_list init_declarator
    storage_class_specifier type_specifier struct_or_union_specifier
    struct_or_union struct_declaration_list struct_declaration
    specifier_qualifier_list struct_declarator_list struct_declarator
    enum_specifier enumerator_list enumerator type_qualifier declarator
    direct_declarator pointer type_qualifier_list parameter_type_list
    parameter_list parameter_declaration identifier_list type_name
    abstract_declarator direct_abstract_declarator initializer initializer_list
    labeled_statement compound_statement declaration_list statement_list
    expression_statement selection_statement iteration_statement jump_statement;
%start translation_unit
%glr-parser
%union {
    char *strval;
    struct ASTNode *node;
}

%%
primary_expression
    : IDENTIFIER
        { $$ = create_node("Identifier", $1, NULL, NULL, NULL); }
    | CONSTANT
        { $$ = create_node("Constant", $1, NULL, NULL, NULL); }
    | STRING_LITERAL
        { $$ = create_node("StringLiteral", $1, NULL, NULL, NULL); }
    | '(' expression ')'
        { $$ = $2; }  // Just pass the expression directly
    | Define primary_expression
        { $$ = create_node("Define", NULL, $2, NULL, NULL); }
    ;


Define
    : DEF
        { $$ = create_node("DefKeyword", $1, NULL, NULL, NULL); }
    ;


postfix_expression
    : primary_expression
        { $$ = $1; }
    | postfix_expression '[' expression ']'
        { $$ = create_node("ArrayAccess", NULL, $1, $3, NULL); }
    | postfix_expression '(' ')'
        { $$ = create_node("FuncCall", NULL, $1, NULL, NULL); }
    | postfix_expression '(' argument_expression_list ')'
        { $$ = create_node("FuncCall", NULL, $1, $3, NULL); }
    | postfix_expression '.' IDENTIFIER
        { $$ = create_node("MemberAccess", $3, $1, NULL, NULL); }
    | postfix_expression PTR_OP IDENTIFIER
        { $$ = create_node("PtrMemberAccess", $3, $1, NULL, NULL); }
    | postfix_expression INC_OP
        { $$ = create_node("PostInc", NULL, $1, NULL, NULL); }
    | postfix_expression DEC_OP
        { $$ = create_node("PostDec", NULL, $1, NULL, NULL); }
    ;


argument_expression_list
    : assignment_expression
        { $$ = create_node("ArgList", NULL, $1, NULL, NULL); }
    | argument_expression_list ',' assignment_expression
        {
            ASTNode *argNode = create_node("ArgList", NULL, $1, $3, NULL);
            $$ = argNode;
        }
    ;


unary_expression
    : postfix_expression
        { $$ = $1; }
    | INC_OP unary_expression
        { $$ = create_node("PreInc", NULL, $2, NULL, NULL); }
    | DEC_OP unary_expression
        { $$ = create_node("PreDec", NULL, $2, NULL, NULL); }
    | unary_operator cast_expression
        { $$ = create_node("UnaryOp", $1, $2, NULL, NULL); }
    | SIZEOF unary_expression
        { $$ = create_node("SizeOfExpr", NULL, $2, NULL, NULL); }
    | SIZEOF '(' type_name ')'
        { $$ = create_node("SizeOfType", NULL, $3, NULL, NULL); }
    ;


unary_operator
    : '&' { $$ = create_node("Operator", "&", NULL, NULL, NULL); }
    | '*' { $$ = create_node("Operator", "*", NULL, NULL, NULL); }
    | '+' { $$ = create_node("Operator", "+", NULL, NULL, NULL); }
    | '-' { $$ = create_node("Operator", "-", NULL, NULL, NULL); }
    | '~' { $$ = create_node("Operator", "~", NULL, NULL, NULL); }
    | '!' { $$ = create_node("Operator", "!", NULL, NULL, NULL); }
    ;


cast_expression
    : unary_expression
        {
            $$ = $1;
        }
    | '(' type_name ')' cast_expression
        {
            $$ = create_node("CAST", $2, NULL, $4, NULL);
        }
    ;

multiplicative_expression
    : cast_expression
        {
            $$ = $1;
        }
    | multiplicative_expression '*' cast_expression
        {
            $$ = create_node("MUL", "*", $1, $3, NULL);
        }
    | multiplicative_expression '/' cast_expression
        {
            $$ = create_node("DIV", "/", $1, $3, NULL);
        }
    | multiplicative_expression '%' cast_expression
        {
            $$ = create_node("MOD", "%", $1, $3, NULL);
        }
    ;

additive_expression
    : multiplicative_expression
        {
            $$ = $1;
        }
    | additive_expression '+' multiplicative_expression
        {
            $$ = create_node("ADD", "+", $1, $3, NULL);
        }
    | additive_expression '-' multiplicative_expression
        {
            $$ = create_node("SUB", "-", $1, $3, NULL);
        }
    ;

shift_expression
    : additive_expression
        {
            $$ = $1;
        }
    | shift_expression LEFT_OP additive_expression
        {
            $$ = create_node("SHL", "<<", $1, $3, NULL);
        }
    | shift_expression RIGHT_OP additive_expression
        {
            $$ = create_node("SHR", ">>", $1, $3, NULL);
        }
    ;

relational_expression
    : shift_expression
        {
            $$ = $1;
        }
    | relational_expression '<' shift_expression
        {
            $$ = create_node("LT", "<", $1, $3, NULL);
        }
    | relational_expression '>' shift_expression
        {
            $$ = create_node("GT", ">", $1, $3, NULL);
        }
    | relational_expression LE_OP shift_expression
        {
            $$ = create_node("LE", "<=", $1, $3, NULL);
        }
    | relational_expression GE_OP shift_expression
        {
            $$ = create_node("GE", ">=", $1, $3, NULL);
        }
    ;

equality_expression
    : relational_expression
        {
            $$ = $1;
        }
    | equality_expression EQ_OP relational_expression
        {
            $$ = create_node("EQ", "==", $1, $3, NULL);
        }
    | equality_expression NE_OP relational_expression
        {
            $$ = create_node("NE", "!=", $1, $3, NULL);
        }
    ;


and_expression
    : equality_expression
        {
            $$ = $1;
        }
    | and_expression '&' equality_expression
        {
            $$ = create_node("AND_BITWISE", "&", $1, $3, NULL);
        }
    ;

exclusive_or_expression
    : and_expression
        {
            $$ = $1;
        }
    | exclusive_or_expression '^' and_expression
        {
            $$ = create_node("XOR_BITWISE", "^", $1, $3, NULL);
        }
    ;

inclusive_or_expression
    : exclusive_or_expression
        {
            $$ = $1;
        }
    | inclusive_or_expression '|' exclusive_or_expression
        {
            $$ = create_node("OR_BITWISE", "|", $1, $3, NULL);
        }
    ;

logical_and_expression
    : inclusive_or_expression
        {
            $$ = $1;
        }
    | logical_and_expression AND_OP inclusive_or_expression
        {
            $$ = create_node("AND_LOGICAL", "&&", $1, $3, NULL);
        }
    ;

logical_or_expression
    : logical_and_expression
        {
            $$ = $1;
        }
    | logical_or_expression OR_OP logical_and_expression
        {
            $$ = create_node("OR_LOGICAL", "||", $1, $3, NULL);
        }
    ;

conditional_expression
    : logical_or_expression
        {
            $$ = $1;
        }
    | logical_or_expression '?' expression ':' conditional_expression
        {
            // Ternary ?: node — left = condition, right = true_expr, third = false_expr
            ASTNode *node = create_node("COND", "?:", $1, $3, $5);
            $$ = node;
        }
    ;

assignment_expression
    : conditional_expression
        {
            $$ = $1;
        }
    | unary_expression assignment_operator assignment_expression
        {
            // Assignment node: left = unary_expression (lvalue), right = assigned expr, value = operator
            $$ = create_node("ASSIGN", $2, $1, $3, NULL);
        }
    ;

assignment_operator
    : '=' { $$ = create_node("ASSIGN_OP", "=", NULL, NULL, NULL); }
    | MUL_ASSIGN { $$ = create_node("ASSIGN_OP", "*=", NULL, NULL, NULL); }
    | DIV_ASSIGN { $$ = create_node("ASSIGN_OP", "/=", NULL, NULL, NULL); }
    | MOD_ASSIGN { $$ = create_node("ASSIGN_OP", "%=", NULL, NULL, NULL); }
    | ADD_ASSIGN { $$ = create_node("ASSIGN_OP", "+=", NULL, NULL, NULL); }
    | SUB_ASSIGN { $$ = create_node("ASSIGN_OP", "-=", NULL, NULL, NULL); }
    | LEFT_ASSIGN { $$ = create_node("ASSIGN_OP", "<<=", NULL, NULL, NULL); }
    | RIGHT_ASSIGN { $$ = create_node("ASSIGN_OP", ">>=", NULL, NULL, NULL); }
    | AND_ASSIGN { $$ = create_node("ASSIGN_OP", "&=", NULL, NULL, NULL); }
    | XOR_ASSIGN { $$ = create_node("ASSIGN_OP", "^=", NULL, NULL, NULL); }
    | OR_ASSIGN { $$ = create_node("ASSIGN_OP", "|=", NULL, NULL, NULL); }
    ;

expression
    : assignment_expression
        {
            $$ = $1;
        }
    | expression ',' assignment_expression
        {
            // Comma operator node: left = first expr, right = second expr
            $$ = create_node("COMMA", ",", $1, $3, NULL);
        }
    ;

constant_expression
    : conditional_expression
        {
            $$ = $1;
        }
    ;

declaration
    : declaration_specifiers ';'
        {
            // For now, create a node for declaration specifiers only
            $$ = create_node("DECLARATION", NULL, $1, NULL, NULL);
        }
    | declaration_specifiers init_declarator_list ';'
        {
            // Combine decl specifiers and init declarator list - you may want to build a list here
            $$ = create_node("DECLARATION", NULL, $1, $2, NULL); 
        }
    | error
        {
            // Error node - optionally handle parse errors gracefully
            $$ = create_node("ERROR", "declaration error", NULL, NULL, NULL);
            //yyerrok();
        }
    ;

declaration_specifiers
    : storage_class_specifier
        {
            $$ = $1;
        }
    | storage_class_specifier declaration_specifiers
        {
            // Chain or list - left = current, right = rest
            $$ = create_node("DECL_SPEC", NULL, $1, $2, NULL);
        }
    | type_specifier
        {
            $$ = $1;
        }
    | type_specifier declaration_specifiers
        {
            $$ = create_node("DECL_SPEC", NULL, $1, $2, NULL);
        }
    | type_qualifier
        {
            $$ = $1;
        }
    | type_qualifier declaration_specifiers
        {
            $$ = create_node("DECL_SPEC", NULL, $1, $2, NULL);
        }
    ;

init_declarator_list
    : init_declarator
        {
            $$ = $1;
        }
    | init_declarator_list ',' init_declarator
        {
            // Chain list: left = existing list, right = new init_declarator
            $$ = create_node("INIT_DECL_LIST", NULL, $1, $3, NULL);
        }
    ;

init_declarator
    : declarator
        { $$ = $1; }
    | declarator '=' initializer
        { $$ = create_node("InitDeclarator", NULL, $1, $3, NULL); }
    ;

storage_class_specifier
    : TYPEDEF
        {
            $$ = create_node("STORAGE_CLASS", "typedef", NULL, NULL, NULL);
        }
    | EXTERN
        {
            $$ = create_node("STORAGE_CLASS", "extern", NULL, NULL, NULL);
        }
    | STATIC
        {
            $$ = create_node("STORAGE_CLASS", "static", NULL, NULL, NULL);
        }
    | AUTO
        {
            $$ = create_node("STORAGE_CLASS", "auto", NULL, NULL, NULL);
        }
    | REGISTER
        {
            $$ = create_node("STORAGE_CLASS", "register", NULL, NULL, NULL);
        }
    ;

type_specifier
    : VOID
        {
            $$ = create_node("TYPE_SPEC", "void", NULL, NULL, NULL);
        }
    | CHAR
        {
            $$ = create_node("TYPE_SPEC", "char", NULL, NULL, NULL);
        }
    | SHORT
        {
            $$ = create_node("TYPE_SPEC", "short", NULL, NULL, NULL);
        }
    | INT
        {
            $$ = create_node("TYPE_SPEC", "int", NULL, NULL, NULL);
        }
    | LONG
        {
            $$ = create_node("TYPE_SPEC", "long", NULL, NULL, NULL);
        }
    | FLOAT
        {
            $$ = create_node("TYPE_SPEC", "float", NULL, NULL, NULL);
        }
    | DOUBLE
        {
            $$ = create_node("TYPE_SPEC", "double", NULL, NULL, NULL);
        }
    | SIGNED
        {
            $$ = create_node("TYPE_SPEC", "signed", NULL, NULL, NULL);
        }
    | UNSIGNED
        {
            $$ = create_node("TYPE_SPEC", "unsigned", NULL, NULL, NULL);
        }
    | struct_or_union_specifier
        {
            $$ = $1;
        }
    | enum_specifier
        {
            $$ = $1;
        }
    | TYPE_NAME
        {
            $$ = create_node("TYPE_SPEC", $1, NULL, NULL, NULL);
        }
    ;

struct_or_union_specifier
    : struct_or_union IDENTIFIER '{' struct_declaration_list '}'
        {
            // Node for struct/union with name and declarations list
            // left = struct_or_union (type), right = identifier, third = decl list
            ASTNode *idNode = create_node("IDENTIFIER", $2, NULL, NULL, NULL);
            $$ = create_node("STRUCT_OR_UNION_SPEC", NULL, $1, idNode, $4);
        }
    | struct_or_union '{' struct_declaration_list '}'
        {
            // Anonymous struct/union with declarations
            $$ = create_node("STRUCT_OR_UNION_SPEC", NULL, $1, NULL, $3);
        }
    | struct_or_union IDENTIFIER
        {
            // Forward declaration or incomplete struct/union with just a name
            ASTNode *idNode = create_node("IDENTIFIER", $2, NULL, NULL, NULL);
            $$ = create_node("STRUCT_OR_UNION_SPEC", NULL, $1, idNode, NULL);
        }
    ;

struct_or_union
    : STRUCT
        {
            $$ = create_node("STRUCT_OR_UNION", "struct", NULL, NULL, NULL);
        }
    | UNION
        {
            $$ = create_node("STRUCT_OR_UNION", "union", NULL, NULL, NULL);
        }
    ;

struct_declaration_list
    : struct_declaration
        {
            $$ = $1;
        }
    | struct_declaration_list struct_declaration
        {
            // Chain declarations in a list: left = previous, right = new
            $$ = create_node("STRUCT_DECL_LIST", NULL, $1, $2, NULL);
        }
    ;

struct_declaration
    : specifier_qualifier_list struct_declarator_list ';'
        {
            // A struct declaration node: left = specifier_qualifier_list, right = declarator list
            $$ = create_node("STRUCT_DECLARATION", NULL, $1, $2, NULL);
        }
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list
        {
            // Chain type_specifiers and qualifiers: left = current, right = rest
            $$ = create_node("SPEC_QUAL_LIST", NULL, $1, $2, NULL);
        }
    | type_specifier
        {
            $$ = $1;
        }
    | type_qualifier specifier_qualifier_list
        {
            $$ = create_node("SPEC_QUAL_LIST", NULL, $1, $2, NULL);
        }
    | type_qualifier
        {
            $$ = $1;
        }
    ;

struct_declarator_list
    : struct_declarator
        {
            $$ = $1;
        }
    | struct_declarator_list ',' struct_declarator
        {
            // Chain struct declarators in a list
            $$ = create_node("STRUCT_DECLARATOR_LIST", NULL, $1, $3, NULL);
        }
    ;

struct_declarator
    : declarator
        {
            $$ = create_node("STRUCT_DECLARATOR", NULL, $1, NULL, NULL);
        }
    | ':' constant_expression
        {
            // Bit-field without declarator (anonymous?)
            $$ = create_node("BIT_FIELD", NULL, $2, NULL, NULL);
        }
    | declarator ':' constant_expression
        {
            // Bit-field with declarator: left=declarator, right=bit-width expression
            $$ = create_node("BIT_FIELD", NULL, $1, $3, NULL);
        }
    ;

enum_specifier
    : ENUM '{' enumerator_list '}'
        {
            // Enum with enumerators, no name
            $$ = create_node("ENUM_SPEC", NULL, NULL, $3, NULL);
        }
    | ENUM IDENTIFIER '{' enumerator_list '}'
        {
            ASTNode *idNode = create_node("IDENTIFIER", $2, NULL, NULL, NULL);
            $$ = create_node("ENUM_SPEC", NULL, idNode, $4, NULL);
        }
    | ENUM IDENTIFIER
        {
            ASTNode *idNode = create_node("IDENTIFIER", $2, NULL, NULL, NULL);
            $$ = create_node("ENUM_SPEC", NULL, idNode, NULL, NULL);
        }
    ;

enumerator_list
    : enumerator
        {
            $$ = $1;
        }
    | enumerator_list ',' enumerator
        {
            $$ = create_node("ENUMERATOR_LIST", NULL, $1, $3, NULL);
        }
    ;

enumerator
    : IDENTIFIER
        {
            $$ = create_node("ENUMERATOR", $1, NULL, NULL, NULL);
        }
    | IDENTIFIER '=' constant_expression
        {
            $$ = create_node("ENUMERATOR", $1, NULL, $3, NULL);
        }
    ;

type_qualifier
    : CONST
        {
            $$ = create_node("TYPE_QUALIFIER", "const", NULL, NULL, NULL);
        }
    | VOLATILE
        {
            $$ = create_node("TYPE_QUALIFIER", "volatile", NULL, NULL, NULL);
        }
    ;

declarator
    : pointer direct_declarator
        {
            $$ = create_node("DECLARATOR", NULL, $1, $2, NULL);
        }
    | direct_declarator
        {
            $$ = create_node("DECLARATOR", NULL, $1, NULL, NULL);
        }
    ;


direct_declarator
    : IDENTIFIER
        {
            $$ = create_node("DIRECT_DECLARATOR", $1, NULL, NULL, NULL);
        }
    | '(' declarator ')'
        {
            $$ = create_node("DIRECT_DECLARATOR", NULL, $2, NULL, NULL);
        }
    | direct_declarator '[' constant_expression ']'
        {
            // Array declarator with size
            $$ = create_node("ARRAY_DECLARATOR", NULL, $1, $3, NULL);
        }
    | direct_declarator '[' ']'
        {
            // Array declarator without size
            $$ = create_node("ARRAY_DECLARATOR", NULL, $1, NULL, NULL);
        }
    | direct_declarator '(' parameter_type_list ')'
        {
            $$ = create_node("FUNCTION_DECLARATOR", NULL, $1, $3, NULL);
        }
    | direct_declarator '(' identifier_list ')'
        {
            $$ = create_node("FUNCTION_DECLARATOR", NULL, $1, $3, NULL);
        }
    | direct_declarator '(' ')'
        {
            $$ = create_node("FUNCTION_DECLARATOR", NULL, $1, NULL, NULL);
        }
    ;

pointer
    : '*'
        {
            $$ = create_node("POINTER", NULL, NULL, NULL, NULL);
        }
    | '*' type_qualifier_list
        {
            $$ = create_node("POINTER", NULL, $2, NULL, NULL);
        }
    | '*' pointer
        {
            $$ = create_node("POINTER", NULL, $2, NULL, NULL);
        }
    | '*' type_qualifier_list pointer
        {
            // pointer with qualifiers and nested pointer
            ASTNode *temp = create_node("POINTER", NULL, $3, NULL, NULL);
            $$ = create_node("POINTER", NULL, $2, temp, NULL);
        }
    ;

type_qualifier_list
    : type_qualifier
        {
            $$ = $1;
        }
    | type_qualifier_list type_qualifier
        {
            $$ = create_node("TYPE_QUALIFIER_LIST", NULL, $1, $2, NULL);
        }
    ;

parameter_type_list
    : parameter_list
        {
            $$ = $1;
        }
    | parameter_list ',' ELLIPSIS
        {
            ASTNode *ellipsisNode = create_node("ELLIPSIS", NULL, NULL, NULL, NULL);
            $$ = create_node("PARAMETER_TYPE_LIST", NULL, $1, ellipsisNode, NULL);
        }
    ;

parameter_list
    : parameter_declaration
        {
            $$ = $1;
        }
    | parameter_list ',' parameter_declaration
        {
            $$ = create_node("PARAMETER_LIST", NULL, $1, $3, NULL);
        }
    ;

parameter_declaration
    : declaration_specifiers declarator
        {
            $$ = create_node("PARAMETER_DECLARATION", NULL, $1, $2, NULL);
        }
    | declaration_specifiers abstract_declarator
        {
            $$ = create_node("PARAMETER_DECLARATION", NULL, $1, $2, NULL);
        }
    | declaration_specifiers
        {
            $$ = create_node("PARAMETER_DECLARATION", NULL, $1, NULL, NULL);
        }
    ;

identifier_list
    : IDENTIFIER
        {
            $$ = create_node("IDENTIFIER_LIST", $1, NULL, NULL, NULL);
        }
    | identifier_list ',' IDENTIFIER
        {
            ASTNode *idNode = create_node("IDENTIFIER", $3, NULL, NULL, NULL);
            $$ = create_node("IDENTIFIER_LIST", NULL, $1, idNode, NULL);
        }
    ;

type_name
    : specifier_qualifier_list
        {
            $$ = create_node("TYPE_NAME", NULL, $1, NULL, NULL);
        }
    | specifier_qualifier_list abstract_declarator
        {
            $$ = create_node("TYPE_NAME", NULL, $1, $2, NULL);
        }
    ;

abstract_declarator
    : pointer
        {
            $$ = create_node("ABSTRACT_DECLARATOR", NULL, $1, NULL, NULL);
        }
    | direct_abstract_declarator
        {
            $$ = create_node("ABSTRACT_DECLARATOR", NULL, $1, NULL, NULL);
        }
    | pointer direct_abstract_declarator
        {
            $$ = create_node("ABSTRACT_DECLARATOR", NULL, $1, $2, NULL);
        }
    ;

direct_abstract_declarator
    : '(' abstract_declarator ')'
        {
            $$ = create_node("DIRECT_ABSTRACT_DECLARATOR", NULL, $2, NULL, NULL);
        }
    | '[' ']'
        {
            $$ = create_node("ARRAY_ABSTRACT_DECLARATOR", NULL, NULL, NULL, NULL);
        }
    | '[' constant_expression ']'
        {
            $$ = create_node("ARRAY_ABSTRACT_DECLARATOR", NULL, $2, NULL, NULL);
        }
    | direct_abstract_declarator '[' ']'
        {
            $$ = create_node("ARRAY_ABSTRACT_DECLARATOR", NULL, $1, NULL, NULL);
        }
    | direct_abstract_declarator '[' constant_expression ']'
        {
            $$ = create_node("ARRAY_ABSTRACT_DECLARATOR", NULL, $1, $3, NULL);
        }
    | '(' ')'
        {
            $$ = create_node("FUNCTION_ABSTRACT_DECLARATOR", NULL, NULL, NULL, NULL);
        }
    | '(' parameter_type_list ')'
        {
            $$ = create_node("FUNCTION_ABSTRACT_DECLARATOR", NULL, $2, NULL, NULL);
        }
    | direct_abstract_declarator '(' ')'
        {
            $$ = create_node("FUNCTION_ABSTRACT_DECLARATOR", NULL, $1, NULL, NULL);
        }
    | direct_abstract_declarator '(' parameter_type_list ')'
        {
            $$ = create_node("FUNCTION_ABSTRACT_DECLARATOR", NULL, $1, $3, NULL);
        }
    ;

initializer
    : assignment_expression
        { $$ = $1; }
    | '{' initializer_list '}'
        {
            $$ = create_node("INITIALIZER_LIST", NULL, $2, NULL, NULL);
        }
    | '{' initializer_list ',' '}'
        {
            // Same as above, trailing comma
            $$ = create_node("INITIALIZER_LIST", NULL, $2, NULL, NULL);
        }
    ;

initializer_list
    : initializer
        {
            $$ = create_node("INITIALIZER_LIST", NULL, $1, NULL, NULL);
        }
    | initializer_list ',' initializer
        {
            $$ = create_node("INITIALIZER_LIST", NULL, $1, $3, NULL);
        }
    ;

statement
    : labeled_statement
        {
            $$ = $1;
        }
    | compound_statement
        {
            $$ = $1;
        }
    | expression_statement
        {
            $$ = $1;
        }
    | selection_statement
        {
            $$ = $1;
        }
    | iteration_statement
        {
            $$ = $1;
        }
    | jump_statement
        {
            $$ = $1;
        }
    ;

labeled_statement
    : IDENTIFIER ':' statement
        {
            ASTNode *idNode = create_node("LABEL", $1, NULL, NULL, NULL);
            $$ = create_node("LABELED_STATEMENT", NULL, idNode, $3, NULL);
        }
    | CASE constant_expression ':' statement
        {
            ASTNode *caseNode = create_node("CASE", NULL, $2, $4, NULL);
            $$ = create_node("LABELED_STATEMENT", NULL, caseNode, NULL, NULL);
        }
    | DEFAULT ':' statement
        {
            ASTNode *defaultNode = create_node("DEFAULT", NULL, $3, NULL, NULL);
            $$ = create_node("LABELED_STATEMENT", NULL, defaultNode, NULL, NULL);
        }
    ;

compound_statement
    : LBRACE RBRACE
        {
            $$ = create_node("COMPOUND_STATEMENT", NULL, NULL, NULL, NULL);
        }
    | LBRACE statement_list RBRACE
        {
            $$ = create_node("COMPOUND_STATEMENT", NULL, $2, NULL, NULL);
        }
    | LBRACE declaration_list RBRACE
        {
            $$ = create_node("COMPOUND_STATEMENT", NULL, $2, NULL, NULL);
        }
    | LBRACE declaration_list statement_list RBRACE
        {
            $$ = create_node("COMPOUND_STATEMENT", NULL, $2, $3, NULL);
        }
    ;


declaration_list
    : declaration
        { $$ = $1; }
    | declaration_list declaration
        { $$ = create_node("Declarations", NULL, $1, $2, NULL); }

statement_list
    : statement
        {
            $$ = create_node("STATEMENT_LIST", NULL, $1, NULL, NULL);
        }
    | statement_list statement
        {
            $$ = create_node("STATEMENT_LIST", NULL, $1, $2, NULL);
        }
    ;

expression_statement
    : ';'
        {
            $$ = create_node("EXPRESSION_STATEMENT", NULL, NULL, NULL, NULL);
        }
    | expression ';'
        {
            $$ = create_node("EXPRESSION_STATEMENT", NULL, $1, NULL, NULL);
        }
    ;

selection_statement
    : IF '(' expression ')' statement  %prec NO_ELSE
        {
            $$ = create_node("IF_STATEMENT", NULL, $3, $5, NULL);
        }
    | IF '(' expression ')' statement ELSE statement
        {
            $$ = create_node("IF_ELSE_STATEMENT", NULL, $3, $5, $7);
        }
    | SWITCH '(' expression ')' statement
        {
            $$ = create_node("SWITCH_STATEMENT", NULL, $3, $5, NULL);
        }
    ;

iteration_statement
    : WHILE '(' expression ')' statement
        {
            $$ = create_node("WHILE_STATEMENT", NULL, $3, $5, NULL);
        }
    | DO statement WHILE '(' expression ')' ';'
        {
            $$ = create_node("DO_WHILE_STATEMENT", NULL, $2, $5, NULL);
        }
    | FOR '(' expression_statement expression_statement ')' statement
        {
            $$ = create_node("FOR_STATEMENT", NULL, $3, $4, $6);
        }
    | FOR '(' expression_statement expression_statement expression ')' statement
        {
            ASTNode *forInner = create_node("FOR_INNER", NULL, $3, $4, $5);
            $$ = create_node("FOR_STATEMENT", NULL, forInner, $7, NULL);
        }
    ;

jump_statement
    : GOTO IDENTIFIER ';'
        {
            $$ = create_node("GOTO_STATEMENT", $2, NULL, NULL, NULL);
        }
    | CONTINUE ';'
        {
            $$ = create_node("CONTINUE_STATEMENT", NULL, NULL, NULL, NULL);
        }
    | BREAK ';'
        {
            $$ = create_node("BREAK_STATEMENT", NULL, NULL, NULL, NULL);
        }
    | RETURN ';'
        {
            $$ = create_node("RETURN_STATEMENT", NULL, NULL, NULL, NULL);
        }
    | RETURN expression ';'
        {
            $$ = create_node("RETURN_STATEMENT", NULL, $2, NULL, NULL);
        }
    ;

translation_unit
    : external_declaration
        {
            $$ = $1;
            ast_root = $$;
        }
    | translation_unit external_declaration
        {
            $$ = create_node("TRANSLATION_UNIT", NULL, $1, $2, NULL);
            ast_root = $$; 
        }
    | Define translation_unit
        {
            $$ = create_node("DEFINE", NULL, NULL, $2, NULL);
            ast_root = $$; 
        }
    ;

external_declaration
    : function_definition
        {
            $$ = $1;
        }
    | declaration
        {
            $$ = $1;
        }
    ;

function_definition
    : declaration_specifiers declarator declaration_list compound_statement
        {
            ASTNode *func_body = create_node("FUNCTION_BODY", NULL, $4, NULL, NULL);
            ASTNode *func_decl = create_node("FUNCTION_DECLARATOR", NULL, $2, $3, func_body);
            $$ = create_node("FUNCTION_DEFINITION", NULL, $1, func_decl, NULL);
        }
    | declaration_specifiers declarator compound_statement
        {
            ASTNode *func_body = create_node("FUNCTION_BODY", NULL, $3, NULL, NULL);
            ASTNode *func_decl = create_node("FUNCTION_DECLARATOR", NULL, $2, NULL, func_body);
            $$ = create_node("FUNCTION_DEFINITION", NULL, $1, func_decl, NULL);
        }
    | declarator declaration_list compound_statement
        {
            ASTNode *func_body = create_node("FUNCTION_BODY", NULL, $3, NULL, NULL);
            ASTNode *func_decl = create_node("FUNCTION_DECLARATOR", NULL, $1, $2, func_body);
            $$ = create_node("FUNCTION_DEFINITION", NULL, NULL, func_decl, NULL);
        }
    | declarator compound_statement
        {
            ASTNode *func_body = create_node("FUNCTION_BODY", NULL, $2, NULL, NULL);
            ASTNode *func_decl = create_node("FUNCTION_DECLARATOR", NULL, $1, NULL, func_body);
            $$ = create_node("FUNCTION_DEFINITION", NULL, NULL, func_decl, NULL);
        }
    ;


%%

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	if(!yyparse()){
		printf("\nParsing complete\n");
        print_ast(ast_root, 0);
    }
	else
		printf("\nParsing failed\n");

	fclose(yyin);
	return 0;
}
extern char *yytext;
void yyerror(const char *s) {  
    printf("\nLine %d : %s\n", yylineno, s);
}        


ASTNode *create_node(const char *type, const char *val, ASTNode *l, ASTNode *r, ASTNode *t) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->node_type = strdup(type);
    newNode->value = val ? strdup(val) : NULL;
    newNode->left = l;
    newNode->right = r;
    newNode->third = t;
    return newNode;
}

void print_ast(ASTNode *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; ++i) printf("  ");
    printf("%s", node->node_type);
    if (node->value) printf(": %s", node->value);
    printf("\n");
    print_ast(node->left, depth + 1);
    print_ast(node->right, depth + 1);
    print_ast(node->third, depth + 1);
}