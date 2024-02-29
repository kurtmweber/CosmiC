/*****************************************************************
 * This file is part of CosmiC                                   *
 * Copyright (C) 2024 Kurt M. Weber                              *
 * Released under the stated terms in the file LICENSE           *
 * See the file "LICENSE" in the source distribution for details *
 *****************************************************************/

#ifndef _TOKENIZE_H
#define _TOKENIZE_H

#include <stdio.h>

#include <tokens.h>

token_t *tokenize(unsigned char ch, FILE *input);

#endif