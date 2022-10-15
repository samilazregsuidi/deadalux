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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"


// This is based on the original Yacc grammar of SPIN (spin.y):

/* Copyright (c) 1989-2003 by Lucent Technologies, Bell Laboratories.     */
/* All Rights Reserved.  This software is for educational purposes only.  */
/* No guarantee whatsoever is expressed or implied by the distribution of */
/* this code.  Permission is given to distribute this code provided that  */
/* this introductory message is not removed and no monies are exchanged.  */
/* Software written by Gerard J. Holzmann.  For tool documentation see:   */
/*             http://spinroot.com/                                       */
/* Send all bug-reports and/or questions to: bugs@spinroot.com            */

#include <stdlib.h>
#include <string>
#include <iostream>
#include <list>

#include "symbols.hpp"
#include "ast.hpp"

#include "y.tab.hpp"

#define YYDEBUG 1

#ifdef CPP
extern "C" 
#endif

int yylex(YYSTYPE * yylval_param, symTable** globalSymTab);

extern int nbrLines;

int yyerror (symTable** globalSymTab, stmnt** program, const char* msg){
	fprintf(stderr, "Syntax error on line %d: '%s'.\n", nbrLines, msg);
	exit(1);
}

std::string nameSpace = "global";
symbol::Type declType = symbol::T_NA;
tdefSymNode* typeDef = nullptr;
mtypedefSymNode* mtypeDef = nullptr;

symTable* currentSymTab = nullptr;
symTable* savedSymTab = nullptr;

std::list<varSymNode*> declSyms;
std::list<varSymNode*> typeLst;
std::list<std::string> params;
std::list<variantQuantifier*> variants;

int mtypeId = 1;
bool inInline = false;


#line 127 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"

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

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_DO = 5,                         /* DO  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_NAME = 7,                       /* NAME  */
  YYSYMBOL_UNAME = 8,                      /* UNAME  */
  YYSYMBOL_PNAME = 9,                      /* PNAME  */
  YYSYMBOL_INAME = 10,                     /* INAME  */
  YYSYMBOL_VNAME = 11,                     /* VNAME  */
  YYSYMBOL_BASE = 12,                      /* BASE  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_REAL = 14,                      /* REAL  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_SKIP = 17,                      /* SKIP  */
  YYSYMBOL_ASSERT = 18,                    /* ASSERT  */
  YYSYMBOL_PRINT = 19,                     /* PRINT  */
  YYSYMBOL_PRINTM = 20,                    /* PRINTM  */
  YYSYMBOL_C_CODE = 21,                    /* C_CODE  */
  YYSYMBOL_C_DECL = 22,                    /* C_DECL  */
  YYSYMBOL_C_EXPR = 23,                    /* C_EXPR  */
  YYSYMBOL_C_STATE = 24,                   /* C_STATE  */
  YYSYMBOL_C_TRACK = 25,                   /* C_TRACK  */
  YYSYMBOL_RUN = 26,                       /* RUN  */
  YYSYMBOL_LEN = 27,                       /* LEN  */
  YYSYMBOL_ENABLED = 28,                   /* ENABLED  */
  YYSYMBOL_EVAL = 29,                      /* EVAL  */
  YYSYMBOL_PC_VAL = 30,                    /* PC_VAL  */
  YYSYMBOL_TYPEDEF = 31,                   /* TYPEDEF  */
  YYSYMBOL_MTYPE = 32,                     /* MTYPE  */
  YYSYMBOL_INLINE = 33,                    /* INLINE  */
  YYSYMBOL_LABEL = 34,                     /* LABEL  */
  YYSYMBOL_OF = 35,                        /* OF  */
  YYSYMBOL_GOTO = 36,                      /* GOTO  */
  YYSYMBOL_BREAK = 37,                     /* BREAK  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_SEMI = 39,                      /* SEMI  */
  YYSYMBOL_FI = 40,                        /* FI  */
  YYSYMBOL_OD = 41,                        /* OD  */
  YYSYMBOL_SEP = 42,                       /* SEP  */
  YYSYMBOL_ATOMIC = 43,                    /* ATOMIC  */
  YYSYMBOL_NON_ATOMIC = 44,                /* NON_ATOMIC  */
  YYSYMBOL_D_STEP = 45,                    /* D_STEP  */
  YYSYMBOL_UNLESS = 46,                    /* UNLESS  */
  YYSYMBOL_TIMEOUT = 47,                   /* TIMEOUT  */
  YYSYMBOL_NONPROGRESS = 48,               /* NONPROGRESS  */
  YYSYMBOL_ACTIVE = 49,                    /* ACTIVE  */
  YYSYMBOL_PROCTYPE = 50,                  /* PROCTYPE  */
  YYSYMBOL_D_PROCTYPE = 51,                /* D_PROCTYPE  */
  YYSYMBOL_HIDDEN = 52,                    /* HIDDEN  */
  YYSYMBOL_SHOW = 53,                      /* SHOW  */
  YYSYMBOL_ISLOCAL = 54,                   /* ISLOCAL  */
  YYSYMBOL_PRIORITY = 55,                  /* PRIORITY  */
  YYSYMBOL_PROVIDED = 56,                  /* PROVIDED  */
  YYSYMBOL_FULL = 57,                      /* FULL  */
  YYSYMBOL_EMPTY = 58,                     /* EMPTY  */
  YYSYMBOL_NFULL = 59,                     /* NFULL  */
  YYSYMBOL_NEMPTY = 60,                    /* NEMPTY  */
  YYSYMBOL_XU = 61,                        /* XU  */
  YYSYMBOL_CLAIM = 62,                     /* CLAIM  */
  YYSYMBOL_TRACE = 63,                     /* TRACE  */
  YYSYMBOL_INIT = 64,                      /* INIT  */
  YYSYMBOL_WHILE = 65,                     /* WHILE  */
  YYSYMBOL_WHEN = 66,                      /* WHEN  */
  YYSYMBOL_WAIT = 67,                      /* WAIT  */
  YYSYMBOL_RESET = 68,                     /* RESET  */
  YYSYMBOL_SPEC = 69,                      /* SPEC  */
  YYSYMBOL_EVENTUALLY = 70,                /* EVENTUALLY  */
  YYSYMBOL_ALWAYS = 71,                    /* ALWAYS  */
  YYSYMBOL_GLOBALLY = 72,                  /* GLOBALLY  */
  YYSYMBOL_FINALLY = 73,                   /* FINALLY  */
  YYSYMBOL_UNTIL = 74,                     /* UNTIL  */
  YYSYMBOL_NEXT = 75,                      /* NEXT  */
  YYSYMBOL_LTL = 76,                       /* LTL  */
  YYSYMBOL_BLTL = 77,                      /* BLTL  */
  YYSYMBOL_K = 78,                         /* K  */
  YYSYMBOL_FMULTILTL = 79,                 /* FMULTILTL  */
  YYSYMBOL_ASGN = 80,                      /* ASGN  */
  YYSYMBOL_SND = 81,                       /* SND  */
  YYSYMBOL_O_SND = 82,                     /* O_SND  */
  YYSYMBOL_RCV = 83,                       /* RCV  */
  YYSYMBOL_R_RCV = 84,                     /* R_RCV  */
  YYSYMBOL_OR = 85,                        /* OR  */
  YYSYMBOL_AND = 86,                       /* AND  */
  YYSYMBOL_87_ = 87,                       /* '|'  */
  YYSYMBOL_88_ = 88,                       /* '^'  */
  YYSYMBOL_89_ = 89,                       /* '&'  */
  YYSYMBOL_EQ = 90,                        /* EQ  */
  YYSYMBOL_NE = 91,                        /* NE  */
  YYSYMBOL_GT = 92,                        /* GT  */
  YYSYMBOL_LT = 93,                        /* LT  */
  YYSYMBOL_GE = 94,                        /* GE  */
  YYSYMBOL_LE = 95,                        /* LE  */
  YYSYMBOL_LSHIFT = 96,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 97,                    /* RSHIFT  */
  YYSYMBOL_98_ = 98,                       /* '+'  */
  YYSYMBOL_99_ = 99,                       /* '-'  */
  YYSYMBOL_100_ = 100,                     /* '*'  */
  YYSYMBOL_101_ = 101,                     /* '/'  */
  YYSYMBOL_102_ = 102,                     /* '%'  */
  YYSYMBOL_INCR = 103,                     /* INCR  */
  YYSYMBOL_DECR = 104,                     /* DECR  */
  YYSYMBOL_105_ = 105,                     /* '~'  */
  YYSYMBOL_UMIN = 106,                     /* UMIN  */
  YYSYMBOL_NEG = 107,                      /* NEG  */
  YYSYMBOL_COUNT = 108,                    /* COUNT  */
  YYSYMBOL_CONTEXT = 109,                  /* CONTEXT  */
  YYSYMBOL_DOT = 110,                      /* DOT  */
  YYSYMBOL_IMPLIES = 111,                  /* IMPLIES  */
  YYSYMBOL_112_ = 112,                     /* '('  */
  YYSYMBOL_113_ = 113,                     /* ')'  */
  YYSYMBOL_114_ = 114,                     /* '['  */
  YYSYMBOL_115_ = 115,                     /* ']'  */
  YYSYMBOL_116_ = 116,                     /* '{'  */
  YYSYMBOL_117_ = 117,                     /* '}'  */
  YYSYMBOL_118_ = 118,                     /* ':'  */
  YYSYMBOL_119_ = 119,                     /* ','  */
  YYSYMBOL_120_ = 120,                     /* '.'  */
  YYSYMBOL_121_ = 121,                     /* '@'  */
  YYSYMBOL_YYACCEPT = 122,                 /* $accept  */
  YYSYMBOL_start_parsing = 123,            /* start_parsing  */
  YYSYMBOL_124_1 = 124,                    /* $@1  */
  YYSYMBOL_125_2 = 125,                    /* $@2  */
  YYSYMBOL_program = 126,                  /* program  */
  YYSYMBOL_units = 127,                    /* units  */
  YYSYMBOL_unit = 128,                     /* unit  */
  YYSYMBOL_proc = 129,                     /* proc  */
  YYSYMBOL_130_3 = 130,                    /* $@3  */
  YYSYMBOL_131_4 = 131,                    /* $@4  */
  YYSYMBOL_proctype = 132,                 /* proctype  */
  YYSYMBOL_inst = 133,                     /* inst  */
  YYSYMBOL_init = 134,                     /* init  */
  YYSYMBOL_135_5 = 135,                    /* $@5  */
  YYSYMBOL_events = 136,                   /* events  */
  YYSYMBOL_utypedef = 137,                 /* utypedef  */
  YYSYMBOL_mtypedef = 138,                 /* mtypedef  */
  YYSYMBOL_139_6 = 139,                    /* $@6  */
  YYSYMBOL_ns = 140,                       /* ns  */
  YYSYMBOL_141_7 = 141,                    /* $@7  */
  YYSYMBOL_142_8 = 142,                    /* $@8  */
  YYSYMBOL_143_9 = 143,                    /* $@9  */
  YYSYMBOL_c_fcts = 144,                   /* c_fcts  */
  YYSYMBOL_cstate = 145,                   /* cstate  */
  YYSYMBOL_ccode = 146,                    /* ccode  */
  YYSYMBOL_cexpr = 147,                    /* cexpr  */
  YYSYMBOL_body = 148,                     /* body  */
  YYSYMBOL_149_10 = 149,                   /* $@10  */
  YYSYMBOL_sequence = 150,                 /* sequence  */
  YYSYMBOL_step = 151,                     /* step  */
  YYSYMBOL_vis = 152,                      /* vis  */
  YYSYMBOL_asgn = 153,                     /* asgn  */
  YYSYMBOL_one_decl = 154,                 /* one_decl  */
  YYSYMBOL_155_11 = 155,                   /* $@11  */
  YYSYMBOL_156_12 = 156,                   /* $@12  */
  YYSYMBOL_decl_lst = 157,                 /* decl_lst  */
  YYSYMBOL_decl = 158,                     /* decl  */
  YYSYMBOL_var_list = 159,                 /* var_list  */
  YYSYMBOL_ivar = 160,                     /* ivar  */
  YYSYMBOL_param_list = 161,               /* param_list  */
  YYSYMBOL_ch_init = 162,                  /* ch_init  */
  YYSYMBOL_basetype = 163,                 /* basetype  */
  YYSYMBOL_typ_list = 164,                 /* typ_list  */
  YYSYMBOL_vardcl = 165,                   /* vardcl  */
  YYSYMBOL_varref = 166,                   /* varref  */
  YYSYMBOL_pfld = 167,                     /* pfld  */
  YYSYMBOL_cmpnd = 168,                    /* cmpnd  */
  YYSYMBOL_sfld = 169,                     /* sfld  */
  YYSYMBOL_stmnt = 170,                    /* stmnt  */
  YYSYMBOL_Special = 171,                  /* Special  */
  YYSYMBOL_Stmnt = 172,                    /* Stmnt  */
  YYSYMBOL_options = 173,                  /* options  */
  YYSYMBOL_option = 174,                   /* option  */
  YYSYMBOL_real_expr = 175,                /* real_expr  */
  YYSYMBOL_OS = 176,                       /* OS  */
  YYSYMBOL_MS = 177,                       /* MS  */
  YYSYMBOL_aname = 178,                    /* aname  */
  YYSYMBOL_expr = 179,                     /* expr  */
  YYSYMBOL_Opt_priority = 180,             /* Opt_priority  */
  YYSYMBOL_full_expr = 181,                /* full_expr  */
  YYSYMBOL_Opt_enabler = 182,              /* Opt_enabler  */
  YYSYMBOL_Expr = 183,                     /* Expr  */
  YYSYMBOL_Probe = 184,                    /* Probe  */
  YYSYMBOL_args = 185,                     /* args  */
  YYSYMBOL_prargs = 186,                   /* prargs  */
  YYSYMBOL_margs = 187,                    /* margs  */
  YYSYMBOL_arg = 188,                      /* arg  */
  YYSYMBOL_rarg = 189,                     /* rarg  */
  YYSYMBOL_rargs = 190,                    /* rargs  */
  YYSYMBOL_nlst = 191,                     /* nlst  */
  YYSYMBOL_props = 192,                    /* props  */
  YYSYMBOL_prop = 193,                     /* prop  */
  YYSYMBOL_ltl_expr = 194,                 /* ltl_expr  */
  YYSYMBOL_bltl_expr = 195,                /* bltl_expr  */
  YYSYMBOL_k_steps = 196,                  /* k_steps  */
  YYSYMBOL_variant_quants = 197,           /* variant_quants  */
  YYSYMBOL_variant_quant = 198,            /* variant_quant  */
  YYSYMBOL_variant_expr = 199              /* variant_expr  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2053

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  122
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  488

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   357


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
       2,     2,     2,     2,     2,     2,     2,   102,    89,     2,
     112,   113,   100,    98,   119,    99,   120,   101,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   118,     2,
       2,     2,     2,     2,   121,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   114,     2,   115,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   116,    87,   117,   105,     2,     2,     2,
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
      85,    86,    90,    91,    92,    93,    94,    95,    96,    97,
     103,   104,   106,   107,   108,   109,   110,   111
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   149,   149,   149,   149,   154,   157,   158,   161,   162,
     163,   164,   177,   178,   179,   180,   181,   187,   195,   185,
     210,   211,   214,   215,   216,   217,   231,   230,   246,   249,
     261,   261,   280,   281,   283,   280,   298,   299,   302,   303,
     304,   305,   308,   309,   312,   315,   315,   325,   326,   327,
     330,   335,   336,   337,   338,   346,   347,   348,   349,   352,
     353,   359,   359,   360,   360,   363,   364,   368,   369,   376,
     377,   380,   385,   390,   395,   396,   397,   401,   404,   405,
     409,   424,   441,   442,   443,   446,   449,   450,   453,   454,
     457,   458,   462,   463,   466,   467,   468,   469,   470,   471,
     472,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   505,
     506,   509,   510,   514,   515,   516,   517,   518,   519,   520,
     523,   524,   527,   528,   531,   532,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   564,   565,
     566,   571,   572,   573,   574,   575,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     594,   595,   598,   599,   602,   603,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   622,   623,   624,   625,   629,
     630,   634,   635,   639,   640,   643,   644,   647,   648,   649,
     650,   654,   655,   656,   657,   660,   661,   662,   666,   667,
     668,   671,   678,   686,   697,   698,   699,   700,   701,   704,
     705,   706,   707,   708,   711,   712,   713,   714,   715,   716,
     719,   720,   723,   724,   727
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
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "IF", "DO",
  "TYPE", "NAME", "UNAME", "PNAME", "INAME", "VNAME", "BASE", "STRING",
  "REAL", "TRUE", "FALSE", "SKIP", "ASSERT", "PRINT", "PRINTM", "C_CODE",
  "C_DECL", "C_EXPR", "C_STATE", "C_TRACK", "RUN", "LEN", "ENABLED",
  "EVAL", "PC_VAL", "TYPEDEF", "MTYPE", "INLINE", "LABEL", "OF", "GOTO",
  "BREAK", "ELSE", "SEMI", "FI", "OD", "SEP", "ATOMIC", "NON_ATOMIC",
  "D_STEP", "UNLESS", "TIMEOUT", "NONPROGRESS", "ACTIVE", "PROCTYPE",
  "D_PROCTYPE", "HIDDEN", "SHOW", "ISLOCAL", "PRIORITY", "PROVIDED",
  "FULL", "EMPTY", "NFULL", "NEMPTY", "XU", "CLAIM", "TRACE", "INIT",
  "WHILE", "WHEN", "WAIT", "RESET", "SPEC", "EVENTUALLY", "ALWAYS",
  "GLOBALLY", "FINALLY", "UNTIL", "NEXT", "LTL", "BLTL", "K", "FMULTILTL",
  "ASGN", "SND", "O_SND", "RCV", "R_RCV", "OR", "AND", "'|'", "'^'", "'&'",
  "EQ", "NE", "GT", "LT", "GE", "LE", "LSHIFT", "RSHIFT", "'+'", "'-'",
  "'*'", "'/'", "'%'", "INCR", "DECR", "'~'", "UMIN", "NEG", "COUNT",
  "CONTEXT", "DOT", "IMPLIES", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "':'", "','", "'.'", "'@'", "$accept", "start_parsing", "$@1", "$@2",
  "program", "units", "unit", "proc", "$@3", "$@4", "proctype", "inst",
  "init", "$@5", "events", "utypedef", "mtypedef", "$@6", "ns", "$@7",
  "$@8", "$@9", "c_fcts", "cstate", "ccode", "cexpr", "body", "$@10",
  "sequence", "step", "vis", "asgn", "one_decl", "$@11", "$@12",
  "decl_lst", "decl", "var_list", "ivar", "param_list", "ch_init",
  "basetype", "typ_list", "vardcl", "varref", "pfld", "cmpnd", "sfld",
  "stmnt", "Special", "Stmnt", "options", "option", "real_expr", "OS",
  "MS", "aname", "expr", "Opt_priority", "full_expr", "Opt_enabler",
  "Expr", "Probe", "args", "prargs", "margs", "arg", "rarg", "rargs",
  "nlst", "props", "prop", "ltl_expr", "bltl_expr", "k_steps",
  "variant_quants", "variant_quant", "variant_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-390)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-132)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -390,    16,   484,  -390,  -390,  -390,    17,    27,    59,  -390,
    -390,   -35,  -390,  -390,  -390,   -28,  -390,  -390,   284,  -390,
    -390,    19,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
     135,  -390,    87,    98,    37,   130,    50,  -390,  -390,   110,
      91,  -390,  -390,  -390,   176,     6,  -390,   129,   167,    39,
    -390,    83,    96,  1000,   202,   -28,   205,   206,   212,  -390,
      91,  -390,  -390,  -390,   213,   213,  -390,  -390,   173,   182,
     106,   112,  -390,  -390,  -390,   183,   183,   -46,   -31,   115,
    -390,  -390,  -390,  1348,   116,   118,  -390,   177,   121,   122,
     131,   241,  -390,  -390,   136,   138,  -390,  -390,   139,   143,
     179,   181,  1177,  1177,  1415,  1415,  1415,  1415,   188,   174,
    1348,  1000,  -390,  -390,   441,  -390,  -390,   215,   184,  -390,
     255,  -390,  -390,  1913,  -390,    64,  -390,  -390,  -390,  -390,
    -390,   186,   187,    90,  -390,   198,   196,   -37,  -390,   192,
     236,  -390,  -390,    39,  -390,   313,   666,   285,   183,   281,
    1415,   780,  1415,   317,   321,  1415,   216,   -56,  -390,   316,
      15,  -390,  -390,   227,    24,  1415,  1415,  -390,  1000,  1000,
      24,    24,    24,    24,  1415,    24,   -59,  1415,   -59,  1415,
     -59,   -59,   -59,   -59,  1415,   317,   282,   -48,   441,   -16,
    -390,   223,   890,  1348,  1415,  1415,    73,   123,  -390,  -390,
      24,    24,  -390,  1110,  1415,  1348,  1348,  1415,  1415,  1415,
    1415,  1415,  1415,  1415,  1415,  1415,  1415,  1415,  1415,  1415,
    1415,  1415,  1415,  1415,  1348,  1348,  1415,  1415,   225,   225,
     226,   230,    21,   338,   343,   348,   213,  1244,  -390,   233,
     240,    20,   556,  -390,  -390,  -390,  1675,   -36,  -390,  -390,
    -390,  1706,  -390,  -390,  1380,   242,  -390,   244,   245,   235,
     247,   248,  1415,   249,  1768,  1797,   441,   441,   250,   251,
     252,   272,  1209,   193,  1415,  1415,   -59,   -59,  1826,   184,
    1415,  -390,  -390,   269,  -390,  -390,  -390,  -390,  1143,  -390,
    -390,  -390,  -390,   275,    26,   385,    26,    26,  -390,   -69,
    -390,    26,    26,  -390,   273,  -390,  -390,  1942,   552,   303,
     775,  -390,   885,   993,  1239,  1287,  1287,   324,   324,   324,
     324,    95,    95,   -53,   -53,   -59,   -59,   -59,   -59,   552,
     303,   775,  -390,  1942,   277,   279,   392,  -390,  -390,  1415,
      90,  -390,   287,  -390,    12,   288,  -390,  -390,   389,  -390,
    1942,   313,  -390,  -390,  -390,    20,    76,  -390,  -390,  1110,
     -79,  1415,  -390,  1415,   289,  -390,  -390,   291,  -390,  -390,
    -390,   290,   292,  -390,  -390,  -390,  -390,  1415,  1415,  1415,
    1415,  1415,  1415,   662,   775,  -390,  -390,  1443,  -390,  1415,
    1415,   314,  -390,   295,   296,    26,    26,   318,   297,  -390,
    -390,  -390,   299,   300,  -390,  -390,  -390,  -390,  -390,  -390,
     312,  -390,   -28,   140,    20,    20,    20,    20,  1000,   317,
     398,  -390,  -390,  -390,   110,  -390,  -390,  1477,  1510,  1543,
    1576,  1609,  1642,  1415,   301,  1855,  -390,  -390,  -390,   305,
    -390,  -390,  -390,   322,  -390,   110,   393,  -390,  -390,    88,
      88,  -390,  -390,   556,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  1884,  -390,  -390,  -390,  1415,   381,   323,
    -390,  -390,  1737,   326,   -28,   195,  -390,  1348,  -390,  -390,
    -390,   328,   332,   327,   195,  -390,  -390,  -390
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    22,     1,    42,    43,     0,     0,     0,    32,
      16,    23,    56,    57,    58,     0,    26,     3,     5,     6,
       8,     0,     9,    10,    12,    13,    15,    14,    37,    36,
       0,    11,     0,     0,     0,     0,     0,    45,    28,   180,
     218,     7,    20,    21,     0,    59,    63,    38,    39,    55,
      33,     0,     0,    55,     0,     0,     0,     0,     0,     4,
     218,    17,    60,    30,     0,     0,    40,    41,     0,    65,
       0,     0,    24,    25,   168,     0,     0,    86,     0,     0,
     169,   170,   194,     0,     0,     0,    44,     0,     0,     0,
       0,     0,    98,   114,     0,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,   108,   167,    55,    47,    50,   166,    90,    85,
      53,    92,    93,   182,   113,   183,   186,   178,   179,   181,
      27,     0,     0,     0,   220,     0,     0,    82,    62,    69,
      71,    64,    61,    55,    29,    74,    55,     0,   119,     0,
       0,    55,     0,     0,     0,   199,    86,   166,   107,     0,
       0,   134,   135,     0,     0,     0,     0,    99,    55,    55,
       0,     0,     0,     0,     0,     0,   224,     0,   225,     0,
     226,   158,   157,   156,     0,     0,     0,     0,    55,   132,
      49,     0,    55,     0,     0,     0,     0,     0,   102,   103,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,    55,     0,     0,     0,     0,     0,    66,    75,
       0,     0,   130,    96,   120,    97,     0,    86,    52,    51,
     100,     0,   177,   176,   205,     0,   200,     0,     0,   201,
       0,     0,   199,     0,     0,     0,    55,    55,     0,     0,
       0,     0,     0,     0,     0,     0,   229,   230,     0,    90,
       0,   136,   187,     0,    46,   133,    48,   101,   205,    95,
     203,   112,   209,     0,     0,     0,     0,     0,   207,   211,
      94,     0,     0,   109,     0,    91,    54,   227,   152,   193,
     151,   192,   144,   143,   142,   149,   150,   145,   146,   147,
     148,   153,   154,   137,   138,   139,   140,   141,   228,   191,
     190,   189,   188,     0,   178,   179,     0,   243,   242,     0,
       0,    68,     0,   215,     0,     0,    83,    70,     0,    73,
      72,    74,    34,   129,   128,     0,     0,   121,    87,     0,
       0,     0,   118,     0,     0,   106,   105,     0,   161,   162,
     173,     0,     0,   195,   197,   196,   198,     0,     0,     0,
       0,     0,     0,   152,   151,   155,    89,     0,   117,     0,
       0,     0,   210,     0,     0,     0,     0,     0,     0,   165,
     221,   222,     0,   178,   241,    18,   216,    31,   217,    84,
       0,    76,     0,     0,     0,     0,     0,     0,    55,     0,
       0,   206,   202,   104,   180,   115,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   214,   163,     0,
     212,   111,   164,     0,   223,   180,     0,    35,   123,   124,
     125,   126,   127,   130,   175,   174,   160,   238,   239,   234,
     235,   236,   237,     0,   204,   208,   213,     0,   184,     0,
     122,   159,     0,     0,     0,     0,   244,     0,    19,    78,
      79,    80,     0,     0,     0,    77,   185,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -390,  -390,  -390,  -390,  -390,  -390,   425,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,    18,  -390,   -55,  -390,  -105,  -103,
      43,  -390,    49,  -390,  -390,  -135,  -390,   -58,  -390,   101,
    -390,  -390,   -30,  -390,   -52,  -139,   254,   191,  -149,  -390,
    -390,   -64,  -390,  -311,  -171,  -390,  -390,    52,  -389,   -80,
    -390,   -78,  -390,   203,  -390,   258,  -190,  -390,  -187,  -390,
     406,  -390,  -217,   246,   369,   134,  -390,   253
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    40,    17,    18,    19,    20,   135,   445,
      44,    21,    22,    39,    23,    24,    25,   136,    26,    35,
      71,   412,    27,    28,   112,   113,    38,    53,   114,   115,
      68,    63,   116,    64,    65,    70,   342,   138,   139,   240,
     349,   481,   482,   140,   157,   118,   119,   202,   120,   121,
     122,   147,   148,   356,   191,   192,   163,   123,    55,   124,
     474,   125,   126,   255,   364,   289,   256,   299,   300,   344,
      59,    60,   127,   128,   177,   230,   231,   337
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     130,   117,   250,   158,   290,   290,   188,   141,   238,   334,
     303,   190,   149,   -61,   252,   204,     3,   283,   260,   406,
      29,   204,   156,   353,  -131,  -131,  -131,   257,   258,   292,
      32,   156,   187,   156,   354,   456,    29,   224,   225,   419,
      33,   242,   420,   395,   413,    30,   279,   220,   221,   222,
     396,    31,   223,    51,   306,   293,   468,    52,   223,   117,
     200,    30,   117,   266,   267,   282,    34,    31,   150,    42,
      43,   357,   151,    12,    13,    14,   292,   234,   150,    36,
     156,   235,   359,   152,   244,   190,    62,   153,    37,   286,
     154,    12,    13,    14,   117,   371,   372,   341,    69,   117,
      47,  -131,   293,   449,   450,   451,   452,   391,   261,   393,
     394,    48,   263,   287,   397,   398,   117,   117,   268,   269,
     270,   271,   403,   273,   109,   295,   292,   309,   311,   407,
     156,   408,   355,   109,   -67,   109,   117,    50,   296,   190,
     117,    45,    66,    46,   298,   298,   330,   332,   304,   224,
     225,   117,   293,    49,   176,   178,   180,   181,   182,   183,
     228,   229,   186,   190,   190,    54,   294,    56,    57,   204,
      58,   421,   295,   422,   414,   415,   416,   417,   347,   142,
      67,    46,   109,    61,   161,   296,   162,   297,   416,   417,
     117,   418,    69,   218,   219,   220,   221,   222,    72,   434,
     249,   479,   246,   480,   251,   129,   223,   254,   439,   440,
     250,    73,   131,   132,   117,   117,   301,   264,   265,   133,
     137,   143,   295,   144,   145,   146,   272,   155,   159,   276,
     160,   277,   109,   164,   165,   296,   278,   302,   414,   415,
     416,   417,   298,   166,   298,   298,   288,   288,   167,   298,
     298,   170,   168,   448,   169,   171,   307,   308,   310,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   331,   333,   333,
     454,    69,   470,   377,   378,   379,   380,   381,   382,   350,
     -55,   172,   -55,   173,   185,   193,   194,   195,   196,   197,
     184,   203,   226,   227,   201,     4,     5,   117,     6,     7,
     232,   236,   233,   453,   254,     8,   237,     9,   198,   199,
     239,   280,   245,    10,   156,   243,   383,   384,   253,   259,
     150,   200,   387,    11,   -22,   -22,    12,    13,    14,   262,
     284,   336,   339,   298,   298,   343,   345,    15,    16,   340,
     190,   346,   351,   352,   363,   362,   204,   447,   297,   302,
     365,   366,   368,   373,   374,   375,   117,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   376,   388,   390,   392,   225,
     399,   333,   410,   223,   400,   281,   401,   483,   204,   402,
     405,   117,   423,   409,   424,   455,   436,   425,   437,   426,
     441,   438,   442,   254,   464,   254,   443,   444,   466,   478,
     216,   217,   218,   219,   220,   221,   222,   446,   469,   427,
     428,   429,   430,   431,   432,   223,   467,   473,   477,   475,
     486,   254,   435,    41,    74,    75,    76,   484,    77,   485,
      78,    79,   411,   291,   487,   305,    80,    81,    82,    83,
      84,    85,     4,     5,    86,   367,   134,    87,    88,    89,
     386,    90,   179,   335,   404,     0,     0,    91,    92,    93,
     189,     0,   338,     0,    94,   463,    95,     0,    96,    97,
     -55,     0,   -55,    12,    13,    14,     0,     0,    98,    99,
     100,   101,     0,     0,     0,     4,     5,     0,     6,     7,
       0,     0,     0,   102,   103,     8,   104,     9,     0,   472,
       0,     0,   105,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,    12,    13,    14,     0,
     106,     0,     0,     0,     0,     0,   107,    15,    16,   108,
     109,     0,     0,   110,     0,     0,     0,   111,  -130,    74,
      75,    76,   -55,    77,   -55,    78,    79,     0,     0,     0,
       0,    80,    81,    82,    83,    84,    85,     4,     5,    86,
       0,     0,    87,    88,    89,     0,    90,     0,     0,     0,
       0,     0,    91,    92,    93,   189,     0,     0,     0,    94,
       0,    95,     0,    96,    97,     0,     0,     0,    12,    13,
      14,     0,     0,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,   102,   103,
       0,   104,     0,     0,     0,     0,     0,   105,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   106,     0,     0,     0,     0,
       0,   107,     0,   223,   108,   109,     0,     0,   110,    74,
      75,    76,   111,    77,     0,    78,    79,     0,     0,     0,
       0,    80,    81,    82,    83,    84,    85,     4,     5,    86,
       0,     0,    87,    88,    89,     0,    90,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,     0,     0,    94,
       0,    95,     0,    96,    97,     0,     0,     0,    12,    13,
      14,     0,     0,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,   102,   103,
       0,   104,     0,     0,     0,     0,     0,   105,   275,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   106,     0,     0,     0,     0,
       0,   107,     0,   223,   108,   109,     0,     0,   110,     0,
     241,     0,   111,    74,    75,    76,     0,   247,     0,    78,
      79,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,     4,     5,    86,     0,     0,    87,    88,    89,     0,
      90,     0,     0,     0,     0,     0,    91,    92,    93,     0,
       0,     0,     0,    94,     0,    95,     0,    96,    97,     0,
       0,     0,    12,    13,    14,     0,     0,    98,    99,   100,
     101,   248,     0,     0,     0,     0,     0,     0,     0,   204,
       0,     0,   102,   103,     0,   104,     0,     0,     0,     0,
       0,   105,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,     0,   106,
       0,     0,     0,     0,     0,   107,   223,     0,   108,   109,
       0,     0,   110,    74,    75,    76,   111,    77,     0,    78,
      79,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,     4,     5,    86,     0,     0,    87,    88,    89,     0,
      90,     0,     0,     0,     0,     0,    91,    92,    93,   285,
       0,     0,     0,    94,     0,    95,     0,    96,    97,     0,
       0,     0,    12,    13,    14,     0,     0,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,     0,   102,   103,     0,   104,     0,     0,     0,     0,
       0,   105,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,     0,   106,
       0,     0,     0,     0,     0,   107,   223,     0,   108,   109,
       0,     0,   110,    74,    75,    76,   111,    77,     0,    78,
      79,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,     4,     5,    86,     0,     0,    87,    88,    89,     0,
      90,     0,     0,     0,     0,     0,    91,    92,    93,     0,
       0,     0,     0,    94,     0,    95,     0,    96,    97,     0,
       0,     0,    12,    13,    14,     0,     0,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,   204,     0,     0,
       0,     0,   102,   103,     0,   104,     0,     0,     0,     0,
       0,   105,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,   106,
       0,     0,     0,     0,   223,   107,     0,     0,   108,   109,
       0,     0,   110,    74,    75,    76,   111,   247,     0,    78,
      79,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,     4,     5,    86,     0,     0,    87,    88,    89,     0,
      90,     0,     0,     0,     0,     0,    91,    92,    93,     0,
       0,     0,     0,    94,     0,    95,     0,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,   102,   103,   156,   104,    78,     0,     0,     0,
       0,   105,    80,    81,     0,     0,     0,     0,     0,     0,
      86,     0,     0,    87,    88,    89,     0,    90,     0,   106,
       0,     0,     0,     0,     0,   107,     0,   204,   108,   109,
       0,     0,   110,     0,    96,    97,   111,     0,   274,   275,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,     0,    74,   280,   102,
     103,   156,   104,    78,   223,   389,     0,     0,   105,    80,
      81,     0,   361,     0,     0,     0,     0,    86,     0,     0,
      87,    88,    89,     0,    90,     0,   106,     0,     0,     0,
       0,     0,   107,   204,     0,   108,   109,     0,     0,   174,
       0,    96,    97,   175,   274,   275,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,     0,   204,     0,     0,   102,   103,     0,   104,
     223,     0,   281,     0,     0,   105,     0,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,     0,   106,     0,     0,     0,     0,     0,   107,
     223,    74,   108,   109,     0,   156,   174,    78,   348,     0,
       0,   204,     0,    80,    81,    82,     0,     0,     0,     0,
       0,    86,     0,     0,    87,    88,    89,     0,    90,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,     0,    96,    97,     0,   223,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
     102,   103,   156,   104,    78,     0,     0,     0,     0,   105,
      80,    81,     0,     0,     0,     0,     0,     0,    86,     0,
       0,    87,    88,    89,     0,    90,     0,   106,     0,     0,
       0,     0,     0,   107,   204,     0,   108,   109,     0,     0,
     110,     0,    96,    97,     0,   274,   275,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,     0,     0,     0,     0,   102,   103,     0,
     104,   223,     0,     0,     0,     0,   105,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,   204,     0,     0,
     107,     0,     0,   108,   109,     0,     0,   174,   274,   275,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
       0,   204,     0,     0,   223,     0,     0,     0,     0,     0,
       0,   433,   274,   275,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,   204,     0,     0,     0,   223,     0,
       0,     0,     0,     0,   457,   274,   275,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,     0,     0,     0,     0,   204,     0,     0,
       0,   223,     0,     0,     0,     0,     0,   458,   274,   275,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
     204,     0,     0,     0,   223,     0,     0,     0,     0,     0,
     459,   274,   275,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
       0,     0,     0,   204,     0,     0,     0,   223,     0,     0,
       0,     0,     0,   460,   274,   275,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,     0,     0,     0,     0,   204,     0,     0,     0,
     223,     0,     0,     0,     0,     0,   461,   274,   275,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,     0,     0,     0,     0,   204,
       0,     0,     0,   223,     0,     0,     0,     0,     0,   462,
     274,   275,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,     0,     0,
     204,     0,     0,     0,     0,     0,   223,     0,     0,     0,
     358,   274,   275,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
       0,   204,     0,     0,     0,     0,     0,   223,     0,     0,
       0,   360,   274,   275,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
       0,     0,   204,     0,     0,     0,     0,     0,   223,     0,
       0,     0,   476,   274,   275,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   204,     0,     0,     0,     0,     0,     0,     0,   223,
       0,   369,   274,   275,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     204,     0,     0,     0,     0,     0,     0,     0,   223,     0,
     370,   274,   275,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   204,
       0,     0,     0,     0,     0,     0,     0,   223,     0,   385,
     274,   275,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   204,     0,
       0,     0,     0,     0,     0,     0,   223,     0,   465,   274,
     275,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   204,     0,     0,
       0,     0,     0,     0,     0,   223,     0,   471,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   204,     0,     0,     0,
       0,     0,     0,     0,   223,     0,     0,   274,   275,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,     0,     0,     0,     0,     0,
       0,     0,     0,   223
};

static const yytype_int16 yycheck[] =
{
      55,    53,   151,    83,   194,   195,   111,    65,   143,   226,
     197,   114,    76,     7,   153,    74,     0,   188,     3,     7,
       2,    74,     7,     3,    40,    41,    42,    83,    84,     3,
      13,     7,   110,     7,    14,   424,    18,    85,    86,   118,
      13,   146,   121,   112,   355,     2,   185,   100,   101,   102,
     119,     2,   111,     3,   203,    29,   445,     7,   111,   111,
     116,    18,   114,   168,   169,   113,     7,    18,   114,    50,
      51,   242,   118,    52,    53,    54,     3,   114,   114,   114,
       7,   118,   118,   114,   148,   188,    80,   118,   116,   192,
     121,    52,    53,    54,   146,   266,   267,   232,    49,   151,
      13,   117,    29,   414,   415,   416,   417,   294,   160,   296,
     297,    13,   164,   193,   301,   302,   168,   169,   170,   171,
     172,   173,   339,   175,   109,    99,     3,   205,   206,   117,
       7,   119,   112,   109,   113,   109,   188,     7,   112,   242,
     192,     6,    13,     8,   196,   197,   224,   225,   200,    85,
      86,   203,    29,   116,   102,   103,   104,   105,   106,   107,
      70,    71,   110,   266,   267,    55,    93,    76,    77,    74,
      79,   361,    99,   363,    98,    99,   100,   101,   236,     6,
      13,     8,   109,     7,     7,   112,     9,   114,   100,   101,
     242,   115,   143,    98,    99,   100,   101,   102,   115,   389,
     151,     6,   150,     8,   152,     3,   111,   155,   395,   396,
     359,   115,     7,     7,   266,   267,    93,   165,   166,     7,
       7,    39,    99,   117,   112,    42,   174,   112,   112,   177,
     112,   179,   109,   112,   112,   112,   184,   114,    98,    99,
     100,   101,   294,   112,   296,   297,   194,   195,     7,   301,
     302,   112,   116,   113,   116,   112,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     419,   232,   453,    90,    91,    92,    93,    94,    95,   237,
       6,   112,     8,   112,   120,    80,    81,    82,    83,    84,
     112,    46,   116,   116,   120,    21,    22,   359,    24,    25,
     112,   119,   116,   418,   262,    31,    80,    33,   103,   104,
       7,    39,    41,    39,     7,    40,   274,   275,     7,    13,
     114,   116,   280,    49,    50,    51,    52,    53,    54,   112,
     117,   116,   116,   395,   396,     7,     3,    63,    64,   119,
     453,     3,   119,   113,   119,   113,    74,   412,   114,   114,
     113,   113,   113,   113,   113,   113,   418,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   113,   117,   112,     3,    86,
     117,   339,     3,   111,   117,   113,   117,   477,    74,     7,
     113,   453,   113,   115,   113,     7,    92,   117,   113,   117,
      92,   115,   115,   361,   113,   363,   117,   117,   113,   474,
      96,    97,    98,    99,   100,   101,   102,   115,    35,   377,
     378,   379,   380,   381,   382,   111,   114,    56,   112,   116,
     113,   389,   390,    18,     3,     4,     5,   119,     7,   117,
       9,    10,   351,   195,   484,   201,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   262,    60,    26,    27,    28,
     279,    30,   103,   227,   340,    -1,    -1,    36,    37,    38,
      39,    -1,   229,    -1,    43,   433,    45,    -1,    47,    48,
       6,    -1,     8,    52,    53,    54,    -1,    -1,    57,    58,
      59,    60,    -1,    -1,    -1,    21,    22,    -1,    24,    25,
      -1,    -1,    -1,    72,    73,    31,    75,    33,    -1,   467,
      -1,    -1,    81,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,    -1,
      99,    -1,    -1,    -1,    -1,    -1,   105,    63,    64,   108,
     109,    -1,    -1,   112,    -1,    -1,    -1,   116,   117,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    43,
      -1,    45,    -1,    47,    48,    -1,    -1,    -1,    52,    53,
      54,    -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    72,    73,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    81,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,   111,   108,   109,    -1,    -1,   112,     3,
       4,     5,   116,     7,    -1,     9,    10,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
      -1,    45,    -1,    47,    48,    -1,    -1,    -1,    52,    53,
      54,    -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    72,    73,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    81,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,   111,   108,   109,    -1,    -1,   112,    -1,
     114,    -1,   116,     3,     4,     5,    -1,     7,    -1,     9,
      10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    -1,    43,    -1,    45,    -1,    47,    48,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    72,    73,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    81,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,   111,    -1,   108,   109,
      -1,    -1,   112,     3,     4,     5,   116,     7,    -1,     9,
      10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    43,    -1,    45,    -1,    47,    48,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    72,    73,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,   111,    -1,   108,   109,
      -1,    -1,   112,     3,     4,     5,   116,     7,    -1,     9,
      10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    -1,    43,    -1,    45,    -1,    47,    48,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    72,    73,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    81,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,   111,   105,    -1,    -1,   108,   109,
      -1,    -1,   112,     3,     4,     5,   116,     7,    -1,     9,
      10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    -1,    43,    -1,    45,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    72,    73,     7,    75,     9,    -1,    -1,    -1,
      -1,    81,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    26,    27,    28,    -1,    30,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    74,   108,   109,
      -1,    -1,   112,    -1,    47,    48,   116,    -1,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,     3,    39,    72,
      73,     7,    75,     9,   111,   112,    -1,    -1,    81,    15,
      16,    -1,   119,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      26,    27,    28,    -1,    30,    -1,    99,    -1,    -1,    -1,
      -1,    -1,   105,    74,    -1,   108,   109,    -1,    -1,   112,
      -1,    47,    48,   116,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    74,    -1,    -1,    72,    73,    -1,    75,
     111,    -1,   113,    -1,    -1,    81,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
     111,     3,   108,   109,    -1,     7,   112,     9,   114,    -1,
      -1,    74,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    26,    27,    28,    -1,    30,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      72,    73,     7,    75,     9,    -1,    -1,    -1,    -1,    81,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    26,    27,    28,    -1,    30,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   105,    74,    -1,   108,   109,    -1,    -1,
     112,    -1,    47,    48,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    72,    73,    -1,
      75,   111,    -1,    -1,    -1,    -1,    81,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    74,    -1,    -1,
     105,    -1,    -1,   108,   109,    -1,    -1,   112,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,   117,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
     117,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,   117,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     115,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,   115,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,   115,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
     113,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   123,   124,     0,    21,    22,    24,    25,    31,    33,
      39,    49,    52,    53,    54,    63,    64,   126,   127,   128,
     129,   133,   134,   136,   137,   138,   140,   144,   145,   146,
     152,   154,    13,    13,     7,   141,   114,   116,   148,   135,
     125,   128,    50,    51,   132,     6,     8,    13,    13,   116,
       7,     3,     7,   149,    55,   180,    76,    77,    79,   192,
     193,     7,    80,   153,   155,   156,    13,    13,   152,   154,
     157,   142,   115,   115,     3,     4,     5,     7,     9,    10,
      15,    16,    17,    18,    19,    20,    23,    26,    27,    28,
      30,    36,    37,    38,    43,    45,    47,    48,    57,    58,
      59,    60,    72,    73,    75,    81,    99,   105,   108,   109,
     112,   116,   146,   147,   150,   151,   154,   166,   167,   168,
     170,   171,   172,   179,   181,   183,   184,   194,   195,     3,
     148,     7,     7,     7,   192,   130,   139,     7,   159,   160,
     165,   159,     6,    39,   117,   112,    42,   173,   174,   173,
     114,   118,   114,   118,   121,   112,     7,   166,   181,   112,
     112,     7,     9,   178,   112,   112,   112,     7,   116,   116,
     112,   112,   112,   112,   112,   116,   179,   196,   179,   196,
     179,   179,   179,   179,   112,   120,   179,   183,   150,    39,
     151,   176,   177,    80,    81,    82,    83,    84,   103,   104,
     116,   120,   169,    46,    74,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   111,    85,    86,   116,   116,    70,    71,
     197,   198,   112,   116,   114,   118,   119,    80,   157,     7,
     161,   114,   150,    40,   173,    41,   179,     7,    61,   154,
     170,   179,   167,     7,   179,   185,   188,    83,    84,    13,
       3,   166,   112,   166,   179,   179,   150,   150,   166,   166,
     166,   166,   179,   166,    85,    86,   179,   179,   179,   167,
      39,   113,   113,   176,   117,    39,   151,   181,   179,   187,
     188,   187,     3,    29,    93,    99,   112,   114,   166,   189,
     190,    93,   114,   190,   166,   168,   170,   179,   179,   183,
     179,   183,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     183,   179,   183,   179,   194,   195,   116,   199,   199,   116,
     119,   157,   158,     7,   191,     3,     3,   159,   114,   162,
     179,   119,   113,     3,    14,   112,   175,   176,   115,   118,
     115,   119,   113,   119,   186,   113,   113,   185,   113,   113,
     113,   176,   176,   113,   113,   113,   113,    90,    91,    92,
      93,    94,    95,   179,   179,   113,   169,   179,   117,   112,
     112,   190,     3,   190,   190,   112,   119,   190,   190,   117,
     117,   117,     7,   194,   197,   113,     7,   117,   119,   115,
       3,   161,   143,   175,    98,    99,   100,   101,   115,   118,
     121,   188,   188,   113,   113,   117,   117,   179,   179,   179,
     179,   179,   179,   118,   188,   179,    92,   113,   115,   190,
     190,    92,   115,   117,   117,   131,   115,   148,   113,   175,
     175,   175,   175,   150,   167,     7,   180,   117,   117,   117,
     117,   117,   117,   179,   113,   113,   113,   114,   180,    35,
     176,   113,   179,    56,   182,   116,   115,   112,   148,     6,
       8,   163,   164,   181,   119,   117,   113,   164
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   122,   124,   125,   123,   126,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   130,   131,   129,
     132,   132,   133,   133,   133,   133,   135,   134,   136,   137,
     139,   138,   141,   142,   143,   140,   144,   144,   145,   145,
     145,   145,   146,   146,   147,   149,   148,   150,   150,   150,
     151,   151,   151,   151,   151,   152,   152,   152,   152,   153,
     153,   155,   154,   156,   154,   157,   157,   158,   158,   159,
     159,   160,   160,   160,   161,   161,   161,   162,   163,   163,
     164,   164,   165,   165,   165,   166,   167,   167,   168,   168,
     169,   169,   170,   170,   171,   171,   171,   171,   171,   171,
     171,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   173,
     173,   174,   174,   175,   175,   175,   175,   175,   175,   175,
     176,   176,   177,   177,   178,   178,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     180,   180,   181,   181,   182,   182,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   184,   184,   184,   184,   185,
     185,   186,   186,   187,   187,   188,   188,   189,   189,   189,
     189,   190,   190,   190,   190,   191,   191,   191,   192,   192,
     192,   193,   193,   193,   194,   194,   194,   194,   194,   195,
     195,   195,   195,   195,   196,   196,   196,   196,   196,   196,
     197,   197,   198,   198,   199
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     4,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,    11,
       1,     1,     0,     1,     4,     4,     0,     4,     2,     5,
       0,     7,     0,     0,     0,     9,     1,     1,     3,     3,
       4,     4,     1,     1,     1,     0,     5,     1,     3,     2,
       1,     3,     3,     1,     3,     0,     1,     1,     1,     0,
       1,     0,     4,     0,     4,     1,     3,     0,     1,     1,
       3,     1,     3,     3,     0,     1,     3,     7,     1,     1,
       1,     3,     1,     3,     4,     1,     1,     4,     2,     4,
       0,     2,     1,     1,     3,     3,     3,     3,     1,     2,
       3,     3,     2,     2,     5,     4,     4,     2,     1,     3,
       5,     5,     3,     1,     1,     5,     5,     4,     4,     1,
       2,     3,     6,     3,     3,     3,     3,     3,     1,     1,
       0,     1,     1,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     2,     2,     2,     7,
       6,     4,     4,     5,     5,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     6,     3,     3,     1,     1,
       0,     2,     1,     1,     0,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     4,     4,     4,     4,     0,
       1,     0,     2,     1,     4,     1,     3,     1,     4,     1,
       2,     1,     3,     4,     3,     1,     2,     2,     0,     1,
       2,     5,     5,     6,     2,     2,     2,     3,     3,     3,
       3,     2,     3,     3,     5,     5,     5,     5,     5,     5,
       1,     3,     2,     2,     6
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
        yyerror (globalSymTab, program, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, globalSymTab, program); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, symTable** globalSymTab, stmnt** program)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (globalSymTab);
  YY_USE (program);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, symTable** globalSymTab, stmnt** program)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, globalSymTab, program);
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
                 int yyrule, symTable** globalSymTab, stmnt** program)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], globalSymTab, program);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, globalSymTab, program); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, symTable** globalSymTab, stmnt** program)
{
  YY_USE (yyvaluep);
  YY_USE (globalSymTab);
  YY_USE (program);
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
yyparse (symTable** globalSymTab, stmnt** program)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
      yychar = yylex (&yylval, globalSymTab);
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
  case 2: /* $@1: %empty  */
#line 149 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                  { *globalSymTab = new symTable("global"); symTable::addPredefinedSym(*globalSymTab); currentSymTab = *globalSymTab; }
#line 2254 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 3: /* $@2: %empty  */
#line 149 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                                                                { currentSymTab = *globalSymTab; }
#line 2260 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 5: /* program: units  */
#line 154 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: units -> program\n")*/}
#line 2266 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 6: /* units: unit  */
#line 157 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: unit -> units\n")*/ }
#line 2272 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 7: /* units: units unit  */
#line 158 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: units unit -> units\n")*/ }
#line 2278 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 8: /* unit: proc  */
#line 161 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                        { /*DBUG("REDUCE: proc -> unit\n")*/ *program = stmnt::merge(*program, (yyvsp[0].pStmntVal)); }
#line 2284 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 9: /* unit: init  */
#line 162 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { /*DBUG("REDUCE: init -> unit\n")*/ *program = stmnt::merge(*program, (yyvsp[0].pStmntVal)); }
#line 2290 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 10: /* unit: events  */
#line 163 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { assert(false); std::cout << "The 'events' construct is currently not supported."; }
#line 2296 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 11: /* unit: one_decl  */
#line 164 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { 
													/*DBUG("REDUCE: one_decl -> unit\n")*/
													stmnt* decl = nullptr;
													if (declSyms.front()->getType() == symbol::T_CHAN) 
														decl = new chanDecl(declSyms, nbrLines);
													else {
														assert(declSyms.front()->getType() != symbol::T_MTYPE_DEF && declSyms.front()->getType() != symbol::T_TDEF);
														decl = new varDecl(declSyms, nbrLines);
													}
													assert(decl);
													declSyms.clear();
													*program = stmnt::merge(*program, decl);
												}
#line 2314 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 12: /* unit: utypedef  */
#line 177 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { /*DBUG("REDUCE: utype -> unit\n")*/ *program = stmnt::merge(*program, (yyvsp[0].pStmntVal)); }
#line 2320 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 13: /* unit: mtypedef  */
#line 178 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { /*DBUG("REDUCE: mtype -> unit\n")*/ *program = stmnt::merge(*program, (yyvsp[0].pStmntVal)); }
#line 2326 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 14: /* unit: c_fcts  */
#line 179 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { std::cout << "Embedded C code is not supported."; 						}
#line 2332 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 15: /* unit: ns  */
#line 180 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { /*DBUG("REDUCE: ns -> unit\n")*/ *program = stmnt::merge(*program, (yyvsp[0].pStmntVal)); 	}
#line 2338 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 17: /* $@3: %empty  */
#line 187 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                { 
													nameSpace = (yyvsp[0].sVal); savedSymTab = currentSymTab; 
													currentSymTab = currentSymTab->createSubTable(nameSpace); 
													auto predef = new pidSymNode(0, "_pid");
													predef->setMask(symbol::READ_ACCESS | symbol::PREDEFINED); 
													currentSymTab->insert(predef);
												}
#line 2350 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 18: /* $@4: %empty  */
#line 195 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                  { currentSymTab = savedSymTab; }
#line 2356 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 19: /* proc: inst proctype NAME $@3 '(' decl ')' $@4 Opt_priority Opt_enabler body  */
#line 198 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        {	
		  											/*DBUG("REDUCE: inst proctype NAME ( decl ) prio ena body -> proc\n")*/
													auto procNbLine = (yyvsp[0].pStmntVal)->getLineNb();
		  											procSymNode* proc = new procSymNode((yyvsp[-8].sVal), (yyvsp[-10].pConstExprVal), declSyms, (yyvsp[0].pStmntVal), procNbLine);
		  											declSyms.clear();
		  											(yyval.pStmntVal) = new procDecl(proc, procNbLine);
		  											(*globalSymTab)->insert(proc);
		  											nameSpace = "global";
		  											free((yyvsp[-8].sVal));
		  										}
#line 2371 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 20: /* proctype: PROCTYPE  */
#line 210 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: -> PROCTYPE proctype\n")*/ }
#line 2377 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 21: /* proctype: D_PROCTYPE  */
#line 211 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { std::cout << "Deterministic proctypes are not supported (only useful for simulation)."; }
#line 2383 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 22: /* inst: %empty  */
#line 214 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { /*DBUG("REDUCE: void -> inst\n")*/ (yyval.pConstExprVal) = new exprConst(0, nbrLines); 	}
#line 2389 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 23: /* inst: ACTIVE  */
#line 215 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { /*DBUG("REDUCE: ACTIVE -> inst\n")*/ (yyval.pConstExprVal) = new exprConst(1, nbrLines); }
#line 2395 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 24: /* inst: ACTIVE '[' CONST ']'  */
#line 216 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { /*DBUG("REDUCE: ACTIVE [ CONST ] -> inst \n")*/ (yyval.pConstExprVal) = new exprConst((yyvsp[-1].iVal), nbrLines); }
#line 2401 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 25: /* inst: ACTIVE '[' NAME ']'  */
#line 217 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { 
													/*DBUG("REDUCE: ACTIVE [ NAME ] -> inst\n")*/
													varSymNode* var = *globalSymTab? static_cast<varSymNode*>((*globalSymTab)->lookup((yyvsp[-1].sVal))) : nullptr;
													if(var == nullptr) std::cout << "The variable "<<(yyvsp[-1].sVal)<<" does not exist.";
													else if(var->getType() != symbol::T_INT && var->getType() != symbol::T_BYTE && var->getType() != symbol::T_SHORT) std::cout << "The variable "<<(yyvsp[-1].sVal)<<" is not of type int, short or bit.";
													else if(var->getInitExpr() == nullptr || var->getInitExpr()->getType() != astNode::E_EXPR_CONST) std::cout << "The variable "<<(yyvsp[-1].sVal)<<" does not have a constant value.";
													else {
														(yyval.pConstExprVal) = new exprConst(static_cast<exprConst*>(var->getInitExpr())->getCstValue(), nbrLines);
													}
													free((yyvsp[-1].sVal));											
												}
#line 2417 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 26: /* $@5: %empty  */
#line 231 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                { nameSpace = "init"; }
#line 2423 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 27: /* init: INIT $@5 Opt_priority body  */
#line 233 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        {	
													/*DBUG("REDUCE: INIT Opt_priority body -> init\n")*/
													if(*globalSymTab && (*globalSymTab)->lookup("init") != nullptr) 
														std::cout << "This is the second init process; only one is allowed.";
													else {
														initSymNode* init = new initSymNode(nbrLines, (yyvsp[0].pStmntVal));
														(yyval.pStmntVal) = new initDecl(init, nbrLines);
														(*globalSymTab)->insert(init);
													}
													nameSpace = "global";
												}
#line 2439 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 28: /* events: TRACE body  */
#line 246 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { std::cout << "Event sequences (traces) are not supported."; }
#line 2445 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 29: /* utypedef: TYPEDEF NAME '{' decl_lst '}'  */
#line 249 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                        {	
													/*DBUG("REDUCE: TYPEDEF NAME '{' decl_lst '}' -> utype\n")*/
													tdefSymNode* tdef = new tdefSymNode((yyvsp[-3].sVal), *globalSymTab, declSyms, nbrLines);
													(yyval.pStmntVal) = new tdefDecl(tdef, nbrLines);
													(*globalSymTab)->insert(tdef);
													for(auto declSym : declSyms)
														(*globalSymTab)->remove(declSym->getName());
													declSyms.clear();
													free((yyvsp[-3].sVal));  
												}
#line 2460 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 30: /* $@6: %empty  */
#line 261 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        {	mtypeDef = new mtypedefSymNode(nbrLines);	}
#line 2466 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 31: /* mtypedef: vis TYPE asgn $@6 '{' nlst '}'  */
#line 262 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                {
													assert(mtypeDef->getMTypeList().size() != 0);
													(*globalSymTab)->insert(mtypeDef);

													/*DBUG("REDUCE: vis TYPE asgn { nlst } -> one_decl\n")*/
													if((yyvsp[-5].iType) != symbol::T_MTYPE) {
														std::cout <<  "This syntax only works for MTYPEs definition.";
														exit(1);
													}
													(yyval.pStmntVal) = new mtypeDecl(mtypeDef, nbrLines);
													// The mtype values are added in the nlst rule.
												}
#line 2483 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 32: /* $@7: %empty  */
#line 280 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                         { inInline = true; }
#line 2489 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 33: /* $@8: %empty  */
#line 281 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                       { nameSpace = (yyvsp[0].sVal); savedSymTab = currentSymTab; currentSymTab = currentSymTab->createSubTable(nameSpace); }
#line 2495 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 34: /* $@9: %empty  */
#line 283 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                  { for(std::string it : params) 
		  		currentSymTab->insert(varSymNode::createSymbol(symbol::T_NA, nbrLines, it));
		    currentSymTab = savedSymTab;
		  }
#line 2504 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 35: /* ns: INLINE $@7 NAME $@8 '(' param_list ')' $@9 body  */
#line 287 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        {
													/*DBUG("REDUCE: INLINE nm ( param_list ) body -> ns\n")*/
													auto sym = new inlineSymNode((yyvsp[-6].sVal), params, (yyvsp[0].pStmntVal), nbrLines);
													params.clear();
		  											(yyval.pStmntVal) = new inlineDecl(sym, nbrLines);
													(*globalSymTab)->insert(sym);
													inInline = false;
													free((yyvsp[-6].sVal));
												}
#line 2518 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 45: /* $@10: %empty  */
#line 315 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { 
													savedSymTab = currentSymTab; 
													if(!(currentSymTab = (*globalSymTab)->getSubSymTab(nameSpace)))
														currentSymTab = savedSymTab->createSubTable(nameSpace); 
													nameSpace = "";
												}
#line 2529 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 46: /* body: '{' $@10 sequence OS '}'  */
#line 322 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { /*DBUG("REDUCE: '{' sequence OS '}' -> body\n")*/ (yyval.pStmntVal) = (yyvsp[-2].pStmntVal); (yyval.pStmntVal)->setLocalSymTab(currentSymTab); currentSymTab->setBlock((yyvsp[-2].pStmntVal)); currentSymTab = savedSymTab; }
#line 2535 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 47: /* sequence: step  */
#line 325 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: step -> sequence\n")*/ (yyval.pStmntVal) = (yyvsp[0].pStmntVal);  }
#line 2541 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 48: /* sequence: sequence MS step  */
#line 326 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: sequence MS step -> sequence\n")*/ (yyval.pStmntVal) = stmnt::merge((yyvsp[-2].pStmntVal), (yyvsp[0].pStmntVal)); }
#line 2547 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 49: /* sequence: sequence step  */
#line 327 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: sequence step -> sequence\n")*/ (yyval.pStmntVal) = stmnt::merge((yyvsp[-1].pStmntVal), (yyvsp[0].pStmntVal)); }
#line 2553 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 50: /* step: one_decl  */
#line 330 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { 
													assert(declSyms.front()->getType() != symbol::T_MTYPE_DEF); 
												 	(yyval.pStmntVal) = new varDecl(static_cast<std::list<varSymNode*>>(declSyms), nbrLines);
												 	declSyms.clear();
												}
#line 2563 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 51: /* step: NAME ':' one_decl  */
#line 335 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { std::cout << "Declarations with labels are not suported."; }
#line 2569 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 52: /* step: NAME ':' XU  */
#line 336 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { std::cout << "Channel assertions are currently not supported."; }
#line 2575 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 53: /* step: stmnt  */
#line 337 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { /*DBUG("REDUCE: stmnt -> step\n")*/ (yyval.pStmntVal) = (yyvsp[0].pStmntVal); }
#line 2581 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 54: /* step: stmnt UNLESS stmnt  */
#line 338 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { std::cout << "Unless statements are currently not supported."; }
#line 2587 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 56: /* vis: HIDDEN  */
#line 347 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { std::cout << "The 'hidden' keyword is not supported."; }
#line 2593 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 57: /* vis: SHOW  */
#line 348 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { std::cout << "The 'show' keyword is not supported."; }
#line 2599 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 58: /* vis: ISLOCAL  */
#line 349 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { std::cout << "The 'local' keyword is not supported."; }
#line 2605 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 61: /* $@11: %empty  */
#line 359 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                   { declType = (yyvsp[0].iType); }
#line 2611 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 62: /* one_decl: vis TYPE $@11 var_list  */
#line 359 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                { /*DBUG("REDUCE: vis TYPE var_list -> one_decl\n")*/ }
#line 2617 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 63: /* $@12: %empty  */
#line 360 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                            { declType = symbol::T_UTYPE; typeDef = *globalSymTab? static_cast<tdefSymNode*>((*globalSymTab)->lookup((yyvsp[0].sVal))) : nullptr; assert(typeDef); }
#line 2623 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 64: /* one_decl: vis UNAME $@12 var_list  */
#line 360 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                                                                                                                        { /*DBUG("REDUCE: vis UNAME var_list -> one_decl\n")*/ free((yyvsp[-2].sVal)); }
#line 2629 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 65: /* decl_lst: one_decl  */
#line 363 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: one_decl -> decl_list\n")*/ }
#line 2635 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 66: /* decl_lst: one_decl SEMI decl_lst  */
#line 364 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { /*DBUG("REDUCE: one_decl SEMI decl_list -> decl_lst\n")*/ }
#line 2641 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 67: /* decl: %empty  */
#line 368 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { /*DBUG("REDUCE: void -> decl\n")*/ }
#line 2647 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 68: /* decl: decl_lst  */
#line 369 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { /*DBUG("REDUCE: decl_list -> decl\n")*/ }
#line 2653 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 69: /* var_list: ivar  */
#line 376 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: ivar -> var_list\n")*/ currentSymTab->insert((yyvsp[0].pVarSymVal)); declSyms.push_front((yyvsp[0].pVarSymVal)); }
#line 2659 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 70: /* var_list: ivar ',' var_list  */
#line 377 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: ivar , var_list -> var_list\n")*/ currentSymTab->insert((yyvsp[-2].pVarSymVal)); declSyms.push_front((yyvsp[-2].pVarSymVal)); }
#line 2665 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 71: /* ivar: vardcl  */
#line 380 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { 
												  /*DBUG("REDUCE: var_decl -> ivar\n")*/ (yyval.pVarSymVal) = varSymNode::createSymbol(declType, nbrLines, (yyvsp[0].pDataVal).sVal, (yyvsp[0].pDataVal).iVal); 
												  if(declType == symbol::T_UTYPE) { assert(typeDef); static_cast<utypeSymNode*>((yyval.pVarSymVal))->setUType(typeDef); }
												  if((yyvsp[0].pDataVal).sVal) free((yyvsp[0].pDataVal).sVal);
												}
#line 2675 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 72: /* ivar: vardcl ASGN expr  */
#line 385 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: var_decl ASGN expr -> ivar\n")*/ 
												  (yyval.pVarSymVal) = varSymNode::createSymbol(declType, nbrLines, (yyvsp[-2].pDataVal).sVal, (yyvsp[-2].pDataVal).iVal, (yyvsp[0].pExprVal)); 
												  if(declType == symbol::T_UTYPE) { assert(typeDef); static_cast<utypeSymNode*>((yyval.pVarSymVal))->setUType(typeDef); }
												  if((yyvsp[-2].pDataVal).sVal) free((yyvsp[-2].pDataVal).sVal);
												}
#line 2685 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 73: /* ivar: vardcl ASGN ch_init  */
#line 390 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { /*DBUG("REDUCE: var_decl ASGN ch_init -> ivar\n")*/ (yyval.pVarSymVal) = new chanSymNode(nbrLines, (yyvsp[-2].pDataVal).sVal, (yyvsp[-2].pDataVal).iVal, (yyvsp[0].pDataVal).iVal, typeLst);	
												  typeLst.clear(); if((yyvsp[-2].pDataVal).sVal) free((yyvsp[-2].pDataVal).sVal); //double free???if($3.sVal) free($3.sVal); 
												}
#line 2693 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 74: /* param_list: %empty  */
#line 395 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { }
#line 2699 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 75: /* param_list: NAME  */
#line 396 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { params.push_front(std::string((yyvsp[0].sVal))); free((yyvsp[0].sVal)); }
#line 2705 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 76: /* param_list: NAME ',' param_list  */
#line 397 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                            { params.push_front(std::string((yyvsp[-2].sVal))); free((yyvsp[-2].sVal)); }
#line 2711 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 77: /* ch_init: '[' CONST ']' OF '{' typ_list '}'  */
#line 401 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                        { /*DBUG("REDUCE: [ CONST ] OF { typ_list } -> ch_init\n")*/ (yyval.pDataVal).iVal = (yyvsp[-5].iVal); }
#line 2717 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 78: /* basetype: TYPE  */
#line 404 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pDataVal).sVal = nullptr; (yyval.pDataVal).iType = (yyvsp[0].iType); }
#line 2723 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 79: /* basetype: UNAME  */
#line 405 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pDataVal).sVal = (yyvsp[0].sVal); (yyval.pDataVal).iType = symbol::T_UTYPE; }
#line 2729 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 80: /* typ_list: basetype  */
#line 409 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                {	/*DBUG("REDUCE: basetype -> typ_list\n")*/
													varSymNode* typ = nullptr;
													if((yyvsp[0].pDataVal).iType != symbol::T_UTYPE && (yyvsp[0].pDataVal).iType != symbol::T_NA) {
														typ = varSymNode::createSymbol((yyvsp[0].pDataVal).iType, nbrLines);
													} else {
														tdefSymNode* pType = *globalSymTab ? dynamic_cast<tdefSymNode*>((*globalSymTab)->lookup((yyvsp[0].pDataVal).sVal)) : nullptr;
														typ = new utypeSymNode(pType, nbrLines);
														if(typ == nullptr) {
															std::cout << "The type "<<(yyvsp[0].pDataVal).sVal<<" was not declared in a typedef.\n";
															assert(false);
														}
													}
													typeLst.push_back(typ);
													if((yyvsp[0].pDataVal).sVal) free((yyvsp[0].pDataVal).sVal);
												}
#line 2749 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 81: /* typ_list: basetype ',' typ_list  */
#line 424 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        {	/*DBUG("REDUCE: basetype , typ_list -> typ_list\n")*/
													varSymNode* typ = nullptr;
													if((yyvsp[-2].pDataVal).iType != symbol::T_UTYPE && (yyvsp[-2].pDataVal).iType != symbol::T_NA) {
														typ = varSymNode::createSymbol((yyvsp[-2].pDataVal).iType, nbrLines);
													} else {
														tdefSymNode* pType = *globalSymTab ? dynamic_cast<tdefSymNode*>((*globalSymTab)->lookup((yyvsp[-2].pDataVal).sVal)) : nullptr;
														typ = new utypeSymNode(pType, nbrLines);
														if(typ == nullptr) {
															std::cout << "The type "<<(yyvsp[-2].pDataVal).sVal<<" was not declared in a typedef.\n";
															assert(false);
														}
													}
													typeLst.push_front(typ);
													if((yyvsp[-2].pDataVal).sVal) free((yyvsp[-2].pDataVal).sVal);
												}
#line 2769 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 82: /* vardcl: NAME  */
#line 441 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*/*DBUG("REDUCE: NAME -> vardcl\n"*)*/ (yyval.pDataVal).sVal = (yyvsp[0].sVal); (yyval.pDataVal).iVal = 1; }
#line 2775 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 83: /* vardcl: NAME ':' CONST  */
#line 442 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { std::cout << "The 'unsigned' data type is not supported."; }
#line 2781 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 84: /* vardcl: NAME '[' CONST ']'  */
#line 443 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { /*DBUG("REDUCE: NAME [ CONST ] -> vardcl\n")*/ (yyval.pDataVal).sVal = (yyvsp[-3].sVal); (yyval.pDataVal).iVal = (yyvsp[-1].iVal); }
#line 2787 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 85: /* varref: cmpnd  */
#line 446 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: cmpnd -> varref\n")*/ (yyval.pExprVarRefVal) = (yyvsp[0].pExprVarRefVal); symbol* sym = nullptr; if(!inInline) sym = (yyval.pExprVarRefVal)->resolve(currentSymTab); assert(sym || inInline); }
#line 2793 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 86: /* pfld: NAME  */
#line 449 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: NAME -> pfld\n")*/ (yyval.pExprVarRefNameVal) = new exprVarRefName((yyvsp[0].sVal), nbrLines); free((yyvsp[0].sVal)); }
#line 2799 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 87: /* pfld: NAME '[' expr ']'  */
#line 450 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: NAME [ expr ] -> pfld\n")*/ (yyval.pExprVarRefNameVal) = new exprVarRefName((yyvsp[-3].sVal), (yyvsp[-1].pExprVal), nbrLines); free((yyvsp[-3].sVal)); }
#line 2805 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 88: /* cmpnd: pfld sfld  */
#line 453 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: pfld sfld -> cmpnd\n")*/ (yyval.pExprVarRefVal) = new exprVarRef(nbrLines, (yyvsp[-1].pExprVarRefNameVal), (yyvsp[0].pExprVarRefVal)); }
#line 2811 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 89: /* cmpnd: CONTEXT '.' pfld sfld  */
#line 454 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { /*DBUG("REDUCE: CONTEX . pfld sfld -> cmpnd\n")*/ (yyval.pExprVarRefVal) = new exprVarRef(nbrLines, (yyvsp[-1].pExprVarRefNameVal), (yyvsp[0].pExprVarRefVal)); }
#line 2817 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 90: /* sfld: %empty  */
#line 457 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { /*DBUG("REDUCE: void -> sfld\n")*/ (yyval.pExprVarRefVal) = nullptr; }
#line 2823 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 91: /* sfld: '.' cmpnd  */
#line 458 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { /*DBUG("REDUCE: . cmpnd -> sfld\n")*/ (yyval.pExprVarRefVal) = (yyvsp[0].pExprVarRefVal);   }
#line 2829 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 92: /* stmnt: Special  */
#line 462 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: special -> stmnt\n")*/ (yyval.pStmntVal) = (yyvsp[0].pStmntVal); }
#line 2835 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 93: /* stmnt: Stmnt  */
#line 463 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { /*DBUG("REDUCE: Stmnt -> stmnt\n")*/ (yyval.pStmntVal) = (yyvsp[0].pStmntVal); }
#line 2841 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 94: /* Special: varref RCV rargs  */
#line 466 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pStmntVal) = new stmntChanRecv((yyvsp[-2].pExprVarRefVal), (yyvsp[0].pExprRArgListVal), nbrLines); }
#line 2847 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 95: /* Special: varref SND margs  */
#line 467 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pStmntVal) = new stmntChanSnd((yyvsp[-2].pExprVarRefVal), (yyvsp[0].pExprArgListVal), nbrLines); }
#line 2853 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 96: /* Special: IF options FI  */
#line 468 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pStmntVal) = new stmntIf((yyvsp[-1].pStmntOptVal), (yyvsp[-2].iVal)); }
#line 2859 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 97: /* Special: DO options OD  */
#line 469 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pStmntVal) = new stmntDo((yyvsp[-1].pStmntOptVal), (yyvsp[-2].iVal)); }
#line 2865 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 98: /* Special: BREAK  */
#line 470 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pStmntVal) = new stmntBreak(nbrLines); }
#line 2871 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 99: /* Special: GOTO NAME  */
#line 471 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pStmntVal) = new stmntGoto((yyvsp[0].sVal), nbrLines); free((yyvsp[0].sVal)); }
#line 2877 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 100: /* Special: NAME ':' stmnt  */
#line 472 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { if((yyvsp[0].pStmntVal)->getType() == astNode::E_STMNT_LABEL && static_cast<stmntLabel*>((yyvsp[0].pStmntVal))->getLabelled()->getType() == astNode::E_STMNT_LABEL) 
													std::cout << "Only two labels per state are supported."; 
												  (yyval.pStmntVal) = new stmntLabel((yyvsp[-2].sVal), (yyvsp[0].pStmntVal), nbrLines); free((yyvsp[-2].sVal)); }
#line 2885 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 101: /* Stmnt: varref ASGN full_expr  */
#line 476 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { (yyval.pStmntVal) = new stmntAsgn((yyvsp[-2].pExprVarRefVal), (yyvsp[0].pExprVal), nbrLines); }
#line 2891 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 102: /* Stmnt: varref INCR  */
#line 477 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pStmntVal) = new stmntIncr((yyvsp[-1].pExprVarRefVal), nbrLines); }
#line 2897 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 103: /* Stmnt: varref DECR  */
#line 478 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pStmntVal) = new stmntDecr((yyvsp[-1].pExprVarRefVal), nbrLines); }
#line 2903 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 104: /* Stmnt: PRINT '(' STRING prargs ')'  */
#line 479 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { (yyval.pStmntVal) = new stmntPrint((yyvsp[-2].sVal), (yyvsp[-1].pExprArgListVal), nbrLines); }
#line 2909 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 105: /* Stmnt: PRINTM '(' varref ')'  */
#line 480 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pStmntVal) = new stmntPrintm((yyvsp[-1].pExprVarRefVal), nbrLines); }
#line 2915 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 106: /* Stmnt: PRINTM '(' CONST ')'  */
#line 481 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pStmntVal) = new stmntPrintm((yyvsp[-1].iVal), nbrLines); }
#line 2921 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 107: /* Stmnt: ASSERT full_expr  */
#line 482 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pStmntVal) = new stmntAssert((yyvsp[0].pExprVal), nbrLines); }
#line 2927 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 108: /* Stmnt: ccode  */
#line 483 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { std::cout << "Embedded C code is not supported."; }
#line 2933 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 109: /* Stmnt: varref R_RCV rargs  */
#line 484 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { std::cout << "Sorted send and random receive are not supported."; }
#line 2939 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 110: /* Stmnt: varref RCV LT rargs GT  */
#line 485 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { std::cout << "Channel poll operations are not supported."; }
#line 2945 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 111: /* Stmnt: varref R_RCV LT rargs GT  */
#line 486 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { std::cout << "Channel poll operations are not supported."; }
#line 2951 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 112: /* Stmnt: varref O_SND margs  */
#line 487 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { std::cout << "Sorted send and random receive are not supported."; }
#line 2957 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 113: /* Stmnt: full_expr  */
#line 488 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pStmntVal) = new stmntExpr((yyvsp[0].pExprVal), nbrLines); }
#line 2963 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 114: /* Stmnt: ELSE  */
#line 489 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pStmntVal) = new stmntElse(nbrLines); }
#line 2969 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 115: /* Stmnt: ATOMIC '{' sequence OS '}'  */
#line 490 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { (yyval.pStmntVal) = new stmntAtomic((yyvsp[-2].pStmntVal), nbrLines); }
#line 2975 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 116: /* Stmnt: D_STEP '{' sequence OS '}'  */
#line 491 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { (yyval.pStmntVal) = new stmntDStep((yyvsp[-2].pStmntVal), nbrLines); }
#line 2981 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 117: /* Stmnt: '{' sequence OS '}'  */
#line 492 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pStmntVal) = new stmntSeq((yyvsp[-2].pStmntVal), nbrLines); }
#line 2987 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 118: /* Stmnt: INAME '(' args ')'  */
#line 493 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { 
													(yyval.pStmntVal) = new stmntCall((yyvsp[-3].sVal), (yyvsp[-1].pExprArgListVal), nbrLines); 
													auto fctSym = (*globalSymTab)->lookup((yyvsp[-3].sVal));
													std::cout << "Inline call "<< (yyvsp[-3].sVal) <<" at line "<< nbrLines <<"\n";
													assert(fctSym->getType() == symbol::T_INLINE);
													assert(dynamic_cast<inlineSymNode*>(fctSym) != nullptr);
													if((yyvsp[-1].pExprArgListVal))
														assert(dynamic_cast<inlineSymNode*>(fctSym)->getParams().size() == (yyvsp[-1].pExprArgListVal)->getSize());
													free((yyvsp[-3].sVal)); 
												}
#line 3002 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 119: /* options: option  */
#line 505 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pStmntOptVal) = new stmntOpt((yyvsp[0].pStmntVal), nbrLines); }
#line 3008 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 120: /* options: option options  */
#line 506 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pStmntOptVal) = new stmntOpt((yyvsp[-1].pStmntVal), (yyvsp[0].pStmntOptVal), nbrLines); }
#line 3014 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 121: /* option: SEP sequence OS  */
#line 509 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pStmntVal) = (yyvsp[-1].pStmntVal); }
#line 3020 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 122: /* option: SEP '[' real_expr ']' sequence OS  */
#line 510 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { (yyval.pStmntVal) = (yyvsp[-1].pStmntVal); (yyvsp[-1].pStmntVal)->setProb((yyvsp[-3].rVal)); }
#line 3026 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 123: /* real_expr: '(' real_expr ')'  */
#line 514 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.rVal) = (yyvsp[-1].rVal); }
#line 3032 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 124: /* real_expr: real_expr '+' real_expr  */
#line 515 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.rVal) = (yyvsp[-2].rVal) + (yyvsp[0].rVal); }
#line 3038 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 125: /* real_expr: real_expr '-' real_expr  */
#line 516 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.rVal) = (yyvsp[-2].rVal) - (yyvsp[0].rVal); }
#line 3044 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 126: /* real_expr: real_expr '*' real_expr  */
#line 517 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                    { (yyval.rVal) = (yyvsp[-2].rVal) * (yyvsp[0].rVal); }
#line 3050 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 127: /* real_expr: real_expr '/' real_expr  */
#line 518 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                    { (yyval.rVal) = (yyvsp[-2].rVal) / (yyvsp[0].rVal); }
#line 3056 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 128: /* real_expr: REAL  */
#line 519 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                        { (yyval.rVal) = (yyvsp[0].rVal);}
#line 3062 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 129: /* real_expr: CONST  */
#line 520 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                        { (yyval.rVal) = (yyvsp[0].iVal);}
#line 3068 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 131: /* OS: SEMI  */
#line 524 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                        { /* redundant semi at end of sequence */ }
#line 3074 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 132: /* MS: SEMI  */
#line 527 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                        { /* at least one semi-colon */ }
#line 3080 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 133: /* MS: MS SEMI  */
#line 528 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                        { /* but more are okay too   */ }
#line 3086 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 134: /* aname: NAME  */
#line 531 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.sVal) = (yyvsp[0].sVal); }
#line 3092 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 135: /* aname: PNAME  */
#line 532 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.sVal) = (yyvsp[0].sVal); }
#line 3098 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 136: /* expr: '(' expr ')'  */
#line 535 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprPar		((yyvsp[-1].pExprVal), nbrLines); }
#line 3104 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 137: /* expr: expr '+' expr  */
#line 536 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprPlus		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3110 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 138: /* expr: expr '-' expr  */
#line 537 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprMinus	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3116 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 139: /* expr: expr '*' expr  */
#line 538 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprTimes	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3122 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 140: /* expr: expr '/' expr  */
#line 539 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprDiv		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3128 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 141: /* expr: expr '%' expr  */
#line 540 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprMod		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3134 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 142: /* expr: expr '&' expr  */
#line 541 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprBitwAnd	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3140 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 143: /* expr: expr '^' expr  */
#line 542 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprBitwXor	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3146 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 144: /* expr: expr '|' expr  */
#line 543 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprBitwOr	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3152 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 145: /* expr: expr GT expr  */
#line 544 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprGT		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3158 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 146: /* expr: expr LT expr  */
#line 545 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprLT		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3164 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 147: /* expr: expr GE expr  */
#line 546 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprGE		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3170 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 148: /* expr: expr LE expr  */
#line 547 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprLE		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3176 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 149: /* expr: expr EQ expr  */
#line 548 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprEQ		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3182 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 150: /* expr: expr NE expr  */
#line 549 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprNE		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3188 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 151: /* expr: expr AND expr  */
#line 550 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprAnd		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3194 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 152: /* expr: expr OR expr  */
#line 551 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprOr		((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3200 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 153: /* expr: expr LSHIFT expr  */
#line 552 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprLShift	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3206 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 154: /* expr: expr RSHIFT expr  */
#line 553 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprRShift	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3212 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 155: /* expr: COUNT '(' expr ')'  */
#line 554 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprCount	((yyvsp[-1].pExprVal), nbrLines); }
#line 3218 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 156: /* expr: '~' expr  */
#line 555 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = new exprBitwNeg	((yyvsp[0].pExprVal), nbrLines); }
#line 3224 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 157: /* expr: '-' expr  */
#line 556 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { 	if((yyvsp[0].pExprVal)->getType() != astNode::E_EXPR_CONST) 
														(yyval.pExprVal) = new exprUMin((yyvsp[0].pExprVal), nbrLines);
													else {
														exprConst* tmp = dynamic_cast<exprConst*>((yyvsp[0].pExprVal));
														(yyval.pExprVal) = new exprConst(- tmp->getCstValue(), nbrLines);
														delete tmp;
													}
												}
#line 3237 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 158: /* expr: SND expr  */
#line 564 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprNeg	((yyvsp[0].pExprVal), nbrLines); }
#line 3243 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 159: /* expr: '(' expr SEMI expr ':' expr ')'  */
#line 565 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { (yyval.pExprVal) = new exprCond	((yyvsp[-5].pExprVal), (yyvsp[-3].pExprVal), (yyvsp[-1].pExprVal), nbrLines); }
#line 3249 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 160: /* expr: RUN aname '(' args ')' Opt_priority  */
#line 566 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                        { auto run = new exprRun ((yyvsp[-4].sVal), (yyvsp[-2].pExprArgListVal), nbrLines);
												  (yyval.pExprVal) = run;
												  auto procSym = run->resolve(*globalSymTab); 
												  assert(procSym); free((yyvsp[-4].sVal)); 
												}
#line 3259 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 161: /* expr: LEN '(' varref ')'  */
#line 571 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprLen	((yyvsp[-1].pExprVarRefVal), nbrLines); }
#line 3265 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 162: /* expr: ENABLED '(' expr ')'  */
#line 572 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { std::cout << "The enabled keyword is not supported."; }
#line 3271 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 163: /* expr: varref RCV '[' rargs ']'  */
#line 573 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { std::cout << "Construct not supported."; /* Unclear */ }
#line 3277 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 164: /* expr: varref R_RCV '[' rargs ']'  */
#line 574 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { std::cout << "Sorted send and random receive are not supported."; }
#line 3283 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 165: /* expr: varref '{' varref '}'  */
#line 575 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprProjVar((yyvsp[-3].pExprVarRefVal), (yyvsp[-1].pExprVarRefVal), nbrLines); 
													assert((yyvsp[-3].pExprVarRefVal)->getFinalSymbol()->getType() != symbol::T_VARIANT && (yyvsp[-1].pExprVarRefVal)->getFinalSymbol()->getType() == symbol::T_VARIANT) ; 
												}
#line 3291 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 166: /* expr: varref  */
#line 578 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = new exprVar	((yyvsp[0].pExprVarRefVal), nbrLines); }
#line 3297 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 167: /* expr: cexpr  */
#line 579 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { std::cout << "Embedded C code is not supported."; }
#line 3303 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 168: /* expr: CONST  */
#line 580 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = new exprConst((yyvsp[0].iVal), nbrLines); }
#line 3309 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 169: /* expr: TRUE  */
#line 581 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = new exprTrue	(nbrLines); }
#line 3315 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 170: /* expr: FALSE  */
#line 582 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = new exprFalse(nbrLines); }
#line 3321 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 171: /* expr: TIMEOUT  */
#line 583 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = new exprTimeout(nbrLines); }
#line 3327 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 172: /* expr: NONPROGRESS  */
#line 584 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { std::cout << "The 'np_' variable is not supported."; }
#line 3333 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 173: /* expr: PC_VAL '(' expr ')'  */
#line 585 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { std::cout << "The 'pc_value()' construct is not supported."; }
#line 3339 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 174: /* expr: PNAME '[' expr ']' '@' NAME  */
#line 586 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { std::cout << "Construct not supported."; /* Unclear */ }
#line 3345 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 175: /* expr: PNAME '[' expr ']' ':' pfld  */
#line 587 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { std::cout << "Construct not supported."; /* Unclear */ }
#line 3351 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 176: /* expr: PNAME '@' NAME  */
#line 588 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { std::cout << "Construct not supported."; /* Unclear */ }
#line 3357 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 177: /* expr: PNAME ':' pfld  */
#line 589 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { std::cout << "Construct not supported."; /* Unclear */ }
#line 3363 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 178: /* expr: ltl_expr  */
#line 590 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = (yyvsp[0].pExprVal); }
#line 3369 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 179: /* expr: bltl_expr  */
#line 591 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = (yyvsp[0].pExprVal); }
#line 3375 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 181: /* Opt_priority: PRIORITY CONST  */
#line 595 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { assert(false); std::cout << "The 'priority' construct is related to simulation and not supported."; }
#line 3381 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 182: /* full_expr: expr  */
#line 598 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = (yyvsp[0].pExprVal); }
#line 3387 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 183: /* full_expr: Expr  */
#line 599 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = (yyvsp[0].pExprVal); }
#line 3393 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 185: /* Opt_enabler: PROVIDED '(' full_expr ')'  */
#line 603 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { assert(false); std::cout << "The 'provided' construct is currently not supported."; }
#line 3399 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 186: /* Expr: Probe  */
#line 608 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = (yyvsp[0].pExprVal); }
#line 3405 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 187: /* Expr: '(' Expr ')'  */
#line 609 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprPar	((yyvsp[-1].pExprVal), nbrLines); }
#line 3411 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 188: /* Expr: Expr AND Expr  */
#line 610 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprAnd	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3417 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 189: /* Expr: Expr AND expr  */
#line 611 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprAnd	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3423 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 190: /* Expr: Expr OR Expr  */
#line 612 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprOr	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3429 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 191: /* Expr: Expr OR expr  */
#line 613 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprOr	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3435 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 192: /* Expr: expr AND Expr  */
#line 614 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprAnd	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3441 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 193: /* Expr: expr OR Expr  */
#line 615 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprOr	((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3447 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 194: /* Expr: SKIP  */
#line 616 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = new exprSkip	(nbrLines); }
#line 3453 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 195: /* Probe: FULL '(' varref ')'  */
#line 622 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { (yyval.pExprVal) = new exprFull	((yyvsp[-1].pExprVarRefVal), nbrLines); }
#line 3459 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 196: /* Probe: NFULL '(' varref ')'  */
#line 623 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprNFull((yyvsp[-1].pExprVarRefVal), nbrLines); }
#line 3465 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 197: /* Probe: EMPTY '(' varref ')'  */
#line 624 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprEmpty((yyvsp[-1].pExprVarRefVal), nbrLines); }
#line 3471 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 198: /* Probe: NEMPTY '(' varref ')'  */
#line 625 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprNEmpty((yyvsp[-1].pExprVarRefVal), nbrLines); }
#line 3477 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 199: /* args: %empty  */
#line 629 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                { (yyval.pExprArgListVal) = nullptr; }
#line 3483 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 200: /* args: arg  */
#line 630 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprArgListVal) = (yyvsp[0].pExprArgListVal); }
#line 3489 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 201: /* prargs: %empty  */
#line 634 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprArgListVal) = nullptr; }
#line 3495 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 202: /* prargs: ',' arg  */
#line 635 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprArgListVal) = (yyvsp[0].pExprArgListVal); }
#line 3501 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 203: /* margs: arg  */
#line 639 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprArgListVal) = (yyvsp[0].pExprArgListVal); }
#line 3507 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 204: /* margs: expr '(' arg ')'  */
#line 640 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { assert(false); }
#line 3513 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 205: /* arg: expr  */
#line 643 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprArgListVal) = new exprArgList(new exprArg((yyvsp[0].pExprVal), nbrLines), nbrLines); }
#line 3519 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 206: /* arg: expr ',' arg  */
#line 644 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprArgListVal) = new exprArgList(new exprArg((yyvsp[-2].pExprVal), nbrLines), (yyvsp[0].pExprArgListVal), nbrLines); }
#line 3525 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 207: /* rarg: varref  */
#line 647 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprRArgVal) = new exprRArgVar((yyvsp[0].pExprVarRefVal), nbrLines); }
#line 3531 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 208: /* rarg: EVAL '(' expr ')'  */
#line 648 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprRArgVal) = new exprRArgEval((yyvsp[-1].pExprVal), nbrLines); }
#line 3537 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 209: /* rarg: CONST  */
#line 649 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprRArgVal) = new exprRArgConst(new exprConst((yyvsp[0].iVal), nbrLines), nbrLines); }
#line 3543 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 210: /* rarg: '-' CONST  */
#line 650 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprRArgVal) = new exprRArgConst(new exprConst(-(yyvsp[0].iVal), nbrLines), nbrLines); }
#line 3549 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 211: /* rargs: rarg  */
#line 654 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprRArgListVal) = new exprRArgList((yyvsp[0].pExprRArgVal), nbrLines); }
#line 3555 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 212: /* rargs: rarg ',' rargs  */
#line 655 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprRArgListVal) = new exprRArgList((yyvsp[-2].pExprRArgVal), (yyvsp[0].pExprRArgListVal), nbrLines); }
#line 3561 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 213: /* rargs: rarg '(' rargs ')'  */
#line 656 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprRArgListVal) = new exprRArgList((yyvsp[-3].pExprRArgVal), (yyvsp[-1].pExprRArgListVal), nbrLines); }
#line 3567 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 214: /* rargs: '(' rargs ')'  */
#line 657 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprRArgListVal) = (yyvsp[-1].pExprRArgListVal); }
#line 3573 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 215: /* nlst: NAME  */
#line 660 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { /*DBUG("REDUCE: NAME -> nlst\n")*/ cmtypeSymNode* sym = new cmtypeSymNode(nbrLines, mtypeDef, (yyvsp[0].sVal), mtypeId++); (*globalSymTab)->insert(sym); free((yyvsp[0].sVal)); }
#line 3579 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 216: /* nlst: nlst NAME  */
#line 661 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { /*DBUG("REDUCE: nlst NAME -> NAME\n")*/ cmtypeSymNode* sym = new cmtypeSymNode(nbrLines, mtypeDef, (yyvsp[0].sVal), mtypeId++); (*globalSymTab)->insert(sym); free((yyvsp[0].sVal)); }
#line 3585 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 217: /* nlst: nlst ','  */
#line 662 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                { /*DBUG("REDUCE: nlst , -> nlst\n")*/ }
#line 3591 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 221: /* prop: LTL NAME '{' ltl_expr '}'  */
#line 671 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                {	/*DBUG("REDUCE: one_decl -> unit\n")*/
															auto sym = new ltlSymNode((yyvsp[-3].sVal), (yyvsp[-1].pExprVal), nbrLines);
															(*globalSymTab)->insert(sym);
															stmnt* decl = new ltlDecl(sym, nbrLines);
															assert(decl);
															*program = stmnt::merge(*program, decl);
														}
#line 3603 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 222: /* prop: BLTL NAME '{' bltl_expr '}'  */
#line 678 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                {
															/*DBUG("REDUCE: one_decl -> unit\n")*/
															auto sym = new bltlSymNode((yyvsp[-3].sVal), (yyvsp[-1].pExprVal), nbrLines);
															(*globalSymTab)->insert(sym);
															stmnt* decl = new bltlDecl(sym, nbrLines);
															assert(decl);
															*program = stmnt::merge(*program, decl);
														}
#line 3616 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 223: /* prop: FMULTILTL NAME variant_quants '{' ltl_expr '}'  */
#line 686 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                 { 	/*DBUG("REDUCE: one_decl -> unit\n")*/
															auto sym = new fMultiLTLSymNode((yyvsp[-4].sVal), variants, (yyvsp[-1].pExprVal), nbrLines);
															(*globalSymTab)->insert(sym);
															variants.clear();
															stmnt* decl = new fMultiLTLDecl(sym, nbrLines);
															assert(decl);
															*program = stmnt::merge(*program, decl);
														}
#line 3629 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 224: /* ltl_expr: GLOBALLY expr  */
#line 697 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprGlobally((yyvsp[0].pExprVal), nbrLines); 	}
#line 3635 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 225: /* ltl_expr: FINALLY expr  */
#line 698 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = new exprFinally((yyvsp[0].pExprVal), nbrLines); 	}
#line 3641 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 226: /* ltl_expr: NEXT expr  */
#line 699 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                { (yyval.pExprVal) = new exprNext((yyvsp[0].pExprVal), nbrLines); 		}
#line 3647 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 227: /* ltl_expr: expr UNTIL expr  */
#line 700 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                { (yyval.pExprVal) = new exprUntil((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3653 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 228: /* ltl_expr: expr IMPLIES expr  */
#line 701 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                { (yyval.pExprVal) = new exprImplies((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3659 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 229: /* bltl_expr: GLOBALLY k_steps expr  */
#line 704 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprBoundedGlobally((yyvsp[-1].pExprVal), (yyvsp[0].pExprVal), nbrLines); 	}
#line 3665 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 230: /* bltl_expr: FINALLY k_steps expr  */
#line 705 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprBoundedFinally((yyvsp[-1].pExprVal), (yyvsp[0].pExprVal), nbrLines); 	}
#line 3671 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 231: /* bltl_expr: NEXT expr  */
#line 706 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pExprVal) = new exprNext((yyvsp[0].pExprVal), nbrLines); 		}
#line 3677 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 232: /* bltl_expr: expr UNTIL expr  */
#line 707 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                { (yyval.pExprVal) = new exprUntil((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3683 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 233: /* bltl_expr: expr IMPLIES expr  */
#line 708 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                                { (yyval.pExprVal) = new exprImplies((yyvsp[-2].pExprVal), (yyvsp[0].pExprVal), nbrLines); }
#line 3689 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 234: /* k_steps: '{' varref GT expr '}'  */
#line 711 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pExprVal) = new exprGT ((yyvsp[-3].pExprVarRefVal), (yyvsp[-1].pExprVal), nbrLines); }
#line 3695 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 235: /* k_steps: '{' varref LT expr '}'  */
#line 712 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprLT ((yyvsp[-3].pExprVarRefVal), (yyvsp[-1].pExprVal), nbrLines); }
#line 3701 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 236: /* k_steps: '{' varref GE expr '}'  */
#line 713 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprGE ((yyvsp[-3].pExprVarRefVal), (yyvsp[-1].pExprVal), nbrLines); }
#line 3707 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 237: /* k_steps: '{' varref LE expr '}'  */
#line 714 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprLE ((yyvsp[-3].pExprVarRefVal), (yyvsp[-1].pExprVal), nbrLines); }
#line 3713 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 238: /* k_steps: '{' varref EQ expr '}'  */
#line 715 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprEQ ((yyvsp[-3].pExprVarRefVal), (yyvsp[-1].pExprVal), nbrLines); }
#line 3719 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 239: /* k_steps: '{' varref NE expr '}'  */
#line 716 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { (yyval.pExprVal) = new exprNE ((yyvsp[-3].pExprVarRefVal), (yyvsp[-1].pExprVal), nbrLines); }
#line 3725 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 240: /* variant_quants: variant_quant  */
#line 719 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                { variants.push_front((yyvsp[0].pVarQuantVal)); }
#line 3731 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 241: /* variant_quants: variant_quant ',' variant_quants  */
#line 720 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { variants.push_front((yyvsp[-2].pVarQuantVal)); }
#line 3737 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 242: /* variant_quant: ALWAYS variant_expr  */
#line 723 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                        { (yyval.pVarQuantVal) = new exprAlways((yyvsp[0].pExprVarRefNameVal), nbrLines); }
#line 3743 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 243: /* variant_quant: EVENTUALLY variant_expr  */
#line 724 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                                                        { (yyval.pVarQuantVal) = new exprEventually((yyvsp[0].pExprVarRefNameVal), nbrLines); }
#line 3749 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;

  case 244: /* variant_expr: '{' NAME '}' '[' expr ']'  */
#line 727 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
                                                        { auto sym = new variantSymNode(nbrLines, (yyvsp[-4].sVal), (yyvsp[-1].pExprVal)); (*globalSymTab)->insert(sym); (yyval.pExprVarRefNameVal) = new exprVarRefName((yyvsp[-4].sVal), sym, nbrLines); }
#line 3755 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"
    break;


#line 3759 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/y.tab.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
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
        yyerror (globalSymTab, program, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
                      yytoken, &yylval, globalSymTab, program);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, globalSymTab, program);
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
  yyerror (globalSymTab, program, YY_("memory exhausted"));
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
                  yytoken, &yylval, globalSymTab, program);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, globalSymTab, program);
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

#line 733 "/home/slazreg/Work/Research/Mutation/Deadalux/parser/promela.y"
