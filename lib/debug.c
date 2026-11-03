/*
 * SPDX-FileCopyrightText: 2007, 2010 Colin Watson
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/* Debugging messages. */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pipeline-private.h"

int debug_level = 0;

void init_debug (void)
{
	static int inited = 0;
	const char *pipeline_debug;

	if (inited)
		return;
	inited = 1;

	pipeline_debug = getenv ("PIPELINE_DEBUG");
	if (pipeline_debug && !strcmp (pipeline_debug, "1"))
		debug_level = 1;
}

static void PIPELINE_ATTR_FORMAT_PRINTF (1, 0)
        vdebug (const char *message, va_list args)
{
	if (debug_level)
		vfprintf (stderr, message, args);
}

void debug (const char *message, ...)
{
	init_debug ();

	if (debug_level) {
		va_list args;

		va_start (args, message);
		vdebug (message, args);
		va_end (args);
	}
}
