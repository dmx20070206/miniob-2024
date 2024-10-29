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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

UnboundAggregateExpr *create_aggregate_expression(const char *aggregate_name,
                                           Expression *child,
                                           const char *sql_string,
                                           YYLTYPE *llocp)
{
  UnboundAggregateExpr *expr = new UnboundAggregateExpr(aggregate_name, child);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}


#line 125 "yacc_sql.cpp"

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

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_BY = 4,                         /* BY  */
  YYSYMBOL_CREATE = 5,                     /* CREATE  */
  YYSYMBOL_DROP = 6,                       /* DROP  */
  YYSYMBOL_GROUP = 7,                      /* GROUP  */
  YYSYMBOL_INNER_JOIN = 8,                 /* INNER_JOIN  */
  YYSYMBOL_TABLE = 9,                      /* TABLE  */
  YYSYMBOL_TABLES = 10,                    /* TABLES  */
  YYSYMBOL_INDEX = 11,                     /* INDEX  */
  YYSYMBOL_CALC = 12,                      /* CALC  */
  YYSYMBOL_SELECT = 13,                    /* SELECT  */
  YYSYMBOL_ASC = 14,                       /* ASC  */
  YYSYMBOL_DESC = 15,                      /* DESC  */
  YYSYMBOL_SHOW = 16,                      /* SHOW  */
  YYSYMBOL_SYNC = 17,                      /* SYNC  */
  YYSYMBOL_INSERT = 18,                    /* INSERT  */
  YYSYMBOL_DELETE = 19,                    /* DELETE  */
  YYSYMBOL_UPDATE = 20,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 21,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 24,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 25,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 26,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 27,                     /* INT_T  */
  YYSYMBOL_DATE_T = 28,                    /* DATE_T  */
  YYSYMBOL_STRING_T = 29,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 30,                   /* FLOAT_T  */
  YYSYMBOL_VECTOR_T = 31,                  /* VECTOR_T  */
  YYSYMBOL_TEXT_T = 32,                    /* TEXT_T  */
  YYSYMBOL_HELP = 33,                      /* HELP  */
  YYSYMBOL_EXIT = 34,                      /* EXIT  */
  YYSYMBOL_DOT = 35,                       /* DOT  */
  YYSYMBOL_INTO = 36,                      /* INTO  */
  YYSYMBOL_VALUES = 37,                    /* VALUES  */
  YYSYMBOL_FROM = 38,                      /* FROM  */
  YYSYMBOL_WHERE = 39,                     /* WHERE  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_SET = 41,                       /* SET  */
  YYSYMBOL_ON = 42,                        /* ON  */
  YYSYMBOL_LOAD = 43,                      /* LOAD  */
  YYSYMBOL_DATA = 44,                      /* DATA  */
  YYSYMBOL_INFILE = 45,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 46,                   /* EXPLAIN  */
  YYSYMBOL_STORAGE = 47,                   /* STORAGE  */
  YYSYMBOL_FORMAT = 48,                    /* FORMAT  */
  YYSYMBOL_MAX = 49,                       /* MAX  */
  YYSYMBOL_MIN = 50,                       /* MIN  */
  YYSYMBOL_AVG = 51,                       /* AVG  */
  YYSYMBOL_SUM = 52,                       /* SUM  */
  YYSYMBOL_COUNT = 53,                     /* COUNT  */
  YYSYMBOL_NOT_LIKE = 54,                  /* NOT_LIKE  */
  YYSYMBOL_LIKE = 55,                      /* LIKE  */
  YYSYMBOL_NOT_IN = 56,                    /* NOT_IN  */
  YYSYMBOL_IN = 57,                        /* IN  */
  YYSYMBOL_NOT_EXISTS = 58,                /* NOT_EXISTS  */
  YYSYMBOL_EXISTS = 59,                    /* EXISTS  */
  YYSYMBOL_LENGTH = 60,                    /* LENGTH  */
  YYSYMBOL_ROUND = 61,                     /* ROUND  */
  YYSYMBOL_DATE_FORMAT = 62,               /* DATE_FORMAT  */
  YYSYMBOL_NULLABLE = 63,                  /* NULLABLE  */
  YYSYMBOL_UNNULLABLE = 64,                /* UNNULLABLE  */
  YYSYMBOL_IS_NULL = 65,                   /* IS_NULL  */
  YYSYMBOL_IS_NOT_NULL = 66,               /* IS_NOT_NULL  */
  YYSYMBOL_VEC_L2_DISTANCE = 67,           /* VEC_L2_DISTANCE  */
  YYSYMBOL_VEC_COSINE_DISTANCE_FUNC = 68,  /* VEC_COSINE_DISTANCE_FUNC  */
  YYSYMBOL_VEC_INNER_PRODUCT_FUNC = 69,    /* VEC_INNER_PRODUCT_FUNC  */
  YYSYMBOL_LBRACKET = 70,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 71,                  /* RBRACKET  */
  YYSYMBOL_UNIQUE = 72,                    /* UNIQUE  */
  YYSYMBOL_ORDER_BY = 73,                  /* ORDER_BY  */
  YYSYMBOL_AS = 74,                        /* AS  */
  YYSYMBOL_EQ = 75,                        /* EQ  */
  YYSYMBOL_LT = 76,                        /* LT  */
  YYSYMBOL_GT = 77,                        /* GT  */
  YYSYMBOL_LE = 78,                        /* LE  */
  YYSYMBOL_GE = 79,                        /* GE  */
  YYSYMBOL_NE = 80,                        /* NE  */
  YYSYMBOL_NUMBER = 81,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 82,                     /* FLOAT  */
  YYSYMBOL_ID = 83,                        /* ID  */
  YYSYMBOL_DATE_STR = 84,                  /* DATE_STR  */
  YYSYMBOL_TEXT_STR = 85,                  /* TEXT_STR  */
  YYSYMBOL_SSS = 86,                       /* SSS  */
  YYSYMBOL_HIGHER_THAN_EXPRESSION = 87,    /* HIGHER_THAN_EXPRESSION  */
  YYSYMBOL_88_ = 88,                       /* '+'  */
  YYSYMBOL_89_ = 89,                       /* '-'  */
  YYSYMBOL_90_ = 90,                       /* '*'  */
  YYSYMBOL_91_ = 91,                       /* '/'  */
  YYSYMBOL_UMINUS = 92,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 93,                  /* $accept  */
  YYSYMBOL_commands = 94,                  /* commands  */
  YYSYMBOL_command_wrapper = 95,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 96,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 97,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 98,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 99,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 100,              /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 101,            /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 102,          /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 103,         /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 104,          /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 105,        /* create_index_stmt  */
  YYSYMBOL_id_list = 106,                  /* id_list  */
  YYSYMBOL_drop_index_stmt = 107,          /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 108,        /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 109,            /* attr_def_list  */
  YYSYMBOL_attr_def = 110,                 /* attr_def  */
  YYSYMBOL_null_def = 111,                 /* null_def  */
  YYSYMBOL_number = 112,                   /* number  */
  YYSYMBOL_type = 113,                     /* type  */
  YYSYMBOL_insert_stmt = 114,              /* insert_stmt  */
  YYSYMBOL_value_list = 115,               /* value_list  */
  YYSYMBOL_value = 116,                    /* value  */
  YYSYMBOL_storage_format = 117,           /* storage_format  */
  YYSYMBOL_delete_stmt = 118,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 119,              /* update_stmt  */
  YYSYMBOL_update_target = 120,            /* update_target  */
  YYSYMBOL_update_target_list = 121,       /* update_target_list  */
  YYSYMBOL_select_stmt = 122,              /* select_stmt  */
  YYSYMBOL_sub_select_stmt = 123,          /* sub_select_stmt  */
  YYSYMBOL_calc_stmt = 124,                /* calc_stmt  */
  YYSYMBOL_expression_list = 125,          /* expression_list  */
  YYSYMBOL_expression = 126,               /* expression  */
  YYSYMBOL_relation = 127,                 /* relation  */
  YYSYMBOL_rel_list = 128,                 /* rel_list  */
  YYSYMBOL_where = 129,                    /* where  */
  YYSYMBOL_join_list = 130,                /* join_list  */
  YYSYMBOL_order_by_list = 131,            /* order_by_list  */
  YYSYMBOL_order_by = 132,                 /* order_by  */
  YYSYMBOL_order_by_flag = 133,            /* order_by_flag  */
  YYSYMBOL_condition_list = 134,           /* condition_list  */
  YYSYMBOL_condition = 135,                /* condition  */
  YYSYMBOL_comp_op = 136,                  /* comp_op  */
  YYSYMBOL_group_by = 137,                 /* group_by  */
  YYSYMBOL_load_data_stmt = 138,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 139,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 140,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 141             /* opt_semicolon  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  80
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   720

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  305

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   343


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    90,    88,     2,    89,     2,    91,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    92
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   234,   234,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   265,   272,   278,   285,   292,   299,   306,
     314,   321,   330,   347,   371,   375,   388,   399,   424,   427,
     440,   454,   465,   468,   471,   475,   478,   479,   480,   481,
     482,   483,   486,   504,   508,   520,   524,   529,   533,   538,
     542,   551,   557,   563,   577,   580,   587,   600,   618,   627,
     638,   641,   651,   656,   692,   698,   707,   712,   723,   729,
     734,   739,   744,   749,   754,   758,   762,   765,   768,   772,
     775,   780,   783,   786,   789,   792,   795,   798,   805,   812,
     819,   826,   833,   837,   841,   845,   849,   853,   860,   865,
     871,   880,   883,   896,   899,   906,   909,   921,   924,   937,
     940,   953,   956,   960,   968,   971,   976,   983,   992,  1003,
    1014,  1023,  1032,  1045,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,  1054,  1055,  1056,  1057,  1058,  1064,  1069,  1083,
    1092,  1103,  1104
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "BY",
  "CREATE", "DROP", "GROUP", "INNER_JOIN", "TABLE", "TABLES", "INDEX",
  "CALC", "SELECT", "ASC", "DESC", "SHOW", "SYNC", "INSERT", "DELETE",
  "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "DATE_T", "STRING_T", "FLOAT_T", "VECTOR_T",
  "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE",
  "AND", "SET", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN", "STORAGE",
  "FORMAT", "MAX", "MIN", "AVG", "SUM", "COUNT", "NOT_LIKE", "LIKE",
  "NOT_IN", "IN", "NOT_EXISTS", "EXISTS", "LENGTH", "ROUND", "DATE_FORMAT",
  "NULLABLE", "UNNULLABLE", "IS_NULL", "IS_NOT_NULL", "VEC_L2_DISTANCE",
  "VEC_COSINE_DISTANCE_FUNC", "VEC_INNER_PRODUCT_FUNC", "LBRACKET",
  "RBRACKET", "UNIQUE", "ORDER_BY", "AS", "EQ", "LT", "GT", "LE", "GE",
  "NE", "NUMBER", "FLOAT", "ID", "DATE_STR", "TEXT_STR", "SSS",
  "HIGHER_THAN_EXPRESSION", "'+'", "'-'", "'*'", "'/'", "UMINUS",
  "$accept", "commands", "command_wrapper", "exit_stmt", "help_stmt",
  "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "id_list", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "null_def", "number", "type", "insert_stmt",
  "value_list", "value", "storage_format", "delete_stmt", "update_stmt",
  "update_target", "update_target_list", "select_stmt", "sub_select_stmt",
  "calc_stmt", "expression_list", "expression", "relation", "rel_list",
  "where", "join_list", "order_by_list", "order_by", "order_by_flag",
  "condition_list", "condition", "comp_op", "group_by", "load_data_stmt",
  "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-254)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     639,     4,    19,   471,   471,   -65,    14,  -254,    20,     7,
     -22,  -254,  -254,  -254,  -254,  -254,    24,    33,   639,   111,
      88,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,    34,    35,   108,    41,    47,   471,   110,   112,   114,
     116,   117,   136,   141,   142,  -254,   143,   144,   150,   121,
    -254,  -254,   -28,  -254,  -254,  -254,   514,  -254,  -254,  -254,
      78,    94,  -254,  -254,    99,   103,   149,   119,   148,  -254,
    -254,  -254,  -254,   171,   153,   125,  -254,   167,   -20,   256,
     299,   342,   385,   428,   471,   471,   471,   471,   471,   471,
     -42,   175,   128,   130,  -254,  -254,  -254,  -254,   471,   471,
     471,   471,   471,   131,   178,   179,   134,   121,   139,   137,
     145,   177,   146,  -254,  -254,   204,  -254,   211,  -254,   212,
    -254,   217,  -254,   219,   -16,   133,   147,   156,   160,   209,
    -254,  -254,   121,   172,   -60,  -254,  -254,   -58,   -58,  -254,
    -254,   -49,   208,   221,   206,  -254,   195,   229,  -254,   243,
     118,   230,   259,   210,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,   471,   471,   471,   471,   471,   175,  -254,   218,  -254,
     220,  -254,   131,   286,   121,    91,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
     640,   612,  -254,   262,   283,   115,   134,   179,   301,  -254,
    -254,  -254,  -254,  -254,  -254,    -4,   137,   289,   231,   291,
      -6,     5,     9,    25,    32,  -254,  -254,  -254,   208,   131,
     179,   175,   293,   471,   557,   206,   300,  -254,  -254,  -254,
     229,  -254,   239,   246,  -254,  -254,  -254,   230,   281,   306,
     247,  -254,  -254,  -254,  -254,  -254,  -254,   290,  -254,   309,
    -254,   -53,    91,  -254,   -53,  -254,  -254,  -254,  -254,   311,
    -254,   287,  -254,   251,   314,   306,   206,   270,  -254,    21,
      39,   269,   306,  -254,   325,   286,   471,  -254,   331,  -254,
     271,  -254,  -254,  -254,   -10,  -254,  -254,  -254,  -254,   332,
     471,  -254,   -10,   332,  -254
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     151,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
      56,    57,    78,    60,    61,    62,     0,    91,    90,    75,
      76,    72,    31,    30,     0,     0,     0,     0,     0,   149,
       1,   152,     2,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,    80,    56,    57,    89,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,    88,    92,     0,    93,     0,    94,     0,
      95,     0,    96,     0,     0,     0,     0,     0,     0,     0,
      58,    59,     0,     0,    79,    81,    77,    84,    85,    86,
      87,   108,   111,     0,   124,    66,     0,    70,   150,     0,
       0,    38,     0,     0,    36,    97,    98,   100,   101,    99,
     102,     0,     0,     0,     0,     0,    53,    63,     0,    82,
       0,   109,     0,   115,     0,     0,   141,   142,   143,   144,
     145,   146,   139,   140,   133,   134,   135,   136,   137,   138,
       0,     0,   114,   125,     0,     0,     0,   113,     0,    46,
      49,    47,    48,    50,    51,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    83,   110,   111,     0,
     113,    53,     0,     0,   127,   124,     0,   131,    68,    69,
      70,    67,     0,     0,    43,    44,    41,    38,    64,    34,
       0,   103,   104,   107,   106,   105,   112,     0,   147,     0,
      74,   129,     0,   128,   130,   126,    71,   148,    45,     0,
      39,     0,    37,     0,     0,    34,   124,   117,    52,    90,
      42,     0,    34,    32,     0,   115,     0,    73,     0,    40,
       0,    35,    33,   116,   121,   132,    65,   122,   123,   119,
       0,   118,   121,   119,   120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -254,  -254,   338,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -253,  -254,  -254,   123,   155,    77,  -254,
    -254,  -254,  -173,   -50,  -254,  -254,  -254,   152,   132,     8,
    -193,  -254,    -3,   -46,  -172,   151,  -188,    80,  -254,    70,
      72,  -214,  -254,   -91,  -254,  -254,  -254,  -254,  -254
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   274,    31,    32,   217,   161,   246,   269,
     215,    33,   143,    68,   272,    34,    35,   157,   207,   232,
     200,    37,    69,    70,   152,   183,   155,   230,   287,   301,
     299,   202,   203,   204,   277,    38,    39,    40,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,    71,   123,   225,   297,   298,   170,   102,    36,   101,
     228,   237,   239,    41,   178,    42,   251,   243,    72,   241,
     107,   265,   284,   179,    73,   180,    36,   252,    44,   291,
      45,   253,   111,   112,   181,   109,   110,   111,   112,   140,
     141,   263,   258,   -53,   142,    75,   103,   254,   134,   135,
     136,   137,   138,   139,   255,   104,    74,   257,   259,   244,
     245,    76,   285,   147,   148,   149,   150,   158,   109,   110,
     111,   112,   109,   110,   111,   112,    43,    78,   109,   110,
     111,   112,   109,   110,   111,   112,   125,   127,   129,   131,
     133,    81,   176,   109,   110,   111,   112,   109,   110,   111,
     112,   108,   244,   245,     4,   146,   288,    77,   201,   233,
     234,    80,    46,   109,   110,   111,   112,    83,    84,    85,
     109,   110,   111,   112,    86,   220,   221,   222,   223,   224,
      87,    89,   113,    90,   231,    91,   236,    92,    93,    88,
      47,    48,    49,    50,    51,   209,   210,   211,   212,   213,
     214,    52,    53,    54,    55,   238,   171,    94,    56,    57,
      58,    59,    95,    96,    97,    98,   109,   110,   111,   112,
     172,    99,    60,    61,    62,    63,    64,    65,    55,   173,
      66,    67,   114,   174,    55,    59,   115,   261,   264,   201,
     116,    59,   119,   118,   117,   120,    60,    61,   142,    63,
      64,    65,    60,    61,   100,    63,    64,    65,   121,   122,
     100,   144,   279,   145,   151,   153,    88,   156,   154,   163,
     160,   109,   110,   111,   112,   159,   165,   185,   162,   164,
     201,   182,   175,   166,   167,   109,   110,   111,   112,   168,
     294,   169,   184,   177,   109,   110,   111,   112,   109,   110,
     111,   112,   206,   216,   302,    47,    48,    49,    50,    51,
     186,   187,   188,   189,   190,   191,    52,    53,    54,    55,
     205,   192,   193,    56,    57,    58,    59,    46,   124,   208,
     218,   194,   195,   196,   197,   198,   199,    60,    61,    62,
      63,    64,    65,   219,   229,    66,    67,   109,   110,   111,
     112,   226,   235,   227,   236,    47,    48,    49,    50,    51,
     242,   248,   250,     4,   249,   260,    52,    53,    54,    55,
      46,   126,   267,    56,    57,    58,    59,   268,   271,   273,
     275,   278,   276,   280,   282,   281,   283,    60,    61,    62,
      63,    64,    65,   286,   290,    66,    67,   292,    47,    48,
      49,    50,    51,   295,   296,   300,    79,   289,   240,    52,
      53,    54,    55,    46,   128,   293,    56,    57,    58,    59,
     270,   247,   266,   304,   303,     0,     0,     0,     0,   256,
      60,    61,    62,    63,    64,    65,     0,     0,    66,    67,
       0,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,    52,    53,    54,    55,    46,   130,     0,    56,
      57,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,    65,     0,
       0,    66,    67,     0,    47,    48,    49,    50,    51,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,    46,
     132,     0,    56,    57,    58,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,     0,     0,    66,    67,     0,    47,    48,    49,
      50,    51,     0,     0,     0,     0,     0,     0,    52,    53,
      54,    55,    46,     0,     0,    56,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,     0,     0,    66,    67,     0,
      47,    48,    49,    50,    51,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,    46,     0,     0,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,    65,     0,     0,
      66,    67,     0,    47,    48,    49,    50,    51,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,   262,     0,
       0,    56,    57,    58,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,    62,    63,    64,
      65,     0,     0,    66,    67,     0,    47,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,    65,     1,     2,    66,    67,     0,     0,
       0,     3,     4,     0,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,   186,   187,   188,   189,
     190,   191,    14,    15,     0,     0,     0,   192,   193,     0,
      16,     0,    17,     0,     0,    18,     0,   194,   195,   196,
     197,   198,   199,     0,   186,   187,   188,   189,   190,   191,
     109,   110,   111,   112,     0,   192,   193,     0,     0,     0,
       0,     0,     0,     0,     0,   194,   195,   196,   197,   198,
     199
};

static const yytype_int16 yycheck[] =
{
      46,     4,    22,   176,    14,    15,    22,    35,     0,    59,
     182,   204,   205,     9,    74,    11,    22,    21,    83,   207,
      66,   235,   275,    83,    10,    74,    18,    22,     9,   282,
      11,    22,    90,    91,    83,    88,    89,    90,    91,    81,
      82,   234,   230,    22,    23,    38,    74,    22,    94,    95,
      96,    97,    98,    99,    22,    83,    36,   229,   231,    63,
      64,    83,   276,   109,   110,   111,   112,   117,    88,    89,
      90,    91,    88,    89,    90,    91,    72,    44,    88,    89,
      90,    91,    88,    89,    90,    91,    89,    90,    91,    92,
      93,     3,   142,    88,    89,    90,    91,    88,    89,    90,
      91,    23,    63,    64,    13,   108,   279,    83,   154,   200,
     201,     0,    21,    88,    89,    90,    91,    83,    83,    11,
      88,    89,    90,    91,    83,   171,   172,   173,   174,   175,
      83,    21,    38,    21,   184,    21,    21,    21,    21,   185,
      49,    50,    51,    52,    53,    27,    28,    29,    30,    31,
      32,    60,    61,    62,    63,   205,    23,    21,    67,    68,
      69,    70,    21,    21,    21,    21,    88,    89,    90,    91,
      23,    21,    81,    82,    83,    84,    85,    86,    63,    23,
      89,    90,    83,    23,    63,    70,    83,   233,   234,   235,
      41,    70,    21,    45,    75,    42,    81,    82,    23,    84,
      85,    86,    81,    82,    89,    84,    85,    86,    83,    42,
      89,    83,   262,    83,    83,    37,   262,    83,    39,    42,
      83,    88,    89,    90,    91,    86,    22,    21,    83,    83,
     276,    23,    23,    22,    22,    88,    89,    90,    91,    22,
     286,    22,    21,    71,    88,    89,    90,    91,    88,    89,
      90,    91,    23,    23,   300,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      75,    65,    66,    67,    68,    69,    70,    21,    22,    36,
      21,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    83,     8,    89,    90,    88,    89,    90,
      91,    83,    40,    83,    21,    49,    50,    51,    52,    53,
       9,    22,    21,    13,    83,    22,    60,    61,    62,    63,
      21,    22,    83,    67,    68,    69,    70,    81,    47,    23,
      83,    22,    42,    22,    83,    48,    22,    81,    82,    83,
      84,    85,    86,    73,    75,    89,    90,    22,    49,    50,
      51,    52,    53,    22,    83,    23,    18,   280,   206,    60,
      61,    62,    63,    21,    22,   285,    67,    68,    69,    70,
     247,   216,   240,   303,   302,    -1,    -1,    -1,    -1,   228,
      81,    82,    83,    84,    85,    86,    -1,    -1,    89,    90,
      -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    21,    22,    -1,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    86,    -1,
      -1,    89,    90,    -1,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    21,
      22,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    21,    -1,    -1,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    -1,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    21,    -1,    -1,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    -1,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    21,    -1,
      -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    -1,    89,    90,    -1,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,     5,     6,    89,    90,    -1,    -1,
      -1,    12,    13,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    54,    55,    56,    57,
      58,    59,    33,    34,    -1,    -1,    -1,    65,    66,    -1,
      41,    -1,    43,    -1,    -1,    46,    -1,    75,    76,    77,
      78,    79,    80,    -1,    54,    55,    56,    57,    58,    59,
      88,    89,    90,    91,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    12,    13,    15,    16,    17,    18,    19,
      20,    24,    25,    26,    33,    34,    41,    43,    46,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   107,   108,   114,   118,   119,   122,   124,   138,   139,
     140,     9,    11,    72,     9,    11,    21,    49,    50,    51,
      52,    53,    60,    61,    62,    63,    67,    68,    69,    70,
      81,    82,    83,    84,    85,    86,    89,    90,   116,   125,
     126,   125,    83,    10,    36,    38,    83,    83,    44,    95,
       0,     3,   141,    83,    83,    11,    83,    83,   126,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      89,   116,    35,    74,    83,    81,    82,   126,    23,    88,
      89,    90,    91,    38,    83,    83,    41,    75,    45,    21,
      42,    83,    42,    22,    22,   125,    22,   125,    22,   125,
      22,   125,    22,   125,   126,   126,   126,   126,   126,   126,
      81,    82,    23,   115,    83,    83,   125,   126,   126,   126,
     126,    83,   127,    37,    39,   129,    83,   120,   116,    86,
      83,   110,    83,    42,    83,    22,    22,    22,    22,    22,
      22,    23,    23,    23,    23,    23,   116,    71,    74,    83,
      74,    83,    23,   128,    21,    21,    54,    55,    56,    57,
      58,    59,    65,    66,    75,    76,    77,    78,    79,    80,
     123,   126,   134,   135,   136,    75,    23,   121,    36,    27,
      28,    29,    30,    31,    32,   113,    23,   109,    21,    83,
     126,   126,   126,   126,   126,   115,    83,    83,   127,     8,
     130,   116,   122,   136,   136,    40,    21,   123,   116,   123,
     120,   129,     9,    21,    63,    64,   111,   110,    22,    83,
      21,    22,    22,    22,    22,    22,   128,   127,   129,   115,
      22,   126,    21,   123,   126,   134,   121,    83,    81,   112,
     109,    47,   117,    23,   106,    83,    42,   137,    22,   116,
      22,    48,    83,    22,   106,   134,    73,   131,   115,   111,
      75,   106,    22,   130,   126,    22,    83,    14,    15,   133,
      23,   132,   126,   133,   132
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   105,   106,   106,   107,   108,   109,   109,
     110,   110,   111,   111,   111,   112,   113,   113,   113,   113,
     113,   113,   114,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   117,   117,   118,   119,   120,   120,
     121,   121,   122,   122,   123,   124,   125,   125,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   133,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   137,   138,   139,
     140,   141,   141
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     9,    10,     0,     3,     5,     8,     0,     3,
       6,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     8,     0,     3,     1,     1,     1,     2,     2,
       1,     1,     1,     4,     0,     4,     4,     6,     3,     3,
       0,     3,     2,     9,     3,     2,     1,     3,     1,     3,
       2,     3,     4,     5,     3,     3,     3,     3,     3,     2,
       1,     1,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     6,     6,     1,     2,
       3,     0,     3,     0,     2,     0,     5,     0,     4,     0,
       4,     0,     1,     1,     0,     1,     3,     2,     3,     3,
       3,     2,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     7,     2,
       4,     0,     1
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
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
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


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
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
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
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
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 235 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1962 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 265 "yacc_sql.y"
         {
      LOG_DEBUG("parse exit_stmt");
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1972 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 272 "yacc_sql.y"
         {
      LOG_DEBUG("parse help_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1981 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 278 "yacc_sql.y"
         {
      LOG_DEBUG("parse sync_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1990 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 285 "yacc_sql.y"
               {
      LOG_DEBUG("parse begin_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1999 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 292 "yacc_sql.y"
               {
      LOG_DEBUG("parse commit_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2008 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 299 "yacc_sql.y"
                  {
      LOG_DEBUG("parse rollback_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2017 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 306 "yacc_sql.y"
                  {
      LOG_DEBUG("parse drop_table_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2028 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 314 "yacc_sql.y"
                {
      LOG_DEBUG("parse show_tables_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2037 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 321 "yacc_sql.y"
             {
      LOG_DEBUG("parse desc_table_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2048 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID id_list RBRACE  */
#line 331 "yacc_sql.y"
    {
      LOG_DEBUG("parse create_index_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      if ((yyvsp[-1].relation_list) != nullptr) {
        create_index.attribute_names.swap(*(yyvsp[-1].relation_list));
        delete (yyvsp[-1].relation_list);
      }
      create_index.attribute_names.emplace_back((yyvsp[-2].string));
      create_index.is_unique = false;
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
    }
#line 2069 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID id_list RBRACE  */
#line 348 "yacc_sql.y"
    {
      LOG_DEBUG("parse create_index_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      create_index.is_unique = true;
      std::vector<std::string> attribute_names;
      attribute_names.emplace_back((yyvsp[-2].string));
      if ((yyvsp[-1].relation_list) != nullptr) {
        attribute_names.insert(attribute_names.end(), (yyvsp[-1].relation_list)->begin(), (yyvsp[-1].relation_list)->end());
        delete (yyvsp[-1].relation_list);
      }
      create_index.attribute_names = std::move(attribute_names);

      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
    }
#line 2093 "yacc_sql.cpp"
    break;

  case 34: /* id_list: %empty  */
#line 371 "yacc_sql.y"
    {
      LOG_DEBUG("parse id_list");
      (yyval.relation_list) = nullptr;
    }
#line 2102 "yacc_sql.cpp"
    break;

  case 35: /* id_list: COMMA ID id_list  */
#line 375 "yacc_sql.y"
                        { 
      LOG_DEBUG("parse id_list");
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }
      (yyval.relation_list)->emplace_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 2117 "yacc_sql.cpp"
    break;

  case 36: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 389 "yacc_sql.y"
    {
      LOG_DEBUG("parse drop_index_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2130 "yacc_sql.cpp"
    break;

  case 37: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 400 "yacc_sql.y"
    {
      LOG_DEBUG("parse create_table_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
        delete src_attrs;
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-3].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);
      if ((yyvsp[0].string) != nullptr) {
        create_table.storage_format = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 2156 "yacc_sql.cpp"
    break;

  case 38: /* attr_def_list: %empty  */
#line 424 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2164 "yacc_sql.cpp"
    break;

  case 39: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 428 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2178 "yacc_sql.cpp"
    break;

  case 40: /* attr_def: ID type LBRACE number RBRACE null_def  */
#line 441 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->can_be_null = (yyvsp[0].boolean);

      if((yyval.attr_info)->type == AttrType::VECTORS){
        (yyval.attr_info)->length = (yyvsp[-2].number) * 4;
      }

      free((yyvsp[-5].string));
    }
#line 2196 "yacc_sql.cpp"
    break;

  case 41: /* attr_def: ID type null_def  */
#line 455 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->can_be_null = (yyvsp[0].boolean);
      free((yyvsp[-2].string));
    }
#line 2209 "yacc_sql.cpp"
    break;

  case 42: /* null_def: %empty  */
#line 465 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2217 "yacc_sql.cpp"
    break;

  case 43: /* null_def: NULLABLE  */
#line 468 "yacc_sql.y"
               {
      (yyval.boolean) = true;
    }
#line 2225 "yacc_sql.cpp"
    break;

  case 44: /* null_def: UNNULLABLE  */
#line 471 "yacc_sql.y"
                 {
      (yyval.boolean) = false;
    }
#line 2233 "yacc_sql.cpp"
    break;

  case 45: /* number: NUMBER  */
#line 475 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2239 "yacc_sql.cpp"
    break;

  case 46: /* type: INT_T  */
#line 478 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2245 "yacc_sql.cpp"
    break;

  case 47: /* type: STRING_T  */
#line 479 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2251 "yacc_sql.cpp"
    break;

  case 48: /* type: FLOAT_T  */
#line 480 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2257 "yacc_sql.cpp"
    break;

  case 49: /* type: DATE_T  */
#line 481 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATE); }
#line 2263 "yacc_sql.cpp"
    break;

  case 50: /* type: VECTOR_T  */
#line 482 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::VECTORS); }
#line 2269 "yacc_sql.cpp"
    break;

  case 51: /* type: TEXT_T  */
#line 483 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::TEXT); }
#line 2275 "yacc_sql.cpp"
    break;

  case 52: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 487 "yacc_sql.y"
    {
      LOG_DEBUG("parse insert_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-5].string);
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[-1].value_list));
        delete (yyvsp[-1].value_list);
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-2].value);
      free((yyvsp[-5].string));
    }
#line 2293 "yacc_sql.cpp"
    break;

  case 53: /* value_list: %empty  */
#line 504 "yacc_sql.y"
    {
      LOG_DEBUG("parse value_list");
      (yyval.value_list) = nullptr;
    }
#line 2302 "yacc_sql.cpp"
    break;

  case 54: /* value_list: COMMA value value_list  */
#line 508 "yacc_sql.y"
                              { 
      LOG_DEBUG("parse value_list");
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2317 "yacc_sql.cpp"
    break;

  case 55: /* value: NULLABLE  */
#line 520 "yacc_sql.y"
             {
      (yyval.value) = new Value(string("ckk is stupid!"), 114514);
      (yyloc) = (yylsp[0]);
    }
#line 2326 "yacc_sql.cpp"
    break;

  case 56: /* value: NUMBER  */
#line 524 "yacc_sql.y"
            {
      LOG_DEBUG("NUMBER: ", (yyvsp[0].number));
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2336 "yacc_sql.cpp"
    break;

  case 57: /* value: FLOAT  */
#line 529 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2345 "yacc_sql.cpp"
    break;

  case 58: /* value: '-' NUMBER  */
#line 533 "yacc_sql.y"
                {
      LOG_DEBUG("- %d", (yyvsp[0].number));
      (yyval.value) = new Value(-(int)(yyvsp[0].number));
      (yyloc) = (yylsp[-1]);
    }
#line 2355 "yacc_sql.cpp"
    break;

  case 59: /* value: '-' FLOAT  */
#line 538 "yacc_sql.y"
               {
      (yyval.value) = new Value(-(float)(yyvsp[0].floats));
      (yyloc) = (yylsp[-1]);
    }
#line 2364 "yacc_sql.cpp"
    break;

  case 60: /* value: DATE_STR  */
#line 542 "yacc_sql.y"
              {
      char *tmp = common::substr((yyvsp[0].string), 1, strlen((yyvsp[0].string))-2);  // 去掉首尾的引号
      int year, month, day;
      sscanf(tmp, "%d-%d-%d", &year, &month, &day);    //sscanf会自动转换字符串中的数字，不用显式stoi
      int date_num = year * 10000 + month * 100 + day;
      (yyval.value) = new Value(date_num, true);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2378 "yacc_sql.cpp"
    break;

  case 61: /* value: TEXT_STR  */
#line 551 "yacc_sql.y"
              {
      char *tmp = common::substr((yyvsp[0].string), 1, strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp, strlen(tmp));
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2389 "yacc_sql.cpp"
    break;

  case 62: /* value: SSS  */
#line 557 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp, strlen(tmp));  
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2400 "yacc_sql.cpp"
    break;

  case 63: /* value: LBRACKET value value_list RBRACKET  */
#line 563 "yacc_sql.y"
                                         {
      std::vector<float> nums;
      nums.emplace_back((yyvsp[-2].value)->get_float());
      if((yyvsp[-1].value_list) != nullptr) {
        std::reverse((yyvsp[-1].value_list)->begin(), (yyvsp[-1].value_list)->end());
        for (Value value : *(yyvsp[-1].value_list)) {
          nums.emplace_back(value.get_float());
        }
      }
      (yyval.value) = new Value(nums);
    }
#line 2416 "yacc_sql.cpp"
    break;

  case 64: /* storage_format: %empty  */
#line 577 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2424 "yacc_sql.cpp"
    break;

  case 65: /* storage_format: STORAGE FORMAT EQ ID  */
#line 581 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2432 "yacc_sql.cpp"
    break;

  case 66: /* delete_stmt: DELETE FROM ID where  */
#line 588 "yacc_sql.y"
    {
      LOG_DEBUG("parse delete_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2447 "yacc_sql.cpp"
    break;

  case 67: /* update_stmt: UPDATE ID SET update_target update_target_list where  */
#line 601 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-4].string);

      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }

      if((yyvsp[-1].update_target_list) != nullptr)
        (yyval.sql_node)->update.update_targets.swap(*(yyvsp[-1].update_target_list));
      (yyval.sql_node)->update.update_targets.emplace_back(*(yyvsp[-2].update_target));
      std::reverse((yyval.sql_node)->update.update_targets.begin(), (yyval.sql_node)->update.update_targets.end());
    }
#line 2466 "yacc_sql.cpp"
    break;

  case 68: /* update_target: ID EQ value  */
#line 619 "yacc_sql.y"
    {
      (yyval.update_target) = new UpdateTarget;
      (yyval.update_target)->attribute_name = (yyvsp[-2].string);
      (yyval.update_target)->value = *(yyvsp[0].value);
      (yyval.update_target)->is_value = true;

      delete (yyvsp[0].value);
    }
#line 2479 "yacc_sql.cpp"
    break;

  case 69: /* update_target: ID EQ sub_select_stmt  */
#line 628 "yacc_sql.y"
    {
      (yyval.update_target) = new UpdateTarget;
      (yyval.update_target)->attribute_name = (yyvsp[-2].string);
      (yyval.update_target)->sub_select = (yyvsp[0].sql_node);
      (yyval.update_target)->is_value = false;
    }
#line 2490 "yacc_sql.cpp"
    break;

  case 70: /* update_target_list: %empty  */
#line 638 "yacc_sql.y"
    {
      (yyval.update_target_list) = nullptr;
    }
#line 2498 "yacc_sql.cpp"
    break;

  case 71: /* update_target_list: COMMA update_target update_target_list  */
#line 642 "yacc_sql.y"
    {
      if((yyvsp[0].update_target_list) == nullptr)
        (yyval.update_target_list) = new std::vector<UpdateTarget>;
      else (yyval.update_target_list) = (yyvsp[0].update_target_list);
      (yyval.update_target_list)->emplace_back(*(yyvsp[-1].update_target));
    }
#line 2509 "yacc_sql.cpp"
    break;

  case 72: /* select_stmt: SELECT expression_list  */
#line 652 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      (yyval.sql_node)->selection.expressions.swap(*(yyvsp[0].expression_list));
    }
#line 2518 "yacc_sql.cpp"
    break;

  case 73: /* select_stmt: SELECT expression_list FROM relation rel_list join_list where group_by order_by_list  */
#line 657 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-7].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-7].expression_list));
        delete (yyvsp[-7].expression_list);
      }

      if ((yyvsp[-4].expression_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-4].expression_list));
        delete (yyvsp[-4].expression_list);
      }
      (yyval.sql_node)->selection.relations.emplace_back((yyvsp[-5].expression));

      if ((yyvsp[-3].expression_list) != nullptr) {
        (yyval.sql_node)->selection.join.swap(*(yyvsp[-3].expression_list));
        delete (yyvsp[-3].expression_list);
      }

      if ((yyvsp[-2].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-2].condition_list));
        delete (yyvsp[-2].condition_list);
      }

      if ((yyvsp[-1].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[-1].expression_list));
        delete (yyvsp[-1].expression_list);
      }

      if((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->selection.order_by.swap(*(yyvsp[0].expression_list));
        delete (yyvsp[0].expression_list);
      }
    }
#line 2556 "yacc_sql.cpp"
    break;

  case 74: /* sub_select_stmt: LBRACE select_stmt RBRACE  */
#line 693 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[-1].sql_node);
    }
#line 2564 "yacc_sql.cpp"
    break;

  case 75: /* calc_stmt: CALC expression_list  */
#line 699 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2574 "yacc_sql.cpp"
    break;

  case 76: /* expression_list: expression  */
#line 708 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2583 "yacc_sql.cpp"
    break;

  case 77: /* expression_list: expression COMMA expression_list  */
#line 713 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2596 "yacc_sql.cpp"
    break;

  case 78: /* expression: ID  */
#line 723 "yacc_sql.y"
       {
      LOG_DEBUG("ID %s", (yyvsp[0].string));
      (yyval.expression) = new UnboundFieldExpr(string(), (yyvsp[0].string));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      free((yyvsp[0].string));
    }
#line 2607 "yacc_sql.cpp"
    break;

  case 79: /* expression: ID DOT ID  */
#line 729 "yacc_sql.y"
                {
      (yyval.expression) = new UnboundFieldExpr((yyvsp[-2].string), (yyvsp[0].string));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      free((yyvsp[-2].string));
    }
#line 2617 "yacc_sql.cpp"
    break;

  case 80: /* expression: ID ID  */
#line 734 "yacc_sql.y"
            {
      (yyval.expression) = new UnboundFieldExpr(string(), (yyvsp[-1].string), (yyvsp[0].string));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      free((yyvsp[-1].string));
    }
#line 2627 "yacc_sql.cpp"
    break;

  case 81: /* expression: ID AS ID  */
#line 739 "yacc_sql.y"
               {
      (yyval.expression) = new UnboundFieldExpr(string(), (yyvsp[-2].string), (yyvsp[0].string));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      free((yyvsp[-2].string));
    }
#line 2637 "yacc_sql.cpp"
    break;

  case 82: /* expression: ID DOT ID ID  */
#line 744 "yacc_sql.y"
                   {
      (yyval.expression) = new UnboundFieldExpr((yyvsp[-3].string), (yyvsp[-1].string), (yyvsp[0].string));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      free((yyvsp[-3].string));
    }
#line 2647 "yacc_sql.cpp"
    break;

  case 83: /* expression: ID DOT ID AS ID  */
#line 749 "yacc_sql.y"
                      {
      (yyval.expression) = new UnboundFieldExpr((yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      free((yyvsp[-4].string));
    }
#line 2657 "yacc_sql.cpp"
    break;

  case 84: /* expression: expression '+' expression  */
#line 754 "yacc_sql.y"
                                {
      LOG_DEBUG("add");
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2666 "yacc_sql.cpp"
    break;

  case 85: /* expression: expression '-' expression  */
#line 758 "yacc_sql.y"
                                {
      LOG_DEBUG("sub");
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2675 "yacc_sql.cpp"
    break;

  case 86: /* expression: expression '*' expression  */
#line 762 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2683 "yacc_sql.cpp"
    break;

  case 87: /* expression: expression '/' expression  */
#line 765 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2691 "yacc_sql.cpp"
    break;

  case 88: /* expression: LBRACE expression RBRACE  */
#line 768 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2700 "yacc_sql.cpp"
    break;

  case 89: /* expression: '-' expression  */
#line 772 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2708 "yacc_sql.cpp"
    break;

  case 90: /* expression: value  */
#line 775 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2718 "yacc_sql.cpp"
    break;

  case 91: /* expression: '*'  */
#line 780 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2726 "yacc_sql.cpp"
    break;

  case 92: /* expression: MAX LBRACE RBRACE  */
#line 783 "yacc_sql.y"
                        {
      (yyval.expression) = create_aggregate_expression("MAX", nullptr, sql_string, &(yyloc));
    }
#line 2734 "yacc_sql.cpp"
    break;

  case 93: /* expression: MIN LBRACE RBRACE  */
#line 786 "yacc_sql.y"
                        {
      (yyval.expression) = create_aggregate_expression("MIN", nullptr, sql_string, &(yyloc));
    }
#line 2742 "yacc_sql.cpp"
    break;

  case 94: /* expression: AVG LBRACE RBRACE  */
#line 789 "yacc_sql.y"
                        {
      (yyval.expression) = create_aggregate_expression("AVG", nullptr, sql_string, &(yyloc));
    }
#line 2750 "yacc_sql.cpp"
    break;

  case 95: /* expression: SUM LBRACE RBRACE  */
#line 792 "yacc_sql.y"
                        {
      (yyval.expression) = create_aggregate_expression("SUM", nullptr, sql_string, &(yyloc));
    }
#line 2758 "yacc_sql.cpp"
    break;

  case 96: /* expression: COUNT LBRACE RBRACE  */
#line 795 "yacc_sql.y"
                          {
      (yyval.expression) = create_aggregate_expression("COUNT", nullptr, sql_string, &(yyloc));
    }
#line 2766 "yacc_sql.cpp"
    break;

  case 97: /* expression: MAX LBRACE expression_list RBRACE  */
#line 798 "yacc_sql.y"
                                        {
      if((yyvsp[-1].expression_list)->size() != 1) {
        (yyval.expression) = create_aggregate_expression("MAX", nullptr, sql_string, &(yyloc));
      } else {
        (yyval.expression) = create_aggregate_expression("MAX", (yyvsp[-1].expression_list)->at(0).get(), sql_string, &(yyloc));
      }
    }
#line 2778 "yacc_sql.cpp"
    break;

  case 98: /* expression: MIN LBRACE expression_list RBRACE  */
#line 805 "yacc_sql.y"
                                        {
      if((yyvsp[-1].expression_list)->size() != 1) {
        (yyval.expression) = create_aggregate_expression("MIN", nullptr, sql_string, &(yyloc));
      } else {
        (yyval.expression) = create_aggregate_expression("MIN", (yyvsp[-1].expression_list)->at(0).get(), sql_string, &(yyloc));
      }
    }
#line 2790 "yacc_sql.cpp"
    break;

  case 99: /* expression: COUNT LBRACE expression_list RBRACE  */
#line 812 "yacc_sql.y"
                                          {
      if((yyvsp[-1].expression_list)->size() != 1) {
        (yyval.expression) = create_aggregate_expression("COUNT", nullptr, sql_string, &(yyloc));
      } else {
        (yyval.expression) = create_aggregate_expression("COUNT", (yyvsp[-1].expression_list)->at(0).get(), sql_string, &(yyloc));
      }
    }
#line 2802 "yacc_sql.cpp"
    break;

  case 100: /* expression: AVG LBRACE expression_list RBRACE  */
#line 819 "yacc_sql.y"
                                        {
      if((yyvsp[-1].expression_list)->size() != 1) {
        (yyval.expression) = create_aggregate_expression("AVG", nullptr, sql_string, &(yyloc));
      } else {
        (yyval.expression) = create_aggregate_expression("AVG", (yyvsp[-1].expression_list)->at(0).get(), sql_string, &(yyloc));
      }
    }
#line 2814 "yacc_sql.cpp"
    break;

  case 101: /* expression: SUM LBRACE expression_list RBRACE  */
#line 826 "yacc_sql.y"
                                        {
      if((yyvsp[-1].expression_list)->size() != 1) {
        (yyval.expression) = create_aggregate_expression("SUM", nullptr, sql_string, &(yyloc));
      } else {
        (yyval.expression) = create_aggregate_expression("SUM", (yyvsp[-1].expression_list)->at(0).get(), sql_string, &(yyloc));
      }
    }
#line 2826 "yacc_sql.cpp"
    break;

  case 102: /* expression: LENGTH LBRACE expression RBRACE  */
#line 833 "yacc_sql.y"
                                      {
      (yyval.expression) = new FuncExpr(FuncExpr::FuncType::LENGTH, nullptr, nullptr, (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2835 "yacc_sql.cpp"
    break;

  case 103: /* expression: ROUND LBRACE expression COMMA expression RBRACE  */
#line 837 "yacc_sql.y"
                                                      {
      (yyval.expression) = new FuncExpr(FuncExpr::FuncType::ROUND, (yyvsp[-1].expression), nullptr, (yyvsp[-3].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2844 "yacc_sql.cpp"
    break;

  case 104: /* expression: DATE_FORMAT LBRACE expression COMMA expression RBRACE  */
#line 841 "yacc_sql.y"
                                                            {
      (yyval.expression) = new FuncExpr(FuncExpr::FuncType::DATE_FORMAT, nullptr, (yyvsp[-1].expression), (yyvsp[-3].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2853 "yacc_sql.cpp"
    break;

  case 105: /* expression: VEC_INNER_PRODUCT_FUNC LBRACE expression COMMA expression RBRACE  */
#line 845 "yacc_sql.y"
                                                                       {
      (yyval.expression) = new VecFuncExpr(VecFuncExpr::VecFuncType::INNER_PRODUCT, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2862 "yacc_sql.cpp"
    break;

  case 106: /* expression: VEC_COSINE_DISTANCE_FUNC LBRACE expression COMMA expression RBRACE  */
#line 849 "yacc_sql.y"
                                                                         {
      (yyval.expression) = new VecFuncExpr(VecFuncExpr::VecFuncType::COSINE_DISTANCE, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2871 "yacc_sql.cpp"
    break;

  case 107: /* expression: VEC_L2_DISTANCE LBRACE expression COMMA expression RBRACE  */
#line 853 "yacc_sql.y"
                                                                {
      (yyval.expression) = new VecFuncExpr(VecFuncExpr::VecFuncType::L2_DISTANCE, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2880 "yacc_sql.cpp"
    break;

  case 108: /* relation: ID  */
#line 860 "yacc_sql.y"
       {
      (yyval.expression) = new UnboundTableExpr((yyvsp[0].string), string());
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      free((yyvsp[0].string));
    }
#line 2890 "yacc_sql.cpp"
    break;

  case 109: /* relation: ID ID  */
#line 865 "yacc_sql.y"
            {
      (yyval.expression) = new UnboundTableExpr((yyvsp[-1].string), (yyvsp[0].string));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      free((yyvsp[-1].string));
      free((yyvsp[0].string));
    }
#line 2901 "yacc_sql.cpp"
    break;

  case 110: /* relation: ID AS ID  */
#line 871 "yacc_sql.y"
               {
      (yyval.expression) = new UnboundTableExpr((yyvsp[-2].string), (yyvsp[0].string));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2912 "yacc_sql.cpp"
    break;

  case 111: /* rel_list: %empty  */
#line 880 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2920 "yacc_sql.cpp"
    break;

  case 112: /* rel_list: COMMA relation rel_list  */
#line 883 "yacc_sql.y"
                              {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }

      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
    }
#line 2934 "yacc_sql.cpp"
    break;

  case 113: /* where: %empty  */
#line 896 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2942 "yacc_sql.cpp"
    break;

  case 114: /* where: WHERE condition_list  */
#line 899 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2950 "yacc_sql.cpp"
    break;

  case 115: /* join_list: %empty  */
#line 906 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2958 "yacc_sql.cpp"
    break;

  case 116: /* join_list: INNER_JOIN relation ON condition_list join_list  */
#line 909 "yacc_sql.y"
                                                      {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace_back(new JoinTableExpr(*(yyvsp[-1].condition_list), (yyvsp[-3].expression)));
    }
#line 2971 "yacc_sql.cpp"
    break;

  case 117: /* order_by_list: %empty  */
#line 921 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2979 "yacc_sql.cpp"
    break;

  case 118: /* order_by_list: ORDER_BY expression order_by_flag order_by  */
#line 925 "yacc_sql.y"
    {
       if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace_back(make_unique<OrderByExpr>((yyvsp[-2].expression), (yyvsp[-1].number)));
    }
#line 2992 "yacc_sql.cpp"
    break;

  case 119: /* order_by: %empty  */
#line 937 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3000 "yacc_sql.cpp"
    break;

  case 120: /* order_by: COMMA expression order_by_flag order_by  */
#line 941 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace_back(make_unique<OrderByExpr>((yyvsp[-2].expression), (yyvsp[-1].number)));
    }
#line 3013 "yacc_sql.cpp"
    break;

  case 121: /* order_by_flag: %empty  */
#line 953 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3021 "yacc_sql.cpp"
    break;

  case 122: /* order_by_flag: ASC  */
#line 957 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3029 "yacc_sql.cpp"
    break;

  case 123: /* order_by_flag: DESC  */
#line 961 "yacc_sql.y"
    {
      (yyval.number) = -1;
    }
#line 3037 "yacc_sql.cpp"
    break;

  case 124: /* condition_list: %empty  */
#line 968 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3045 "yacc_sql.cpp"
    break;

  case 125: /* condition_list: condition  */
#line 971 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3055 "yacc_sql.cpp"
    break;

  case 126: /* condition_list: condition AND condition_list  */
#line 976 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3065 "yacc_sql.cpp"
    break;

  case 127: /* condition: expression comp_op  */
#line 984 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_sub_query = false;
      (yyval.condition)->right_is_sub_query = false;
      (yyval.condition)->comp = (yyvsp[0].comp);
      (yyval.condition)->left_expression = (yyvsp[-1].expression);
      (yyval.condition)->right_expression = new ValueExpr(Value(114514));
    }
#line 3078 "yacc_sql.cpp"
    break;

  case 128: /* condition: expression comp_op sub_select_stmt  */
#line 993 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_sub_query = false;
      (yyval.condition)->right_is_sub_query = true;
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->left_expression = (yyvsp[-2].expression);
      (yyval.condition)->right_sub_query = (yyvsp[0].sql_node);
      (yyval.condition)->right_expression = nullptr;
    }
#line 3092 "yacc_sql.cpp"
    break;

  case 129: /* condition: sub_select_stmt comp_op expression  */
#line 1004 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_sub_query = true;
      (yyval.condition)->right_is_sub_query = false;
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->left_sub_query = (yyvsp[-2].sql_node);
      (yyval.condition)->left_expression = nullptr;
      (yyval.condition)->right_expression = (yyvsp[0].expression);
    }
#line 3106 "yacc_sql.cpp"
    break;

  case 130: /* condition: expression comp_op expression  */
#line 1015 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_sub_query = false;
      (yyval.condition)->right_is_sub_query = false;
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->left_expression = (yyvsp[-2].expression);
      (yyval.condition)->right_expression = (yyvsp[0].expression);
    }
#line 3119 "yacc_sql.cpp"
    break;

  case 131: /* condition: comp_op sub_select_stmt  */
#line 1024 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_sub_query = false;
      (yyval.condition)->right_is_sub_query = true;
      (yyval.condition)->right_sub_query = (yyvsp[0].sql_node);
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->left_expression = new ValueExpr(Value(114514));
    }
#line 3132 "yacc_sql.cpp"
    break;

  case 132: /* condition: expression comp_op LBRACE value value_list RBRACE  */
#line 1033 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_sub_query = false;
      (yyval.condition)->right_is_sub_query = false;
      (yyval.condition)->comp = (yyvsp[-4].comp);
      (yyval.condition)->left_expression = (yyvsp[-5].expression);
      (yyvsp[-1].value_list)->push_back(*(yyvsp[-2].value));
      (yyval.condition)->right_expression = new ValueListExpr(*(yyvsp[-1].value_list));
    }
#line 3146 "yacc_sql.cpp"
    break;

  case 133: /* comp_op: EQ  */
#line 1045 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3152 "yacc_sql.cpp"
    break;

  case 134: /* comp_op: LT  */
#line 1046 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3158 "yacc_sql.cpp"
    break;

  case 135: /* comp_op: GT  */
#line 1047 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3164 "yacc_sql.cpp"
    break;

  case 136: /* comp_op: LE  */
#line 1048 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3170 "yacc_sql.cpp"
    break;

  case 137: /* comp_op: GE  */
#line 1049 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3176 "yacc_sql.cpp"
    break;

  case 138: /* comp_op: NE  */
#line 1050 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3182 "yacc_sql.cpp"
    break;

  case 139: /* comp_op: IS_NULL  */
#line 1051 "yacc_sql.y"
              { (yyval.comp) = XXX_IS_NULL; }
#line 3188 "yacc_sql.cpp"
    break;

  case 140: /* comp_op: IS_NOT_NULL  */
#line 1052 "yacc_sql.y"
                  { (yyval.comp) = XXX_IS_NOT_NULL; }
#line 3194 "yacc_sql.cpp"
    break;

  case 141: /* comp_op: NOT_LIKE  */
#line 1053 "yacc_sql.y"
               { (yyval.comp) = NOT_LIKE_XXX; }
#line 3200 "yacc_sql.cpp"
    break;

  case 142: /* comp_op: LIKE  */
#line 1054 "yacc_sql.y"
           { (yyval.comp) = LIKE_XXX; }
#line 3206 "yacc_sql.cpp"
    break;

  case 143: /* comp_op: NOT_IN  */
#line 1055 "yacc_sql.y"
             { (yyval.comp) = NOT_IN_XXX; }
#line 3212 "yacc_sql.cpp"
    break;

  case 144: /* comp_op: IN  */
#line 1056 "yacc_sql.y"
         { (yyval.comp) = IN_XXX; }
#line 3218 "yacc_sql.cpp"
    break;

  case 145: /* comp_op: NOT_EXISTS  */
#line 1057 "yacc_sql.y"
                 { (yyval.comp) = XXX_NOT_EXISTS; }
#line 3224 "yacc_sql.cpp"
    break;

  case 146: /* comp_op: EXISTS  */
#line 1058 "yacc_sql.y"
             { (yyval.comp) = XXX_EXISTS; }
#line 3230 "yacc_sql.cpp"
    break;

  case 147: /* group_by: %empty  */
#line 1064 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 3238 "yacc_sql.cpp"
    break;

  case 148: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1070 "yacc_sql.y"
    {
      LOG_DEBUG("parse load_data_stmt");
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3253 "yacc_sql.cpp"
    break;

  case 149: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1084 "yacc_sql.y"
    {
      LOG_DEBUG("parse explain_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3263 "yacc_sql.cpp"
    break;

  case 150: /* set_variable_stmt: SET ID EQ value  */
#line 1093 "yacc_sql.y"
    {
      LOG_DEBUG("parse set_variable_stmt");
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3276 "yacc_sql.cpp"
    break;


#line 3280 "yacc_sql.cpp"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1106 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
