/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    extern FILE *yyin;
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

#line 122 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_CHARACTER = 4,                  /* CHARACTER  */
  YYSYMBOL_PRINTFF = 5,                    /* PRINTFF  */
  YYSYMBOL_SCANFF = 6,                     /* SCANFF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_TRUE = 13,                      /* TRUE  */
  YYSYMBOL_FALSE = 14,                     /* FALSE  */
  YYSYMBOL_NUMBER = 15,                    /* NUMBER  */
  YYSYMBOL_FLOAT_NUM = 16,                 /* FLOAT_NUM  */
  YYSYMBOL_ID = 17,                        /* ID  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LT = 23,                        /* LT  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_STR = 26,                       /* STR  */
  YYSYMBOL_ADD = 27,                       /* ADD  */
  YYSYMBOL_MULTIPLY = 28,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 29,                    /* DIVIDE  */
  YYSYMBOL_SUBTRACT = 30,                  /* SUBTRACT  */
  YYSYMBOL_UNARY = 31,                     /* UNARY  */
  YYSYMBOL_INCLUDE = 32,                   /* INCLUDE  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '&'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_headers = 44,                   /* headers  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_main = 46,                      /* main  */
  YYSYMBOL_datatype = 47,                  /* datatype  */
  YYSYMBOL_body = 48,                      /* body  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_53_6 = 53,                      /* $@6  */
  YYSYMBOL_54_7 = 54,                      /* $@7  */
  YYSYMBOL_else = 55,                      /* else  */
  YYSYMBOL_56_8 = 56,                      /* $@8  */
  YYSYMBOL_opt_printf_args = 57,           /* opt_printf_args  */
  YYSYMBOL_printf_args = 58,               /* printf_args  */
  YYSYMBOL_condition = 59,                 /* condition  */
  YYSYMBOL_statement = 60,                 /* statement  */
  YYSYMBOL_61_9 = 61,                      /* $@9  */
  YYSYMBOL_62_10 = 62,                     /* $@10  */
  YYSYMBOL_63_11 = 63,                     /* $@11  */
  YYSYMBOL_64_12 = 64,                     /* $@12  */
  YYSYMBOL_init = 65,                      /* init  */
  YYSYMBOL_expression = 66,                /* expression  */
  YYSYMBOL_arithmetic = 67,                /* arithmetic  */
  YYSYMBOL_relop = 68,                     /* relop  */
  YYSYMBOL_value = 69,                     /* value  */
  YYSYMBOL_return = 70,                    /* return  */
  YYSYMBOL_71_13 = 71                      /* $@13  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
       2,     2,     2,     2,     2,     2,     2,     2,    40,     2,
      34,    35,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    86,    87,    87,    90,    93,    94,    95,
      96,    99,    99,   107,   107,   107,   107,   112,   113,   114,
     114,   122,   122,   125,   125,   126,   129,   130,   133,   138,
     146,   159,   160,   161,   164,   164,   182,   182,   206,   206,
     207,   207,   222,   240,   241,   244,   265,   268,   269,   270,
     271,   274,   275,   276,   277,   278,   279,   282,   283,   284,
     285,   288,   288,   289
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "CHARACTER",
  "PRINTFF", "SCANFF", "INT", "FLOAT", "CHAR", "FOR", "IF", "ELSE", "TRUE",
  "FALSE", "NUMBER", "FLOAT_NUM", "ID", "LE", "GE", "EQ", "NE", "GT", "LT",
  "AND", "OR", "STR", "ADD", "MULTIPLY", "DIVIDE", "SUBTRACT", "UNARY",
  "INCLUDE", "RETURN", "'('", "')'", "'{'", "'}'", "';'", "','", "'&'",
  "'='", "$accept", "program", "headers", "$@1", "main", "datatype",
  "body", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "else", "$@8",
  "opt_printf_args", "printf_args", "condition", "statement", "$@9",
  "$@10", "$@11", "$@12", "init", "expression", "arithmetic", "relop",
  "value", "return", "$@13", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -28,   -49,     6,    34,   -49,   -49,   -49,   -49,   -49,   -49,
     -28,   -19,     0,   -17,   -49,   -14,   105,   -49,   -49,   -49,
     -49,   -10,     3,    15,    92,   -15,     1,    19,    20,    21,
      -1,   122,    42,   -49,   -49,   -49,   105,    37,   -49,    50,
      51,   121,    12,    71,   -49,   -49,   -49,   -49,   -49,   -49,
      71,   -49,    38,    71,   -49,    43,    44,    46,   -49,   -49,
     -49,   -49,   -49,   -49,    45,   122,    40,   -49,    40,    71,
     -49,    52,    71,    57,    53,    12,   -49,    71,   -49,   -49,
     -49,   -49,    71,   -49,   -49,    55,    40,    66,    88,    68,
      81,   -49,    40,    71,   -49,    72,   121,   105,    40,    80,
      84,     2,   -49,    85,   -49,   105,   108,    41,   -49,   -49,
     -49,    90,   105,    54,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     5,     1,    10,     7,     8,     9,
       3,     0,     0,     0,     6,     0,     0,    19,    21,    11,
      13,    38,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    34,    61,    18,     0,    17,     0,
       0,     0,    33,     0,    53,    54,    55,    56,    52,    51,
       0,    41,    44,     0,     2,    26,     0,     0,    59,    31,
      32,    57,    58,    60,     0,     0,    37,    46,    39,     0,
      35,     0,     0,     0,     0,    33,    14,     0,    47,    49,
      50,    48,     0,    43,    62,    27,    28,     0,     0,     0,
       0,    30,    45,     0,    20,     0,     0,     0,    29,     0,
       0,     0,    22,     0,    15,     0,    25,     0,    23,    16,
      12,     0,     0,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   127,   -49,   -49,   128,   -16,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,    58,   -40,   -49,
     -49,   -49,   -49,   -49,   -48,   -49,    67,   -39,   -49,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    10,     4,    11,    23,    36,    28,    29,    90,
     106,    26,    27,   109,   111,    73,    85,    64,    25,    52,
      30,    31,    32,    70,    66,    82,    50,    67,    37,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    57,    68,    65,     1,     6,     5,    17,    18,     7,
       8,     9,    19,    20,    71,    13,    58,    14,    15,    21,
      33,   -40,    16,    38,    86,    59,    60,    61,    62,    63,
      83,   -36,    34,    22,    92,    39,    65,     6,    91,   104,
      43,     7,     8,     9,     6,    98,    17,    18,     7,     8,
       9,    19,    20,    40,    41,    42,   100,     6,    21,    17,
      18,     7,     8,     9,    19,    20,     1,    78,    79,    80,
      81,    21,    22,    51,    54,    58,    55,    56,   110,    69,
      76,   101,    72,    74,    75,    22,    61,    62,    63,   107,
      84,   114,    87,    88,    93,     6,   113,    17,    18,     7,
       8,     9,    19,    20,    94,    95,    96,    99,     6,    21,
      17,    18,     7,     8,     9,    19,    20,    97,   102,   103,
     108,   105,    21,    22,     6,    35,   112,     3,     7,     8,
       9,    12,    77,    89,     0,     0,    22,     0,    21,     0,
      44,    45,    46,    47,    48,    49,     0,     0,     0,     0,
       0,     0,    22
};

static const yytype_int8 yycheck[] =
{
      16,    41,    50,    42,    32,     3,     0,     5,     6,     7,
       8,     9,    10,    11,    53,    34,     4,    17,    35,    17,
      17,    31,    36,    38,    72,    13,    14,    15,    16,    17,
      69,    41,    17,    31,    82,    34,    75,     3,    77,    37,
      41,     7,     8,     9,     3,    93,     5,     6,     7,     8,
       9,    10,    11,    34,    34,    34,    96,     3,    17,     5,
       6,     7,     8,     9,    10,    11,    32,    27,    28,    29,
      30,    17,    31,    31,    37,     4,    26,    26,    37,    41,
      35,    97,    39,    39,    38,    31,    15,    16,    17,   105,
      38,    37,    35,    40,    39,     3,   112,     5,     6,     7,
       8,     9,    10,    11,    38,    17,    38,    35,     3,    17,
       5,     6,     7,     8,     9,    10,    11,    36,    38,    35,
      12,    36,    17,    31,     3,    33,    36,     0,     7,     8,
       9,     3,    65,    75,    -1,    -1,    31,    -1,    17,    -1,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    43,    44,    45,     0,     3,     7,     8,     9,
      44,    46,    47,    34,    17,    35,    36,     5,     6,    10,
      11,    17,    31,    47,    48,    60,    53,    54,    49,    50,
      62,    63,    64,    17,    17,    33,    48,    70,    38,    34,
      34,    34,    34,    41,    18,    19,    20,    21,    22,    23,
      68,    31,    61,    71,    37,    26,    26,    60,     4,    13,
      14,    15,    16,    17,    59,    69,    66,    69,    66,    41,
      65,    69,    39,    57,    39,    38,    35,    68,    27,    28,
      29,    30,    67,    69,    38,    58,    66,    35,    40,    59,
      51,    69,    66,    39,    38,    17,    38,    36,    66,    35,
      60,    48,    38,    35,    37,    36,    52,    48,    12,    55,
      37,    56,    36,    48,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    44,    46,    47,    47,    47,
      47,    49,    48,    50,    51,    52,    48,    48,    48,    53,
      48,    54,    48,    56,    55,    55,    57,    57,    58,    58,
      59,    59,    59,    59,    61,    60,    62,    60,    63,    60,
      64,    60,    60,    65,    65,    66,    66,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    71,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     0,     2,     2,     1,     1,     1,
       1,     0,    12,     0,     0,     0,    11,     2,     2,     0,
       7,     0,     9,     0,     5,     0,     0,     2,     1,     3,
       3,     1,     1,     0,     0,     4,     0,     4,     0,     4,
       0,     3,     2,     2,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
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

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






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


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: headers main '(' ')' '{' body return '}'  */
#line 79 "parser.y"
                                                  { 
    (yyvsp[-6].nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "main"); 
    (yyval.nd_obj).nd = mknode((yyvsp[-7].nd_obj).nd, (yyvsp[-6].nd_obj).nd, "program"); 
    head = (yyval.nd_obj).nd;
}
#line 1266 "parser.tab.c"
    break;

  case 3: /* headers: headers headers  */
#line 86 "parser.y"
                         { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "headers"); }
#line 1272 "parser.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 87 "parser.y"
          { add('H'); }
#line 1278 "parser.tab.c"
    break;

  case 5: /* headers: INCLUDE $@1  */
#line 87 "parser.y"
                        { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name); }
#line 1284 "parser.tab.c"
    break;

  case 6: /* main: datatype ID  */
#line 90 "parser.y"
                  { add('F'); }
#line 1290 "parser.tab.c"
    break;

  case 7: /* datatype: INT  */
#line 93 "parser.y"
              { insert_type(); }
#line 1296 "parser.tab.c"
    break;

  case 8: /* datatype: FLOAT  */
#line 94 "parser.y"
        { insert_type(); }
#line 1302 "parser.tab.c"
    break;

  case 9: /* datatype: CHAR  */
#line 95 "parser.y"
       { insert_type(); }
#line 1308 "parser.tab.c"
    break;

  case 10: /* datatype: VOID  */
#line 96 "parser.y"
       { insert_type(); }
#line 1314 "parser.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 99 "parser.y"
          { add('K'); is_for = 1; }
#line 1320 "parser.tab.c"
    break;

  case 12: /* body: FOR $@2 '(' statement ';' condition ';' statement ')' '{' body '}'  */
#line 99 "parser.y"
                                                                                               { 
    struct node *temp = mknode((yyvsp[-6].nd_obj3).nd, (yyvsp[-4].nd_obj).nd, "CONDITION"); 
    struct node *temp2 = mknode((yyvsp[-8].nd_obj).nd, temp, "CONDITION"); 
    (yyval.nd_obj).nd = mknode(temp2, (yyvsp[-1].nd_obj).nd, (yyvsp[-11].nd_obj).name); 
    sprintf(icg[ic_idx++], "%s", buff);
    sprintf(icg[ic_idx++], "JUMP to %s\n", (yyvsp[-6].nd_obj3).if_body);
    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-6].nd_obj3).else_body);
}
#line 1333 "parser.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 107 "parser.y"
     { add('K'); is_for = 0; }
#line 1339 "parser.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 107 "parser.y"
                                                 { sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-1].nd_obj3).if_body); }
#line 1345 "parser.tab.c"
    break;

  case 15: /* $@5: %empty  */
#line 107 "parser.y"
                                                                                                                       { sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-5].nd_obj3).else_body); }
#line 1351 "parser.tab.c"
    break;

  case 16: /* body: IF $@3 '(' condition ')' $@4 '{' body '}' $@5 else  */
#line 107 "parser.y"
                                                                                                                                                                                       { 
    struct node *iff = mknode((yyvsp[-7].nd_obj3).nd, (yyvsp[-3].nd_obj).nd, (yyvsp[-10].nd_obj).name); 
    (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else"); 
    sprintf(icg[ic_idx++], "GOTO next\n");
}
#line 1361 "parser.tab.c"
    break;

  case 17: /* body: statement ';'  */
#line 112 "parser.y"
                { (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd; }
#line 1367 "parser.tab.c"
    break;

  case 18: /* body: body body  */
#line 113 "parser.y"
            { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statements"); }
#line 1373 "parser.tab.c"
    break;

  case 19: /* $@6: %empty  */
#line 114 "parser.y"
          { add('K'); }
#line 1379 "parser.tab.c"
    break;

  case 20: /* body: PRINTFF $@6 '(' STR opt_printf_args ')' ';'  */
#line 116 "parser.y"
    {
      struct node *strNode = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
      struct node *argsNode = (yyvsp[-2].nd_obj).nd;          
      (yyval.nd_obj).nd = mknode(strNode, argsNode, "printf");
    }
#line 1389 "parser.tab.c"
    break;

  case 21: /* $@7: %empty  */
#line 122 "parser.y"
         { add('K'); }
#line 1395 "parser.tab.c"
    break;

  case 22: /* body: SCANFF $@7 '(' STR ',' '&' ID ')' ';'  */
#line 122 "parser.y"
                                                  { (yyval.nd_obj).nd = mknode(NULL, NULL, "scanf"); }
#line 1401 "parser.tab.c"
    break;

  case 23: /* $@8: %empty  */
#line 125 "parser.y"
           { add('K'); }
#line 1407 "parser.tab.c"
    break;

  case 24: /* else: ELSE $@8 '{' body '}'  */
#line 125 "parser.y"
                                      { (yyval.nd_obj).nd = mknode(NULL, (yyvsp[-1].nd_obj).nd, (yyvsp[-4].nd_obj).name); }
#line 1413 "parser.tab.c"
    break;

  case 25: /* else: %empty  */
#line 126 "parser.y"
  { (yyval.nd_obj).nd = NULL; }
#line 1419 "parser.tab.c"
    break;

  case 26: /* opt_printf_args: %empty  */
#line 129 "parser.y"
                   { (yyval.nd_obj).nd = NULL; }
#line 1425 "parser.tab.c"
    break;

  case 27: /* opt_printf_args: ',' printf_args  */
#line 130 "parser.y"
                    { (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd; }
#line 1431 "parser.tab.c"
    break;

  case 28: /* printf_args: expression  */
#line 134 "parser.y"
      { 
        /* leaf node for a single argument */
        (yyval.nd_obj).nd = mknode(NULL, (yyvsp[0].nd_obj2).nd, "arg");  
      }
#line 1440 "parser.tab.c"
    break;

  case 29: /* printf_args: printf_args ',' expression  */
#line 139 "parser.y"
      {
        /* append another arg to the right */
        struct node *leftList = (yyvsp[-2].nd_obj).nd;
        struct node *newArg   = mknode(NULL, (yyvsp[0].nd_obj2).nd, "arg");
        (yyval.nd_obj).nd = mknode(leftList, newArg, "args");
      }
#line 1451 "parser.tab.c"
    break;

  case 30: /* condition: value relop value  */
#line 146 "parser.y"
                             { 
    (yyval.nd_obj3).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
    if(is_for) {
        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
        sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
        sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name, label);
        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
    } else {
        sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name, label, label+1);
        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
    }
}
#line 1469 "parser.tab.c"
    break;

  case 31: /* condition: TRUE  */
#line 159 "parser.y"
       { add('K'); (yyval.nd_obj3).nd = NULL; }
#line 1475 "parser.tab.c"
    break;

  case 32: /* condition: FALSE  */
#line 160 "parser.y"
        { add('K'); (yyval.nd_obj3).nd = NULL; }
#line 1481 "parser.tab.c"
    break;

  case 33: /* condition: %empty  */
#line 161 "parser.y"
  { (yyval.nd_obj3).nd = NULL; }
#line 1487 "parser.tab.c"
    break;

  case 34: /* $@9: %empty  */
#line 164 "parser.y"
                       { add('V'); }
#line 1493 "parser.tab.c"
    break;

  case 35: /* statement: datatype ID $@9 init  */
#line 164 "parser.y"
                                          { 
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    int t = check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).type); 
    if(t>0) { 
        struct node *temp;
        if(t == 1) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "floattoint"); 
        else if(t == 2) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttofloat"); 
        else if(t == 3) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartoint"); 
        else if(t == 4) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttochar"); 
        else if(t == 5) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartofloat"); 
        else temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "floattochar"); 
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration"); 
    } 
    else { 
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "declaration"); 
    } 
    sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-2].nd_obj).name, (yyvsp[0].nd_obj2).name);
}
#line 1516 "parser.tab.c"
    break;

  case 36: /* $@10: %empty  */
#line 182 "parser.y"
     { check_declaration((yyvsp[0].nd_obj).name); }
#line 1522 "parser.tab.c"
    break;

  case 37: /* statement: ID $@10 '=' expression  */
#line 182 "parser.y"
                                                    {
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name); 
    char *id_type = get_type((yyvsp[-3].nd_obj).name); 
    if(strcmp(id_type, (yyvsp[0].nd_obj2).type)) {
        struct node *temp;
        if(!strcmp(id_type, "int")) {
            if(!strcmp((yyvsp[0].nd_obj2).type, "float")) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "floattoint");
            else temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartoint");
        }
        else if(!strcmp(id_type, "float")) {
            if(!strcmp((yyvsp[0].nd_obj2).type, "int")) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttofloat");
            else temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartofloat");
        }
        else {
            if(!strcmp((yyvsp[0].nd_obj2).type, "int")) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttochar");
            else temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "floattochar");
        }
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
    }
    else {
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "="); 
    }
    sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).name);
}
#line 1551 "parser.tab.c"
    break;

  case 38: /* $@11: %empty  */
#line 206 "parser.y"
     { check_declaration((yyvsp[0].nd_obj).name); }
#line 1557 "parser.tab.c"
    break;

  case 39: /* statement: ID $@11 relop expression  */
#line 206 "parser.y"
                                                      { (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name); (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); }
#line 1563 "parser.tab.c"
    break;

  case 40: /* $@12: %empty  */
#line 207 "parser.y"
     { check_declaration((yyvsp[0].nd_obj).name); }
#line 1569 "parser.tab.c"
    break;

  case 41: /* statement: ID $@12 UNARY  */
#line 207 "parser.y"
                                           { 
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "ITERATOR");  
    if(!strcmp((yyvsp[0].nd_obj).name, "++")) {
        int current_temp = temp_var;
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", current_temp, (yyvsp[-2].nd_obj).name, (yyvsp[-2].nd_obj).name, current_temp);
        temp_var++;
    }
    else {
        int current_temp = temp_var;
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", current_temp, (yyvsp[-2].nd_obj).name, (yyvsp[-2].nd_obj).name, current_temp);
        temp_var++;
    }
}
#line 1589 "parser.tab.c"
    break;

  case 42: /* statement: UNARY ID  */
#line 222 "parser.y"
           { 
    check_declaration((yyvsp[0].nd_obj).name); 
    (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name); 
    (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "ITERATOR"); 
    if(!strcmp((yyvsp[-1].nd_obj).name, "++")) {
        int current_temp = temp_var;
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", current_temp, (yyvsp[0].nd_obj).name, (yyvsp[0].nd_obj).name, current_temp);
        temp_var++;
    }
    else {
        int current_temp = temp_var;
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", current_temp, (yyvsp[0].nd_obj).name, (yyvsp[0].nd_obj).name, current_temp);
        temp_var++;
    }
}
#line 1610 "parser.tab.c"
    break;

  case 43: /* init: '=' value  */
#line 240 "parser.y"
                { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type); strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name); }
#line 1616 "parser.tab.c"
    break;

  case 44: /* init: %empty  */
#line 241 "parser.y"
  { sprintf((yyval.nd_obj2).type, "null"); (yyval.nd_obj2).nd = mknode(NULL, NULL, "NULL"); strcpy((yyval.nd_obj2).name, "NULL"); }
#line 1622 "parser.tab.c"
    break;

  case 45: /* expression: expression arithmetic expression  */
#line 244 "parser.y"
                                             { 
    if(!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
        sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
        (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
    }
    else {
        struct node *temp;
        if(!strcmp((yyvsp[-2].nd_obj2).type, "int") && !strcmp((yyvsp[0].nd_obj2).type, "float")) temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inttofloat");
        else if(!strcmp((yyvsp[-2].nd_obj2).type, "float") && !strcmp((yyvsp[0].nd_obj2).type, "int")) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttofloat");
        else if(!strcmp((yyvsp[-2].nd_obj2).type, "int") && !strcmp((yyvsp[0].nd_obj2).type, "char")) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartoint");
        else if(!strcmp((yyvsp[-2].nd_obj2).type, "char") && !strcmp((yyvsp[0].nd_obj2).type, "int")) temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "chartoint");
        else if(!strcmp((yyvsp[-2].nd_obj2).type, "float") && !strcmp((yyvsp[0].nd_obj2).type, "char")) temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartofloat");
        else temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "chartofloat");
        
        sprintf((yyval.nd_obj2).type, "%s", !strcmp((yyvsp[-2].nd_obj2).type, "float") ? "float" : "int");
        (yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
    }
    sprintf((yyval.nd_obj2).name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
}
#line 1648 "parser.tab.c"
    break;

  case 46: /* expression: value  */
#line 265 "parser.y"
        { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name); sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type); (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; }
#line 1654 "parser.tab.c"
    break;

  case 57: /* value: NUMBER  */
#line 282 "parser.y"
              { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); sprintf((yyval.nd_obj2).type, "int"); add('C'); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 1660 "parser.tab.c"
    break;

  case 58: /* value: FLOAT_NUM  */
#line 283 "parser.y"
            { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); sprintf((yyval.nd_obj2).type, "float"); add('C'); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 1666 "parser.tab.c"
    break;

  case 59: /* value: CHARACTER  */
#line 284 "parser.y"
            { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); sprintf((yyval.nd_obj2).type, "char"); add('C'); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 1672 "parser.tab.c"
    break;

  case 60: /* value: ID  */
#line 285 "parser.y"
     { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); char *id_type = get_type((yyvsp[0].nd_obj).name); sprintf((yyval.nd_obj2).type, "%s", id_type); check_declaration((yyvsp[0].nd_obj).name); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 1678 "parser.tab.c"
    break;

  case 61: /* $@13: %empty  */
#line 288 "parser.y"
               { add('K'); }
#line 1684 "parser.tab.c"
    break;

  case 62: /* return: RETURN $@13 value ';'  */
#line 288 "parser.y"
                                       { check_return_type((yyvsp[-1].nd_obj2).name); (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, "return"); (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj2).nd, "RETURN"); }
#line 1690 "parser.tab.c"
    break;

  case 63: /* return: %empty  */
#line 289 "parser.y"
  { (yyval.nd_obj).nd = NULL; }
#line 1696 "parser.tab.c"
    break;


#line 1700 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 292 "parser.y"


void generate_dot(FILE *fp, struct node *node) {
    if(node == NULL) return;
    char *tok = node->token;
    char  buf[512];
    if (tok[0] == '"' && tok[strlen(tok)-1] == '"') {
        // strip leading and trailing quote
        size_t len = strlen(tok);
        memcpy(buf, tok+1, len-2);
        buf[len-2] = '\0';
        tok = buf;
    }
    fprintf(fp, "  \"%p\" [label=\"%s\"];\n", (void*)node, tok);
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
    if (!yyin) {
        perror(argv[1]);
        return 1;
    }
    yyparse();
    visualize_parse_tree();
    printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    print_tree(head); 
    printf("\n");
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
    if (yytext == NULL || strlen(yytext) == 0) {
        fprintf(stderr, "Invalid yytext in add()\n");
    }

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
    if (yytext == NULL || strlen(yytext) == 0) {
        fprintf(stderr, "Invalid yytext in add()\n");
    }
   
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
