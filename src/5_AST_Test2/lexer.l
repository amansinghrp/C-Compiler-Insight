%{
    #include "y.tab.h"
    int countn=0;
%}
%option yylineno

alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"

%%

"printf"                    { yylval.strval = strdup(yytext); return PRINTFF; }
"scanf"                     { yylval.strval = strdup(yytext); return SCANFF; }
"int"                       { yylval.strval = strdup(yytext); return INT; }
"float"                     { yylval.strval = strdup(yytext); return FLOAT; }
"char"                      { yylval.strval = strdup(yytext); return CHAR; }
"void"                      { yylval.strval = strdup(yytext); return VOID; }
"return"                    { yylval.strval = strdup(yytext); return RETURN; }
"for"	                    { yylval.strval = strdup(yytext); return FOR; }
"if"	                    { yylval.strval = strdup(yytext); return IF; }
"else"	                    { yylval.strval = strdup(yytext); return ELSE; }
^"#include"[ ]*<.+\.h>      { yylval.strval = strdup(yytext); return INCLUDE; }
"true"                      { yylval.strval = strdup(yytext); return TRUE; }
"false"                     { yylval.strval = strdup(yytext); return FALSE; }
[-]?{digit}+                { yylval.strval = strdup(yytext); return CONSTANT; }
[-]?{digit}+\.{digit}{1,6}  { yylval.strval = strdup(yytext); return FLOAT_NUM; }
{alpha}({alpha}|{digit})*   { yylval.strval = strdup(yytext); return IDENTIFIER ; }
{unary}                     { yylval.strval = strdup(yytext); return UNARY; }
"<="                        { yylval.strval = strdup(yytext); return LE; }
">="                        { yylval.strval = strdup(yytext); return GE; }
"=="                        { yylval.strval = strdup(yytext); return EQ; }
"!="                        { yylval.strval = strdup(yytext); return NE; }
">"	                        { yylval.strval = strdup(yytext); return GT; }
"<"	                        { yylval.strval = strdup(yytext); return LT; }
"&&"	                    { yylval.strval = strdup(yytext); return AND; }
"||"	                    { yylval.strval = strdup(yytext); return OR; }
"+"                         { yylval.strval = strdup(yytext); return ADD; }
"-"                         { yylval.strval = strdup(yytext); return SUBTRACT; }
"/"                         { yylval.strval = strdup(yytext); return DIVIDE; }
"*"                         { yylval.strval = strdup(yytext); return MULTIPLY; }
"("                         { return LPAREN; }
")"                         { return RPAREN; }
"{"                         { return LBRACE; }
"}"                         { return RBRACE; }
";"                         { return SEMICOLON; }
","                         { return COMMA; }
"="                         { return ASSIGN; }

\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
.	                        { printf("Lexical Error: Unrecognized token '%s' at line %d\n", yytext, yylineno); }
["].*["]                    { yylval.strval = strdup(yytext); return STRING_LITERAL; }
['].[']                     { yylval.strval = strdup(yytext); return CONSTANT; }
^#[^\n]*                    { /* Ignore preprocessor lines like #include, #define */ }

%%

int yywrap() {
    return 1;
}