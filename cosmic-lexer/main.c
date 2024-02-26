/*****************************************************************
 * This file is part of CosmiC                                   *
 * Copyright (C) 2024 Kurt M. Weber                              *
 * Released under the stated terms in the file LICENSE           *
 * See the file "LICENSE" in the source distribution for details *
 *****************************************************************/

#include <stdio.h>
#include <errno.h>

#include <cosmic-error.h>

FILE *open_input_file(const char *name);

int main(int argc, char *argv[]) {
  FILE *input;

  // If there are no arguments, input is provided via stdin; otherwise, the
  // argument is a filename and we need to open it
  if (argc == 2) {
    input = open_input_file(argv[1]);
    if (input == NULL) {
      perror("Lexer error");
    }
  } else {
    input = stdin;
  }

  return 0;
}

FILE *open_input_file(const char *name) {
  // Purpose:
  //    If we are reading from a named file specified on the command line, open
  //    it for reading or return an error condition if that is not possible
  // Arguments:
  //    const char *name - name of the input file to open
  // Return:
  //    If opening input file is successful, a stdio FILE * referring to the
  //    opened file stream; otherwise return NULL and set global cosmic_errno to
  //    an appropriate value

  FILE *fp;

  fp = fopen(name, "r");

  if (fp == NULL) {
  }

  return fp; // will have been set to NULL by fopen if error
}