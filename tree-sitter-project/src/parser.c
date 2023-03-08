#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 16
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 15
#define ALIAS_COUNT 0
#define TOKEN_COUNT 8
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_COLON = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  anon_sym_LBRACK = 4,
  anon_sym_RBRACK = 5,
  sym_integer = 6,
  sym_name = 7,
  sym_source_file = 8,
  sym__expression = 9,
  sym__indexBaseExpression = 10,
  sym_fieldCall = 11,
  sym_fieldExpression = 12,
  sym_fieldName = 13,
  sym_index = 14,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLON] = ":",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_integer] = "integer",
  [sym_name] = "name",
  [sym_source_file] = "source_file",
  [sym__expression] = "_expression",
  [sym__indexBaseExpression] = "_indexBaseExpression",
  [sym_fieldCall] = "fieldCall",
  [sym_fieldExpression] = "fieldExpression",
  [sym_fieldName] = "fieldName",
  [sym_index] = "index",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_integer] = sym_integer,
  [sym_name] = sym_name,
  [sym_source_file] = sym_source_file,
  [sym__expression] = sym__expression,
  [sym__indexBaseExpression] = sym__indexBaseExpression,
  [sym_fieldCall] = sym_fieldCall,
  [sym_fieldExpression] = sym_fieldExpression,
  [sym_fieldName] = sym_fieldName,
  [sym_index] = sym_index,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
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
      if (eof) ADVANCE(1);
      if (lookahead == '(') ADVANCE(3);
      if (lookahead == ')') ADVANCE(4);
      if (lookahead == ':') ADVANCE(2);
      if (lookahead == '[') ADVANCE(5);
      if (lookahead == ']') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(7);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
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
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_name] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(13),
    [sym__expression] = STATE(9),
    [sym__indexBaseExpression] = STATE(14),
    [sym_fieldCall] = STATE(4),
    [sym_fieldExpression] = STATE(9),
    [sym_fieldName] = STATE(4),
    [sym_index] = STATE(4),
    [anon_sym_COLON] = ACTIONS(3),
    [sym_integer] = ACTIONS(5),
    [sym_name] = ACTIONS(5),
  },
  [2] = {
    [sym__expression] = STATE(10),
    [sym__indexBaseExpression] = STATE(14),
    [sym_fieldCall] = STATE(4),
    [sym_fieldExpression] = STATE(10),
    [sym_fieldName] = STATE(4),
    [sym_index] = STATE(4),
    [anon_sym_COLON] = ACTIONS(3),
    [sym_integer] = ACTIONS(5),
    [sym_name] = ACTIONS(5),
  },
  [3] = {
    [sym__expression] = STATE(11),
    [sym__indexBaseExpression] = STATE(14),
    [sym_fieldCall] = STATE(4),
    [sym_fieldExpression] = STATE(11),
    [sym_fieldName] = STATE(4),
    [sym_index] = STATE(4),
    [anon_sym_COLON] = ACTIONS(3),
    [sym_integer] = ACTIONS(5),
    [sym_name] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(9), 1,
      anon_sym_LBRACK,
    ACTIONS(7), 4,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [10] = 1,
    ACTIONS(11), 5,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [18] = 2,
    ACTIONS(15), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 4,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [28] = 1,
    ACTIONS(17), 5,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [36] = 1,
    ACTIONS(19), 5,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [44] = 2,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      anon_sym_COLON,
  [51] = 2,
    ACTIONS(23), 1,
      anon_sym_COLON,
    ACTIONS(25), 1,
      anon_sym_RBRACK,
  [58] = 2,
    ACTIONS(23), 1,
      anon_sym_COLON,
    ACTIONS(27), 1,
      anon_sym_RPAREN,
  [65] = 1,
    ACTIONS(29), 1,
      sym_name,
  [69] = 1,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
  [73] = 1,
    ACTIONS(33), 1,
      anon_sym_LBRACK,
  [77] = 1,
    ACTIONS(35), 1,
      sym_name,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 10,
  [SMALL_STATE(6)] = 18,
  [SMALL_STATE(7)] = 28,
  [SMALL_STATE(8)] = 36,
  [SMALL_STATE(9)] = 44,
  [SMALL_STATE(10)] = 51,
  [SMALL_STATE(11)] = 58,
  [SMALL_STATE(12)] = 65,
  [SMALL_STATE(13)] = 69,
  [SMALL_STATE(14)] = 73,
  [SMALL_STATE(15)] = 77,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__indexBaseExpression, 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fieldName, 2),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fieldExpression, 3),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index, 4),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fieldCall, 6),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [31] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
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
