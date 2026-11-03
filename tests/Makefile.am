# SPDX-FileCopyrightText: 2010 Colin Watson
#
# SPDX-License-Identifier: GPL-2.0-or-later

## Process this file with automake to produce Makefile.in.

# basic deliberately comes first so that any fundamental problems are more
# obviously attributed to it.
TESTS = \
	basic \
	argstr \
	exec \
	inspect \
	pump \
	read \
	redirect
check_PROGRAMS = $(TESTS)

LIBS = ../gl/lib/libgnu.la $(LTLIBOBJS) $(top_builddir)/lib/libpipeline.la

AM_CPPFLAGS = \
	-I$(top_srcdir)/gl/lib \
	-I$(top_builddir)/gl/lib \
	-I$(top_srcdir)/lib
AM_CFLAGS = $(WARN_CFLAGS) @CHECK_CFLAGS@

clean-local:
	rm -f testtmp.*

basic_SOURCES = basic.c common.c common.h
basic_LDADD = $(LIBS) @CHECK_LIBS@

argstr_SOURCES = argstr.c common.c common.h
argstr_LDADD = $(LIBS) @CHECK_LIBS@

exec_SOURCES = exec.c common.c common.h
exec_LDADD = $(LIBS) @CHECK_LIBS@

inspect_SOURCES = inspect.c common.c common.h
inspect_LDADD = $(LIBS) @CHECK_LIBS@

pump_SOURCES = pump.c common.c common.h
pump_LDADD = $(LIBS) @CHECK_LIBS@

read_SOURCES = read.c common.c common.h
read_LDADD = $(LIBS) @CHECK_LIBS@

redirect_SOURCES = redirect.c common.c common.h
redirect_LDADD = $(LIBS) @CHECK_LIBS@
