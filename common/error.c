/*****************************************************************
 * This file is part of CosmiC                                   *
 * Copyright (C) 2024 Kurt M. Weber                              *
 * Released under the stated terms in the file LICENSE           *
 * See the file "LICENSE" in the source distribution for details *
 *****************************************************************/

#include <stdio.h>

#include <cosmic-error.h>
#include "errortext.h"

void cosmic_perror(const char *str) {
  // Purpose:
  //    Display an error message corresponding to the current value of the
  //    cosmic_errno global variable, with the same formatting used by the
  //    perror() standard library function: a user-supplied message, a colon, a
  //    space, the error message, then a newline
  // Arguments:
  //    const char *str - user-supplied message to prepend the error message
  //    with
  // Return:
  //   void

  fprintf(stderr, str);
  fprintf(stderr, ": ");
  fprintf(stderr, cosmic_errmsg[cosmic_errno]);
  fprintf(stderr, "\n");

  return;
}