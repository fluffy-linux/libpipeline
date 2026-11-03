/*
 * SPDX-FileCopyrightText: 2012 Colin Watson
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "xalloc.h"

#include "common.h"

char *temp_dir;

void temp_dir_setup (void)
{
	temp_dir = xstrdup ("libpipeline.XXXXXX");
	if (mkdtemp (temp_dir) == NULL)
		ck_abort_msg ("mkdtemp failed: %s", strerror (errno));
}

void temp_dir_teardown (void)
{
	pipeline_run (
	        pipeline_new_command_args ("rm", "-rf", temp_dir, nullptr));
	free (temp_dir);
	temp_dir = NULL;
}
