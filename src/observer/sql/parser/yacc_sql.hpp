/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_SQL_HPP_INCLUDED
# define YY_YY_YACC_SQL_HPP_INCLUDED
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
    SEMICOLON = 258,               /* SEMICOLON  */
    BY = 259,                      /* BY  */
    CREATE = 260,                  /* CREATE  */
    DROP = 261,                    /* DROP  */
    GROUP = 262,                   /* GROUP  */
    INNER_JOIN = 263,              /* INNER_JOIN  */
    HAVING = 264,                  /* HAVING  */
    TABLE = 265,                   /* TABLE  */
    TABLES = 266,                  /* TABLES  */
    INDEX = 267,                   /* INDEX  */
    CALC = 268,                    /* CALC  */
    SELECT = 269,                  /* SELECT  */
    ASC = 270,                     /* ASC  */
    DESC = 271,                    /* DESC  */
    SHOW = 272,                    /* SHOW  */
    SYNC = 273,                    /* SYNC  */
    INSERT = 274,                  /* INSERT  */
    DELETE = 275,                  /* DELETE  */
    UPDATE = 276,                  /* UPDATE  */
    LBRACE = 277,                  /* LBRACE  */
    RBRACE = 278,                  /* RBRACE  */
    COMMA = 279,                   /* COMMA  */
    TRX_BEGIN = 280,               /* TRX_BEGIN  */
    TRX_COMMIT = 281,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 282,            /* TRX_ROLLBACK  */
    INT_T = 283,                   /* INT_T  */
    DATE_T = 284,                  /* DATE_T  */
    STRING_T = 285,                /* STRING_T  */
    FLOAT_T = 286,                 /* FLOAT_T  */
    VECTOR_T = 287,                /* VECTOR_T  */
    TEXT_T = 288,                  /* TEXT_T  */
    HELP = 289,                    /* HELP  */
    EXIT = 290,                    /* EXIT  */
    DOT = 291,                     /* DOT  */
    INTO = 292,                    /* INTO  */
    VALUES = 293,                  /* VALUES  */
    FROM = 294,                    /* FROM  */
    WHERE = 295,                   /* WHERE  */
    AND = 296,                     /* AND  */
    SET = 297,                     /* SET  */
    ON = 298,                      /* ON  */
    LOAD = 299,                    /* LOAD  */
    DATA = 300,                    /* DATA  */
    INFILE = 301,                  /* INFILE  */
    EXPLAIN = 302,                 /* EXPLAIN  */
    STORAGE = 303,                 /* STORAGE  */
    FORMAT = 304,                  /* FORMAT  */
    MAX = 305,                     /* MAX  */
    MIN = 306,                     /* MIN  */
    AVG = 307,                     /* AVG  */
    SUM = 308,                     /* SUM  */
    COUNT = 309,                   /* COUNT  */
    NOT_LIKE = 310,                /* NOT_LIKE  */
    LIKE = 311,                    /* LIKE  */
    NOT_IN = 312,                  /* NOT_IN  */
    IN = 313,                      /* IN  */
    NOT_EXISTS = 314,              /* NOT_EXISTS  */
    EXISTS = 315,                  /* EXISTS  */
    LENGTH = 316,                  /* LENGTH  */
    ROUND = 317,                   /* ROUND  */
    DATE_FORMAT = 318,             /* DATE_FORMAT  */
    NULLABLE = 319,                /* NULLABLE  */
    UNNULLABLE = 320,              /* UNNULLABLE  */
    IS_NULL = 321,                 /* IS_NULL  */
    IS_NOT_NULL = 322,             /* IS_NOT_NULL  */
    VEC_L2_DISTANCE = 323,         /* VEC_L2_DISTANCE  */
    VEC_COSINE_DISTANCE_FUNC = 324, /* VEC_COSINE_DISTANCE_FUNC  */
    VEC_INNER_PRODUCT_FUNC = 325,  /* VEC_INNER_PRODUCT_FUNC  */
    LBRACKET = 326,                /* LBRACKET  */
    RBRACKET = 327,                /* RBRACKET  */
    UNIQUE = 328,                  /* UNIQUE  */
    ORDER_BY = 329,                /* ORDER_BY  */
    AS = 330,                      /* AS  */
    EQ = 331,                      /* EQ  */
    LT = 332,                      /* LT  */
    GT = 333,                      /* GT  */
    LE = 334,                      /* LE  */
    GE = 335,                      /* GE  */
    NE = 336,                      /* NE  */
    NUMBER = 337,                  /* NUMBER  */
    FLOAT = 338,                   /* FLOAT  */
    ID = 339,                      /* ID  */
    DATE_STR = 340,                /* DATE_STR  */
    TEXT_STR = 341,                /* TEXT_STR  */
    SSS = 342,                     /* SSS  */
    HIGHER_THAN_EXPRESSION = 343,  /* HIGHER_THAN_EXPRESSION  */
    UMINUS = 344                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 148 "yacc_sql.y"

  ParsedSqlNode *                            sql_node;
  ConditionSqlNode *                         condition;
  UpdateTarget *                             update_target;
  Value *                                    value;
  enum CompOp                                comp;
  std::vector<AttrInfoSqlNode> *             attr_infos;
  AttrInfoSqlNode *                          attr_info;
  Expression *                               expression;
  std::vector<std::unique_ptr<Expression>> * expression_list;
  std::vector<Value> *                       value_list;
  std::vector<ConditionSqlNode> *            condition_list;
  std::vector<std::string> *                 relation_list;
  std::vector<UpdateTarget> *                update_target_list;
  char *                                     string;
  int                                        number;
  float                                      floats;
  bool                                       boolean;

#line 173 "yacc_sql.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner);


#endif /* !YY_YY_YACC_SQL_HPP_INCLUDED  */
