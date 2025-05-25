%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    extern FILE *yyin;
    extern FILE *yyout;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
    };
    
    extern char* yytext;
    extern int countn;
    void yyerror(const char *s);
    int yylex();
    void add(char);
    void insert_type();
    int search(char *);
    void print_tree(struct node*);
    void print_inorder(struct node *);
    void check_declaration(char *);
    void check_return_type(char *);
    int check_types(char *, char *);
    char *get_type(char *);
    struct node* mknode(struct node *left, struct node *right, char *token);
    void generate_dot(FILE *fp, struct node *node);
    void visualize_parse_tree();

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[40];

    int count=0;
    int q;
    char type[10];
    struct node *head;
    int sem_errors=0;
    int ic_idx=0;
    int temp_var=0;
    int label=0;
    int is_for=0;
    char buff[100];
    char errors[10][100];
    char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
    char icg[50][100];
%}

%union { 
    struct var_name { 
        char name[100]; 
        struct node* nd;
    } nd_obj;
    struct var_name2 { 
        char name[100]; 
        struct node* nd;
        char type[10];
    } nd_obj2; 
    struct var_name3 {
        char name[100];
        struct node* nd;
        char if_body[10];
        char else_body[10];
    } nd_obj3;
} 

%token VOID 
%token <nd_obj> CHARACTER PRINTFF SCANFF INT FLOAT CHAR FOR IF ELSE TRUE FALSE NUMBER FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MULTIPLY DIVIDE SUBTRACT UNARY INCLUDE RETURN 
%type <nd_obj> headers main body return datatype statement arithmetic relop program else
%type <nd_obj2> init value expression
%type <nd_obj> printf_args opt_printf_args
%type <nd_obj3> condition

%%

program: headers main '(' ')' '{' body return '}' { 
    $2.nd = mknode($6.nd, $7.nd, "main"); 
    $$.nd = mknode($1.nd, $2.nd, "program"); 
    head = $$.nd;
} 
;

headers: headers headers { $$.nd = mknode($1.nd, $2.nd, "headers"); }
| INCLUDE { add('H'); } { $$.nd = mknode(NULL, NULL, $1.name); }
;

main: datatype ID { add('F'); }
;

datatype: INT { insert_type(); }
| FLOAT { insert_type(); }
| CHAR { insert_type(); }
| VOID { insert_type(); }
;

body: FOR { add('K'); is_for = 1; } '(' statement ';' condition ';' statement ')' '{' body '}' { 
    struct node *temp = mknode($6.nd, $8.nd, "CONDITION"); 
    struct node *temp2 = mknode($4.nd, temp, "CONDITION"); 
    $$.nd = mknode(temp2, $11.nd, $1.name); 
    sprintf(icg[ic_idx++], "%s", buff);
    sprintf(icg[ic_idx++], "JUMP to %s\n", $6.if_body);
    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $6.else_body);
}
| IF { add('K'); is_for = 0; } '(' condition ')' { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.if_body); } '{' body '}' { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body); } else { 
    struct node *iff = mknode($4.nd, $8.nd, $1.name); 
    $$.nd = mknode(iff, $11.nd, "if-else"); 
    sprintf(icg[ic_idx++], "GOTO next\n");
}
| statement ';' { $$.nd = $1.nd; }
| body body { $$.nd = mknode($1.nd, $2.nd, "statements"); }
| PRINTFF { add('K'); }
    '(' STR opt_printf_args ')' ';'
    {
      struct node *strNode = mknode(NULL, NULL, $4.name);
      struct node *argsNode = $5.nd;          
      $$.nd = mknode(strNode, argsNode, "printf");
    }

| SCANFF { add('K'); } '(' STR ',' '&' ID ')' ';' { $$.nd = mknode(NULL, NULL, "scanf"); }
;

else: ELSE { add('K'); } '{' body '}' { $$.nd = mknode(NULL, $4.nd, $1.name); }
| { $$.nd = NULL; }
;
opt_printf_args
  :                { $$.nd = NULL; }
  | ',' printf_args { $$.nd = $2.nd; }
;
printf_args
  : expression
      { 
        /* leaf node for a single argument */
        $$.nd = mknode(NULL, $1.nd, "arg");  
      }
  | printf_args ',' expression
      {
        /* append another arg to the right */
        struct node *leftList = $1.nd;
        struct node *newArg   = mknode(NULL, $3.nd, "arg");
        $$.nd = mknode(leftList, newArg, "args");
      }
;

condition: value relop value { 
    $$.nd = mknode($1.nd, $3.nd, $2.name); 
    if(is_for) {
        sprintf($$.if_body, "L%d", label++);
        sprintf($$.else_body, "L%d", label++);
    } else {
        sprintf($$.if_body, "L%d", label++);
        sprintf($$.else_body, "L%d", label++);
    }
}
| TRUE { add('K'); $$.nd = NULL; }
| FALSE { add('K'); $$.nd = NULL; }
| { $$.nd = NULL; }
;

statement: datatype ID { add('V'); } init { 
    $2.nd = mknode(NULL, NULL, $2.name); 
    int t = check_types($1.name, $4.type); 
    if(t>0) { 
        struct node *temp;
        if(t == 1) temp = mknode(NULL, $4.nd, "floattoint"); 
        else if(t == 2) temp = mknode(NULL, $4.nd, "inttofloat"); 
        else if(t == 3) temp = mknode(NULL, $4.nd, "chartoint"); 
        else if(t == 4) temp = mknode(NULL, $4.nd, "inttochar"); 
        else if(t == 5) temp = mknode(NULL, $4.nd, "chartofloat"); 
        else temp = mknode(NULL, $4.nd, "floattochar"); 
        $$.nd = mknode($2.nd, temp, "declaration"); 
    } 
    else { 
        $$.nd = mknode($2.nd, $4.nd, "declaration"); 
    } 
}
| ID { check_declaration($1.name); } '=' expression {
    $1.nd = mknode(NULL, NULL, $1.name); 
    char *id_type = get_type($1.name); 
    if(strcmp(id_type, $4.type)) {
        struct node *temp;
        if(!strcmp(id_type, "int")) {
            if(!strcmp($4.type, "float")) temp = mknode(NULL, $4.nd, "floattoint");
            else temp = mknode(NULL, $4.nd, "chartoint");
        }
        else if(!strcmp(id_type, "float")) {
            if(!strcmp($4.type, "int")) temp = mknode(NULL, $4.nd, "inttofloat");
            else temp = mknode(NULL, $4.nd, "chartofloat");
        }
        else {
            if(!strcmp($4.type, "int")) temp = mknode(NULL, $4.nd, "inttochar");
            else temp = mknode(NULL, $4.nd, "floattochar");
        }
        $$.nd = mknode($1.nd, temp, "="); 
    }
    else {
        $$.nd = mknode($1.nd, $4.nd, "="); 
    }
}
| ID { check_declaration($1.name); } relop expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $4.nd, $3.name); }
| ID { check_declaration($1.name); } UNARY { 
    $1.nd = mknode(NULL, NULL, $1.name); 
    $3.nd = mknode(NULL, NULL, $3.name); 
    $$.nd = mknode($1.nd, $3.nd, "ITERATOR");  
    if(!strcmp($3.name, "++")) {
        int current_temp = temp_var;
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", current_temp, $1.name, $1.name, current_temp);
        temp_var++;
    }
    else {
        int current_temp = temp_var;
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", current_temp, $1.name, $1.name, current_temp);
        temp_var++;
    }
}
| UNARY ID { 
    check_declaration($2.name); 
    $1.nd = mknode(NULL, NULL, $1.name); 
    $2.nd = mknode(NULL, NULL, $2.name); 
    $$.nd = mknode($1.nd, $2.nd, "ITERATOR"); 
    if(!strcmp($1.name, "++")) {
        int current_temp = temp_var;
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", current_temp, $2.name, $2.name, current_temp);
        temp_var++;
    }
    else {
        int current_temp = temp_var;
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", current_temp, $2.name, $2.name, current_temp);
        temp_var++;
    }
}
;

init: '=' value { $$.nd = $2.nd; sprintf($$.type, "%s", $2.type); strcpy($$.name, $2.name); }
| { sprintf($$.type, "null"); $$.nd = mknode(NULL, NULL, "NULL"); strcpy($$.name, "NULL"); }
;

expression: expression arithmetic expression { 
    if(!strcmp($1.type, $3.type)) {
        sprintf($$.type, "%s", $1.type);
        $$.nd = mknode($1.nd, $3.nd, $2.name); 
    }
    else {
        struct node *temp;
        if(!strcmp($1.type, "int") && !strcmp($3.type, "float")) temp = mknode(NULL, $1.nd, "inttofloat");
        else if(!strcmp($1.type, "float") && !strcmp($3.type, "int")) temp = mknode(NULL, $3.nd, "inttofloat");
        else if(!strcmp($1.type, "int") && !strcmp($3.type, "char")) temp = mknode(NULL, $3.nd, "chartoint");
        else if(!strcmp($1.type, "char") && !strcmp($3.type, "int")) temp = mknode(NULL, $1.nd, "chartoint");
        else if(!strcmp($1.type, "float") && !strcmp($3.type, "char")) temp = mknode(NULL, $3.nd, "chartofloat");
        else temp = mknode(NULL, $1.nd, "chartofloat");
        
        sprintf($$.type, "%s", !strcmp($1.type, "float") ? "float" : "int");
        $$.nd = mknode(temp, $3.nd, $2.name);
    }
    sprintf($$.name, "t%d", temp_var);
    temp_var++;
}
| value { strcpy($$.name, $1.name); sprintf($$.type, "%s", $1.type); $$.nd = $1.nd; }
;

arithmetic: ADD 
| SUBTRACT 
| MULTIPLY
| DIVIDE
;

relop: LT
| GT
| LE
| GE
| EQ
| NE
;

value: NUMBER { strcpy($$.name, $1.name); sprintf($$.type, "int"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| FLOAT_NUM { strcpy($$.name, $1.name); sprintf($$.type, "float"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| CHARACTER { strcpy($$.name, $1.name); sprintf($$.type, "char"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| ID { strcpy($$.name, $1.name); char *id_type = get_type($1.name); sprintf($$.type, "%s", id_type); check_declaration($1.name); $$.nd = mknode(NULL, NULL, $1.name); }
;

return: RETURN { add('K'); } value ';' { check_return_type($3.name); $1.nd = mknode(NULL, NULL, "return"); $$.nd = mknode($1.nd, $3.nd, "RETURN"); }
| { $$.nd = NULL; }
;

%%

void generate_dot(FILE *fp, struct node *node) {
    if(node == NULL) return;
    fprintf(fp, "  \"%p\" [label=\"%s\"];\n", (void*)node, node->token);
    if(node->left) {
        fprintf(fp, "  \"%p\" -> \"%p\";\n", (void*)node, (void*)node->left);
        generate_dot(fp, node->left);
    }
    if(node->right) {
        fprintf(fp, "  \"%p\" -> \"%p\";\n", (void*)node, (void*)node->right);
        generate_dot(fp, node->right);
    }
}

void visualize_parse_tree() {
    FILE *fp = fopen("parse_tree.dot", "w");
    if(fp == NULL) return;
    fprintf(fp, "digraph ParseTree {\n");
    fprintf(fp, "  node [shape=box];\n");
    generate_dot(fp, head);
    fprintf(fp, "}\n");
    fclose(fp);
    system("dot -Tpng parse_tree.dot -o parse_tree.png");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen("semantic.txt", "w");  // Output semantic results here
    if (!yyin) {
        perror(argv[1]);
        return 1;
    }
    if (!yyout) {
        perror("semantic.txt");
        exit(1);
    }

    yyparse();

    printf("\n\t\t\t\t\t\tPHASE 3: SEMANTIC ANALYSIS\n\n");

    if (sem_errors > 0) {
        printf("Semantic analysis completed with %d error(s)\n", sem_errors);
        fprintf(yyout, "Semantic analysis completed with %d error(s)\n", sem_errors);
        for (int i = 0; i < sem_errors; i++) {
            printf("\t- %s\n", errors[i]);
            fprintf(yyout, "\t- %s\n", errors[i]);
        }
    } else {
        printf("Semantic analysis completed with no errors\n");
        fprintf(yyout, "Semantic analysis completed with no errors\n");
    }

    fclose(yyout);
    fclose(yyin);
    return 0;
}


int search(char *type) {
    for(int i=count-1; i>=0; i--) {
        if(strcmp(symbol_table[i].id_name, type)==0) return -1;
    }
    return 0;
}

void check_declaration(char *c) {
    q = search(c);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared!\n", countn+1, c);
        sem_errors++;
    }
}

void check_return_type(char *value) {
    char *main_datatype = get_type("main");
    char *return_datatype = get_type(value);
    if(!strcmp(main_datatype, "int") && !strcmp(return_datatype, "CONST")) return;
    if(!strcmp(main_datatype, return_datatype)) return;
    sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", countn+1);
    sem_errors++;
}

int check_types(char *type1, char *type2){
    if(!strcmp(type2, "null")) return -1;
    if(!strcmp(type1, type2)) return 0;
    if(!strcmp(type1, "int") && !strcmp(type2, "float")) return 1;
    if(!strcmp(type1, "float") && !strcmp(type2, "int")) return 2;
    if(!strcmp(type1, "int") && !strcmp(type2, "char")) return 3;
    if(!strcmp(type1, "char") && !strcmp(type2, "int")) return 4;
    if(!strcmp(type1, "float") && !strcmp(type2, "char")) return 5;
    return 6;
}

char *get_type(char *var){
    for(int i=0; i<count; i++) {
        if(!strcmp(symbol_table[i].id_name, var)) return symbol_table[i].data_type;
    }
    return "unknown";
}

void add(char c) {
    if(c == 'V'){
        for(int i=0; i<10; i++){
            if(!strcmp(reserved[i], yytext)){
                sprintf(errors[sem_errors], "Line %d: Reserved keyword \"%s\"\n", countn+1, yytext);
                sem_errors++;
                return;
            }
        }
    }
    q=search(yytext);
    if(!q) {
        symbol_table[count].id_name = strdup(yytext);
        if(c == 'H') symbol_table[count].data_type = strdup(type);
        else if(c == 'K') symbol_table[count].data_type = strdup("N/A");
        else if(c == 'V') symbol_table[count].data_type = strdup(type);
        else if(c == 'C') symbol_table[count].data_type = strdup("CONST");
        else if(c == 'F') symbol_table[count].data_type = strdup(type);
        symbol_table[count].line_no = countn;
        symbol_table[count].type = c == 'H' ? strdup("Header") : 
                                 c == 'K' ? strdup("Keyword") : 
                                 c == 'V' ? strdup("Variable") : 
                                 strdup("Constant");
        count++;
    }
    else if(c == 'V') {
        sprintf(errors[sem_errors], "Line %d: Redeclaration of \"%s\"\n", countn+1, yytext);
        sem_errors++;
    }
}

struct node* mknode(struct node *left, struct node *right, char *token) {    
    struct node *newnode = malloc(sizeof(struct node));
    newnode->left = left;
    newnode->right = right;
    newnode->token = strdup(token);
    return newnode;
}

void print_tree(struct node* tree) {
    print_inorder(tree);
}

void print_inorder(struct node *tree) {
    if(tree->left) print_inorder(tree->left);
    printf("%s, ", tree->token);
    if(tree->right) print_inorder(tree->right);
}

void insert_type() {
    strcpy(type, yytext);
}

void yyerror(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
}