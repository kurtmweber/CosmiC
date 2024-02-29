/*****************************************************************
 * This file is part of CosmiC                                   *
 * Copyright (C) 2024 Kurt M. Weber                              *
 * Released under the stated terms in the file LICENSE           *
 * See the file "LICENSE" in the source distribution for details *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "scan.h"
#include "tokenize.h"

unsigned char discard_whitespace(unsigned char ch);
int next_char(FILE *input);

void scan(FILE *input) {
  int ch;

  while ((ch = next_char(input)) !=
         EOF) { // ch has to be an int up to this point so we can properly check
                // for EOF, which is (or at least can be) defined as -1
                // this is why fgetc() returns an int, rather than an unsigned
                // char (and it can't be a signed char either because the range
                // isn't enough)
    if (discard_whitespace((unsigned char)ch)) {
      tokenize((unsigned char)ch, input);
    }
  }

  return;
}

int next_char(FILE *input) {
  // Purpose:
  //    Pull the next character from the input file stream,
  // Arguments:
  //    FILE *input - input file stream
  // Return:
  //    The next character in the input file stream
  int ch;

  ch = fgetc(input);

  return ch;
}

unsigned char discard_whitespace(unsigned char ch) {
  // Purpose:
  //  Discard whitespace characters in input stream
  // Arguments:
  //  unsigned char ch - character to examine and possibly discard
  // Return:
  //  NULL if ch is a whitespace character; otherwise return ch unchanged

  if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f') {
    return (unsigned char)0;
  } else {
    return ch;
  }
}