# SPDX-FileCopyrightText: 2010 Colin Watson
#
# SPDX-License-Identifier: GPL-2.0-or-later

## Process this file with automake to produce Makefile.in.

SUBDIRS = gl/lib lib man
if RUN_TESTS
SUBDIRS += tests
endif

dist_noinst_DATA = NEWS.md

EXTRA_DIST = \
	.gitignore \
	ChangeLog-2013 \
	bootstrap \
	bootstrap.conf

# These macro files are imported by gnulib-tool, but at present not used. We
# include them in the distribution anyway for maximum consistency.
EXTRA_DIST += \
	gl/m4/math_h.m4

# Note that autopoint installs into the first directory here. Yes, this
# means that it installs into gl/m4, so we always run gnulib-tool after
# autopoint, at least for now. See
# https://lists.gnu.org/archive/html/bug-gnulib/2009-03/msg00154.html and
# thread.
ACLOCAL_AMFLAGS = -I gl/m4 -I m4

dist-hook: gen-ChangeLog

gen_start_date = 2013-11-30 21:08
.PHONY: gen-ChangeLog
gen-ChangeLog:
	$(AM_V_GEN)if test -d .git; then \
		$(top_srcdir)/build-aux/gitlog-to-changelog \
			--format='%s%n%n%b%n' \
			--since="$(gen_start_date)" > $(distdir)/cl-t; \
		rm -f $(distdir)/ChangeLog; \
		mv $(distdir)/cl-t $(distdir)/ChangeLog; \
	fi
