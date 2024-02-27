/*****************************************************************
 * This file is part of CosmiC                                   *
 * Copyright (C) 2024 Kurt M. Weber                              *
 * Released under the stated terms in the file LICENSE           *
 * See the file "LICENSE" in the source distribution for details *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "scan.h"

int nextchar(FILE *input);

void scan(FILE *input) {
  int ch;

  while ((ch = nextchar(input)) != EOF) {
    fputc(ch, stdout);
  }

  return;
}

int nextchar(FILE *input) {
  int ch;

  do {
    ch = fgetc(input);
  } while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f');

  return ch;
}