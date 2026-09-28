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


/* Substitute the variable and function names.  */
#define yyparse         _xkbcommon_parse
#define yylex           _xkbcommon_lex
#define yyerror         _xkbcommon_error
#define yydebug         _xkbcommon_debug
#define yynerrs         _xkbcommon_nerrs

/* First part of user prologue.  */
#line 33 "src/xkbcomp/parser.y"

#include "config.h"

#include "xkbcomp/xkbcomp-priv.h"
#include "xkbcomp/ast-build.h"
#include "xkbcomp/parser-priv.h"
#include "scanner-utils.h"
#include "keysym.h"

struct parser_param {
    struct xkb_context *ctx;
    struct scanner *scanner;
    XkbFile *rtrn;
    bool more_maps;
};

#define parser_err(param, error_id, fmt, ...) \
    scanner_err((param)->scanner, error_id, fmt, ##__VA_ARGS__)

#define parser_warn(param, warning_id, fmt, ...) \
    scanner_warn((param)->scanner, warning_id, fmt, ##__VA_ARGS__)

static void
_xkbcommon_error(struct parser_param *param, const char *msg)
{
    parser_err(param, XKB_ERROR_INVALID_SYNTAX, "%s", msg);
}

static bool
resolve_keysym(struct parser_param *param, const char *name, xkb_keysym_t *sym_rtrn)
{
    xkb_keysym_t sym;

    if (!name || istreq(name, "any") || istreq(name, "nosymbol")) {
        *sym_rtrn = XKB_KEY_NoSymbol;
        return true;
    }

    if (istreq(name, "none") || istreq(name, "voidsymbol")) {
        *sym_rtrn = XKB_KEY_VoidSymbol;
        return true;
    }

    sym = xkb_keysym_from_name(name, XKB_KEYSYM_NO_FLAGS);
    if (sym != XKB_KEY_NoSymbol) {
        *sym_rtrn = sym;
        check_deprecated_keysyms(parser_warn, param, param->ctx,
                                 sym, name, name, "%s", "");
        return true;
    }

    return false;
}

#define param_scanner param->scanner

#line 133 "config/libxkbcommon.so.0.0.0.p/parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* END_OF_FILE  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ERROR_TOK = 3,                  /* ERROR_TOK  */
  YYSYMBOL_XKB_KEYMAP = 4,                 /* XKB_KEYMAP  */
  YYSYMBOL_XKB_KEYCODES = 5,               /* XKB_KEYCODES  */
  YYSYMBOL_XKB_TYPES = 6,                  /* XKB_TYPES  */
  YYSYMBOL_XKB_SYMBOLS = 7,                /* XKB_SYMBOLS  */
  YYSYMBOL_XKB_COMPATMAP = 8,              /* XKB_COMPATMAP  */
  YYSYMBOL_XKB_GEOMETRY = 9,               /* XKB_GEOMETRY  */
  YYSYMBOL_XKB_SEMANTICS = 10,             /* XKB_SEMANTICS  */
  YYSYMBOL_XKB_LAYOUT = 11,                /* XKB_LAYOUT  */
  YYSYMBOL_INCLUDE = 12,                   /* INCLUDE  */
  YYSYMBOL_OVERRIDE = 13,                  /* OVERRIDE  */
  YYSYMBOL_AUGMENT = 14,                   /* AUGMENT  */
  YYSYMBOL_REPLACE = 15,                   /* REPLACE  */
  YYSYMBOL_ALTERNATE = 16,                 /* ALTERNATE  */
  YYSYMBOL_VIRTUAL_MODS = 17,              /* VIRTUAL_MODS  */
  YYSYMBOL_TYPE = 18,                      /* TYPE  */
  YYSYMBOL_INTERPRET = 19,                 /* INTERPRET  */
  YYSYMBOL_ACTION_TOK = 20,                /* ACTION_TOK  */
  YYSYMBOL_KEY = 21,                       /* KEY  */
  YYSYMBOL_ALIAS = 22,                     /* ALIAS  */
  YYSYMBOL_GROUP = 23,                     /* GROUP  */
  YYSYMBOL_MODIFIER_MAP = 24,              /* MODIFIER_MAP  */
  YYSYMBOL_INDICATOR = 25,                 /* INDICATOR  */
  YYSYMBOL_SHAPE = 26,                     /* SHAPE  */
  YYSYMBOL_KEYS = 27,                      /* KEYS  */
  YYSYMBOL_ROW = 28,                       /* ROW  */
  YYSYMBOL_SECTION = 29,                   /* SECTION  */
  YYSYMBOL_OVERLAY = 30,                   /* OVERLAY  */
  YYSYMBOL_TEXT = 31,                      /* TEXT  */
  YYSYMBOL_OUTLINE = 32,                   /* OUTLINE  */
  YYSYMBOL_SOLID = 33,                     /* SOLID  */
  YYSYMBOL_LOGO = 34,                      /* LOGO  */
  YYSYMBOL_VIRTUAL = 35,                   /* VIRTUAL  */
  YYSYMBOL_EQUALS = 36,                    /* EQUALS  */
  YYSYMBOL_PLUS = 37,                      /* PLUS  */
  YYSYMBOL_MINUS = 38,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 39,                    /* DIVIDE  */
  YYSYMBOL_TIMES = 40,                     /* TIMES  */
  YYSYMBOL_OBRACE = 41,                    /* OBRACE  */
  YYSYMBOL_CBRACE = 42,                    /* CBRACE  */
  YYSYMBOL_OPAREN = 43,                    /* OPAREN  */
  YYSYMBOL_CPAREN = 44,                    /* CPAREN  */
  YYSYMBOL_OBRACKET = 45,                  /* OBRACKET  */
  YYSYMBOL_CBRACKET = 46,                  /* CBRACKET  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_SEMI = 49,                      /* SEMI  */
  YYSYMBOL_EXCLAM = 50,                    /* EXCLAM  */
  YYSYMBOL_INVERT = 51,                    /* INVERT  */
  YYSYMBOL_STRING = 52,                    /* STRING  */
  YYSYMBOL_INTEGER = 53,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 54,                     /* FLOAT  */
  YYSYMBOL_IDENT = 55,                     /* IDENT  */
  YYSYMBOL_KEYNAME = 56,                   /* KEYNAME  */
  YYSYMBOL_PARTIAL = 57,                   /* PARTIAL  */
  YYSYMBOL_DEFAULT = 58,                   /* DEFAULT  */
  YYSYMBOL_HIDDEN = 59,                    /* HIDDEN  */
  YYSYMBOL_ALPHANUMERIC_KEYS = 60,         /* ALPHANUMERIC_KEYS  */
  YYSYMBOL_MODIFIER_KEYS = 61,             /* MODIFIER_KEYS  */
  YYSYMBOL_KEYPAD_KEYS = 62,               /* KEYPAD_KEYS  */
  YYSYMBOL_FUNCTION_KEYS = 63,             /* FUNCTION_KEYS  */
  YYSYMBOL_ALTERNATE_GROUP = 64,           /* ALTERNATE_GROUP  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_XkbFile = 66,                   /* XkbFile  */
  YYSYMBOL_XkbCompositeMap = 67,           /* XkbCompositeMap  */
  YYSYMBOL_XkbCompositeType = 68,          /* XkbCompositeType  */
  YYSYMBOL_XkbMapConfigList = 69,          /* XkbMapConfigList  */
  YYSYMBOL_XkbMapConfig = 70,              /* XkbMapConfig  */
  YYSYMBOL_FileType = 71,                  /* FileType  */
  YYSYMBOL_OptFlags = 72,                  /* OptFlags  */
  YYSYMBOL_Flags = 73,                     /* Flags  */
  YYSYMBOL_Flag = 74,                      /* Flag  */
  YYSYMBOL_DeclList = 75,                  /* DeclList  */
  YYSYMBOL_Decl = 76,                      /* Decl  */
  YYSYMBOL_VarDecl = 77,                   /* VarDecl  */
  YYSYMBOL_KeyNameDecl = 78,               /* KeyNameDecl  */
  YYSYMBOL_KeyAliasDecl = 79,              /* KeyAliasDecl  */
  YYSYMBOL_VModDecl = 80,                  /* VModDecl  */
  YYSYMBOL_VModDefList = 81,               /* VModDefList  */
  YYSYMBOL_VModDef = 82,                   /* VModDef  */
  YYSYMBOL_InterpretDecl = 83,             /* InterpretDecl  */
  YYSYMBOL_InterpretMatch = 84,            /* InterpretMatch  */
  YYSYMBOL_VarDeclList = 85,               /* VarDeclList  */
  YYSYMBOL_KeyTypeDecl = 86,               /* KeyTypeDecl  */
  YYSYMBOL_SymbolsDecl = 87,               /* SymbolsDecl  */
  YYSYMBOL_OptSymbolsBody = 88,            /* OptSymbolsBody  */
  YYSYMBOL_SymbolsBody = 89,               /* SymbolsBody  */
  YYSYMBOL_SymbolsVarDecl = 90,            /* SymbolsVarDecl  */
  YYSYMBOL_ArrayInit = 91,                 /* ArrayInit  */
  YYSYMBOL_GroupCompatDecl = 92,           /* GroupCompatDecl  */
  YYSYMBOL_ModMapDecl = 93,                /* ModMapDecl  */
  YYSYMBOL_LedMapDecl = 94,                /* LedMapDecl  */
  YYSYMBOL_LedNameDecl = 95,               /* LedNameDecl  */
  YYSYMBOL_ShapeDecl = 96,                 /* ShapeDecl  */
  YYSYMBOL_SectionDecl = 97,               /* SectionDecl  */
  YYSYMBOL_SectionBody = 98,               /* SectionBody  */
  YYSYMBOL_SectionBodyItem = 99,           /* SectionBodyItem  */
  YYSYMBOL_RowBody = 100,                  /* RowBody  */
  YYSYMBOL_RowBodyItem = 101,              /* RowBodyItem  */
  YYSYMBOL_Keys = 102,                     /* Keys  */
  YYSYMBOL_Key = 103,                      /* Key  */
  YYSYMBOL_OverlayDecl = 104,              /* OverlayDecl  */
  YYSYMBOL_OverlayKeyList = 105,           /* OverlayKeyList  */
  YYSYMBOL_OverlayKey = 106,               /* OverlayKey  */
  YYSYMBOL_OutlineList = 107,              /* OutlineList  */
  YYSYMBOL_OutlineInList = 108,            /* OutlineInList  */
  YYSYMBOL_CoordList = 109,                /* CoordList  */
  YYSYMBOL_Coord = 110,                    /* Coord  */
  YYSYMBOL_DoodadDecl = 111,               /* DoodadDecl  */
  YYSYMBOL_DoodadType = 112,               /* DoodadType  */
  YYSYMBOL_FieldSpec = 113,                /* FieldSpec  */
  YYSYMBOL_Element = 114,                  /* Element  */
  YYSYMBOL_OptMergeMode = 115,             /* OptMergeMode  */
  YYSYMBOL_MergeMode = 116,                /* MergeMode  */
  YYSYMBOL_OptExprList = 117,              /* OptExprList  */
  YYSYMBOL_ExprList = 118,                 /* ExprList  */
  YYSYMBOL_Expr = 119,                     /* Expr  */
  YYSYMBOL_Term = 120,                     /* Term  */
  YYSYMBOL_MultiActionList = 121,          /* MultiActionList  */
  YYSYMBOL_ActionList = 122,               /* ActionList  */
  YYSYMBOL_Actions = 123,                  /* Actions  */
  YYSYMBOL_Action = 124,                   /* Action  */
  YYSYMBOL_Lhs = 125,                      /* Lhs  */
  YYSYMBOL_Terminal = 126,                 /* Terminal  */
  YYSYMBOL_MultiKeySymList = 127,          /* MultiKeySymList  */
  YYSYMBOL_KeySymList = 128,               /* KeySymList  */
  YYSYMBOL_KeySyms = 129,                  /* KeySyms  */
  YYSYMBOL_KeySym = 130,                   /* KeySym  */
  YYSYMBOL_SignedNumber = 131,             /* SignedNumber  */
  YYSYMBOL_Number = 132,                   /* Number  */
  YYSYMBOL_Float = 133,                    /* Float  */
  YYSYMBOL_Integer = 134,                  /* Integer  */
  YYSYMBOL_KeyCode = 135,                  /* KeyCode  */
  YYSYMBOL_Ident = 136,                    /* Ident  */
  YYSYMBOL_String = 137,                   /* String  */
  YYSYMBOL_OptMapName = 138,               /* OptMapName  */
  YYSYMBOL_MapName = 139                   /* MapName  */
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   788

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   257


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
       0,     4,     5,     6,     7,     8,     9,    10,    11,     2,
      12,    13,    14,    15,    16,     2,     2,     2,     2,     2,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     2,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     2,     2,     2,     2,
      52,    53,    54,    55,    56,     2,     2,     2,     2,     2,
      57,    58,    59,    60,    61,    62,    63,    64,     2,     2,
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
       2,     2,     2,     2,     2,     3,     1,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   257,   257,   259,   261,   265,   271,   272,   273,   276,
     278,   282,   290,   291,   292,   293,   294,   297,   298,   301,
     302,   305,   306,   307,   308,   309,   310,   311,   312,   315,
     330,   340,   343,   349,   354,   359,   364,   369,   374,   379,
     384,   389,   394,   395,   396,   397,   404,   406,   408,   412,
     416,   420,   424,   426,   430,   432,   436,   442,   444,   448,
     450,   454,   460,   466,   467,   470,   472,   476,   477,   478,
     479,   480,   483,   485,   487,   491,   495,   499,   503,   505,
     509,   511,   515,   519,   520,   523,   525,   527,   529,   531,
     535,   536,   539,   540,   544,   545,   548,   550,   554,   558,
     559,   562,   565,   567,   571,   573,   575,   579,   581,   585,
     589,   593,   594,   595,   596,   599,   600,   603,   605,   607,
     609,   611,   613,   615,   617,   619,   621,   623,   627,   628,
     631,   632,   633,   634,   635,   645,   646,   649,   651,   655,
     657,   659,   661,   663,   665,   669,   671,   673,   675,   677,
     679,   681,   683,   687,   693,   695,   697,   701,   703,   707,
     711,   715,   717,   719,   721,   725,   727,   729,   731,   735,
     741,   743,   745,   749,   751,   758,   762,   776,   777,   815,
     816,   819,   820,   823,   826,   829,   832,   833,   836,   839,
     840,   843
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
  "END_OF_FILE", "error", "\"invalid token\"", "ERROR_TOK", "XKB_KEYMAP",
  "XKB_KEYCODES", "XKB_TYPES", "XKB_SYMBOLS", "XKB_COMPATMAP",
  "XKB_GEOMETRY", "XKB_SEMANTICS", "XKB_LAYOUT", "INCLUDE", "OVERRIDE",
  "AUGMENT", "REPLACE", "ALTERNATE", "VIRTUAL_MODS", "TYPE", "INTERPRET",
  "ACTION_TOK", "KEY", "ALIAS", "GROUP", "MODIFIER_MAP", "INDICATOR",
  "SHAPE", "KEYS", "ROW", "SECTION", "OVERLAY", "TEXT", "OUTLINE", "SOLID",
  "LOGO", "VIRTUAL", "EQUALS", "PLUS", "MINUS", "DIVIDE", "TIMES",
  "OBRACE", "CBRACE", "OPAREN", "CPAREN", "OBRACKET", "CBRACKET", "DOT",
  "COMMA", "SEMI", "EXCLAM", "INVERT", "STRING", "INTEGER", "FLOAT",
  "IDENT", "KEYNAME", "PARTIAL", "DEFAULT", "HIDDEN", "ALPHANUMERIC_KEYS",
  "MODIFIER_KEYS", "KEYPAD_KEYS", "FUNCTION_KEYS", "ALTERNATE_GROUP",
  "$accept", "XkbFile", "XkbCompositeMap", "XkbCompositeType",
  "XkbMapConfigList", "XkbMapConfig", "FileType", "OptFlags", "Flags",
  "Flag", "DeclList", "Decl", "VarDecl", "KeyNameDecl", "KeyAliasDecl",
  "VModDecl", "VModDefList", "VModDef", "InterpretDecl", "InterpretMatch",
  "VarDeclList", "KeyTypeDecl", "SymbolsDecl", "OptSymbolsBody",
  "SymbolsBody", "SymbolsVarDecl", "ArrayInit", "GroupCompatDecl",
  "ModMapDecl", "LedMapDecl", "LedNameDecl", "ShapeDecl", "SectionDecl",
  "SectionBody", "SectionBodyItem", "RowBody", "RowBodyItem", "Keys",
  "Key", "OverlayDecl", "OverlayKeyList", "OverlayKey", "OutlineList",
  "OutlineInList", "CoordList", "Coord", "DoodadDecl", "DoodadType",
  "FieldSpec", "Element", "OptMergeMode", "MergeMode", "OptExprList",
  "ExprList", "Expr", "Term", "MultiActionList", "ActionList", "Actions",
  "Action", "Lhs", "Terminal", "MultiKeySymList", "KeySymList", "KeySyms",
  "KeySym", "SignedNumber", "Number", "Float", "Integer", "KeyCode",
  "Ident", "String", "OptMapName", "MapName", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-182)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-187)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     142,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
       8,  -182,  -182,   769,   724,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,   -24,   -24,  -182,  -182,    -6,
    -182,    11,   724,  -182,   699,  -182,   241,     3,    28,  -182,
    -182,  -182,  -182,  -182,  -182,    35,  -182,   318,    36,  -182,
    -182,   -18,    44,   -23,  -182,    52,    55,    81,   -18,   108,
      44,  -182,    44,    93,  -182,  -182,  -182,   124,   -18,  -182,
     122,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,    44,   -36,  -182,   126,
     125,  -182,   189,  -182,   151,  -182,   144,  -182,  -182,  -182,
     153,   183,  -182,   187,   204,   207,   213,   221,   228,   233,
     234,    81,   227,   224,   238,   441,   714,   441,  -182,   -18,
    -182,   441,   654,   654,   441,   336,   231,   441,   441,   441,
     654,   -16,   523,   248,  -182,  -182,   239,   654,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,   441,   441,   441,
     441,   441,  -182,  -182,    46,    64,  -182,   253,  -182,  -182,
    -182,  -182,  -182,   245,    33,  -182,   174,  -182,   540,   568,
     174,   275,   -18,   250,   254,  -182,  -182,   271,     6,   259,
      77,    38,   174,   128,   583,   265,    -4,    85,  -182,   104,
    -182,   276,    44,   270,    44,  -182,  -182,   482,  -182,  -182,
    -182,   441,  -182,   611,  -182,  -182,  -182,   195,  -182,  -182,
     441,   441,   441,   441,   441,  -182,   441,   441,  -182,   264,
    -182,   266,   274,   672,  -182,   277,   280,     5,  -182,  -182,
      72,  -182,  -182,  -182,   269,   336,   359,  -182,  -182,   278,
     441,  -182,   282,   106,   169,  -182,  -182,   284,  -182,   285,
     -14,   296,   265,   400,   631,   273,   309,  -182,   143,   314,
    -182,   281,   321,   232,   232,  -182,  -182,   174,    92,  -182,
    -182,   115,   322,   127,   323,   441,  -182,   695,  -182,   -17,
    -182,  -182,  -182,   174,  -182,   174,  -182,  -182,  -182,    -4,
    -182,  -182,  -182,  -182,   265,   174,   283,  -182,    37,  -182,
     263,  -182,  -182,  -182,  -182,  -182,  -182,   714,   714,  -182,
     -23,   -23,   328,   714,  -182,  -182,   -23,  -182,  -182,   320,
     131,   -10,   326,  -182,   290,   147,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,   441,  -182,   149,  -182,  -182,   333,
     344,   263,   167,   346,   -10,  -182,  -182,  -182,  -182,  -182,
    -182
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      18,     4,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     2,     3,     0,    17,    20,     1,     6,    12,    13,
      15,    14,    16,     7,     8,   190,   190,    19,   191,     0,
     189,     0,    18,    31,    18,    10,     0,   129,     0,     9,
     130,   132,   131,   133,   134,     0,    29,     0,   128,     5,
      11,     0,   119,   118,   117,   120,     0,   121,   122,   123,
     124,   125,   126,   127,   112,   113,   114,     0,     0,   186,
       0,   187,    32,    34,    35,    30,    33,    36,    37,    39,
      38,    40,    41,    42,    43,    44,     0,   161,   116,     0,
     115,    45,     0,    53,    54,   188,     0,   177,   184,   176,
       0,    58,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      51,     0,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,     0,    48,   185,     0,     0,   119,   118,
     120,   121,   122,   123,   124,   126,   127,     0,     0,     0,
       0,     0,   183,   168,   161,     0,   144,   149,   151,   167,
     166,   115,   165,   162,     0,    52,    55,    60,     0,     0,
      57,     0,     0,     0,    63,    66,    71,     0,   115,     0,
       0,     0,   138,     0,     0,     0,     0,     0,   103,     0,
     108,     0,   123,   125,     0,    86,    88,     0,    84,    89,
      87,     0,    49,     0,   146,   149,   145,     0,   147,   148,
     136,     0,     0,     0,     0,   163,     0,     0,    46,     0,
      59,     0,   177,     0,    74,   176,     0,     0,   156,   155,
       0,   172,   171,    70,     0,     0,     0,    50,    75,     0,
       0,    78,     0,     0,     0,   182,   181,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
     152,     0,   135,   140,   141,   139,   142,   143,     0,    61,
      56,     0,     0,     0,     0,   136,    73,     0,    72,     0,
      62,    65,    68,    67,    76,   137,    77,   104,   179,     0,
      80,   102,    81,   107,     0,   106,     0,    93,     0,    91,
       0,    82,    79,   110,   150,   164,   159,     0,     0,   175,
       0,     0,     0,     0,   154,   153,     0,   170,   169,     0,
       0,     0,     0,    90,     0,     0,   100,   157,   158,   173,
     174,   160,   109,   105,     0,    96,     0,    95,    85,     0,
       0,     0,     0,     0,     0,   101,    98,    99,    97,    92,
      94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,  -182,  -182,  -182,    91,  -182,   398,  -182,   385,
    -182,  -182,   -33,  -182,  -182,  -182,  -182,   286,  -182,  -182,
     -56,  -182,  -182,  -182,  -182,   165,   170,  -182,  -182,   354,
    -182,  -182,  -182,  -182,   206,  -182,   109,  -182,    78,  -182,
    -182,    67,  -182,   166,  -181,   175,   383,  -182,   -47,  -182,
    -182,  -182,   157,  -126,    69,   105,  -182,  -182,   156,  -168,
      94,  -182,  -182,  -182,   155,   -43,   146,   192,  -182,   -52,
    -182,   -25,   -39,   413,  -182
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    10,    11,    25,    34,    12,    26,    36,    14,    15,
      37,    46,   167,    73,    74,    75,    92,    93,    76,   100,
     168,    77,    78,   173,   174,   175,   176,    79,    80,   196,
      82,    83,    84,   197,   198,   298,   299,   336,   337,   199,
     325,   326,   187,   188,   189,   190,   200,    86,   154,    88,
      47,    48,   261,   262,   182,   156,   227,   271,   228,   272,
     157,   158,   230,   273,   231,   274,   247,   248,   159,   160,
     136,   161,   162,    29,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,   102,   181,   229,   243,   105,    97,   107,    16,   115,
     101,   116,    97,    96,    72,    40,    41,    42,    43,    44,
     108,   109,    90,   110,   316,   185,    94,   185,    28,   186,
      98,   334,    99,   106,   244,    32,    98,    69,    99,    69,
      71,    69,    71,   112,    71,    45,   335,   114,   -69,   245,
     246,   276,    33,   277,   -69,   138,   139,    54,   140,   133,
     141,   142,   143,   144,   296,    61,   145,   169,   146,   163,
     211,   212,   213,   214,   184,    87,    87,    49,    87,   322,
     239,   203,   218,    87,    50,    87,   240,    68,    91,   210,
      87,   115,    69,   116,    94,    71,    95,    90,    90,   195,
     178,   211,   212,   213,   214,    90,   191,    90,   103,   315,
     215,   104,    90,   320,   211,   212,   213,   214,   278,   102,
     279,    87,    87,    35,   226,    39,   238,   249,   232,   211,
     212,   213,   214,   250,    98,   220,   220,    87,   305,   327,
     328,    89,     1,    90,    90,  -111,   251,   233,   287,   111,
      87,   220,   252,   108,   252,   255,    87,   306,   113,    90,
      95,    98,   117,   307,   195,   211,   212,   213,   214,   309,
     220,   102,    90,   333,   118,   310,   226,   241,    90,   252,
     211,   212,   213,   214,   155,   122,   164,   121,    87,   340,
     166,   343,   302,   170,   123,   341,   180,   344,   183,     2,
       3,     4,     5,     6,     7,     8,     9,    87,   342,   348,
     178,   211,   212,   213,   214,   240,    89,    89,   207,   177,
     124,   297,   245,   246,    89,   191,    89,   102,   125,    90,
     226,    89,   211,   212,   213,   214,   318,   119,   120,   260,
     126,   205,   205,   127,   205,   205,    18,    19,    20,    21,
      22,    87,   204,   206,   128,   208,   209,   129,   102,   102,
     226,   226,    89,    89,   102,   297,   226,   329,   330,   130,
     258,   213,   214,    90,   131,   132,   134,   135,    89,   137,
     263,   264,   265,   266,   201,   267,   268,   179,   202,   216,
     217,    89,   234,   138,   139,    54,   140,    89,   141,   142,
     143,   144,   235,    61,   222,   283,   146,   236,   237,   285,
     186,   254,   253,   269,   300,   270,   223,  -126,   280,   324,
    -186,   224,   295,   275,   321,   304,   339,   284,    98,   177,
     225,   286,   289,    71,   290,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,   292,    61,    62,    89,    63,
      64,    65,    66,    67,   138,   139,    54,   140,   301,   141,
     142,   143,   144,   303,    61,   145,   332,   146,    68,   240,
     308,   311,   331,    69,    70,   338,    71,   138,   139,    54,
     140,   171,   141,   142,   143,   144,   172,    61,   145,   345,
     146,    69,    89,   346,    71,   349,   147,   148,    13,    27,
     281,    81,   149,   257,   171,   165,   282,   323,   347,   150,
     151,    95,    98,   152,    69,   153,   291,    71,   138,   139,
      54,   140,   350,   141,   142,   143,   144,   293,    61,   145,
      85,   146,   312,   314,   317,   319,   288,   147,   148,    31,
       0,   294,     0,   149,     0,     0,     0,     0,     0,     0,
     150,   151,    95,    98,   152,    69,   153,     0,    71,   138,
     139,    54,   140,     0,   141,   142,   143,   144,     0,    61,
     145,     0,   146,     0,     0,     0,     0,     0,   147,   148,
       0,     0,     0,     0,   149,     0,     0,     0,     0,     0,
       0,   150,   151,    95,    98,   152,    69,   153,     0,    71,
     138,   139,    54,   140,     0,   141,   142,   192,   144,     0,
     193,   145,   194,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,   256,     0,     0,     0,     0,     0,
       0,     0,    68,     0,     0,     0,     0,    69,     0,     0,
      71,   138,   139,    54,   140,     0,   141,   142,   192,   144,
       0,   193,   145,   194,    63,    64,    65,    66,   138,   139,
      54,   140,     0,   141,   142,   143,   144,     0,    61,   145,
       0,   146,     0,    68,     0,     0,     0,     0,    69,     0,
       0,    71,   219,     0,     0,     0,   138,   139,    54,   140,
      68,   141,   142,   143,   144,    69,    61,   145,    71,   146,
       0,   138,   139,    54,   140,     0,   141,   142,   143,   144,
     221,    61,   145,     0,   146,     0,     0,     0,    68,     0,
       0,     0,     0,    69,     0,   242,    71,     0,     0,   138,
     139,    54,   140,    68,   141,   142,   143,   144,    69,    61,
     145,    71,   146,     0,     0,     0,     0,     0,     0,   138,
     139,    54,   140,   259,   141,   142,   143,   144,   296,    61,
     145,    68,   146,     0,     0,     0,    69,     0,     0,    71,
       0,     0,   138,   139,    54,   140,     0,   141,   142,   143,
     144,    68,    61,   145,     0,   146,    69,     0,     0,    71,
     138,   139,    54,   140,     0,   141,   142,   143,   144,     0,
      61,   222,     0,   146,    68,     0,     0,     0,     0,    69,
       0,     0,    71,   138,   139,    54,   140,     0,   141,   142,
     143,   144,     0,    61,   145,    98,   146,   225,     0,     0,
      71,     0,   138,   139,    54,   140,   313,   141,   142,   143,
     144,    38,    61,   145,     0,   146,     0,     0,     0,     0,
      69,     0,     0,    71,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    69,
       0,     0,    71,    17,    18,    19,    20,    21,    22,    23,
      24,     2,     3,     4,     5,     6,     7,     8,     9
};

static const yytype_int16 yycheck[] =
{
      47,    53,   128,   171,   185,    57,    29,    59,     0,    45,
      53,    47,    29,    52,    47,    12,    13,    14,    15,    16,
      59,    60,    47,    62,    41,    41,    51,    41,    52,    45,
      53,    41,    55,    58,    38,    41,    53,    55,    55,    55,
      58,    55,    58,    68,    58,    42,    56,    86,    42,    53,
      54,    46,    41,    48,    48,    18,    19,    20,    21,   111,
      23,    24,    25,    26,    27,    28,    29,   123,    31,   116,
      37,    38,    39,    40,   130,   122,   123,    49,   125,    42,
      42,   137,    49,   130,    49,   132,    48,    50,    52,    43,
     137,    45,    55,    47,   119,    58,    52,   122,   123,   132,
     125,    37,    38,    39,    40,   130,   131,   132,    56,   277,
      46,    56,   137,   294,    37,    38,    39,    40,    46,   171,
      48,   168,   169,    32,   171,    34,    49,    42,   171,    37,
      38,    39,    40,    48,    53,   168,   169,   184,    46,   307,
     308,    47,     0,   168,   169,    52,    42,   172,    42,    25,
     197,   184,    48,   192,    48,   194,   203,    42,    36,   184,
      52,    53,    36,    48,   197,    37,    38,    39,    40,    42,
     203,   223,   197,    42,    49,    48,   223,    49,   203,    48,
      37,    38,    39,    40,   115,    41,   117,    36,   235,    42,
     121,    42,    49,   124,    41,    48,   127,    48,   129,    57,
      58,    59,    60,    61,    62,    63,    64,   254,   334,    42,
     235,    37,    38,    39,    40,    48,   122,   123,   149,   125,
      37,   254,    53,    54,   130,   250,   132,   279,    41,   254,
     277,   137,    37,    38,    39,    40,   279,    48,    49,    44,
      36,   147,   148,    36,   150,   151,     5,     6,     7,     8,
       9,   298,   147,   148,    41,   150,   151,    36,   310,   311,
     307,   308,   168,   169,   316,   298,   313,   310,   311,    41,
     201,    39,    40,   298,    41,    41,    49,    53,   184,    41,
     211,   212,   213,   214,    36,   216,   217,    56,    49,    36,
      45,   197,    42,    18,    19,    20,    21,   203,    23,    24,
      25,    26,    48,    28,    29,   236,    31,    36,    49,   240,
      45,    41,    36,    49,    41,    49,    41,    43,    49,    56,
      43,    46,   253,    43,    41,    44,    36,    49,    53,   235,
      55,    49,    48,    58,    49,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    49,    28,    29,   254,    31,
      32,    33,    34,    35,    18,    19,    20,    21,    49,    23,
      24,    25,    26,    49,    28,    29,    46,    31,    50,    48,
      48,    48,    44,    55,    56,    49,    58,    18,    19,    20,
      21,    45,    23,    24,    25,    26,    50,    28,    29,    56,
      31,    55,   298,    49,    58,    49,    37,    38,     0,    14,
     235,    47,    43,   197,    45,   119,   236,   298,   341,    50,
      51,    52,    53,    54,    55,    56,   250,    58,    18,    19,
      20,    21,   344,    23,    24,    25,    26,   252,    28,    29,
      47,    31,   275,   277,   279,   289,   244,    37,    38,    26,
      -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,    -1,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    -1,    28,    29,
      -1,    31,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    42,    -1,    -1,    -1,    18,    19,    20,    21,
      50,    23,    24,    25,    26,    55,    28,    29,    58,    31,
      -1,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      42,    28,    29,    -1,    31,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    55,    -1,    42,    58,    -1,    -1,    18,
      19,    20,    21,    50,    23,    24,    25,    26,    55,    28,
      29,    58,    31,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    42,    23,    24,    25,    26,    27,    28,
      29,    50,    31,    -1,    -1,    -1,    55,    -1,    -1,    58,
      -1,    -1,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    50,    28,    29,    -1,    31,    55,    -1,    -1,    58,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    -1,
      28,    29,    -1,    31,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    18,    19,    20,    21,    -1,    23,    24,
      25,    26,    -1,    28,    29,    53,    31,    55,    -1,    -1,
      58,    -1,    18,    19,    20,    21,    41,    23,    24,    25,
      26,    42,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    58,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,     4,     5,     6,     7,     8,     9,    10,
      11,    57,    58,    59,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      66,    67,    70,    72,    73,    74,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    68,    71,    74,    52,   138,
     139,   138,    41,    41,    69,    70,    72,    75,    42,    70,
      12,    13,    14,    15,    16,    42,    76,   115,   116,    49,
      49,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    28,    29,    31,    32,    33,    34,    35,    50,    55,
      56,    58,    77,    78,    79,    80,    83,    86,    87,    92,
      93,    94,    95,    96,    97,   111,   112,   113,   114,   125,
     136,    52,    81,    82,   136,    52,   137,    29,    53,    55,
      84,   130,   134,    56,    56,   134,   136,   134,   137,   137,
     137,    25,   136,    36,   137,    45,    47,    36,    49,    48,
      49,    36,    41,    41,    37,    41,    36,    36,    41,    36,
      41,    41,    41,   134,    49,    53,   135,    41,    18,    19,
      21,    23,    24,    25,    26,    29,    31,    37,    38,    43,
      50,    51,    54,    56,   113,   119,   120,   125,   126,   133,
     134,   136,   137,   113,   119,    82,   119,    77,    85,    85,
     119,    45,    50,    88,    89,    90,    91,   125,   136,    56,
     119,   118,   119,   119,    85,    41,    45,   107,   108,   109,
     110,   136,    25,    28,    30,    77,    94,    98,    99,   104,
     111,    36,    49,    85,   120,   125,   120,   119,   120,   120,
      43,    37,    38,    39,    40,    46,    36,    45,    49,    42,
      77,    42,    29,    41,    46,    55,   113,   121,   123,   124,
     127,   129,   130,   136,    42,    48,    36,    49,    49,    42,
      48,    49,    42,   109,    38,    53,    54,   131,   132,    42,
      48,    42,    48,    36,    41,   137,    42,    99,   119,    42,
      44,   117,   118,   119,   119,   119,   119,   119,   119,    49,
      49,   122,   124,   128,   130,    43,    46,    48,    46,    48,
      49,    90,    91,   119,    49,   119,    49,    42,   132,    48,
      49,   108,    49,   110,    41,   119,    27,    77,   100,   101,
      41,    49,    49,    49,    44,    46,    42,    48,    48,    42,
      48,    48,   117,    41,   123,   124,    41,   129,   130,   131,
     109,    41,    42,   101,    56,   105,   106,   124,   124,   130,
     130,    44,    46,    42,    41,    56,   102,   103,    49,    36,
      42,    48,   118,    42,    48,    56,    49,   106,    42,    49,
     103
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    67,    68,    68,    68,    69,
      69,    70,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    78,
      79,    80,    81,    81,    82,    82,    83,    84,    84,    85,
      85,    86,    87,    88,    88,    89,    89,    90,    90,    90,
      90,    90,    91,    91,    91,    92,    93,    94,    95,    95,
      96,    96,    97,    98,    98,    99,    99,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   105,
     105,   106,   107,   107,   108,   108,   108,   109,   109,   110,
     111,   112,   112,   112,   112,   113,   113,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   117,   117,   118,   118,   119,
     119,   119,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   122,   122,   123,
     124,   125,   125,   125,   125,   126,   126,   126,   126,   127,
     127,   127,   127,   128,   128,   129,   130,   130,   130,   131,
     131,   132,   132,   133,   134,   135,   136,   136,   137,   138,
     138,   139
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     7,     1,     1,     1,     2,
       1,     7,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     2,     3,     4,
       5,     3,     3,     1,     1,     3,     6,     3,     1,     2,
       1,     6,     6,     1,     0,     3,     1,     3,     3,     1,
       2,     1,     3,     3,     2,     5,     6,     6,     5,     6,
       6,     6,     6,     2,     1,     5,     1,     1,     1,     1,
       2,     1,     5,     1,     3,     1,     1,     3,     6,     3,
       1,     3,     3,     1,     3,     5,     3,     3,     1,     5,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     0,     3,     1,     3,
       3,     3,     3,     3,     1,     2,     2,     2,     2,     1,
       4,     1,     3,     3,     3,     1,     1,     3,     3,     3,
       4,     1,     3,     4,     6,     1,     1,     1,     1,     3,
       3,     1,     1,     3,     3,     3,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1
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
        yyerror (param, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, param); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct parser_param *param)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (param);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct parser_param *param)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, param);
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
                 int yyrule, struct parser_param *param)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], param);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, param); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, struct parser_param *param)
{
  YY_USE (yyvaluep);
  YY_USE (param);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_STRING: /* STRING  */
#line 241 "src/xkbcomp/parser.y"
            { free(((*yyvaluep).str)); }
#line 1343 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_IDENT: /* IDENT  */
#line 241 "src/xkbcomp/parser.y"
            { free(((*yyvaluep).str)); }
#line 1349 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_XkbFile: /* XkbFile  */
#line 239 "src/xkbcomp/parser.y"
            { if (!param->rtrn) FreeXkbFile(((*yyvaluep).file)); }
#line 1355 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_XkbCompositeMap: /* XkbCompositeMap  */
#line 239 "src/xkbcomp/parser.y"
            { if (!param->rtrn) FreeXkbFile(((*yyvaluep).file)); }
#line 1361 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_XkbMapConfigList: /* XkbMapConfigList  */
#line 240 "src/xkbcomp/parser.y"
            { FreeXkbFile(((*yyvaluep).fileList).head); }
#line 1367 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_XkbMapConfig: /* XkbMapConfig  */
#line 239 "src/xkbcomp/parser.y"
            { if (!param->rtrn) FreeXkbFile(((*yyvaluep).file)); }
#line 1373 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_DeclList: /* DeclList  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).anyList).head); }
#line 1379 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_Decl: /* Decl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).any)); }
#line 1385 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_VarDecl: /* VarDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).var)); }
#line 1391 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_KeyNameDecl: /* KeyNameDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).keyCode)); }
#line 1397 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_KeyAliasDecl: /* KeyAliasDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).keyAlias)); }
#line 1403 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_VModDecl: /* VModDecl  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).vmodList).head); }
#line 1409 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_VModDefList: /* VModDefList  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).vmodList).head); }
#line 1415 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_VModDef: /* VModDef  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).vmod)); }
#line 1421 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_InterpretDecl: /* InterpretDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).interp)); }
#line 1427 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_InterpretMatch: /* InterpretMatch  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).interp)); }
#line 1433 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_VarDeclList: /* VarDeclList  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).varList).head); }
#line 1439 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_KeyTypeDecl: /* KeyTypeDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).keyType)); }
#line 1445 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_SymbolsDecl: /* SymbolsDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).syms)); }
#line 1451 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_OptSymbolsBody: /* OptSymbolsBody  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).varList).head); }
#line 1457 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_SymbolsBody: /* SymbolsBody  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).varList).head); }
#line 1463 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_SymbolsVarDecl: /* SymbolsVarDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).var)); }
#line 1469 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_ArrayInit: /* ArrayInit  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1475 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_GroupCompatDecl: /* GroupCompatDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).groupCompat)); }
#line 1481 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_ModMapDecl: /* ModMapDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).modMask)); }
#line 1487 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_LedMapDecl: /* LedMapDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).ledMap)); }
#line 1493 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_LedNameDecl: /* LedNameDecl  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).ledName)); }
#line 1499 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_CoordList: /* CoordList  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1505 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_Coord: /* Coord  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1511 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_OptExprList: /* OptExprList  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).exprList).head); }
#line 1517 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_ExprList: /* ExprList  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).exprList).head); }
#line 1523 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_Expr: /* Expr  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1529 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_Term: /* Term  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1535 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_MultiActionList: /* MultiActionList  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).exprList).head); }
#line 1541 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_ActionList: /* ActionList  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).exprList).head); }
#line 1547 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_Actions: /* Actions  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1553 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_Action: /* Action  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1559 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_Lhs: /* Lhs  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1565 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_Terminal: /* Terminal  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1571 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_MultiKeySymList: /* MultiKeySymList  */
#line 235 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).exprList).head); }
#line 1577 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_KeySymList: /* KeySymList  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1583 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_KeySyms: /* KeySyms  */
#line 232 "src/xkbcomp/parser.y"
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
#line 1589 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_OptMapName: /* OptMapName  */
#line 241 "src/xkbcomp/parser.y"
            { free(((*yyvaluep).str)); }
#line 1595 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

    case YYSYMBOL_MapName: /* MapName  */
#line 241 "src/xkbcomp/parser.y"
            { free(((*yyvaluep).str)); }
#line 1601 "config/libxkbcommon.so.0.0.0.p/parser.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct parser_param *param)
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
      yychar = yylex (&yylval, param_scanner);
    }

  if (yychar <= END_OF_FILE)
    {
      yychar = END_OF_FILE;
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
  case 2: /* XkbFile: XkbCompositeMap  */
#line 258 "src/xkbcomp/parser.y"
                        { (yyval.file) = param->rtrn = (yyvsp[0].file); param->more_maps = !!param->rtrn; (void) yynerrs; }
#line 1877 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 3: /* XkbFile: XkbMapConfig  */
#line 260 "src/xkbcomp/parser.y"
                        { (yyval.file) = param->rtrn = (yyvsp[0].file); param->more_maps = !!param->rtrn; YYACCEPT; }
#line 1883 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 4: /* XkbFile: END_OF_FILE  */
#line 262 "src/xkbcomp/parser.y"
                        { (yyval.file) = param->rtrn = NULL; param->more_maps = false; }
#line 1889 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 5: /* XkbCompositeMap: OptFlags XkbCompositeType OptMapName OBRACE XkbMapConfigList CBRACE SEMI  */
#line 268 "src/xkbcomp/parser.y"
                        { (yyval.file) = XkbFileCreate((yyvsp[-5].file_type), (yyvsp[-4].str), (ParseCommon *) (yyvsp[-2].fileList).head, (yyvsp[-6].mapFlags)); }
#line 1895 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 6: /* XkbCompositeType: XKB_KEYMAP  */
#line 271 "src/xkbcomp/parser.y"
                                        { (yyval.file_type) = FILE_TYPE_KEYMAP; }
#line 1901 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 7: /* XkbCompositeType: XKB_SEMANTICS  */
#line 272 "src/xkbcomp/parser.y"
                                        { (yyval.file_type) = FILE_TYPE_KEYMAP; }
#line 1907 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 8: /* XkbCompositeType: XKB_LAYOUT  */
#line 273 "src/xkbcomp/parser.y"
                                        { (yyval.file_type) = FILE_TYPE_KEYMAP; }
#line 1913 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 9: /* XkbMapConfigList: XkbMapConfigList XkbMapConfig  */
#line 277 "src/xkbcomp/parser.y"
                        { (yyval.fileList).head = (yyvsp[-1].fileList).head; (yyval.fileList).last->common.next = &(yyvsp[0].file)->common; (yyval.fileList).last = (yyvsp[0].file); }
#line 1919 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 10: /* XkbMapConfigList: XkbMapConfig  */
#line 279 "src/xkbcomp/parser.y"
                        { (yyval.fileList).head = (yyval.fileList).last = (yyvsp[0].file); }
#line 1925 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 11: /* XkbMapConfig: OptFlags FileType OptMapName OBRACE DeclList CBRACE SEMI  */
#line 285 "src/xkbcomp/parser.y"
                        {
                            (yyval.file) = XkbFileCreate((yyvsp[-5].file_type), (yyvsp[-4].str), (yyvsp[-2].anyList).head, (yyvsp[-6].mapFlags));
                        }
#line 1933 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 12: /* FileType: XKB_KEYCODES  */
#line 290 "src/xkbcomp/parser.y"
                                                { (yyval.file_type) = FILE_TYPE_KEYCODES; }
#line 1939 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 13: /* FileType: XKB_TYPES  */
#line 291 "src/xkbcomp/parser.y"
                                                { (yyval.file_type) = FILE_TYPE_TYPES; }
#line 1945 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 14: /* FileType: XKB_COMPATMAP  */
#line 292 "src/xkbcomp/parser.y"
                                                { (yyval.file_type) = FILE_TYPE_COMPAT; }
#line 1951 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 15: /* FileType: XKB_SYMBOLS  */
#line 293 "src/xkbcomp/parser.y"
                                                { (yyval.file_type) = FILE_TYPE_SYMBOLS; }
#line 1957 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 16: /* FileType: XKB_GEOMETRY  */
#line 294 "src/xkbcomp/parser.y"
                                                { (yyval.file_type) = FILE_TYPE_GEOMETRY; }
#line 1963 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 17: /* OptFlags: Flags  */
#line 297 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = (yyvsp[0].mapFlags); }
#line 1969 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 18: /* OptFlags: %empty  */
#line 298 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = 0; }
#line 1975 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 19: /* Flags: Flags Flag  */
#line 301 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = ((yyvsp[-1].mapFlags) | (yyvsp[0].mapFlags)); }
#line 1981 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 20: /* Flags: Flag  */
#line 302 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = (yyvsp[0].mapFlags); }
#line 1987 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 21: /* Flag: PARTIAL  */
#line 305 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = MAP_IS_PARTIAL; }
#line 1993 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 22: /* Flag: DEFAULT  */
#line 306 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = MAP_IS_DEFAULT; }
#line 1999 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 23: /* Flag: HIDDEN  */
#line 307 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = MAP_IS_HIDDEN; }
#line 2005 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 24: /* Flag: ALPHANUMERIC_KEYS  */
#line 308 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = MAP_HAS_ALPHANUMERIC; }
#line 2011 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 25: /* Flag: MODIFIER_KEYS  */
#line 309 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = MAP_HAS_MODIFIER; }
#line 2017 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 26: /* Flag: KEYPAD_KEYS  */
#line 310 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = MAP_HAS_KEYPAD; }
#line 2023 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 27: /* Flag: FUNCTION_KEYS  */
#line 311 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = MAP_HAS_FN; }
#line 2029 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 28: /* Flag: ALTERNATE_GROUP  */
#line 312 "src/xkbcomp/parser.y"
                                                { (yyval.mapFlags) = MAP_IS_ALTGR; }
#line 2035 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 29: /* DeclList: DeclList Decl  */
#line 316 "src/xkbcomp/parser.y"
                        {
                            if ((yyvsp[0].any)) {
                                if ((yyvsp[-1].anyList).head) {
                                    (yyval.anyList).head = (yyvsp[-1].anyList).head; (yyvsp[-1].anyList).last->next = (yyvsp[0].any); (yyval.anyList).last = (yyvsp[0].any);
                                } else {
                                    (yyval.anyList).head = (yyval.anyList).last = (yyvsp[0].any);
                                }
                            }
                        }
#line 2049 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 30: /* DeclList: DeclList OptMergeMode VModDecl  */
#line 331 "src/xkbcomp/parser.y"
                        {
                            for (VModDef *vmod = (yyvsp[0].vmodList).head; vmod; vmod = (VModDef *) vmod->common.next)
                                vmod->merge = (yyvsp[-1].merge);
                            if ((yyvsp[-2].anyList).head) {
                                (yyval.anyList).head = (yyvsp[-2].anyList).head; (yyvsp[-2].anyList).last->next = &(yyvsp[0].vmodList).head->common; (yyval.anyList).last = &(yyvsp[0].vmodList).last->common;
                            } else {
                                (yyval.anyList).head = &(yyvsp[0].vmodList).head->common; (yyval.anyList).last = &(yyvsp[0].vmodList).last->common;
                            }
                        }
#line 2063 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 31: /* DeclList: %empty  */
#line 340 "src/xkbcomp/parser.y"
                        { (yyval.anyList).head = (yyval.anyList).last = NULL; }
#line 2069 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 32: /* Decl: OptMergeMode VarDecl  */
#line 344 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].var)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].var);
                        }
#line 2078 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 33: /* Decl: OptMergeMode InterpretDecl  */
#line 350 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].interp)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].interp);
                        }
#line 2087 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 34: /* Decl: OptMergeMode KeyNameDecl  */
#line 355 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].keyCode)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].keyCode);
                        }
#line 2096 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 35: /* Decl: OptMergeMode KeyAliasDecl  */
#line 360 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].keyAlias)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].keyAlias);
                        }
#line 2105 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 36: /* Decl: OptMergeMode KeyTypeDecl  */
#line 365 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].keyType)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].keyType);
                        }
#line 2114 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 37: /* Decl: OptMergeMode SymbolsDecl  */
#line 370 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].syms)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].syms);
                        }
#line 2123 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 38: /* Decl: OptMergeMode ModMapDecl  */
#line 375 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].modMask)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].modMask);
                        }
#line 2132 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 39: /* Decl: OptMergeMode GroupCompatDecl  */
#line 380 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].groupCompat)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].groupCompat);
                        }
#line 2141 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 40: /* Decl: OptMergeMode LedMapDecl  */
#line 385 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].ledMap)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].ledMap);
                        }
#line 2150 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 41: /* Decl: OptMergeMode LedNameDecl  */
#line 390 "src/xkbcomp/parser.y"
                        {
                            (yyvsp[0].ledName)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].ledName);
                        }
#line 2159 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 42: /* Decl: OptMergeMode ShapeDecl  */
#line 394 "src/xkbcomp/parser.y"
                                                        { (yyval.any) = NULL; }
#line 2165 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 43: /* Decl: OptMergeMode SectionDecl  */
#line 395 "src/xkbcomp/parser.y"
                                                        { (yyval.any) = NULL; }
#line 2171 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 44: /* Decl: OptMergeMode DoodadDecl  */
#line 396 "src/xkbcomp/parser.y"
                                                        { (yyval.any) = NULL; }
#line 2177 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 45: /* Decl: MergeMode STRING  */
#line 398 "src/xkbcomp/parser.y"
                        {
                            (yyval.any) = (ParseCommon *) IncludeCreate(param->ctx, (yyvsp[0].str), (yyvsp[-1].merge));
                            free((yyvsp[0].str));
                        }
#line 2186 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 46: /* VarDecl: Lhs EQUALS Expr SEMI  */
#line 405 "src/xkbcomp/parser.y"
                        { (yyval.var) = VarCreate((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2192 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 47: /* VarDecl: Ident SEMI  */
#line 407 "src/xkbcomp/parser.y"
                        { (yyval.var) = BoolVarCreate((yyvsp[-1].atom), true); }
#line 2198 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 48: /* VarDecl: EXCLAM Ident SEMI  */
#line 409 "src/xkbcomp/parser.y"
                        { (yyval.var) = BoolVarCreate((yyvsp[-1].atom), false); }
#line 2204 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 49: /* KeyNameDecl: KEYNAME EQUALS KeyCode SEMI  */
#line 413 "src/xkbcomp/parser.y"
                        { (yyval.keyCode) = KeycodeCreate((yyvsp[-3].atom), (yyvsp[-1].num)); }
#line 2210 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 50: /* KeyAliasDecl: ALIAS KEYNAME EQUALS KEYNAME SEMI  */
#line 417 "src/xkbcomp/parser.y"
                        { (yyval.keyAlias) = KeyAliasCreate((yyvsp[-3].atom), (yyvsp[-1].atom)); }
#line 2216 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 51: /* VModDecl: VIRTUAL_MODS VModDefList SEMI  */
#line 421 "src/xkbcomp/parser.y"
                        { (yyval.vmodList) = (yyvsp[-1].vmodList); }
#line 2222 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 52: /* VModDefList: VModDefList COMMA VModDef  */
#line 425 "src/xkbcomp/parser.y"
                        { (yyval.vmodList).head = (yyvsp[-2].vmodList).head; (yyval.vmodList).last->common.next = &(yyvsp[0].vmod)->common; (yyval.vmodList).last = (yyvsp[0].vmod); }
#line 2228 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 53: /* VModDefList: VModDef  */
#line 427 "src/xkbcomp/parser.y"
                        { (yyval.vmodList).head = (yyval.vmodList).last = (yyvsp[0].vmod); }
#line 2234 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 54: /* VModDef: Ident  */
#line 431 "src/xkbcomp/parser.y"
                        { (yyval.vmod) = VModCreate((yyvsp[0].atom), NULL); }
#line 2240 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 55: /* VModDef: Ident EQUALS Expr  */
#line 433 "src/xkbcomp/parser.y"
                        { (yyval.vmod) = VModCreate((yyvsp[-2].atom), (yyvsp[0].expr)); }
#line 2246 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 56: /* InterpretDecl: INTERPRET InterpretMatch OBRACE VarDeclList CBRACE SEMI  */
#line 439 "src/xkbcomp/parser.y"
                        { (yyvsp[-4].interp)->def = (yyvsp[-2].varList).head; (yyval.interp) = (yyvsp[-4].interp); }
#line 2252 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 57: /* InterpretMatch: KeySym PLUS Expr  */
#line 443 "src/xkbcomp/parser.y"
                        { (yyval.interp) = InterpCreate((yyvsp[-2].keysym), (yyvsp[0].expr)); }
#line 2258 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 58: /* InterpretMatch: KeySym  */
#line 445 "src/xkbcomp/parser.y"
                        { (yyval.interp) = InterpCreate((yyvsp[0].keysym), NULL); }
#line 2264 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 59: /* VarDeclList: VarDeclList VarDecl  */
#line 449 "src/xkbcomp/parser.y"
                        { (yyval.varList).head = (yyvsp[-1].varList).head; (yyval.varList).last->common.next = &(yyvsp[0].var)->common; (yyval.varList).last = (yyvsp[0].var); }
#line 2270 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 60: /* VarDeclList: VarDecl  */
#line 451 "src/xkbcomp/parser.y"
                        { (yyval.varList).head = (yyval.varList).last = (yyvsp[0].var); }
#line 2276 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 61: /* KeyTypeDecl: TYPE String OBRACE VarDeclList CBRACE SEMI  */
#line 457 "src/xkbcomp/parser.y"
                        { (yyval.keyType) = KeyTypeCreate((yyvsp[-4].atom), (yyvsp[-2].varList).head); }
#line 2282 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 62: /* SymbolsDecl: KEY KEYNAME OBRACE OptSymbolsBody CBRACE SEMI  */
#line 463 "src/xkbcomp/parser.y"
                        { (yyval.syms) = SymbolsCreate((yyvsp[-4].atom), (yyvsp[-2].varList).head); }
#line 2288 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 63: /* OptSymbolsBody: SymbolsBody  */
#line 466 "src/xkbcomp/parser.y"
                                    { (yyval.varList) = (yyvsp[0].varList); }
#line 2294 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 64: /* OptSymbolsBody: %empty  */
#line 467 "src/xkbcomp/parser.y"
                                    { (yyval.varList).head = (yyval.varList).last = NULL; }
#line 2300 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 65: /* SymbolsBody: SymbolsBody COMMA SymbolsVarDecl  */
#line 471 "src/xkbcomp/parser.y"
                        { (yyval.varList).head = (yyvsp[-2].varList).head; (yyval.varList).last->common.next = &(yyvsp[0].var)->common; (yyval.varList).last = (yyvsp[0].var); }
#line 2306 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 66: /* SymbolsBody: SymbolsVarDecl  */
#line 473 "src/xkbcomp/parser.y"
                        { (yyval.varList).head = (yyval.varList).last = (yyvsp[0].var); }
#line 2312 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 67: /* SymbolsVarDecl: Lhs EQUALS Expr  */
#line 476 "src/xkbcomp/parser.y"
                                                { (yyval.var) = VarCreate((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2318 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 68: /* SymbolsVarDecl: Lhs EQUALS ArrayInit  */
#line 477 "src/xkbcomp/parser.y"
                                                { (yyval.var) = VarCreate((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2324 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 69: /* SymbolsVarDecl: Ident  */
#line 478 "src/xkbcomp/parser.y"
                                                { (yyval.var) = BoolVarCreate((yyvsp[0].atom), true); }
#line 2330 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 70: /* SymbolsVarDecl: EXCLAM Ident  */
#line 479 "src/xkbcomp/parser.y"
                                                { (yyval.var) = BoolVarCreate((yyvsp[0].atom), false); }
#line 2336 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 71: /* SymbolsVarDecl: ArrayInit  */
#line 480 "src/xkbcomp/parser.y"
                                                { (yyval.var) = VarCreate(NULL, (yyvsp[0].expr)); }
#line 2342 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 72: /* ArrayInit: OBRACKET MultiKeySymList CBRACKET  */
#line 484 "src/xkbcomp/parser.y"
                        { (yyval.expr) = (yyvsp[-1].exprList).head; }
#line 2348 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 73: /* ArrayInit: OBRACKET MultiActionList CBRACKET  */
#line 486 "src/xkbcomp/parser.y"
                        { (yyval.expr) = (yyvsp[-1].exprList).head; }
#line 2354 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 74: /* ArrayInit: OBRACKET CBRACKET  */
#line 488 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprEmptyList(); }
#line 2360 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 75: /* GroupCompatDecl: GROUP Integer EQUALS Expr SEMI  */
#line 492 "src/xkbcomp/parser.y"
                        { (yyval.groupCompat) = GroupCompatCreate((yyvsp[-3].num), (yyvsp[-1].expr)); }
#line 2366 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 76: /* ModMapDecl: MODIFIER_MAP Ident OBRACE ExprList CBRACE SEMI  */
#line 496 "src/xkbcomp/parser.y"
                        { (yyval.modMask) = ModMapCreate((yyvsp[-4].atom), (yyvsp[-2].exprList).head); }
#line 2372 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 77: /* LedMapDecl: INDICATOR String OBRACE VarDeclList CBRACE SEMI  */
#line 500 "src/xkbcomp/parser.y"
                        { (yyval.ledMap) = LedMapCreate((yyvsp[-4].atom), (yyvsp[-2].varList).head); }
#line 2378 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 78: /* LedNameDecl: INDICATOR Integer EQUALS Expr SEMI  */
#line 504 "src/xkbcomp/parser.y"
                        { (yyval.ledName) = LedNameCreate((yyvsp[-3].num), (yyvsp[-1].expr), false); }
#line 2384 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 79: /* LedNameDecl: VIRTUAL INDICATOR Integer EQUALS Expr SEMI  */
#line 506 "src/xkbcomp/parser.y"
                        { (yyval.ledName) = LedNameCreate((yyvsp[-3].num), (yyvsp[-1].expr), true); }
#line 2390 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 80: /* ShapeDecl: SHAPE String OBRACE OutlineList CBRACE SEMI  */
#line 510 "src/xkbcomp/parser.y"
                        { (yyval.geom) = NULL; }
#line 2396 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 81: /* ShapeDecl: SHAPE String OBRACE CoordList CBRACE SEMI  */
#line 512 "src/xkbcomp/parser.y"
                        { (void) (yyvsp[-2].expr); (yyval.geom) = NULL; }
#line 2402 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 82: /* SectionDecl: SECTION String OBRACE SectionBody CBRACE SEMI  */
#line 516 "src/xkbcomp/parser.y"
                        { (yyval.geom) = NULL; }
#line 2408 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 83: /* SectionBody: SectionBody SectionBodyItem  */
#line 519 "src/xkbcomp/parser.y"
                                                        { (yyval.geom) = NULL;}
#line 2414 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 84: /* SectionBody: SectionBodyItem  */
#line 520 "src/xkbcomp/parser.y"
                                                        { (yyval.geom) = NULL; }
#line 2420 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 85: /* SectionBodyItem: ROW OBRACE RowBody CBRACE SEMI  */
#line 524 "src/xkbcomp/parser.y"
                        { (yyval.geom) = NULL; }
#line 2426 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 86: /* SectionBodyItem: VarDecl  */
#line 526 "src/xkbcomp/parser.y"
                        { FreeStmt((ParseCommon *) (yyvsp[0].var)); (yyval.geom) = NULL; }
#line 2432 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 87: /* SectionBodyItem: DoodadDecl  */
#line 528 "src/xkbcomp/parser.y"
                        { (yyval.geom) = NULL; }
#line 2438 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 88: /* SectionBodyItem: LedMapDecl  */
#line 530 "src/xkbcomp/parser.y"
                        { FreeStmt((ParseCommon *) (yyvsp[0].ledMap)); (yyval.geom) = NULL; }
#line 2444 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 89: /* SectionBodyItem: OverlayDecl  */
#line 532 "src/xkbcomp/parser.y"
                        { (yyval.geom) = NULL; }
#line 2450 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 90: /* RowBody: RowBody RowBodyItem  */
#line 535 "src/xkbcomp/parser.y"
                                                { (yyval.geom) = NULL;}
#line 2456 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 91: /* RowBody: RowBodyItem  */
#line 536 "src/xkbcomp/parser.y"
                                                { (yyval.geom) = NULL; }
#line 2462 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 92: /* RowBodyItem: KEYS OBRACE Keys CBRACE SEMI  */
#line 539 "src/xkbcomp/parser.y"
                                                     { (yyval.geom) = NULL; }
#line 2468 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 93: /* RowBodyItem: VarDecl  */
#line 541 "src/xkbcomp/parser.y"
                        { FreeStmt((ParseCommon *) (yyvsp[0].var)); (yyval.geom) = NULL; }
#line 2474 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 94: /* Keys: Keys COMMA Key  */
#line 544 "src/xkbcomp/parser.y"
                                                { (yyval.geom) = NULL; }
#line 2480 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 95: /* Keys: Key  */
#line 545 "src/xkbcomp/parser.y"
                                                { (yyval.geom) = NULL; }
#line 2486 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 96: /* Key: KEYNAME  */
#line 549 "src/xkbcomp/parser.y"
                        { (yyval.geom) = NULL; }
#line 2492 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 97: /* Key: OBRACE ExprList CBRACE  */
#line 551 "src/xkbcomp/parser.y"
                        { FreeStmt((ParseCommon *) (yyvsp[-1].exprList).head); (yyval.geom) = NULL; }
#line 2498 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 98: /* OverlayDecl: OVERLAY String OBRACE OverlayKeyList CBRACE SEMI  */
#line 555 "src/xkbcomp/parser.y"
                        { (yyval.geom) = NULL; }
#line 2504 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 99: /* OverlayKeyList: OverlayKeyList COMMA OverlayKey  */
#line 558 "src/xkbcomp/parser.y"
                                                        { (yyval.geom) = NULL; }
#line 2510 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 100: /* OverlayKeyList: OverlayKey  */
#line 559 "src/xkbcomp/parser.y"
                                                        { (yyval.geom) = NULL; }
#line 2516 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 101: /* OverlayKey: KEYNAME EQUALS KEYNAME  */
#line 562 "src/xkbcomp/parser.y"
                                                        { (yyval.geom) = NULL; }
#line 2522 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 102: /* OutlineList: OutlineList COMMA OutlineInList  */
#line 566 "src/xkbcomp/parser.y"
                        { (yyval.geom) = NULL;}
#line 2528 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 103: /* OutlineList: OutlineInList  */
#line 568 "src/xkbcomp/parser.y"
                        { (yyval.geom) = NULL; }
#line 2534 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 104: /* OutlineInList: OBRACE CoordList CBRACE  */
#line 572 "src/xkbcomp/parser.y"
                        { (void) (yyvsp[-1].expr); (yyval.geom) = NULL; }
#line 2540 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 105: /* OutlineInList: Ident EQUALS OBRACE CoordList CBRACE  */
#line 574 "src/xkbcomp/parser.y"
                        { (void) (yyvsp[-1].expr); (yyval.geom) = NULL; }
#line 2546 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 106: /* OutlineInList: Ident EQUALS Expr  */
#line 576 "src/xkbcomp/parser.y"
                        { FreeStmt((ParseCommon *) (yyvsp[0].expr)); (yyval.geom) = NULL; }
#line 2552 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 107: /* CoordList: CoordList COMMA Coord  */
#line 580 "src/xkbcomp/parser.y"
                        { (void) (yyvsp[-2].expr); (void) (yyvsp[0].expr); (yyval.expr) = NULL; }
#line 2558 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 108: /* CoordList: Coord  */
#line 582 "src/xkbcomp/parser.y"
                        { (void) (yyvsp[0].expr); (yyval.expr) = NULL; }
#line 2564 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 109: /* Coord: OBRACKET SignedNumber COMMA SignedNumber CBRACKET  */
#line 586 "src/xkbcomp/parser.y"
                        { (yyval.expr) = NULL; }
#line 2570 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 110: /* DoodadDecl: DoodadType String OBRACE VarDeclList CBRACE SEMI  */
#line 590 "src/xkbcomp/parser.y"
                        { FreeStmt((ParseCommon *) (yyvsp[-2].varList).head); (yyval.geom) = NULL; }
#line 2576 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 111: /* DoodadType: TEXT  */
#line 593 "src/xkbcomp/parser.y"
                                { (yyval.num) = 0; }
#line 2582 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 112: /* DoodadType: OUTLINE  */
#line 594 "src/xkbcomp/parser.y"
                                { (yyval.num) = 0; }
#line 2588 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 113: /* DoodadType: SOLID  */
#line 595 "src/xkbcomp/parser.y"
                                { (yyval.num) = 0; }
#line 2594 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 114: /* DoodadType: LOGO  */
#line 596 "src/xkbcomp/parser.y"
                                { (yyval.num) = 0; }
#line 2600 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 115: /* FieldSpec: Ident  */
#line 599 "src/xkbcomp/parser.y"
                                { (yyval.atom) = (yyvsp[0].atom); }
#line 2606 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 116: /* FieldSpec: Element  */
#line 600 "src/xkbcomp/parser.y"
                                { (yyval.atom) = (yyvsp[0].atom); }
#line 2612 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 117: /* Element: ACTION_TOK  */
#line 604 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "action"); }
#line 2618 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 118: /* Element: INTERPRET  */
#line 606 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "interpret"); }
#line 2624 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 119: /* Element: TYPE  */
#line 608 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "type"); }
#line 2630 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 120: /* Element: KEY  */
#line 610 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "key"); }
#line 2636 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 121: /* Element: GROUP  */
#line 612 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "group"); }
#line 2642 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 122: /* Element: MODIFIER_MAP  */
#line 614 "src/xkbcomp/parser.y"
                        {(yyval.atom) = xkb_atom_intern_literal(param->ctx, "modifier_map");}
#line 2648 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 123: /* Element: INDICATOR  */
#line 616 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "indicator"); }
#line 2654 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 124: /* Element: SHAPE  */
#line 618 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "shape"); }
#line 2660 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 125: /* Element: ROW  */
#line 620 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "row"); }
#line 2666 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 126: /* Element: SECTION  */
#line 622 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "section"); }
#line 2672 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 127: /* Element: TEXT  */
#line 624 "src/xkbcomp/parser.y"
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "text"); }
#line 2678 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 128: /* OptMergeMode: MergeMode  */
#line 627 "src/xkbcomp/parser.y"
                                        { (yyval.merge) = (yyvsp[0].merge); }
#line 2684 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 129: /* OptMergeMode: %empty  */
#line 628 "src/xkbcomp/parser.y"
                                        { (yyval.merge) = MERGE_DEFAULT; }
#line 2690 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 130: /* MergeMode: INCLUDE  */
#line 631 "src/xkbcomp/parser.y"
                                        { (yyval.merge) = MERGE_DEFAULT; }
#line 2696 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 131: /* MergeMode: AUGMENT  */
#line 632 "src/xkbcomp/parser.y"
                                        { (yyval.merge) = MERGE_AUGMENT; }
#line 2702 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 132: /* MergeMode: OVERRIDE  */
#line 633 "src/xkbcomp/parser.y"
                                        { (yyval.merge) = MERGE_OVERRIDE; }
#line 2708 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 133: /* MergeMode: REPLACE  */
#line 634 "src/xkbcomp/parser.y"
                                        { (yyval.merge) = MERGE_REPLACE; }
#line 2714 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 134: /* MergeMode: ALTERNATE  */
#line 636 "src/xkbcomp/parser.y"
                {
                    /*
                     * This used to be MERGE_ALT_FORM. This functionality was
                     * unused and has been removed.
                     */
                    (yyval.merge) = MERGE_DEFAULT;
                }
#line 2726 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 135: /* OptExprList: ExprList  */
#line 645 "src/xkbcomp/parser.y"
                                        { (yyval.exprList) = (yyvsp[0].exprList); }
#line 2732 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 136: /* OptExprList: %empty  */
#line 646 "src/xkbcomp/parser.y"
                                        { (yyval.exprList).head = (yyval.exprList).last = NULL; }
#line 2738 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 137: /* ExprList: ExprList COMMA Expr  */
#line 650 "src/xkbcomp/parser.y"
                        { (yyval.exprList).head = (yyvsp[-2].exprList).head; (yyval.exprList).last->common.next = &(yyvsp[0].expr)->common; (yyval.exprList).last = (yyvsp[0].expr); }
#line 2744 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 138: /* ExprList: Expr  */
#line 652 "src/xkbcomp/parser.y"
                        { (yyval.exprList).head = (yyval.exprList).last = (yyvsp[0].expr); }
#line 2750 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 139: /* Expr: Expr DIVIDE Expr  */
#line 656 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateBinary(EXPR_DIVIDE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2756 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 140: /* Expr: Expr PLUS Expr  */
#line 658 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateBinary(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2762 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 141: /* Expr: Expr MINUS Expr  */
#line 660 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateBinary(EXPR_SUBTRACT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2768 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 142: /* Expr: Expr TIMES Expr  */
#line 662 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateBinary(EXPR_MULTIPLY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2774 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 143: /* Expr: Lhs EQUALS Expr  */
#line 664 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateBinary(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2780 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 144: /* Expr: Term  */
#line 666 "src/xkbcomp/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2786 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 145: /* Term: MINUS Term  */
#line 670 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateUnary(EXPR_NEGATE, (yyvsp[0].expr)->expr.value_type, (yyvsp[0].expr)); }
#line 2792 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 146: /* Term: PLUS Term  */
#line 672 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateUnary(EXPR_UNARY_PLUS, (yyvsp[0].expr)->expr.value_type, (yyvsp[0].expr)); }
#line 2798 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 147: /* Term: EXCLAM Term  */
#line 674 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateUnary(EXPR_NOT, EXPR_TYPE_BOOLEAN, (yyvsp[0].expr)); }
#line 2804 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 148: /* Term: INVERT Term  */
#line 676 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateUnary(EXPR_INVERT, (yyvsp[0].expr)->expr.value_type, (yyvsp[0].expr)); }
#line 2810 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 149: /* Term: Lhs  */
#line 678 "src/xkbcomp/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr);  }
#line 2816 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 150: /* Term: FieldSpec OPAREN OptExprList CPAREN  */
#line 680 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateAction((yyvsp[-3].atom), (yyvsp[-1].exprList).head); }
#line 2822 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 151: /* Term: Terminal  */
#line 682 "src/xkbcomp/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr);  }
#line 2828 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 152: /* Term: OPAREN Expr CPAREN  */
#line 684 "src/xkbcomp/parser.y"
                        { (yyval.expr) = (yyvsp[-1].expr);  }
#line 2834 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 153: /* MultiActionList: MultiActionList COMMA Action  */
#line 688 "src/xkbcomp/parser.y"
                        {
                            ExprDef *expr = ExprCreateActionList((yyvsp[0].expr));
                            (yyval.exprList) = (yyvsp[-2].exprList);
                            (yyval.exprList).last->common.next = &expr->common; (yyval.exprList).last = expr;
                        }
#line 2844 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 154: /* MultiActionList: MultiActionList COMMA Actions  */
#line 694 "src/xkbcomp/parser.y"
                        { (yyval.exprList) = (yyvsp[-2].exprList); (yyval.exprList).last->common.next = &(yyvsp[0].expr)->common; (yyval.exprList).last = (yyvsp[0].expr); }
#line 2850 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 155: /* MultiActionList: Action  */
#line 696 "src/xkbcomp/parser.y"
                        { (yyval.exprList).head = (yyval.exprList).last = ExprCreateActionList((yyvsp[0].expr)); }
#line 2856 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 156: /* MultiActionList: Actions  */
#line 698 "src/xkbcomp/parser.y"
                        { (yyval.exprList).head = (yyval.exprList).last = (yyvsp[0].expr); }
#line 2862 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 157: /* ActionList: ActionList COMMA Action  */
#line 702 "src/xkbcomp/parser.y"
                        { (yyval.exprList) = (yyvsp[-2].exprList); (yyval.exprList).last->common.next = &(yyvsp[0].expr)->common; (yyval.exprList).last = (yyvsp[0].expr); }
#line 2868 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 158: /* ActionList: Action COMMA Action  */
#line 704 "src/xkbcomp/parser.y"
                        { (yyval.exprList).head = (yyvsp[-2].expr); (yyval.exprList).head->common.next = &(yyvsp[0].expr)->common; (yyval.exprList).last = (yyvsp[0].expr); }
#line 2874 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 159: /* Actions: OBRACE ActionList CBRACE  */
#line 708 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateActionList((yyvsp[-1].exprList).head); }
#line 2880 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 160: /* Action: FieldSpec OPAREN OptExprList CPAREN  */
#line 712 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateAction((yyvsp[-3].atom), (yyvsp[-1].exprList).head); }
#line 2886 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 161: /* Lhs: FieldSpec  */
#line 716 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateIdent((yyvsp[0].atom)); }
#line 2892 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 162: /* Lhs: FieldSpec DOT FieldSpec  */
#line 718 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateFieldRef((yyvsp[-2].atom), (yyvsp[0].atom)); }
#line 2898 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 163: /* Lhs: FieldSpec OBRACKET Expr CBRACKET  */
#line 720 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateArrayRef(XKB_ATOM_NONE, (yyvsp[-3].atom), (yyvsp[-1].expr)); }
#line 2904 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 164: /* Lhs: FieldSpec DOT FieldSpec OBRACKET Expr CBRACKET  */
#line 722 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateArrayRef((yyvsp[-5].atom), (yyvsp[-3].atom), (yyvsp[-1].expr)); }
#line 2910 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 165: /* Terminal: String  */
#line 726 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateString((yyvsp[0].atom)); }
#line 2916 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 166: /* Terminal: Integer  */
#line 728 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateInteger((yyvsp[0].num)); }
#line 2922 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 167: /* Terminal: Float  */
#line 730 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateFloat(/* Discard $1 */); }
#line 2928 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 168: /* Terminal: KEYNAME  */
#line 732 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprCreateKeyName((yyvsp[0].atom)); }
#line 2934 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 169: /* MultiKeySymList: MultiKeySymList COMMA KeySym  */
#line 736 "src/xkbcomp/parser.y"
                        {
                            ExprDef *expr = ExprCreateKeysymList((yyvsp[0].keysym));
                            (yyval.exprList) = (yyvsp[-2].exprList);
                            (yyval.exprList).last->common.next = &expr->common; (yyval.exprList).last = expr;
                        }
#line 2944 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 170: /* MultiKeySymList: MultiKeySymList COMMA KeySyms  */
#line 742 "src/xkbcomp/parser.y"
                        { (yyval.exprList) = (yyvsp[-2].exprList); (yyval.exprList).last->common.next = &(yyvsp[0].expr)->common; (yyval.exprList).last = (yyvsp[0].expr); }
#line 2950 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 171: /* MultiKeySymList: KeySym  */
#line 744 "src/xkbcomp/parser.y"
                        { (yyval.exprList).head = (yyval.exprList).last = ExprCreateKeysymList((yyvsp[0].keysym)); }
#line 2956 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 172: /* MultiKeySymList: KeySyms  */
#line 746 "src/xkbcomp/parser.y"
                        { (yyval.exprList).head = (yyval.exprList).last = (yyvsp[0].expr); }
#line 2962 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 173: /* KeySymList: KeySymList COMMA KeySym  */
#line 750 "src/xkbcomp/parser.y"
                        { (yyval.expr) = ExprAppendKeysymList((yyvsp[-2].expr), (yyvsp[0].keysym)); }
#line 2968 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 174: /* KeySymList: KeySym COMMA KeySym  */
#line 752 "src/xkbcomp/parser.y"
                        {
                            (yyval.expr) = ExprCreateKeysymList((yyvsp[-2].keysym));
                            (yyval.expr) = ExprAppendKeysymList((yyval.expr), (yyvsp[0].keysym));
                        }
#line 2977 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 175: /* KeySyms: OBRACE KeySymList CBRACE  */
#line 759 "src/xkbcomp/parser.y"
                        { (yyval.expr) = (yyvsp[-1].expr); }
#line 2983 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 176: /* KeySym: IDENT  */
#line 763 "src/xkbcomp/parser.y"
                        {
                            if (!resolve_keysym(param, (yyvsp[0].str), &(yyval.keysym))) {
                                parser_warn(
                                    param,
                                    XKB_WARNING_UNRECOGNIZED_KEYSYM,
                                    "unrecognized keysym \"%s\"",
                                    (yyvsp[0].str)
                                );
                                (yyval.keysym) = XKB_KEY_NoSymbol;
                            }
                            free((yyvsp[0].str));
                        }
#line 3000 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 177: /* KeySym: SECTION  */
#line 776 "src/xkbcomp/parser.y"
                                { (yyval.keysym) = XKB_KEY_section; }
#line 3006 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 178: /* KeySym: Integer  */
#line 778 "src/xkbcomp/parser.y"
                        {
                            if ((yyvsp[0].num) < XKB_KEYSYM_MIN) {
                                parser_warn(
                                    param,
                                    XKB_WARNING_UNRECOGNIZED_KEYSYM,
                                    "unrecognized keysym \"%"PRId64"\"",
                                    (yyvsp[0].num)
                                );
                                (yyval.keysym) = XKB_KEY_NoSymbol;
                            }
                            /* Special case for digits 0..9 */
                            else if ((yyvsp[0].num) < 10) {     /* XKB_KEY_0 .. XKB_KEY_9 */
                                (yyval.keysym) = XKB_KEY_0 + (xkb_keysym_t) (yyvsp[0].num);
                            }
                            else {
                                if ((yyvsp[0].num) <= XKB_KEYSYM_MAX) {
                                    (yyval.keysym) = (xkb_keysym_t) (yyvsp[0].num);
                                    check_deprecated_keysyms(
                                        parser_warn, param, param->ctx,
                                        (yyval.keysym), NULL, (yyval.keysym), "0x%"PRIx32, "");
                                } else {
                                    parser_warn(
                                        param, XKB_WARNING_UNRECOGNIZED_KEYSYM,
                                        "unrecognized keysym \"0x%"PRIx64"\" "
                                        "(%"PRId64")", (yyvsp[0].num), (yyvsp[0].num)
                                    );
                                    (yyval.keysym) = XKB_KEY_NoSymbol;
                                }
                                parser_warn(
                                    param, XKB_WARNING_NUMERIC_KEYSYM,
                                    "numeric keysym \"0x%"PRIx64"\" (%"PRId64")",
                                    (yyvsp[0].num), (yyvsp[0].num)
                                );
                            }
                        }
#line 3046 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 179: /* SignedNumber: MINUS Number  */
#line 815 "src/xkbcomp/parser.y"
                                        { (yyval.num) = -(yyvsp[0].num); }
#line 3052 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 180: /* SignedNumber: Number  */
#line 816 "src/xkbcomp/parser.y"
                                        { (yyval.num) = (yyvsp[0].num); }
#line 3058 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 181: /* Number: FLOAT  */
#line 819 "src/xkbcomp/parser.y"
                                { (yyval.num) = (yyvsp[0].num); }
#line 3064 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 182: /* Number: INTEGER  */
#line 820 "src/xkbcomp/parser.y"
                                { (yyval.num) = (yyvsp[0].num); }
#line 3070 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 183: /* Float: FLOAT  */
#line 823 "src/xkbcomp/parser.y"
                                { (yyval.num) = 0; }
#line 3076 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 184: /* Integer: INTEGER  */
#line 826 "src/xkbcomp/parser.y"
                                { (yyval.num) = (yyvsp[0].num); }
#line 3082 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 185: /* KeyCode: INTEGER  */
#line 829 "src/xkbcomp/parser.y"
                                { (yyval.num) = (yyvsp[0].num); }
#line 3088 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 186: /* Ident: IDENT  */
#line 832 "src/xkbcomp/parser.y"
                                { (yyval.atom) = xkb_atom_intern(param->ctx, (yyvsp[0].str), strlen((yyvsp[0].str))); free((yyvsp[0].str)); }
#line 3094 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 187: /* Ident: DEFAULT  */
#line 833 "src/xkbcomp/parser.y"
                                { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "default"); }
#line 3100 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 188: /* String: STRING  */
#line 836 "src/xkbcomp/parser.y"
                                { (yyval.atom) = xkb_atom_intern(param->ctx, (yyvsp[0].str), strlen((yyvsp[0].str))); free((yyvsp[0].str)); }
#line 3106 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 189: /* OptMapName: MapName  */
#line 839 "src/xkbcomp/parser.y"
                                { (yyval.str) = (yyvsp[0].str); }
#line 3112 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 190: /* OptMapName: %empty  */
#line 840 "src/xkbcomp/parser.y"
                                { (yyval.str) = NULL; }
#line 3118 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;

  case 191: /* MapName: STRING  */
#line 843 "src/xkbcomp/parser.y"
                                { (yyval.str) = (yyvsp[0].str); }
#line 3124 "config/libxkbcommon.so.0.0.0.p/parser.c"
    break;


#line 3128 "config/libxkbcommon.so.0.0.0.p/parser.c"

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
      yyerror (param, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= END_OF_FILE)
        {
          /* Return failure if at end of input.  */
          if (yychar == END_OF_FILE)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, param);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, param);
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
  yyerror (param, YY_("memory exhausted"));
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
                  yytoken, &yylval, param);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, param);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 846 "src/xkbcomp/parser.y"


XkbFile *
parse(struct xkb_context *ctx, struct scanner *scanner, const char *map)
{
    int ret;
    XkbFile *first = NULL;
    struct parser_param param = {
        .scanner = scanner,
        .ctx = ctx,
        .rtrn = NULL,
        .more_maps = false,
    };

    /*
     * If we got a specific map, we look for it exclusively and return
     * immediately upon finding it. Otherwise, we need to get the
     * default map. If we find a map marked as default, we return it
     * immediately. If there are no maps marked as default, we return
     * the first map in the file.
     */

    while ((ret = yyparse(&param)) == 0 && param.more_maps) {
        if (map) {
            if (streq_not_null(map, param.rtrn->name))
                return param.rtrn;
            else
                FreeXkbFile(param.rtrn);
        }
        else {
            if (param.rtrn->flags & MAP_IS_DEFAULT) {
                FreeXkbFile(first);
                return param.rtrn;
            }
            else if (!first) {
                first = param.rtrn;
            }
            else {
                FreeXkbFile(param.rtrn);
            }
        }
        param.rtrn = NULL;
    }

    if (ret != 0) {
        /* Some error happend; clear the Xkbfiles parsed so far */
        FreeXkbFile(first);
        FreeXkbFile(param.rtrn);
        return NULL;
    }

    if (first)
        log_vrb(ctx, 5,
                XKB_WARNING_MISSING_DEFAULT_SECTION,
                "No map in include statement, but \"%s\" contains several; "
                "Using first defined map, \"%s\"\n",
                scanner->file_name, first->name);

    return first;
}
