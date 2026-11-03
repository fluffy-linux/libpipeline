/*
 * SPDX-FileCopyrightText: 1994 Markus Armbruster
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/* Append to a dynamically allocated string. */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif /* HAVE_CONFIG_H */

#include <stdarg.h>
#include <string.h>

#include "xalloc.h"

#include "pipeline-private.h"

/* append strings to first argument, which is realloced to the correct size
   first arg may be NULL */
char *appendstr (char *str, ...)
{
	va_list ap;
	int len, newlen;
	char *next, *end;

	len = str ? strlen (str) : 0;

	va_start (ap, str);
	newlen = len + 1;
	while ((next = va_arg (ap, char *)))
		newlen += strlen (next);
	va_end (ap);

	str = xrealloc (str, newlen);
	end = str + len;

	va_start (ap, str);
	while ((next = va_arg (ap, char *))) {
		strcpy (end, next);
		end += strlen (next);
	}
	va_end (ap);

	return str;
}
