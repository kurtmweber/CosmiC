/*****************************************************************
 * This file is part of CosmiC                                   *
 * Copyright (C) 2024 Kurt M. Weber                              *
 * Released under the stated terms in the file LICENSE           *
 * See the file "LICENSE" in the source distribution for details *
 *****************************************************************/

#define LEXER

#include <stdio.h>
#include <stdlib.h>

#include <cosmic-error.h>
#include <tokens.h>

#include "scan.h"

token_t numeric_token(unsigned char ch, FILE *input);
unsigned int find_digit(unsigned char ch);

token_t *tokenize(unsigned char ch, FILE *input) {
  token_t *curtok;

  curtok = calloc(1, sizeof(token_t));

  switch (ch) {
  case '+':
    curtok->type = TOKEN_PLUS;
    break;
  case '-':
    curtok->type = TOKEN_MINUS;
    break;
  case '/':
    curtok->type = TOKEN_SLASH;
    break;
  case '*':
    curtok->type = TOKEN_ASTERISK;
    break;
  // fallthrough is intended behavior here
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    *curtok = numeric_token(ch, input);
    break;
  default:
    LEXER_ERROR("invalid token", 0, "");
    break;
  }

  return 0;
}

token_t numeric_token(unsigned char ch, FILE *input) {
  token_t tmp;
  unsigned char cur = ch;
  unsigned int digit = 0;
  unsigned int val = 0;

  while ((digit = find_digit(cur)) <= 9) {
    val = (val * 10) + digit;
    cur = (unsigned char)next_char(input);
  }

  if (ungetc(cur, input) == EOF) {
    cosmic_errno = COSMIC_ERROR_STREAM;
    cosmic_perror("Could not ungetc, " __FILE__ " at line " COSMIC_LINENO);
    exit(EXIT_FAILURE);
  }

  tmp.type = TOKEN_INTEGER_LITERAL;
  tmp.intval = val;

  return tmp;
}

unsigned int find_digit(unsigned char ch) {
  const unsigned char *refstr = "0123456789";
  unsigned int i = 0;

  while (refstr[i] && (ch != refstr[i])) {
    i++;
  }

  return i;
}