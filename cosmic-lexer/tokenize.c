/*****************************************************************
 * This file is part of CosmiC                                   *
 * Copyright (C) 2024 Kurt M. Weber                              *
 * Released under the stated terms in the file LICENSE           *
 * See the file "LICENSE" in the source distribution for details *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>

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
    break;
  }

  return 0;
}

token_t numeric_token(unsigned char ch, FILE *input) {
  token_t tmp;
  unsigned int digit;

  while ((digit = find_digit(ch)) <= 9) {
    printf("%d\n", digit);
    ch = (unsigned char)next_char(input);
  }

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