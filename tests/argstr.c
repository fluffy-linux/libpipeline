/*
 * SPDX-FileCopyrightText: 2010 Colin Watson
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <string.h>

#include "common.h"

/* Include private definitions so that we can inspect arguments. */
#include "pipeline-private.h"

const char *program_name = "argstr";

START_TEST (test_argstr_trivial)
{
	pipecmd *cmd;

	cmd = pipecmd_new_argstr ("/bin/simple");
	ck_assert_str_eq (cmd->name, "/bin/simple");
	ck_assert_int_eq (cmd->u.process.argc, 1);
	ck_assert_str_eq (cmd->u.process.argv[0], "simple");
	pipecmd_free (cmd);
}
END_TEST

START_TEST (test_argstr_torture)
{
	pipecmd *cmd;

	cmd = pipecmd_new_argstr (
	        "x' \\' \\$\\'\\\"\" \\'\\$\\\"\\\\ \" \\\"");
	ck_assert_str_eq (cmd->name, "x \\");
	ck_assert_int_eq (cmd->u.process.argc, 3);
	ck_assert_str_eq (cmd->u.process.argv[0], "x \\");
	ck_assert_str_eq (cmd->u.process.argv[1], "$'\" \\'$\"\\ ");
	ck_assert_str_eq (cmd->u.process.argv[2], "\"");
	pipecmd_free (cmd);
}
END_TEST

START_TEST (test_argstr_exec)
{
	pipecmd *cmd;

	cmd = pipecmd_new_argstr ("exec /bin/foo bar");
	ck_assert_str_eq (cmd->name, "/bin/foo");
	ck_assert_int_eq (cmd->u.process.argc, 2);
	ck_assert_str_eq (cmd->u.process.argv[0], "foo");
	ck_assert_str_eq (cmd->u.process.argv[1], "bar");
	pipecmd_free (cmd);
}
END_TEST

START_TEST (test_argstr_excess_whitespace)
{
	pipecmd *cmd;

	cmd = pipecmd_new_argstr (" /bin/foo \tbar\t");
	ck_assert_str_eq (cmd->name, "/bin/foo");
	ck_assert_int_eq (cmd->u.process.argc, 2);
	ck_assert_str_eq (cmd->u.process.argv[0], "foo");
	ck_assert_str_eq (cmd->u.process.argv[1], "bar");
	pipecmd_free (cmd);
}
END_TEST

static Suite *argstr_suite (void)
{
	Suite *s = suite_create ("Argstr");

	TEST_CASE (s, argstr, trivial);
	TEST_CASE (s, argstr, torture);
	TEST_CASE (s, argstr, exec);
	TEST_CASE (s, argstr, excess_whitespace);

	return s;
}

MAIN (argstr)
