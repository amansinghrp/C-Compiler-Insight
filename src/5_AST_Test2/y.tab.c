/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user prologue.  */
#line 1 "parser.y"

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
    int yylex(void);


    ASTNode *ast_root = NULL;    


#line 85 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NO_ELSE = 3,                    /* NO_ELSE  */
  YYSYMBOL_4_ = 4,                         /* '<'  */
  YYSYMBOL_5_ = 5,                         /* '>'  */
  YYSYMBOL_6_ = 6,                         /* '='  */
  YYSYMBOL_7_ = 7,                         /* '+'  */
  YYSYMBOL_8_ = 8,                         /* '-'  */
  YYSYMBOL_9_ = 9,                         /* '*'  */
  YYSYMBOL_10_ = 10,                       /* '/'  */
  YYSYMBOL_11_ = 11,                       /* '%'  */
  YYSYMBOL_12_ = 12,                       /* '|'  */
  YYSYMBOL_13_ = 13,                       /* '&'  */
  YYSYMBOL_PRINTFF = 14,                   /* PRINTFF  */
  YYSYMBOL_SCANFF = 15,                    /* SCANFF  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_FLOAT = 17,                     /* FLOAT  */
  YYSYMBOL_CHAR = 18,                      /* CHAR  */
  YYSYMBOL_VOID = 19,                      /* VOID  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_INCLUDE = 24,                   /* INCLUDE  */
  YYSYMBOL_TRUE = 25,                      /* TRUE  */
  YYSYMBOL_FALSE = 26,                     /* FALSE  */
  YYSYMBOL_NUMBER = 27,                    /* NUMBER  */
  YYSYMBOL_FLOAT_NUM = 28,                 /* FLOAT_NUM  */
  YYSYMBOL_IDENTIFIER = 29,                /* IDENTIFIER  */
  YYSYMBOL_UNARY = 30,                     /* UNARY  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_GE = 32,                        /* GE  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_LT = 36,                        /* LT  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_ADD = 39,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 40,                  /* SUBTRACT  */
  YYSYMBOL_DIVIDE = 41,                    /* DIVIDE  */
  YYSYMBOL_MULTIPLY = 42,                  /* MULTIPLY  */
  YYSYMBOL_STRING_LITERAL = 43,            /* STRING_LITERAL  */
  YYSYMBOL_CONSTANT = 44,                  /* CONSTANT  */
  YYSYMBOL_TYPE_NAME = 45,                 /* TYPE_NAME  */
  YYSYMBOL_DEF = 46,                       /* DEF  */
  YYSYMBOL_SHORT = 47,                     /* SHORT  */
  YYSYMBOL_LONG = 48,                      /* LONG  */
  YYSYMBOL_SIGNED = 49,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 50,                  /* UNSIGNED  */
  YYSYMBOL_DOUBLE = 51,                    /* DOUBLE  */
  YYSYMBOL_CONST = 52,                     /* CONST  */
  YYSYMBOL_VOLATILE = 53,                  /* VOLATILE  */
  YYSYMBOL_STRUCT = 54,                    /* STRUCT  */
  YYSYMBOL_UNION = 55,                     /* UNION  */
  YYSYMBOL_ENUM = 56,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 57,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 58,                      /* CASE  */
  YYSYMBOL_DEFAULT = 59,                   /* DEFAULT  */
  YYSYMBOL_SWITCH = 60,                    /* SWITCH  */
  YYSYMBOL_WHILE = 61,                     /* WHILE  */
  YYSYMBOL_DO = 62,                        /* DO  */
  YYSYMBOL_GOTO = 63,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 64,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 65,                     /* BREAK  */
  YYSYMBOL_SIZEOF = 66,                    /* SIZEOF  */
  YYSYMBOL_PTR_OP = 67,                    /* PTR_OP  */
  YYSYMBOL_INC_OP = 68,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 69,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 70,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 71,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 72,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 73,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 74,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 75,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 76,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 77,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 78,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 79,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 80,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 81,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 82,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 83,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 84,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 85,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 86,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 87,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF = 88,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 89,                    /* EXTERN  */
  YYSYMBOL_STATIC = 90,                    /* STATIC  */
  YYSYMBOL_AUTO = 91,                      /* AUTO  */
  YYSYMBOL_REGISTER = 92,                  /* REGISTER  */
  YYSYMBOL_LPAREN = 93,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 94,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 95,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 96,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 97,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 98,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 99,                    /* ASSIGN  */
  YYSYMBOL_100_ = 100,                     /* '('  */
  YYSYMBOL_101_ = 101,                     /* ')'  */
  YYSYMBOL_102_ = 102,                     /* '['  */
  YYSYMBOL_103_ = 103,                     /* ']'  */
  YYSYMBOL_104_ = 104,                     /* '.'  */
  YYSYMBOL_105_ = 105,                     /* ','  */
  YYSYMBOL_106_ = 106,                     /* '~'  */
  YYSYMBOL_107_ = 107,                     /* '!'  */
  YYSYMBOL_108_ = 108,                     /* '^'  */
  YYSYMBOL_109_ = 109,                     /* '?'  */
  YYSYMBOL_110_ = 110,                     /* ':'  */
  YYSYMBOL_111_ = 111,                     /* ';'  */
  YYSYMBOL_112_ = 112,                     /* '{'  */
  YYSYMBOL_113_ = 113,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 114,                 /* $accept  */
  YYSYMBOL_primary_expression = 115,       /* primary_expression  */
  YYSYMBOL_Define = 116,                   /* Define  */
  YYSYMBOL_postfix_expression = 117,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 118, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 119,         /* unary_expression  */
  YYSYMBOL_unary_operator = 120,           /* unary_operator  */
  YYSYMBOL_cast_expression = 121,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 122, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 123,      /* additive_expression  */
  YYSYMBOL_shift_expression = 124,         /* shift_expression  */
  YYSYMBOL_relational_expression = 125,    /* relational_expression  */
  YYSYMBOL_equality_expression = 126,      /* equality_expression  */
  YYSYMBOL_and_expression = 127,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 128,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 129,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 130,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 131,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 132,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 133,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 134,      /* assignment_operator  */
  YYSYMBOL_expression = 135,               /* expression  */
  YYSYMBOL_constant_expression = 136,      /* constant_expression  */
  YYSYMBOL_declaration = 137,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 138,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 139,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 140,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 141,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 142,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 143, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 144,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 145,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 146,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 147, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 148,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 149,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 150,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 151,          /* enumerator_list  */
  YYSYMBOL_enumerator = 152,               /* enumerator  */
  YYSYMBOL_type_qualifier = 153,           /* type_qualifier  */
  YYSYMBOL_declarator = 154,               /* declarator  */
  YYSYMBOL_direct_declarator = 155,        /* direct_declarator  */
  YYSYMBOL_pointer = 156,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 157,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 158,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 159,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 160,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 161,          /* identifier_list  */
  YYSYMBOL_type_name = 162,                /* type_name  */
  YYSYMBOL_abstract_declarator = 163,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 164, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 165,              /* initializer  */
  YYSYMBOL_initializer_list = 166,         /* initializer_list  */
  YYSYMBOL_statement = 167,                /* statement  */
  YYSYMBOL_labeled_statement = 168,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 169,       /* compound_statement  */
  YYSYMBOL_declaration_list = 170,         /* declaration_list  */
  YYSYMBOL_statement_list = 171,           /* statement_list  */
  YYSYMBOL_expression_statement = 172,     /* expression_statement  */
  YYSYMBOL_selection_statement = 173,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 174,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 175,           /* jump_statement  */
  YYSYMBOL_translation_unit = 176,         /* translation_unit  */
  YYSYMBOL_external_declaration = 177,     /* external_declaration  */
  YYSYMBOL_function_definition = 178       /* function_definition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1636

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  114
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  216
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 7
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   344

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   107,     2,     2,     2,    11,    13,     2,
     100,   101,     9,     7,   105,     8,   104,    10,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   110,   111,
       4,     6,     5,   109,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   102,     2,   103,   108,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   112,    12,   113,   106,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    81,    83,    85,    87,    93,    99,   101,
     103,   105,   107,   109,   111,   113,   119,   121,   130,   132,
     134,   136,   138,   140,   146,   147,   148,   149,   150,   151,
     156,   160,   167,   171,   175,   179,   186,   190,   194,   201,
     205,   209,   216,   220,   224,   228,   232,   239,   243,   247,
     255,   259,   266,   270,   277,   281,   288,   292,   299,   303,
     310,   314,   323,   327,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   349,   353,   361,   368,   373,
     378,   387,   391,   396,   400,   404,   408,   415,   419,   427,
     429,   434,   438,   442,   446,   450,   457,   461,   465,   469,
     473,   477,   481,   485,   489,   493,   497,   501,   508,   515,
     520,   529,   533,   540,   544,   552,   560,   565,   569,   573,
     580,   584,   592,   596,   601,   609,   614,   619,   627,   631,
     638,   642,   649,   653,   660,   664,   672,   676,   680,   685,
     690,   694,   698,   705,   709,   713,   717,   726,   730,   737,
     741,   749,   753,   760,   764,   768,   775,   779,   787,   791,
     798,   802,   806,   813,   817,   821,   825,   829,   833,   837,
     841,   845,   852,   854,   858,   866,   870,   877,   881,   885,
     889,   893,   897,   904,   909,   914,   922,   926,   930,   934,
     942,   944,   948,   952,   959,   963,   970,   974,   978,   985,
     989,   993,   997,  1005,  1009,  1013,  1017,  1021,  1028,  1033,
    1038,  1046,  1050,  1057,  1063,  1069,  1075
};
#endif

#define YYPACT_NINF (-156)
#define YYTABLE_NINF (-211)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1218,  -156,    19,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,    -2,
    -156,  -156,  -156,  -156,  -156,    40,  1218,  -156,     8,  1544,
    1544,  -156,    22,  -156,  1544,  1321,   -77,   -11,   896,  -156,
    -156,  -156,  -156,    19,   -90,    30,   -31,   953,  -156,    15,
    -156,   501,  -156,  -156,   -12,  1298,  -156,   309,  -156,     8,
    -156,  1321,  1453,   948,   -77,  -156,  -156,  -156,  -156,    30,
      34,   -47,  -156,  -156,    40,  -156,   534,  -156,  1321,  1298,
    1298,   520,  -156,    23,  1298,  -156,  -156,  -156,  -156,   758,
     -19,    18,    39,  -156,  -156,  1138,    77,    25,    42,   748,
     166,   101,   117,  1148,  1213,  1213,  -156,   833,  -156,  -156,
    -156,  -156,    32,   155,   197,  1138,  -156,   280,   192,   148,
      49,   186,   219,    97,   230,   168,   -29,  -156,  -156,    33,
    -156,  -156,  -156,   405,   610,  -156,  -156,  -156,  -156,   240,
    -156,  -156,  -156,  -156,    27,   157,   144,  -156,    36,  -156,
    -156,  -156,  -156,   153,   -26,  1138,    30,  -156,  -156,   534,
    -156,  -156,  -156,  1276,  -156,  -156,  -156,  1138,    41,  -156,
     162,  -156,  -156,    69,   824,  1138,   748,   164,   748,  1138,
    1138,   234,   185,  -156,  -156,   833,  -156,  1138,  -156,  -156,
      80,     1,   196,  -156,   269,  -156,  -156,  1017,  1138,   271,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  1138,  -156,  1138,  1138,  1138,  1138,  1138,  1138,  1138,
    1138,  1138,  1138,  1138,  1138,  1138,  1138,  1138,  1138,  1138,
    1138,  1138,  1138,  -156,  -156,   679,  -156,  -156,  1374,  1027,
    -156,   -17,  -156,    28,  -156,  1530,  -156,   272,  -156,  -156,
    -156,  -156,  -156,    11,  -156,  -156,    23,  -156,  1138,  -156,
     824,    81,  -156,   748,  -156,    87,    88,   202,  -156,   203,
    -156,  1389,   139,  -156,  1138,  -156,  -156,    96,  -156,   122,
    -156,  -156,  -156,  -156,  -156,   280,   280,   192,   192,   148,
     148,   148,   148,    49,    49,   186,   219,    97,   230,   168,
     -28,  -156,  -156,  -156,   204,   205,  -156,   200,    28,  1467,
    1069,  -156,  -156,  -156,   515,  -156,  -156,  -156,  1096,   748,
    -156,   748,   748,  1138,  -156,  -156,  -156,  1138,  -156,  1138,
    -156,  -156,  -156,  -156,   206,  -156,   208,  -156,  -156,   748,
     106,   285,  -156,  -156,   125,  -156,  -156,  -156,  -156,  -156,
     748,   748,   201,  -156,  -156,  -156
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    80,   143,    99,   101,    97,    96,   136,   107,     7,
      98,   100,   103,   104,   102,   132,   133,   111,   112,     0,
      91,    92,    93,    94,    95,     0,     0,   212,     0,    81,
      83,   105,     0,   106,    85,     0,   135,     0,     0,   208,
     211,   147,   145,   144,   127,     0,     0,     0,    78,     0,
      87,     0,    82,    84,   110,     0,    86,     0,   190,     0,
     216,     0,     0,     0,   134,     1,   209,   148,   146,     0,
     130,     0,   128,   137,     0,    79,     0,   214,     0,     0,
     117,     0,   113,     0,   119,    26,    27,    25,    24,     0,
       0,     0,     2,     4,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,     0,    28,    29,
     194,     8,     0,    18,    30,     0,    32,    36,    39,    42,
      47,    50,    52,    54,    56,    58,    60,    62,    75,     0,
     192,   177,   178,     0,     0,   179,   180,   181,   182,    89,
     191,   215,   156,   142,   155,     0,   149,   151,     0,     2,
     139,    30,    77,     0,     0,     0,     0,   125,    88,     0,
     172,    90,   213,     0,   116,   109,   114,     0,     0,   120,
     122,   118,   206,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   205,     0,    22,     0,    19,    20,
       0,   158,     0,     6,     0,    14,    15,     0,     0,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   195,   188,     0,   187,   193,     0,     0,
     153,   160,   154,   161,   140,     0,   141,     0,   138,   126,
     131,   129,   175,     0,   108,   123,     0,   115,     0,   207,
       0,     0,   183,     0,   185,     0,     0,     0,   203,     0,
       5,     0,   160,   159,     0,    13,    10,     0,    16,     0,
      12,    63,    33,    34,    35,    37,    38,    40,    41,    43,
      44,    45,    46,    48,    49,    51,    53,    55,    57,    59,
       0,    76,   189,   168,     0,     0,   164,     0,   162,     0,
       0,   150,   152,   157,     0,   173,   121,   124,     0,     0,
     184,     0,     0,     0,    23,    31,    11,     0,     9,     0,
     169,   163,   165,   170,     0,   166,     0,   174,   176,     0,
       0,   196,   198,   199,     0,    17,    61,   171,   167,   201,
       0,     0,     0,   202,   197,   200
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,   207,    68,  -156,  -156,   -60,  -156,  -101,    48,    75,
      65,    43,    89,    86,    92,    95,    93,  -156,   -56,   -61,
    -156,   -83,   -62,     6,     0,  -156,   258,  -156,   136,  -156,
    -156,   254,   -72,   -76,  -156,    78,  -156,   266,   180,   129,
      -9,   -35,    -1,  -156,   -57,  -156,    98,  -156,   152,  -131,
    -155,  -138,  -156,   -88,  -156,   143,    94,   209,  -154,  -156,
    -156,  -156,   313,    26,  -156
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   111,   112,   113,   277,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     211,   129,   153,    27,    59,    49,    50,    29,    30,    31,
      32,    81,    82,    83,   168,   169,    33,    71,    72,    34,
      35,    36,    37,    43,   304,   146,   147,   148,   192,   305,
     243,   161,   253,   130,   131,   132,    61,   134,   135,   136,
     137,   138,    38,    39,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    42,    64,   151,   164,   145,   173,   152,   171,   166,
       2,   181,     7,   242,   212,   160,    46,     2,     7,    51,
     260,   252,    69,    62,   190,    63,    28,    44,     2,    52,
      53,   191,     2,   177,    56,   151,     2,     7,    28,   152,
     155,    58,    68,   186,   188,   189,   237,    28,   230,     2,
     139,    54,     7,   220,   221,   151,     7,    58,   156,    70,
     273,   149,   144,    58,    66,   139,   157,   140,    26,     7,
      73,    15,    16,    66,   170,    93,    94,   232,     9,   156,
     231,   174,   329,   238,   140,   239,   308,   249,   262,    25,
     264,   166,   261,   250,    26,   151,   265,   266,   160,   152,
      79,   271,   190,   239,   190,   255,   318,   151,    25,   191,
      45,   152,   282,   283,   284,   279,   314,   308,   175,    48,
      74,   222,   223,    25,   315,   179,    75,   238,   309,   239,
     310,    41,   187,   167,    55,   240,   278,   246,   232,   140,
      25,   247,   180,   241,   233,    78,   256,   237,   300,   176,
     281,   133,   257,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   301,    67,   325,   232,   320,   338,   307,    60,   151,
     259,   270,   319,   152,    84,   232,   232,   178,   321,   322,
     272,    80,   232,   232,    77,   182,   317,   326,   151,   216,
     217,   327,   152,   200,   141,   227,    64,   350,    84,    84,
      84,   232,   183,    84,   151,    80,    80,    80,   218,   219,
      80,   162,   194,   195,   196,   328,   352,   232,   184,    46,
     232,   341,   226,   342,   343,   340,    84,   241,   144,   271,
     344,   239,   228,    80,   229,   144,    76,   170,   336,   245,
     151,   349,   334,   160,   152,   197,   248,   198,   244,   199,
     224,   225,   353,   354,   285,   286,   345,   293,   294,   151,
     272,   144,   258,   346,   263,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   289,   290,   291,   292,   213,
     214,   215,    84,   287,   288,   267,   268,   274,   275,    80,
     280,   313,   323,   332,   324,   330,   331,   347,   351,   144,
       1,   348,   355,   296,    84,   295,    85,    86,    87,   193,
     297,    80,    88,   299,   298,     3,     4,     5,     6,    89,
      90,    91,   158,   163,   316,   154,   251,   269,    92,    47,
       0,     0,   235,   312,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,     0,     0,    57,   106,     1,     0,     0,   107,
       0,     0,    85,    86,    87,   108,   109,     0,    88,     0,
     110,     3,     4,     5,     6,    89,    90,    91,     0,     0,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,     0,     0,
      57,   234,     1,     0,     0,   107,     0,    76,     0,     0,
       0,   108,   109,     0,     0,     0,   110,     3,     4,     5,
       6,     0,    85,    86,    87,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       0,    85,    86,    87,   149,     0,     8,    88,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    93,    94,
       0,     9,     0,   149,     0,     8,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    93,    94,     0,
       9,   103,     0,   104,   105,     0,     0,     0,     0,    20,
      21,    22,    23,    24,     0,     0,    57,     0,     0,     0,
     103,     0,   104,   105,     0,     0,   -89,     0,     0,     0,
       0,     0,   -89,     0,     0,   107,     0,    85,    86,    87,
       0,   108,   109,    88,     0,     0,     0,   159,   337,     0,
      89,    90,    91,   165,   107,     0,     0,     0,     0,    92,
     108,   109,     0,     0,     0,     0,   159,     0,     0,     0,
       0,     0,     0,    93,    94,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
       0,     0,     0,     0,     0,     0,    85,    86,    87,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,    89,
      90,    91,     0,     0,     0,    57,   236,     0,    92,     0,
     107,     0,     0,     0,     0,     0,   108,   109,     0,     0,
       0,   110,    93,    94,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,     0,     0,    85,    86,    87,     0,     0,
       0,    88,     0,     0,     0,    85,    86,    87,    89,    90,
      91,    88,     0,     0,    57,   302,     0,    92,     0,   107,
       0,     0,     0,     0,     0,   108,   109,   149,     0,     0,
     110,    93,    94,     0,     9,     0,     0,     0,     0,     0,
       0,    93,    94,     0,     9,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   104,   105,     0,     0,
       0,     0,     0,     0,   103,     0,   104,   105,     0,     0,
       0,    85,    86,    87,     0,     0,     0,    88,     0,     0,
      85,    86,    87,    57,     0,     0,    88,     0,   107,     3,
       4,     5,     6,   149,   108,   109,     0,     0,   107,   110,
       0,     0,   149,     0,   108,   109,     0,    93,    94,   172,
       9,     0,     0,     0,     0,     0,    93,    94,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     103,     0,   104,   105,     0,     0,    65,     1,     0,   103,
       0,   104,   105,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     7,     0,     0,     0,     0,
     108,   109,     0,   107,     0,   110,     0,     0,     0,   108,
     109,     8,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,  -210,     1,    85,    86,    87,     0,     0,
       0,    88,     2,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     0,     0,     0,     0,   149,     0,     0,
       0,     0,     7,     0,    20,    21,    22,    23,    24,     0,
       0,    93,    94,     0,     9,     0,    25,     0,     8,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,   103,     0,   104,   105,     0,     0,
       0,     0,     0,     0,    85,    86,    87,     0,     0,     0,
      88,     0,     0,     0,    85,    86,    87,     0,     0,     0,
      88,    20,    21,    22,    23,    24,   149,     0,   107,     0,
       0,   150,     0,    25,   108,   109,   149,     0,     0,     0,
      93,    94,     0,     9,     0,     0,     0,     0,     0,     0,
      93,    94,     0,     9,     0,     0,    85,    86,    87,     0,
       0,     0,    88,   103,     0,   104,   105,     0,     0,     0,
       0,     0,     0,   103,     0,   104,   105,     0,   149,     0,
       0,     0,     0,    85,    86,    87,     0,     0,     0,    88,
       0,     0,    93,    94,     0,     9,     0,   107,   276,     0,
       0,     0,     0,   108,   109,   149,     0,   107,     0,     0,
     306,     0,     0,   108,   109,   103,     0,   104,   105,    93,
      94,     0,     9,     0,     0,    85,    86,    87,     0,     0,
       0,    88,     0,     0,     0,    85,    86,    87,     0,     0,
       0,    88,   103,     0,   104,   105,     0,   149,     0,   107,
       0,     0,   335,     0,     0,   108,   109,   149,     0,     0,
       0,    93,    94,     0,     9,     0,     0,     0,     0,     0,
       0,    93,    94,     0,     9,     0,   107,   339,     0,     0,
       0,     0,   108,   109,   103,     0,   104,   105,     0,     0,
       0,     0,     0,     0,   103,     0,   104,   105,     0,     1,
      85,    86,    87,     0,     0,     0,    88,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,   107,     0,
       0,     0,   149,     0,   108,   109,     0,     7,   185,     0,
       0,     0,     0,     0,   108,   109,    93,    94,     0,     9,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,   103,
       0,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,    22,    23,
      24,     0,     0,   187,     3,     4,     5,     6,    25,   108,
     109,     8,     1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     3,     4,     5,
       6,     0,     0,     8,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,   254,
       3,     4,     5,     6,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     7,     0,     3,     4,     5,     6,    20,
      21,    22,    23,    24,     0,     0,    57,     0,     0,     8,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,     0,     0,     8,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,    22,    23,    24,     0,     0,     3,
       4,     5,     6,     0,   238,   303,   239,    20,    21,    22,
      23,    24,   142,     3,     4,     5,     6,     0,     0,   271,
     303,   239,     0,     0,     0,     0,     0,     0,     8,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     8,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,     3,     4,     5,     6,
       0,     0,     0,     0,   143,    20,    21,    22,    23,    24,
       3,     4,     5,     6,     0,     0,     0,     0,   333,     0,
       0,     0,     0,     0,     0,     8,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   311,     0,     8,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,    22,    23,    24
};

static const yytype_int16 yycheck[] =
{
       0,     2,    37,    63,    80,    62,    89,    63,    84,    81,
       9,    99,    29,   144,   115,    76,    25,     9,    29,    28,
     174,   159,   112,   100,   107,   102,    26,    29,     9,    29,
      30,   107,     9,    95,    34,    95,     9,    29,    38,    95,
       6,    35,    43,   103,   104,   105,   134,    47,    77,     9,
      59,    29,    29,     4,     5,   115,    29,    51,   105,    29,
     191,    29,    62,    57,    38,    74,   113,    61,     0,    29,
     101,    52,    53,    47,    83,    43,    44,   105,    46,   105,
     109,   100,   110,   100,    78,   102,   241,   113,   176,   100,
     178,   163,   175,   155,    26,   155,   179,   180,   159,   155,
     112,   100,   185,   102,   187,   167,   260,   167,   100,   185,
     112,   167,   213,   214,   215,   198,   105,   272,   100,   111,
     105,    72,    73,   100,   113,   100,   111,   100,   100,   102,
     102,     2,   100,   110,   112,   144,   197,   101,   105,   133,
     100,   105,   100,   144,   111,    51,   105,   235,   231,   110,
     211,    57,   111,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   232,    43,   274,   105,   263,   314,   239,    35,   239,
     111,   101,   101,   239,    55,   105,   105,   110,   101,   101,
     191,    55,   105,   105,    51,    29,   258,   101,   258,     7,
       8,   105,   258,     6,    61,   108,   241,   101,    79,    80,
      81,   105,   111,    84,   274,    79,    80,    81,    70,    71,
      84,    78,    67,    68,    69,   103,   101,   105,   111,   238,
     105,   319,    13,   321,   322,   318,   107,   238,   238,   100,
     323,   102,    12,   107,    76,   245,     6,   256,   310,   105,
     310,   339,   309,   314,   310,   100,   103,   102,   101,   104,
      74,    75,   350,   351,   216,   217,   327,   224,   225,   329,
     271,   271,   110,   329,   110,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,   220,   221,   222,   223,     9,
      10,    11,   163,   218,   219,    61,   111,   101,    29,   163,
      29,    29,   100,   103,   101,   101,   101,   101,    23,   309,
       1,   103,   111,   227,   185,   226,     7,     8,     9,   112,
     228,   185,    13,   230,   229,    16,    17,    18,    19,    20,
      21,    22,    74,    79,   256,    69,   156,   185,    29,    26,
      -1,    -1,   133,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    -1,    -1,    95,    96,     1,    -1,    -1,   100,
      -1,    -1,     7,     8,     9,   106,   107,    -1,    13,    -1,
     111,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    -1,    -1,
      95,    96,     1,    -1,    -1,   100,    -1,     6,    -1,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,    16,    17,    18,
      19,    -1,     7,     8,     9,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      -1,     7,     8,     9,    29,    -1,    45,    13,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    43,    44,
      -1,    46,    -1,    29,    -1,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    43,    44,    -1,
      46,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    -1,    -1,    95,    -1,    -1,    -1,
      66,    -1,    68,    69,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,   100,    -1,     7,     8,     9,
      -1,   106,   107,    13,    -1,    -1,    -1,   112,   113,    -1,
      20,    21,    22,   113,   100,    -1,    -1,    -1,    -1,    29,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    95,    96,    -1,    29,    -1,
     100,    -1,    -1,    -1,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,    43,    44,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,
      -1,    13,    -1,    -1,    -1,     7,     8,     9,    20,    21,
      22,    13,    -1,    -1,    95,    96,    -1,    29,    -1,   100,
      -1,    -1,    -1,    -1,    -1,   106,   107,    29,    -1,    -1,
     111,    43,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    46,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    -1,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    13,    -1,    -1,
       7,     8,     9,    95,    -1,    -1,    13,    -1,   100,    16,
      17,    18,    19,    29,   106,   107,    -1,    -1,   100,   111,
      -1,    -1,    29,    -1,   106,   107,    -1,    43,    44,   111,
      46,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      66,    -1,    68,    69,    -1,    -1,     0,     1,    -1,    66,
      -1,    68,    69,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,    29,    -1,    -1,    -1,    -1,
     106,   107,    -1,   100,    -1,   111,    -1,    -1,    -1,   106,
     107,    45,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     1,     7,     8,     9,    -1,    -1,
      -1,    13,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    29,    -1,    88,    89,    90,    91,    92,    -1,
      -1,    43,    44,    -1,    46,    -1,   100,    -1,    45,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
      13,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
      13,    88,    89,    90,    91,    92,    29,    -1,   100,    -1,
      -1,   103,    -1,   100,   106,   107,    29,    -1,    -1,    -1,
      43,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    46,    -1,    -1,     7,     8,     9,    -1,
      -1,    -1,    13,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    68,    69,    -1,    29,    -1,
      -1,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,    13,
      -1,    -1,    43,    44,    -1,    46,    -1,   100,   101,    -1,
      -1,    -1,    -1,   106,   107,    29,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,   107,    66,    -1,    68,    69,    43,
      44,    -1,    46,    -1,    -1,     7,     8,     9,    -1,    -1,
      -1,    13,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,
      -1,    13,    66,    -1,    68,    69,    -1,    29,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,   107,    29,    -1,    -1,
      -1,    43,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    46,    -1,   100,   101,    -1,    -1,
      -1,    -1,   106,   107,    66,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    -1,     1,
       7,     8,     9,    -1,    -1,    -1,    13,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,   100,    -1,
      -1,    -1,    29,    -1,   106,   107,    -1,    29,   100,    -1,
      -1,    -1,    -1,    -1,   106,   107,    43,    44,    -1,    46,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    66,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    -1,    -1,   100,    16,    17,    18,    19,   100,   106,
     107,    45,     1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    -1,    -1,    45,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,   113,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    29,    -1,    16,    17,    18,    19,    88,
      89,    90,    91,    92,    -1,    -1,    95,    -1,    -1,    45,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    45,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    -1,    -1,    16,
      17,    18,    19,    -1,   100,   101,   102,    88,    89,    90,
      91,    92,    29,    16,    17,    18,    19,    -1,    -1,   100,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    45,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,   101,    88,    89,    90,    91,    92,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    45,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    16,    17,    18,    19,    29,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      88,    89,    90,    91,    92,   100,   116,   137,   138,   141,
     142,   143,   144,   150,   153,   154,   155,   156,   176,   177,
     178,   153,   156,   157,    29,   112,   154,   176,   111,   139,
     140,   154,   138,   138,    29,   112,   138,    95,   137,   138,
     169,   170,   100,   102,   155,     0,   177,   153,   156,   112,
      29,   151,   152,   101,   105,   111,     6,   169,   170,   112,
     142,   145,   146,   147,   153,     7,     8,     9,    13,    20,
      21,    22,    29,    43,    44,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    68,    69,    96,   100,   106,   107,
     111,   115,   116,   117,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   135,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   154,
     137,   169,    29,   101,   138,   158,   159,   160,   161,    29,
     103,   119,   132,   136,   151,     6,   105,   113,   140,   112,
     133,   165,   169,   145,   147,   113,   146,   110,   148,   149,
     154,   147,   111,   135,   100,   100,   110,   136,   110,   100,
     100,   167,    29,   111,   111,   100,   119,   100,   119,   119,
     135,   147,   162,   115,    67,    68,    69,   100,   102,   104,
       6,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   134,   121,     9,    10,    11,     7,     8,    70,    71,
       4,     5,    72,    73,    74,    75,    13,   108,    12,    76,
      77,   109,   105,   111,    96,   171,    96,   167,   100,   102,
     154,   156,   163,   164,   101,   105,   101,   105,   103,   113,
     136,   152,   165,   166,   113,   136,   105,   111,   110,   111,
     172,   135,   167,   110,   167,   135,   135,    61,   111,   162,
     101,   100,   156,   163,   101,    29,   101,   118,   133,   135,
      29,   133,   121,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   124,   125,   125,   126,   127,   128,   129,   130,
     135,   133,    96,   101,   158,   163,   103,   136,   164,   100,
     102,    57,   160,    29,   105,   113,   149,   136,   172,   101,
     167,   101,   101,   100,   101,   121,   101,   105,   103,   110,
     101,   101,   103,   101,   158,   103,   136,   113,   165,   101,
     135,   167,   167,   167,   135,   133,   132,   101,   103,   167,
     101,    23,   101,   167,   167,   111
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   114,   115,   115,   115,   115,   115,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   119,   120,   120,   120,   120,   120,   120,
     121,   121,   122,   122,   122,   122,   123,   123,   123,   124,
     124,   124,   125,   125,   125,   125,   125,   126,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   136,   137,   137,
     137,   138,   138,   138,   138,   138,   138,   139,   139,   140,
     140,   141,   141,   141,   141,   141,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   143,   143,
     143,   144,   144,   145,   145,   146,   147,   147,   147,   147,
     148,   148,   149,   149,   149,   150,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   155,   155,
     155,   155,   155,   156,   156,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   160,   161,   161,   162,   162,
     163,   163,   163,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   165,   165,   165,   166,   166,   167,   167,   167,
     167,   167,   167,   168,   168,   168,   169,   169,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   173,   174,
     174,   174,   174,   175,   175,   175,   175,   175,   176,   176,
     176,   177,   177,   178,   178,   178,   178
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     2,     1,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     1,     2,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       2,     1,     1,     1,     2,     3,     2,     1,     2,     1,
       1,     3,     1,     2,     3,     4,     5,     2,     1,     3,
       1,     3,     1,     1,     2,     1,     1,     3,     4,     3,
       4,     4,     3,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     3,     3,     4,
       1,     2,     1,     2,     1,     2,     5,     7,     5,     5,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       2,     1,     1,     4,     3,     3,     2
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     5,
       7,     9,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
      17,    19,    21,    23,    25,    27,    29,    31,    33,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    39,    41,    43,    45,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   210,     0,   210,     0,   210,     0,   210,     0,   210,
       0,   210,     0,   210,     0,   210,     0,   210,     0,   210,
       0,   210,     0,   210,     0,   210,     0,   210,     0,   210,
       0,   210,     0,   210,     0,   210,     0,   210,     0,   210,
       0,   210,     0,   210,     0,   210,     0,   210,     0
};



YYSTYPE yylval;

int yynerrs;
int yychar;

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NO_ELSE", "'<'",
  "'>'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", "PRINTFF",
  "SCANFF", "INT", "FLOAT", "CHAR", "VOID", "RETURN", "FOR", "IF", "ELSE",
  "INCLUDE", "TRUE", "FALSE", "NUMBER", "FLOAT_NUM", "IDENTIFIER", "UNARY",
  "LE", "GE", "EQ", "NE", "GT", "LT", "AND", "OR", "ADD", "SUBTRACT",
  "DIVIDE", "MULTIPLY", "STRING_LITERAL", "CONSTANT", "TYPE_NAME", "DEF",
  "SHORT", "LONG", "SIGNED", "UNSIGNED", "DOUBLE", "CONST", "VOLATILE",
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "SWITCH",
  "WHILE", "DO", "GOTO", "CONTINUE", "BREAK", "SIZEOF", "PTR_OP", "INC_OP",
  "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMA",
  "ASSIGN", "'('", "')'", "'['", "']'", "'.'", "','", "'~'", "'!'", "'^'",
  "'?'", "':'", "';'", "'{'", "'}'", "$accept", "primary_expression",
  "Define", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)





/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule));
  switch (yyrule)
    {
  case 2: /* primary_expression: IDENTIFIER  */
#line 80 "parser.y"
        { ((*yyvalp).node) = create_node("Identifier", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL); }
#line 1987 "y.tab.c"
    break;

  case 3: /* primary_expression: CONSTANT  */
#line 82 "parser.y"
        { ((*yyvalp).node) = create_node("Constant", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL); }
#line 1993 "y.tab.c"
    break;

  case 4: /* primary_expression: STRING_LITERAL  */
#line 84 "parser.y"
        { ((*yyvalp).node) = create_node("StringLiteral", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL); }
#line 1999 "y.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 86 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node); }
#line 2005 "y.tab.c"
    break;

  case 6: /* primary_expression: Define primary_expression  */
#line 88 "parser.y"
        { ((*yyvalp).node) = create_node("Define", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2011 "y.tab.c"
    break;

  case 7: /* Define: DEF  */
#line 94 "parser.y"
        { ((*yyvalp).node) = create_node("DefKeyword", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL); }
#line 2017 "y.tab.c"
    break;

  case 8: /* postfix_expression: primary_expression  */
#line 100 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node); }
#line 2023 "y.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 102 "parser.y"
        { ((*yyvalp).node) = create_node("ArrayAccess", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL); }
#line 2029 "y.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression '(' ')'  */
#line 104 "parser.y"
        { ((*yyvalp).node) = create_node("FuncCall", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2035 "y.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 106 "parser.y"
        { ((*yyvalp).node) = create_node("FuncCall", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL); }
#line 2041 "y.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 108 "parser.y"
        { ((*yyvalp).node) = create_node("MemberAccess", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2047 "y.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 110 "parser.y"
        { ((*yyvalp).node) = create_node("PtrMemberAccess", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2053 "y.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression INC_OP  */
#line 112 "parser.y"
        { ((*yyvalp).node) = create_node("PostInc", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2059 "y.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression DEC_OP  */
#line 114 "parser.y"
        { ((*yyvalp).node) = create_node("PostDec", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2065 "y.tab.c"
    break;

  case 16: /* argument_expression_list: assignment_expression  */
#line 120 "parser.y"
        { ((*yyvalp).node) = create_node("ArgList", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2071 "y.tab.c"
    break;

  case 17: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 122 "parser.y"
        {
            ASTNode *argNode = create_node("ArgList", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
            ((*yyvalp).node) = argNode;
        }
#line 2080 "y.tab.c"
    break;

  case 18: /* unary_expression: postfix_expression  */
#line 131 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node); }
#line 2086 "y.tab.c"
    break;

  case 19: /* unary_expression: INC_OP unary_expression  */
#line 133 "parser.y"
        { ((*yyvalp).node) = create_node("PreInc", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2092 "y.tab.c"
    break;

  case 20: /* unary_expression: DEC_OP unary_expression  */
#line 135 "parser.y"
        { ((*yyvalp).node) = create_node("PreDec", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2098 "y.tab.c"
    break;

  case 21: /* unary_expression: unary_operator cast_expression  */
#line 137 "parser.y"
        { ((*yyvalp).node) = create_node("UnaryOp", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2104 "y.tab.c"
    break;

  case 22: /* unary_expression: SIZEOF unary_expression  */
#line 139 "parser.y"
        { ((*yyvalp).node) = create_node("SizeOfExpr", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2110 "y.tab.c"
    break;

  case 23: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 141 "parser.y"
        { ((*yyvalp).node) = create_node("SizeOfType", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL); }
#line 2116 "y.tab.c"
    break;

  case 24: /* unary_operator: '&'  */
#line 146 "parser.y"
          { ((*yyvalp).node) = create_node("Operator", "&", NULL, NULL, NULL); }
#line 2122 "y.tab.c"
    break;

  case 25: /* unary_operator: '*'  */
#line 147 "parser.y"
          { ((*yyvalp).node) = create_node("Operator", "*", NULL, NULL, NULL); }
#line 2128 "y.tab.c"
    break;

  case 26: /* unary_operator: '+'  */
#line 148 "parser.y"
          { ((*yyvalp).node) = create_node("Operator", "+", NULL, NULL, NULL); }
#line 2134 "y.tab.c"
    break;

  case 27: /* unary_operator: '-'  */
#line 149 "parser.y"
          { ((*yyvalp).node) = create_node("Operator", "-", NULL, NULL, NULL); }
#line 2140 "y.tab.c"
    break;

  case 28: /* unary_operator: '~'  */
#line 150 "parser.y"
          { ((*yyvalp).node) = create_node("Operator", "~", NULL, NULL, NULL); }
#line 2146 "y.tab.c"
    break;

  case 29: /* unary_operator: '!'  */
#line 151 "parser.y"
          { ((*yyvalp).node) = create_node("Operator", "!", NULL, NULL, NULL); }
#line 2152 "y.tab.c"
    break;

  case 30: /* cast_expression: unary_expression  */
#line 157 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2160 "y.tab.c"
    break;

  case 31: /* cast_expression: '(' type_name ')' cast_expression  */
#line 161 "parser.y"
        {
            ((*yyvalp).node) = create_node("CAST", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2168 "y.tab.c"
    break;

  case 32: /* multiplicative_expression: cast_expression  */
#line 168 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2176 "y.tab.c"
    break;

  case 33: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 172 "parser.y"
        {
            ((*yyvalp).node) = create_node("MUL", "*", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2184 "y.tab.c"
    break;

  case 34: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 176 "parser.y"
        {
            ((*yyvalp).node) = create_node("DIV", "/", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2192 "y.tab.c"
    break;

  case 35: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 180 "parser.y"
        {
            ((*yyvalp).node) = create_node("MOD", "%", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2200 "y.tab.c"
    break;

  case 36: /* additive_expression: multiplicative_expression  */
#line 187 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2208 "y.tab.c"
    break;

  case 37: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 191 "parser.y"
        {
            ((*yyvalp).node) = create_node("ADD", "+", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2216 "y.tab.c"
    break;

  case 38: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 195 "parser.y"
        {
            ((*yyvalp).node) = create_node("SUB", "-", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2224 "y.tab.c"
    break;

  case 39: /* shift_expression: additive_expression  */
#line 202 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2232 "y.tab.c"
    break;

  case 40: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 206 "parser.y"
        {
            ((*yyvalp).node) = create_node("SHL", "<<", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2240 "y.tab.c"
    break;

  case 41: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 210 "parser.y"
        {
            ((*yyvalp).node) = create_node("SHR", ">>", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2248 "y.tab.c"
    break;

  case 42: /* relational_expression: shift_expression  */
#line 217 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2256 "y.tab.c"
    break;

  case 43: /* relational_expression: relational_expression '<' shift_expression  */
#line 221 "parser.y"
        {
            ((*yyvalp).node) = create_node("LT", "<", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2264 "y.tab.c"
    break;

  case 44: /* relational_expression: relational_expression '>' shift_expression  */
#line 225 "parser.y"
        {
            ((*yyvalp).node) = create_node("GT", ">", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2272 "y.tab.c"
    break;

  case 45: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 229 "parser.y"
        {
            ((*yyvalp).node) = create_node("LE", "<=", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2280 "y.tab.c"
    break;

  case 46: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 233 "parser.y"
        {
            ((*yyvalp).node) = create_node("GE", ">=", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2288 "y.tab.c"
    break;

  case 47: /* equality_expression: relational_expression  */
#line 240 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2296 "y.tab.c"
    break;

  case 48: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 244 "parser.y"
        {
            ((*yyvalp).node) = create_node("EQ", "==", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2304 "y.tab.c"
    break;

  case 49: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 248 "parser.y"
        {
            ((*yyvalp).node) = create_node("NE", "!=", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2312 "y.tab.c"
    break;

  case 50: /* and_expression: equality_expression  */
#line 256 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2320 "y.tab.c"
    break;

  case 51: /* and_expression: and_expression '&' equality_expression  */
#line 260 "parser.y"
        {
            ((*yyvalp).node) = create_node("AND_BITWISE", "&", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2328 "y.tab.c"
    break;

  case 52: /* exclusive_or_expression: and_expression  */
#line 267 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2336 "y.tab.c"
    break;

  case 53: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 271 "parser.y"
        {
            ((*yyvalp).node) = create_node("XOR_BITWISE", "^", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2344 "y.tab.c"
    break;

  case 54: /* inclusive_or_expression: exclusive_or_expression  */
#line 278 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2352 "y.tab.c"
    break;

  case 55: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 282 "parser.y"
        {
            ((*yyvalp).node) = create_node("OR_BITWISE", "|", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2360 "y.tab.c"
    break;

  case 56: /* logical_and_expression: inclusive_or_expression  */
#line 289 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2368 "y.tab.c"
    break;

  case 57: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 293 "parser.y"
        {
            ((*yyvalp).node) = create_node("AND_LOGICAL", "&&", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2376 "y.tab.c"
    break;

  case 58: /* logical_or_expression: logical_and_expression  */
#line 300 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2384 "y.tab.c"
    break;

  case 59: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 304 "parser.y"
        {
            ((*yyvalp).node) = create_node("OR_LOGICAL", "||", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2392 "y.tab.c"
    break;

  case 60: /* conditional_expression: logical_or_expression  */
#line 311 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2400 "y.tab.c"
    break;

  case 61: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 315 "parser.y"
        {
            // Ternary ?: node — left = condition, right = true_expr, third = false_expr
            ASTNode *node = create_node("COND", "?:", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node));
            ((*yyvalp).node) = node;
        }
#line 2410 "y.tab.c"
    break;

  case 62: /* assignment_expression: conditional_expression  */
#line 324 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2418 "y.tab.c"
    break;

  case 63: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 328 "parser.y"
        {
            // Assignment node: left = unary_expression (lvalue), right = assigned expr, value = operator
            ((*yyvalp).node) = create_node("ASSIGN", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2427 "y.tab.c"
    break;

  case 64: /* assignment_operator: '='  */
#line 335 "parser.y"
          { ((*yyvalp).node) = create_node("ASSIGN_OP", "=", NULL, NULL, NULL); }
#line 2433 "y.tab.c"
    break;

  case 65: /* assignment_operator: MUL_ASSIGN  */
#line 336 "parser.y"
                 { ((*yyvalp).node) = create_node("ASSIGN_OP", "*=", NULL, NULL, NULL); }
#line 2439 "y.tab.c"
    break;

  case 66: /* assignment_operator: DIV_ASSIGN  */
#line 337 "parser.y"
                 { ((*yyvalp).node) = create_node("ASSIGN_OP", "/=", NULL, NULL, NULL); }
#line 2445 "y.tab.c"
    break;

  case 67: /* assignment_operator: MOD_ASSIGN  */
#line 338 "parser.y"
                 { ((*yyvalp).node) = create_node("ASSIGN_OP", "%=", NULL, NULL, NULL); }
#line 2451 "y.tab.c"
    break;

  case 68: /* assignment_operator: ADD_ASSIGN  */
#line 339 "parser.y"
                 { ((*yyvalp).node) = create_node("ASSIGN_OP", "+=", NULL, NULL, NULL); }
#line 2457 "y.tab.c"
    break;

  case 69: /* assignment_operator: SUB_ASSIGN  */
#line 340 "parser.y"
                 { ((*yyvalp).node) = create_node("ASSIGN_OP", "-=", NULL, NULL, NULL); }
#line 2463 "y.tab.c"
    break;

  case 70: /* assignment_operator: LEFT_ASSIGN  */
#line 341 "parser.y"
                  { ((*yyvalp).node) = create_node("ASSIGN_OP", "<<=", NULL, NULL, NULL); }
#line 2469 "y.tab.c"
    break;

  case 71: /* assignment_operator: RIGHT_ASSIGN  */
#line 342 "parser.y"
                   { ((*yyvalp).node) = create_node("ASSIGN_OP", ">>=", NULL, NULL, NULL); }
#line 2475 "y.tab.c"
    break;

  case 72: /* assignment_operator: AND_ASSIGN  */
#line 343 "parser.y"
                 { ((*yyvalp).node) = create_node("ASSIGN_OP", "&=", NULL, NULL, NULL); }
#line 2481 "y.tab.c"
    break;

  case 73: /* assignment_operator: XOR_ASSIGN  */
#line 344 "parser.y"
                 { ((*yyvalp).node) = create_node("ASSIGN_OP", "^=", NULL, NULL, NULL); }
#line 2487 "y.tab.c"
    break;

  case 74: /* assignment_operator: OR_ASSIGN  */
#line 345 "parser.y"
                { ((*yyvalp).node) = create_node("ASSIGN_OP", "|=", NULL, NULL, NULL); }
#line 2493 "y.tab.c"
    break;

  case 75: /* expression: assignment_expression  */
#line 350 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2501 "y.tab.c"
    break;

  case 76: /* expression: expression ',' assignment_expression  */
#line 354 "parser.y"
        {
            // Comma operator node: left = first expr, right = second expr
            ((*yyvalp).node) = create_node("COMMA", ",", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2510 "y.tab.c"
    break;

  case 77: /* constant_expression: conditional_expression  */
#line 362 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2518 "y.tab.c"
    break;

  case 78: /* declaration: declaration_specifiers ';'  */
#line 369 "parser.y"
        {
            // For now, create a node for declaration specifiers only
            ((*yyvalp).node) = create_node("DECLARATION", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 2527 "y.tab.c"
    break;

  case 79: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 374 "parser.y"
        {
            // Combine decl specifiers and init declarator list - you may want to build a list here
            ((*yyvalp).node) = create_node("DECLARATION", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL); 
        }
#line 2536 "y.tab.c"
    break;

  case 80: /* declaration: error  */
#line 379 "parser.y"
        {
            // Error node - optionally handle parse errors gracefully
            ((*yyvalp).node) = create_node("ERROR", "declaration error", NULL, NULL, NULL);
            //yyerrok();
        }
#line 2546 "y.tab.c"
    break;

  case 81: /* declaration_specifiers: storage_class_specifier  */
#line 388 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2554 "y.tab.c"
    break;

  case 82: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 392 "parser.y"
        {
            // Chain or list - left = current, right = rest
            ((*yyvalp).node) = create_node("DECL_SPEC", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2563 "y.tab.c"
    break;

  case 83: /* declaration_specifiers: type_specifier  */
#line 397 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2571 "y.tab.c"
    break;

  case 84: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 401 "parser.y"
        {
            ((*yyvalp).node) = create_node("DECL_SPEC", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2579 "y.tab.c"
    break;

  case 85: /* declaration_specifiers: type_qualifier  */
#line 405 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2587 "y.tab.c"
    break;

  case 86: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 409 "parser.y"
        {
            ((*yyvalp).node) = create_node("DECL_SPEC", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2595 "y.tab.c"
    break;

  case 87: /* init_declarator_list: init_declarator  */
#line 416 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2603 "y.tab.c"
    break;

  case 88: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 420 "parser.y"
        {
            // Chain list: left = existing list, right = new init_declarator
            ((*yyvalp).node) = create_node("INIT_DECL_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2612 "y.tab.c"
    break;

  case 89: /* init_declarator: declarator  */
#line 428 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node); }
#line 2618 "y.tab.c"
    break;

  case 90: /* init_declarator: declarator '=' initializer  */
#line 430 "parser.y"
        { ((*yyvalp).node) = create_node("InitDeclarator", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL); }
#line 2624 "y.tab.c"
    break;

  case 91: /* storage_class_specifier: TYPEDEF  */
#line 435 "parser.y"
        {
            ((*yyvalp).node) = create_node("STORAGE_CLASS", "typedef", NULL, NULL, NULL);
        }
#line 2632 "y.tab.c"
    break;

  case 92: /* storage_class_specifier: EXTERN  */
#line 439 "parser.y"
        {
            ((*yyvalp).node) = create_node("STORAGE_CLASS", "extern", NULL, NULL, NULL);
        }
#line 2640 "y.tab.c"
    break;

  case 93: /* storage_class_specifier: STATIC  */
#line 443 "parser.y"
        {
            ((*yyvalp).node) = create_node("STORAGE_CLASS", "static", NULL, NULL, NULL);
        }
#line 2648 "y.tab.c"
    break;

  case 94: /* storage_class_specifier: AUTO  */
#line 447 "parser.y"
        {
            ((*yyvalp).node) = create_node("STORAGE_CLASS", "auto", NULL, NULL, NULL);
        }
#line 2656 "y.tab.c"
    break;

  case 95: /* storage_class_specifier: REGISTER  */
#line 451 "parser.y"
        {
            ((*yyvalp).node) = create_node("STORAGE_CLASS", "register", NULL, NULL, NULL);
        }
#line 2664 "y.tab.c"
    break;

  case 96: /* type_specifier: VOID  */
#line 458 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", "void", NULL, NULL, NULL);
        }
#line 2672 "y.tab.c"
    break;

  case 97: /* type_specifier: CHAR  */
#line 462 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", "char", NULL, NULL, NULL);
        }
#line 2680 "y.tab.c"
    break;

  case 98: /* type_specifier: SHORT  */
#line 466 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", "short", NULL, NULL, NULL);
        }
#line 2688 "y.tab.c"
    break;

  case 99: /* type_specifier: INT  */
#line 470 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", "int", NULL, NULL, NULL);
        }
#line 2696 "y.tab.c"
    break;

  case 100: /* type_specifier: LONG  */
#line 474 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", "long", NULL, NULL, NULL);
        }
#line 2704 "y.tab.c"
    break;

  case 101: /* type_specifier: FLOAT  */
#line 478 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", "float", NULL, NULL, NULL);
        }
#line 2712 "y.tab.c"
    break;

  case 102: /* type_specifier: DOUBLE  */
#line 482 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", "double", NULL, NULL, NULL);
        }
#line 2720 "y.tab.c"
    break;

  case 103: /* type_specifier: SIGNED  */
#line 486 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", "signed", NULL, NULL, NULL);
        }
#line 2728 "y.tab.c"
    break;

  case 104: /* type_specifier: UNSIGNED  */
#line 490 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", "unsigned", NULL, NULL, NULL);
        }
#line 2736 "y.tab.c"
    break;

  case 105: /* type_specifier: struct_or_union_specifier  */
#line 494 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2744 "y.tab.c"
    break;

  case 106: /* type_specifier: enum_specifier  */
#line 498 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2752 "y.tab.c"
    break;

  case 107: /* type_specifier: TYPE_NAME  */
#line 502 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_SPEC", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
        }
#line 2760 "y.tab.c"
    break;

  case 108: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 509 "parser.y"
        {
            // Node for struct/union with name and declarations list
            // left = struct_or_union (type), right = identifier, third = decl list
            ASTNode *idNode = create_node("IDENTIFIER", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
            ((*yyvalp).node) = create_node("STRUCT_OR_UNION_SPEC", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.node), idNode, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node));
        }
#line 2771 "y.tab.c"
    break;

  case 109: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 516 "parser.y"
        {
            // Anonymous struct/union with declarations
            ((*yyvalp).node) = create_node("STRUCT_OR_UNION_SPEC", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node));
        }
#line 2780 "y.tab.c"
    break;

  case 110: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 521 "parser.y"
        {
            // Forward declaration or incomplete struct/union with just a name
            ASTNode *idNode = create_node("IDENTIFIER", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
            ((*yyvalp).node) = create_node("STRUCT_OR_UNION_SPEC", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), idNode, NULL);
        }
#line 2790 "y.tab.c"
    break;

  case 111: /* struct_or_union: STRUCT  */
#line 530 "parser.y"
        {
            ((*yyvalp).node) = create_node("STRUCT_OR_UNION", "struct", NULL, NULL, NULL);
        }
#line 2798 "y.tab.c"
    break;

  case 112: /* struct_or_union: UNION  */
#line 534 "parser.y"
        {
            ((*yyvalp).node) = create_node("STRUCT_OR_UNION", "union", NULL, NULL, NULL);
        }
#line 2806 "y.tab.c"
    break;

  case 113: /* struct_declaration_list: struct_declaration  */
#line 541 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2814 "y.tab.c"
    break;

  case 114: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 545 "parser.y"
        {
            // Chain declarations in a list: left = previous, right = new
            ((*yyvalp).node) = create_node("STRUCT_DECL_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2823 "y.tab.c"
    break;

  case 115: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 553 "parser.y"
        {
            // A struct declaration node: left = specifier_qualifier_list, right = declarator list
            ((*yyvalp).node) = create_node("STRUCT_DECLARATION", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2832 "y.tab.c"
    break;

  case 116: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 561 "parser.y"
        {
            // Chain type_specifiers and qualifiers: left = current, right = rest
            ((*yyvalp).node) = create_node("SPEC_QUAL_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2841 "y.tab.c"
    break;

  case 117: /* specifier_qualifier_list: type_specifier  */
#line 566 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2849 "y.tab.c"
    break;

  case 118: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 570 "parser.y"
        {
            ((*yyvalp).node) = create_node("SPEC_QUAL_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2857 "y.tab.c"
    break;

  case 119: /* specifier_qualifier_list: type_qualifier  */
#line 574 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2865 "y.tab.c"
    break;

  case 120: /* struct_declarator_list: struct_declarator  */
#line 581 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2873 "y.tab.c"
    break;

  case 121: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 585 "parser.y"
        {
            // Chain struct declarators in a list
            ((*yyvalp).node) = create_node("STRUCT_DECLARATOR_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2882 "y.tab.c"
    break;

  case 122: /* struct_declarator: declarator  */
#line 593 "parser.y"
        {
            ((*yyvalp).node) = create_node("STRUCT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 2890 "y.tab.c"
    break;

  case 123: /* struct_declarator: ':' constant_expression  */
#line 597 "parser.y"
        {
            // Bit-field without declarator (anonymous?)
            ((*yyvalp).node) = create_node("BIT_FIELD", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 2899 "y.tab.c"
    break;

  case 124: /* struct_declarator: declarator ':' constant_expression  */
#line 602 "parser.y"
        {
            // Bit-field with declarator: left=declarator, right=bit-width expression
            ((*yyvalp).node) = create_node("BIT_FIELD", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2908 "y.tab.c"
    break;

  case 125: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 610 "parser.y"
        {
            // Enum with enumerators, no name
            ((*yyvalp).node) = create_node("ENUM_SPEC", NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2917 "y.tab.c"
    break;

  case 126: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 615 "parser.y"
        {
            ASTNode *idNode = create_node("IDENTIFIER", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
            ((*yyvalp).node) = create_node("ENUM_SPEC", NULL, idNode, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2926 "y.tab.c"
    break;

  case 127: /* enum_specifier: ENUM IDENTIFIER  */
#line 620 "parser.y"
        {
            ASTNode *idNode = create_node("IDENTIFIER", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
            ((*yyvalp).node) = create_node("ENUM_SPEC", NULL, idNode, NULL, NULL);
        }
#line 2935 "y.tab.c"
    break;

  case 128: /* enumerator_list: enumerator  */
#line 628 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 2943 "y.tab.c"
    break;

  case 129: /* enumerator_list: enumerator_list ',' enumerator  */
#line 632 "parser.y"
        {
            ((*yyvalp).node) = create_node("ENUMERATOR_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2951 "y.tab.c"
    break;

  case 130: /* enumerator: IDENTIFIER  */
#line 639 "parser.y"
        {
            ((*yyvalp).node) = create_node("ENUMERATOR", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
        }
#line 2959 "y.tab.c"
    break;

  case 131: /* enumerator: IDENTIFIER '=' constant_expression  */
#line 643 "parser.y"
        {
            ((*yyvalp).node) = create_node("ENUMERATOR", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.strval), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2967 "y.tab.c"
    break;

  case 132: /* type_qualifier: CONST  */
#line 650 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_QUALIFIER", "const", NULL, NULL, NULL);
        }
#line 2975 "y.tab.c"
    break;

  case 133: /* type_qualifier: VOLATILE  */
#line 654 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_QUALIFIER", "volatile", NULL, NULL, NULL);
        }
#line 2983 "y.tab.c"
    break;

  case 134: /* declarator: pointer direct_declarator  */
#line 661 "parser.y"
        {
            ((*yyvalp).node) = create_node("DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 2991 "y.tab.c"
    break;

  case 135: /* declarator: direct_declarator  */
#line 665 "parser.y"
        {
            ((*yyvalp).node) = create_node("DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 2999 "y.tab.c"
    break;

  case 136: /* direct_declarator: IDENTIFIER  */
#line 673 "parser.y"
        {
            ((*yyvalp).node) = create_node("DIRECT_DECLARATOR", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
        }
#line 3007 "y.tab.c"
    break;

  case 137: /* direct_declarator: '(' declarator ')'  */
#line 677 "parser.y"
        {
            ((*yyvalp).node) = create_node("DIRECT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3015 "y.tab.c"
    break;

  case 138: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 681 "parser.y"
        {
            // Array declarator with size
            ((*yyvalp).node) = create_node("ARRAY_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3024 "y.tab.c"
    break;

  case 139: /* direct_declarator: direct_declarator '[' ']'  */
#line 686 "parser.y"
        {
            // Array declarator without size
            ((*yyvalp).node) = create_node("ARRAY_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3033 "y.tab.c"
    break;

  case 140: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 691 "parser.y"
        {
            ((*yyvalp).node) = create_node("FUNCTION_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3041 "y.tab.c"
    break;

  case 141: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 695 "parser.y"
        {
            ((*yyvalp).node) = create_node("FUNCTION_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3049 "y.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator '(' ')'  */
#line 699 "parser.y"
        {
            ((*yyvalp).node) = create_node("FUNCTION_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3057 "y.tab.c"
    break;

  case 143: /* pointer: '*'  */
#line 706 "parser.y"
        {
            ((*yyvalp).node) = create_node("POINTER", NULL, NULL, NULL, NULL);
        }
#line 3065 "y.tab.c"
    break;

  case 144: /* pointer: '*' type_qualifier_list  */
#line 710 "parser.y"
        {
            ((*yyvalp).node) = create_node("POINTER", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3073 "y.tab.c"
    break;

  case 145: /* pointer: '*' pointer  */
#line 714 "parser.y"
        {
            ((*yyvalp).node) = create_node("POINTER", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3081 "y.tab.c"
    break;

  case 146: /* pointer: '*' type_qualifier_list pointer  */
#line 718 "parser.y"
        {
            // pointer with qualifiers and nested pointer
            ASTNode *temp = create_node("POINTER", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
            ((*yyvalp).node) = create_node("POINTER", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), temp, NULL);
        }
#line 3091 "y.tab.c"
    break;

  case 147: /* type_qualifier_list: type_qualifier  */
#line 727 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3099 "y.tab.c"
    break;

  case 148: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 731 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_QUALIFIER_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3107 "y.tab.c"
    break;

  case 149: /* parameter_type_list: parameter_list  */
#line 738 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3115 "y.tab.c"
    break;

  case 150: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 742 "parser.y"
        {
            ASTNode *ellipsisNode = create_node("ELLIPSIS", NULL, NULL, NULL, NULL);
            ((*yyvalp).node) = create_node("PARAMETER_TYPE_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), ellipsisNode, NULL);
        }
#line 3124 "y.tab.c"
    break;

  case 151: /* parameter_list: parameter_declaration  */
#line 750 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3132 "y.tab.c"
    break;

  case 152: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 754 "parser.y"
        {
            ((*yyvalp).node) = create_node("PARAMETER_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3140 "y.tab.c"
    break;

  case 153: /* parameter_declaration: declaration_specifiers declarator  */
#line 761 "parser.y"
        {
            ((*yyvalp).node) = create_node("PARAMETER_DECLARATION", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3148 "y.tab.c"
    break;

  case 154: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 765 "parser.y"
        {
            ((*yyvalp).node) = create_node("PARAMETER_DECLARATION", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3156 "y.tab.c"
    break;

  case 155: /* parameter_declaration: declaration_specifiers  */
#line 769 "parser.y"
        {
            ((*yyvalp).node) = create_node("PARAMETER_DECLARATION", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3164 "y.tab.c"
    break;

  case 156: /* identifier_list: IDENTIFIER  */
#line 776 "parser.y"
        {
            ((*yyvalp).node) = create_node("IDENTIFIER_LIST", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
        }
#line 3172 "y.tab.c"
    break;

  case 157: /* identifier_list: identifier_list ',' IDENTIFIER  */
#line 780 "parser.y"
        {
            ASTNode *idNode = create_node("IDENTIFIER", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
            ((*yyvalp).node) = create_node("IDENTIFIER_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), idNode, NULL);
        }
#line 3181 "y.tab.c"
    break;

  case 158: /* type_name: specifier_qualifier_list  */
#line 788 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_NAME", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3189 "y.tab.c"
    break;

  case 159: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 792 "parser.y"
        {
            ((*yyvalp).node) = create_node("TYPE_NAME", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3197 "y.tab.c"
    break;

  case 160: /* abstract_declarator: pointer  */
#line 799 "parser.y"
        {
            ((*yyvalp).node) = create_node("ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3205 "y.tab.c"
    break;

  case 161: /* abstract_declarator: direct_abstract_declarator  */
#line 803 "parser.y"
        {
            ((*yyvalp).node) = create_node("ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3213 "y.tab.c"
    break;

  case 162: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 807 "parser.y"
        {
            ((*yyvalp).node) = create_node("ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3221 "y.tab.c"
    break;

  case 163: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 814 "parser.y"
        {
            ((*yyvalp).node) = create_node("DIRECT_ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3229 "y.tab.c"
    break;

  case 164: /* direct_abstract_declarator: '[' ']'  */
#line 818 "parser.y"
        {
            ((*yyvalp).node) = create_node("ARRAY_ABSTRACT_DECLARATOR", NULL, NULL, NULL, NULL);
        }
#line 3237 "y.tab.c"
    break;

  case 165: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 822 "parser.y"
        {
            ((*yyvalp).node) = create_node("ARRAY_ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3245 "y.tab.c"
    break;

  case 166: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 826 "parser.y"
        {
            ((*yyvalp).node) = create_node("ARRAY_ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3253 "y.tab.c"
    break;

  case 167: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 830 "parser.y"
        {
            ((*yyvalp).node) = create_node("ARRAY_ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3261 "y.tab.c"
    break;

  case 168: /* direct_abstract_declarator: '(' ')'  */
#line 834 "parser.y"
        {
            ((*yyvalp).node) = create_node("FUNCTION_ABSTRACT_DECLARATOR", NULL, NULL, NULL, NULL);
        }
#line 3269 "y.tab.c"
    break;

  case 169: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 838 "parser.y"
        {
            ((*yyvalp).node) = create_node("FUNCTION_ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3277 "y.tab.c"
    break;

  case 170: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 842 "parser.y"
        {
            ((*yyvalp).node) = create_node("FUNCTION_ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3285 "y.tab.c"
    break;

  case 171: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 846 "parser.y"
        {
            ((*yyvalp).node) = create_node("FUNCTION_ABSTRACT_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3293 "y.tab.c"
    break;

  case 172: /* initializer: assignment_expression  */
#line 853 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node); }
#line 3299 "y.tab.c"
    break;

  case 173: /* initializer: '{' initializer_list '}'  */
#line 855 "parser.y"
        {
            ((*yyvalp).node) = create_node("INITIALIZER_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3307 "y.tab.c"
    break;

  case 174: /* initializer: '{' initializer_list ',' '}'  */
#line 859 "parser.y"
        {
            // Same as above, trailing comma
            ((*yyvalp).node) = create_node("INITIALIZER_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3316 "y.tab.c"
    break;

  case 175: /* initializer_list: initializer  */
#line 867 "parser.y"
        {
            ((*yyvalp).node) = create_node("INITIALIZER_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3324 "y.tab.c"
    break;

  case 176: /* initializer_list: initializer_list ',' initializer  */
#line 871 "parser.y"
        {
            ((*yyvalp).node) = create_node("INITIALIZER_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3332 "y.tab.c"
    break;

  case 177: /* statement: labeled_statement  */
#line 878 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3340 "y.tab.c"
    break;

  case 178: /* statement: compound_statement  */
#line 882 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3348 "y.tab.c"
    break;

  case 179: /* statement: expression_statement  */
#line 886 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3356 "y.tab.c"
    break;

  case 180: /* statement: selection_statement  */
#line 890 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3364 "y.tab.c"
    break;

  case 181: /* statement: iteration_statement  */
#line 894 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3372 "y.tab.c"
    break;

  case 182: /* statement: jump_statement  */
#line 898 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3380 "y.tab.c"
    break;

  case 183: /* labeled_statement: IDENTIFIER ':' statement  */
#line 905 "parser.y"
        {
            ASTNode *idNode = create_node("LABEL", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
            ((*yyvalp).node) = create_node("LABELED_STATEMENT", NULL, idNode, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3389 "y.tab.c"
    break;

  case 184: /* labeled_statement: CASE constant_expression ':' statement  */
#line 910 "parser.y"
        {
            ASTNode *caseNode = create_node("CASE", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
            ((*yyvalp).node) = create_node("LABELED_STATEMENT", NULL, caseNode, NULL, NULL);
        }
#line 3398 "y.tab.c"
    break;

  case 185: /* labeled_statement: DEFAULT ':' statement  */
#line 915 "parser.y"
        {
            ASTNode *defaultNode = create_node("DEFAULT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
            ((*yyvalp).node) = create_node("LABELED_STATEMENT", NULL, defaultNode, NULL, NULL);
        }
#line 3407 "y.tab.c"
    break;

  case 186: /* compound_statement: LBRACE RBRACE  */
#line 923 "parser.y"
        {
            ((*yyvalp).node) = create_node("COMPOUND_STATEMENT", NULL, NULL, NULL, NULL);
        }
#line 3415 "y.tab.c"
    break;

  case 187: /* compound_statement: LBRACE statement_list RBRACE  */
#line 927 "parser.y"
        {
            ((*yyvalp).node) = create_node("COMPOUND_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3423 "y.tab.c"
    break;

  case 188: /* compound_statement: LBRACE declaration_list RBRACE  */
#line 931 "parser.y"
        {
            ((*yyvalp).node) = create_node("COMPOUND_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3431 "y.tab.c"
    break;

  case 189: /* compound_statement: LBRACE declaration_list statement_list RBRACE  */
#line 935 "parser.y"
        {
            ((*yyvalp).node) = create_node("COMPOUND_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3439 "y.tab.c"
    break;

  case 190: /* declaration_list: declaration  */
#line 943 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node); }
#line 3445 "y.tab.c"
    break;

  case 191: /* declaration_list: declaration_list declaration  */
#line 945 "parser.y"
        { ((*yyvalp).node) = create_node("Declarations", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL); }
#line 3451 "y.tab.c"
    break;

  case 192: /* statement_list: statement  */
#line 949 "parser.y"
        {
            ((*yyvalp).node) = create_node("STATEMENT_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3459 "y.tab.c"
    break;

  case 193: /* statement_list: statement_list statement  */
#line 953 "parser.y"
        {
            ((*yyvalp).node) = create_node("STATEMENT_LIST", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3467 "y.tab.c"
    break;

  case 194: /* expression_statement: ';'  */
#line 960 "parser.y"
        {
            ((*yyvalp).node) = create_node("EXPRESSION_STATEMENT", NULL, NULL, NULL, NULL);
        }
#line 3475 "y.tab.c"
    break;

  case 195: /* expression_statement: expression ';'  */
#line 964 "parser.y"
        {
            ((*yyvalp).node) = create_node("EXPRESSION_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3483 "y.tab.c"
    break;

  case 196: /* selection_statement: IF '(' expression ')' statement  */
#line 971 "parser.y"
        {
            ((*yyvalp).node) = create_node("IF_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3491 "y.tab.c"
    break;

  case 197: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 975 "parser.y"
        {
            ((*yyvalp).node) = create_node("IF_ELSE_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node));
        }
#line 3499 "y.tab.c"
    break;

  case 198: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 979 "parser.y"
        {
            ((*yyvalp).node) = create_node("SWITCH_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3507 "y.tab.c"
    break;

  case 199: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 986 "parser.y"
        {
            ((*yyvalp).node) = create_node("WHILE_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3515 "y.tab.c"
    break;

  case 200: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 990 "parser.y"
        {
            ((*yyvalp).node) = create_node("DO_WHILE_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3523 "y.tab.c"
    break;

  case 201: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 994 "parser.y"
        {
            ((*yyvalp).node) = create_node("FOR_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node));
        }
#line 3531 "y.tab.c"
    break;

  case 202: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 998 "parser.y"
        {
            ASTNode *forInner = create_node("FOR_INNER", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node));
            ((*yyvalp).node) = create_node("FOR_STATEMENT", NULL, forInner, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
        }
#line 3540 "y.tab.c"
    break;

  case 203: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1006 "parser.y"
        {
            ((*yyvalp).node) = create_node("GOTO_STATEMENT", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.strval), NULL, NULL, NULL);
        }
#line 3548 "y.tab.c"
    break;

  case 204: /* jump_statement: CONTINUE ';'  */
#line 1010 "parser.y"
        {
            ((*yyvalp).node) = create_node("CONTINUE_STATEMENT", NULL, NULL, NULL, NULL);
        }
#line 3556 "y.tab.c"
    break;

  case 205: /* jump_statement: BREAK ';'  */
#line 1014 "parser.y"
        {
            ((*yyvalp).node) = create_node("BREAK_STATEMENT", NULL, NULL, NULL, NULL);
        }
#line 3564 "y.tab.c"
    break;

  case 206: /* jump_statement: RETURN ';'  */
#line 1018 "parser.y"
        {
            ((*yyvalp).node) = create_node("RETURN_STATEMENT", NULL, NULL, NULL, NULL);
        }
#line 3572 "y.tab.c"
    break;

  case 207: /* jump_statement: RETURN expression ';'  */
#line 1022 "parser.y"
        {
            ((*yyvalp).node) = create_node("RETURN_STATEMENT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, NULL);
        }
#line 3580 "y.tab.c"
    break;

  case 208: /* translation_unit: external_declaration  */
#line 1029 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
            ast_root = ((*yyvalp).node);
        }
#line 3589 "y.tab.c"
    break;

  case 209: /* translation_unit: translation_unit external_declaration  */
#line 1034 "parser.y"
        {
            ((*yyvalp).node) = create_node("TRANSLATION_UNIT", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
            ast_root = ((*yyvalp).node); 
        }
#line 3598 "y.tab.c"
    break;

  case 210: /* translation_unit: Define translation_unit  */
#line 1039 "parser.y"
        {
            ((*yyvalp).node) = create_node("DEFINE", NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL);
            ast_root = ((*yyvalp).node); 
        }
#line 3607 "y.tab.c"
    break;

  case 211: /* external_declaration: function_definition  */
#line 1047 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3615 "y.tab.c"
    break;

  case 212: /* external_declaration: declaration  */
#line 1051 "parser.y"
        {
            ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node);
        }
#line 3623 "y.tab.c"
    break;

  case 213: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 1058 "parser.y"
        {
            ASTNode *func_body = create_node("FUNCTION_BODY", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
            ASTNode *func_decl = create_node("FUNCTION_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), func_body);
            ((*yyvalp).node) = create_node("FUNCTION_DEFINITION", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.node), func_decl, NULL);
        }
#line 3633 "y.tab.c"
    break;

  case 214: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 1064 "parser.y"
        {
            ASTNode *func_body = create_node("FUNCTION_BODY", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
            ASTNode *func_decl = create_node("FUNCTION_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, func_body);
            ((*yyvalp).node) = create_node("FUNCTION_DEFINITION", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), func_decl, NULL);
        }
#line 3643 "y.tab.c"
    break;

  case 215: /* function_definition: declarator declaration_list compound_statement  */
#line 1070 "parser.y"
        {
            ASTNode *func_body = create_node("FUNCTION_BODY", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
            ASTNode *func_decl = create_node("FUNCTION_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), func_body);
            ((*yyvalp).node) = create_node("FUNCTION_DEFINITION", NULL, NULL, func_decl, NULL);
        }
#line 3653 "y.tab.c"
    break;

  case 216: /* function_definition: declarator compound_statement  */
#line 1076 "parser.y"
        {
            ASTNode *func_body = create_node("FUNCTION_BODY", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.node), NULL, NULL);
            ASTNode *func_decl = create_node("FUNCTION_DECLARATOR", NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.node), NULL, func_body);
            ((*yyvalp).node) = create_node("FUNCTION_DEFINITION", NULL, NULL, func_decl, NULL);
        }
#line 3663 "y.tab.c"
    break;


#line 3667 "y.tab.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysz
          = yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs




#line 1084 "parser.y"


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
