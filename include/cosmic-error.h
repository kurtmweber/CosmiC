/*****************************************************************
 * This file is part of CosmiC                                   *
 * Copyright (C) 2024 Kurt M. Weber                              *
 * Released under the stated terms in the file LICENSE           *
 * See the file "LICENSE" in the source distribution for details *
 *****************************************************************/

// cosmic-error.h: for when you've made a HUGE mistake

#ifndef _COSMIC_ERROR_H
#define _COSMIC_ERROR_H

#define _COSMIC_INTERNAL_STRINGIFY(x) #x
#define COSMIC_STRINGIFY(x) _COSMIC_INTERNAL_STRINGIFY(x)
#define COSMIC_LINENO COSMIC_STRINGIFY(__LINE__)

typedef enum {
  COSMIC_ERROR_FILENAME,
  COSMIC_ERROR_STREAM,
  COSMIC_ERROR_END
} cosmic_error_t;

extern cosmic_error_t cosmic_errno;

void cosmic_perror(const char *str);

#endif