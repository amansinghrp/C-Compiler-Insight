/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NO_ELSE = 258,                 /* NO_ELSE  */
    PRINTFF = 259,                 /* PRINTFF  */
    SCANFF = 260,                  /* SCANFF  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    CHAR = 263,                    /* CHAR  */
    VOID = 264,                    /* VOID  */
    RETURN = 265,                  /* RETURN  */
    FOR = 266,                     /* FOR  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    INCLUDE = 269,                 /* INCLUDE  */
    TRUE = 270,                    /* TRUE  */
    FALSE = 271,                   /* FALSE  */
    NUMBER = 272,                  /* NUMBER  */
    FLOAT_NUM = 273,               /* FLOAT_NUM  */
    IDENTIFIER = 274,              /* IDENTIFIER  */
    UNARY = 275,                   /* UNARY  */
    LE = 276,                      /* LE  */
    GE = 277,                      /* GE  */
    EQ = 278,                      /* EQ  */
    NE = 279,                      /* NE  */
    GT = 280,                      /* GT  */
    LT = 281,                      /* LT  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    ADD = 284,                     /* ADD  */
    SUBTRACT = 285,                /* SUBTRACT  */
    DIVIDE = 286,                  /* DIVIDE  */
    MULTIPLY = 287,                /* MULTIPLY  */
    STRING_LITERAL = 288,          /* STRING_LITERAL  */
    CONSTANT = 289,                /* CONSTANT  */
    TYPE_NAME = 290,               /* TYPE_NAME  */
    DEF = 291,                     /* DEF  */
    SHORT = 292,                   /* SHORT  */
    LONG = 293,                    /* LONG  */
    SIGNED = 294,                  /* SIGNED  */
    UNSIGNED = 295,                /* UNSIGNED  */
    DOUBLE = 296,                  /* DOUBLE  */
    CONST = 297,                   /* CONST  */
    VOLATILE = 298,                /* VOLATILE  */
    STRUCT = 299,                  /* STRUCT  */
    UNION = 300,                   /* UNION  */
    ENUM = 301,                    /* ENUM  */
    ELLIPSIS = 302,                /* ELLIPSIS  */
    CASE = 303,                    /* CASE  */
    DEFAULT = 304,                 /* DEFAULT  */
    SWITCH = 305,                  /* SWITCH  */
    WHILE = 306,                   /* WHILE  */
    DO = 307,                      /* DO  */
    GOTO = 308,                    /* GOTO  */
    CONTINUE = 309,                /* CONTINUE  */
    BREAK = 310,                   /* BREAK  */
    SIZEOF = 311,                  /* SIZEOF  */
    PTR_OP = 312,                  /* PTR_OP  */
    INC_OP = 313,                  /* INC_OP  */
    DEC_OP = 314,                  /* DEC_OP  */
    LEFT_OP = 315,                 /* LEFT_OP  */
    RIGHT_OP = 316,                /* RIGHT_OP  */
    LE_OP = 317,                   /* LE_OP  */
    GE_OP = 318,                   /* GE_OP  */
    EQ_OP = 319,                   /* EQ_OP  */
    NE_OP = 320,                   /* NE_OP  */
    AND_OP = 321,                  /* AND_OP  */
    OR_OP = 322,                   /* OR_OP  */
    MUL_ASSIGN = 323,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 324,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 325,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 326,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 327,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 328,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 329,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 330,              /* AND_ASSIGN  */
    XOR_ASSIGN = 331,              /* XOR_ASSIGN  */
    OR_ASSIGN = 332,               /* OR_ASSIGN  */
    TYPEDEF = 333,                 /* TYPEDEF  */
    EXTERN = 334,                  /* EXTERN  */
    STATIC = 335,                  /* STATIC  */
    AUTO = 336,                    /* AUTO  */
    REGISTER = 337,                /* REGISTER  */
    LPAREN = 338,                  /* LPAREN  */
    RPAREN = 339,                  /* RPAREN  */
    LBRACE = 340,                  /* LBRACE  */
    RBRACE = 341,                  /* RBRACE  */
    SEMICOLON = 342,               /* SEMICOLON  */
    COMMA = 343,                   /* COMMA  */
    ASSIGN = 344                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 72 "parser.y"

    char *strval;
    struct ASTNode *node;

#line 153 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
