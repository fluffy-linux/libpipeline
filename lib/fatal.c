/*
 * SPDX-FileCopyrightText: 2022 Colin Watson
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/* Fatal error helper. */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif /* HAVE_CONFIG_H */

#include <stdarg.h>
#include <stdlib.h>

#include "verror.h"

#include "pipeline-private.h"

#include "fatal.h"

void fatal (int errnum, const char *format, ...)
{
	va_list ap;

	va_start (ap, format);
	verror (FATAL, errnum, format, ap);
	va_end (ap);

	/* Never reached, because verror exits if given a non-zero status,
	 * but the compiler may not be able to prove that.
	 */
	abort ();
}
