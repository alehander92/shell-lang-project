#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 44
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 22
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_ = 1,
  anon_sym_COLON = 2,
  anon_sym_LPAREN = 3,
  anon_sym_RPAREN = 4,
  anon_sym_LBRACK = 5,
  anon_sym_RBRACK = 6,
  anon_sym_SLASH = 7,
  sym_integer = 8,
  sym_name = 9,
  sym_source_file = 10,
  sym__expression = 11,
  sym__indexBaseExpression = 12,
  sym_call = 13,
  sym_fieldCall = 14,
  sym_fieldExpression = 15,
  sym_fieldName = 16,
  sym_index = 17,
  sym__path = 18,
  sym_absolutePath = 19,
  sym_relativePath = 20,
  aux_sym_absolutePath_repeat1 = 21,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_] = " ",
  [anon_sym_COLON] = ":",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_SLASH] = "/",
  [sym_integer] = "integer",
  [sym_name] = "name",
  [sym_source_file] = "source_file",
  [sym__expression] = "_expression",
  [sym__indexBaseExpression] = "_indexBaseExpression",
  [sym_call] = "call",
  [sym_fieldCall] = "fieldCall",
  [sym_fieldExpression] = "fieldExpression",
  [sym_fieldName] = "fieldName",
  [sym_index] = "index",
  [sym__path] = "_path",
  [sym_absolutePath] = "absolutePath",
  [sym_relativePath] = "relativePath",
  [aux_sym_absolutePath_repeat1] = "absolutePath_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_] = anon_sym_,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [sym_integer] = sym_integer,
  [sym_name] = sym_name,
  [sym_source_file] = sym_source_file,
  [sym__expression] = sym__expression,
  [sym__indexBaseExpression] = sym__indexBaseExpression,
  [sym_call] = sym_call,
  [sym_fieldCall] = sym_fieldCall,
  [sym_fieldExpression] = sym_fieldExpression,
  [sym_fieldName] = sym_fieldName,
  [sym_index] = sym_index,
  [sym__path] = sym__path,
  [sym_absolutePath] = sym_absolutePath,
  [sym_relativePath] = sym_relativePath,
  [aux_sym_absolutePath_repeat1] = aux_sym_absolutePath_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym__indexBaseExpression] = {
    .visible = false,
    .named = true,
  },
  [sym_call] = {
    .visible = true,
    .named = true,
  },
  [sym_fieldCall] = {
    .visible = true,
    .named = true,
  },
  [sym_fieldExpression] = {
    .visible = true,
    .named = true,
  },
  [sym_fieldName] = {
    .visible = true,
    .named = true,
  },
  [sym_index] = {
    .visible = true,
    .named = true,
  },
  [sym__path] = {
    .visible = false,
    .named = true,
  },
  [sym_absolutePath] = {
    .visible = true,
    .named = true,
  },
  [sym_relativePath] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_absolutePath_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(2);
      if (lookahead == '(') ADVANCE(5);
      if (lookahead == ')') ADVANCE(6);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ':') ADVANCE(4);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == ']') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      if (lookahead == '.' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(11);
      END_STATE();
    case 1:
      if (eof) ADVANCE(2);
      if (lookahead == ' ') ADVANCE(3);
      if (lookahead == ')') ADVANCE(6);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ':') ADVANCE(4);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == ']') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      END_STATE();
    case 2:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(11);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_name] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(39),
    [sym__expression] = STATE(34),
    [sym__indexBaseExpression] = STATE(35),
    [sym_call] = STATE(34),
    [sym_fieldCall] = STATE(23),
    [sym_fieldExpression] = STATE(34),
    [sym_fieldName] = STATE(23),
    [sym_index] = STATE(23),
    [sym__path] = STATE(34),
    [sym_absolutePath] = STATE(34),
    [sym_relativePath] = STATE(34),
    [aux_sym_absolutePath_repeat1] = STATE(13),
    [anon_sym_COLON] = ACTIONS(3),
    [anon_sym_SLASH] = ACTIONS(5),
    [sym_integer] = ACTIONS(7),
    [sym_name] = ACTIONS(9),
  },
  [2] = {
    [sym__expression] = STATE(33),
    [sym__indexBaseExpression] = STATE(43),
    [sym_call] = STATE(33),
    [sym_fieldCall] = STATE(21),
    [sym_fieldExpression] = STATE(33),
    [sym_fieldName] = STATE(21),
    [sym_index] = STATE(21),
    [sym__path] = STATE(33),
    [sym_absolutePath] = STATE(33),
    [sym_relativePath] = STATE(33),
    [aux_sym_absolutePath_repeat1] = STATE(12),
    [anon_sym_COLON] = ACTIONS(11),
    [anon_sym_SLASH] = ACTIONS(13),
    [sym_integer] = ACTIONS(15),
    [sym_name] = ACTIONS(17),
  },
  [3] = {
    [sym__expression] = STATE(29),
    [sym__indexBaseExpression] = STATE(43),
    [sym_call] = STATE(29),
    [sym_fieldCall] = STATE(21),
    [sym_fieldExpression] = STATE(29),
    [sym_fieldName] = STATE(21),
    [sym_index] = STATE(21),
    [sym__path] = STATE(29),
    [sym_absolutePath] = STATE(29),
    [sym_relativePath] = STATE(29),
    [aux_sym_absolutePath_repeat1] = STATE(12),
    [anon_sym_COLON] = ACTIONS(11),
    [anon_sym_SLASH] = ACTIONS(13),
    [sym_integer] = ACTIONS(15),
    [sym_name] = ACTIONS(17),
  },
  [4] = {
    [sym__expression] = STATE(30),
    [sym__indexBaseExpression] = STATE(43),
    [sym_call] = STATE(30),
    [sym_fieldCall] = STATE(21),
    [sym_fieldExpression] = STATE(30),
    [sym_fieldName] = STATE(21),
    [sym_index] = STATE(21),
    [sym__path] = STATE(30),
    [sym_absolutePath] = STATE(30),
    [sym_relativePath] = STATE(30),
    [aux_sym_absolutePath_repeat1] = STATE(12),
    [anon_sym_COLON] = ACTIONS(11),
    [anon_sym_SLASH] = ACTIONS(13),
    [sym_integer] = ACTIONS(15),
    [sym_name] = ACTIONS(17),
  },
  [5] = {
    [sym__expression] = STATE(31),
    [sym__indexBaseExpression] = STATE(43),
    [sym_call] = STATE(31),
    [sym_fieldCall] = STATE(21),
    [sym_fieldExpression] = STATE(31),
    [sym_fieldName] = STATE(21),
    [sym_index] = STATE(21),
    [sym__path] = STATE(31),
    [sym_absolutePath] = STATE(31),
    [sym_relativePath] = STATE(31),
    [aux_sym_absolutePath_repeat1] = STATE(12),
    [anon_sym_COLON] = ACTIONS(11),
    [anon_sym_SLASH] = ACTIONS(13),
    [sym_integer] = ACTIONS(15),
    [sym_name] = ACTIONS(17),
  },
  [6] = {
    [sym__expression] = STATE(27),
    [sym__indexBaseExpression] = STATE(43),
    [sym_call] = STATE(27),
    [sym_fieldCall] = STATE(21),
    [sym_fieldExpression] = STATE(27),
    [sym_fieldName] = STATE(21),
    [sym_index] = STATE(21),
    [sym__path] = STATE(27),
    [sym_absolutePath] = STATE(27),
    [sym_relativePath] = STATE(27),
    [aux_sym_absolutePath_repeat1] = STATE(12),
    [anon_sym_COLON] = ACTIONS(11),
    [anon_sym_SLASH] = ACTIONS(13),
    [sym_integer] = ACTIONS(15),
    [sym_name] = ACTIONS(17),
  },
  [7] = {
    [sym__expression] = STATE(32),
    [sym__indexBaseExpression] = STATE(35),
    [sym_call] = STATE(32),
    [sym_fieldCall] = STATE(23),
    [sym_fieldExpression] = STATE(32),
    [sym_fieldName] = STATE(23),
    [sym_index] = STATE(23),
    [sym__path] = STATE(32),
    [sym_absolutePath] = STATE(32),
    [sym_relativePath] = STATE(32),
    [aux_sym_absolutePath_repeat1] = STATE(13),
    [anon_sym_COLON] = ACTIONS(3),
    [anon_sym_SLASH] = ACTIONS(5),
    [sym_integer] = ACTIONS(7),
    [sym_name] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(19), 1,
      anon_sym_,
    ACTIONS(23), 1,
      anon_sym_LBRACK,
    ACTIONS(25), 1,
      anon_sym_SLASH,
    STATE(11), 1,
      aux_sym_absolutePath_repeat1,
    ACTIONS(21), 3,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [18] = 6,
    ACTIONS(21), 1,
      anon_sym_COLON,
    ACTIONS(23), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(29), 1,
      anon_sym_,
    ACTIONS(31), 1,
      anon_sym_SLASH,
    STATE(14), 1,
      aux_sym_absolutePath_repeat1,
  [37] = 3,
    ACTIONS(35), 1,
      anon_sym_SLASH,
    STATE(10), 1,
      aux_sym_absolutePath_repeat1,
    ACTIONS(33), 3,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [49] = 3,
    ACTIONS(13), 1,
      anon_sym_SLASH,
    STATE(10), 1,
      aux_sym_absolutePath_repeat1,
    ACTIONS(38), 3,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [61] = 3,
    ACTIONS(13), 1,
      anon_sym_SLASH,
    STATE(10), 1,
      aux_sym_absolutePath_repeat1,
    ACTIONS(40), 3,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [73] = 3,
    ACTIONS(5), 1,
      anon_sym_SLASH,
    STATE(17), 1,
      aux_sym_absolutePath_repeat1,
    ACTIONS(40), 2,
      ts_builtin_sym_end,
      anon_sym_COLON,
  [84] = 3,
    ACTIONS(5), 1,
      anon_sym_SLASH,
    STATE(17), 1,
      aux_sym_absolutePath_repeat1,
    ACTIONS(38), 2,
      ts_builtin_sym_end,
      anon_sym_COLON,
  [95] = 1,
    ACTIONS(42), 4,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [102] = 2,
    ACTIONS(46), 1,
      anon_sym_LPAREN,
    ACTIONS(44), 3,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [111] = 3,
    ACTIONS(48), 1,
      anon_sym_SLASH,
    STATE(17), 1,
      aux_sym_absolutePath_repeat1,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_COLON,
  [122] = 1,
    ACTIONS(33), 4,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_SLASH,
  [129] = 1,
    ACTIONS(51), 4,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [136] = 1,
    ACTIONS(53), 4,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [143] = 2,
    ACTIONS(55), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 3,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [152] = 1,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_SLASH,
  [158] = 2,
    ACTIONS(55), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 2,
      ts_builtin_sym_end,
      anon_sym_COLON,
  [166] = 1,
    ACTIONS(53), 3,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_LBRACK,
  [172] = 2,
    ACTIONS(57), 1,
      anon_sym_LPAREN,
    ACTIONS(44), 2,
      ts_builtin_sym_end,
      anon_sym_COLON,
  [180] = 1,
    ACTIONS(51), 3,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_LBRACK,
  [186] = 2,
    ACTIONS(59), 1,
      anon_sym_COLON,
    ACTIONS(61), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [194] = 1,
    ACTIONS(42), 3,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_LBRACK,
  [200] = 2,
    ACTIONS(59), 1,
      anon_sym_COLON,
    ACTIONS(63), 1,
      anon_sym_RBRACK,
  [207] = 2,
    ACTIONS(59), 1,
      anon_sym_COLON,
    ACTIONS(65), 1,
      anon_sym_RPAREN,
  [214] = 2,
    ACTIONS(59), 1,
      anon_sym_COLON,
    ACTIONS(67), 1,
      anon_sym_RBRACK,
  [221] = 2,
    ACTIONS(61), 1,
      ts_builtin_sym_end,
    ACTIONS(69), 1,
      anon_sym_COLON,
  [228] = 2,
    ACTIONS(59), 1,
      anon_sym_COLON,
    ACTIONS(71), 1,
      anon_sym_RPAREN,
  [235] = 2,
    ACTIONS(69), 1,
      anon_sym_COLON,
    ACTIONS(73), 1,
      ts_builtin_sym_end,
  [242] = 1,
    ACTIONS(75), 1,
      anon_sym_LBRACK,
  [246] = 1,
    ACTIONS(77), 1,
      sym_name,
  [250] = 1,
    ACTIONS(79), 1,
      sym_name,
  [254] = 1,
    ACTIONS(81), 1,
      sym_name,
  [258] = 1,
    ACTIONS(83), 1,
      ts_builtin_sym_end,
  [262] = 1,
    ACTIONS(85), 1,
      sym_name,
  [266] = 1,
    ACTIONS(87), 1,
      sym_name,
  [270] = 1,
    ACTIONS(89), 1,
      sym_name,
  [274] = 1,
    ACTIONS(91), 1,
      anon_sym_LBRACK,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 18,
  [SMALL_STATE(10)] = 37,
  [SMALL_STATE(11)] = 49,
  [SMALL_STATE(12)] = 61,
  [SMALL_STATE(13)] = 73,
  [SMALL_STATE(14)] = 84,
  [SMALL_STATE(15)] = 95,
  [SMALL_STATE(16)] = 102,
  [SMALL_STATE(17)] = 111,
  [SMALL_STATE(18)] = 122,
  [SMALL_STATE(19)] = 129,
  [SMALL_STATE(20)] = 136,
  [SMALL_STATE(21)] = 143,
  [SMALL_STATE(22)] = 152,
  [SMALL_STATE(23)] = 158,
  [SMALL_STATE(24)] = 166,
  [SMALL_STATE(25)] = 172,
  [SMALL_STATE(26)] = 180,
  [SMALL_STATE(27)] = 186,
  [SMALL_STATE(28)] = 194,
  [SMALL_STATE(29)] = 200,
  [SMALL_STATE(30)] = 207,
  [SMALL_STATE(31)] = 214,
  [SMALL_STATE(32)] = 221,
  [SMALL_STATE(33)] = 228,
  [SMALL_STATE(34)] = 235,
  [SMALL_STATE(35)] = 242,
  [SMALL_STATE(36)] = 246,
  [SMALL_STATE(37)] = 250,
  [SMALL_STATE(38)] = 254,
  [SMALL_STATE(39)] = 258,
  [SMALL_STATE(40)] = 262,
  [SMALL_STATE(41)] = 266,
  [SMALL_STATE(42)] = 270,
  [SMALL_STATE(43)] = 274,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__indexBaseExpression, 1),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_absolutePath_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_absolutePath_repeat1, 2), SHIFT_REPEAT(37),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relativePath, 2),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_absolutePath, 1),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fieldCall, 6),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fieldExpression, 3),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_absolutePath_repeat1, 2), SHIFT_REPEAT(42),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fieldName, 2),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index, 4),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__indexBaseExpression, 1),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 3),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [83] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_project(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
