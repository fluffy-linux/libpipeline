/*
 * SPDX-FileCopyrightText: 2022 Colin Watson
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/* Interface to fatal error helper. */

#include "pipeline-private.h"

void fatal (int errnum, const char *format, ...)
        PIPELINE_ATTR_FORMAT_PRINTF (2, 3) PIPELINE_ATTR_NORETURN;
