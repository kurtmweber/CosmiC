/*****************************************************************
 * This file is part of CosmiC                                   *
 * Copyright (C) 2024 Kurt M. Weber                              *
 * Released under the stated terms in the file LICENSE           *
 * See the file "LICENSE" in the source distribution for details *
 *****************************************************************/

#ifndef _TOKENS_H
#define _TOKENS_H

typedef enum token_type_t {
  TOKEN_PLUS,     // +
  TOKEN_MINUS,    // -
  TOKEN_ASTERISK, // *
  TOKEN_SLASH,    // /
  TOKEN_INTEGER_LITERAL
} token_type_t;

typedef enum lexer_error_t {
  LEXER_ERROR_INVALID, // Invalid or unrecognized token
} lexer_error_t;

typedef struct token_t {
  token_type_t type;
  union {
    int intval;
  };
} token_t;

typedef struct token_wrapper_t {
  enum { TOKEN_WRAPPER_TOKEN, TOKEN_WRAPPER_ERROR } wrapper_type;
  char *filename;
  unsigned long long line;
  unsigned long long col;
  union {
    token_t token;
    lexer_error_t error;
  };
} token_wrapper_t;

#endif