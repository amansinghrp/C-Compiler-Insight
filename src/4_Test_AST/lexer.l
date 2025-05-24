%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
void yyerror(const char *s);
%}

%option noyywrap

%%

#.*\n                ;  /* Skip preprocessor directives */
"int"                { return INT; }
"return"             { return RETURN; }
"printf"             { return PRINTFF; }
"main"               { yylval.strval = strdup(yytext); return IDENTIFIER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.strval = strdup(yytext); return IDENTIFIER; }
[0-9]+               { yylval.strval = strdup(yytext); return NUMBER; }
";"                  { return SEMICOLON; }
"="                  { return ASSIGN; }
"("                  { return LPAREN; }
")"                  { return RPAREN; }
"{"                  { return LBRACE; }
"}"                  { return RBRACE; }
","                  { return COMMA; }
"+"                  { return '+'; }
"-"                  { return '-'; }
"*"                  { return '*'; }
"/"                  { return '/'; }
[ \t\n]              ;  /* Skip whitespace */
.                    { printf("Unknown token: %s\n", yytext); }

%%