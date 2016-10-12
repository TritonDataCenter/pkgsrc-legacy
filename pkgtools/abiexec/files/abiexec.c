/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#pragma ident	"%Z%%M%	%I%	%E% SMI"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libintl.h>
#include <unistd.h>
#include <locale.h>

/*ARGSUSED*/
int
main(int argc, char **argv, char **envp)
{
	const char *abi;
	const char *default_abi = "32";
	const char *execname;
	const char *fname;
	const char *isadir;
	char *pathname;
	char *str;
	size_t len;

#if !defined(TEXT_DOMAIN)		/* Should be defined by cc -D */
#define	TEXT_DOMAIN	"SYS_TEST"	/* Use this only if it wasn't */
#endif
	(void) setlocale(LC_ALL, "");
	(void) textdomain(TEXT_DOMAIN);

	/*
	 * Get the exec name.
	 */
	if ((execname = getexecname()) == NULL) {
		(void) fprintf(stderr,
				gettext("%s: getexecname() failed\n"),
				argv[0]);
		return (1);
	}

	/*
	 * Allocate storage for execname + longest possible ABI subdir
	 */
	len = strlen(execname) + strlen("amd64/");
	if ((pathname = malloc(len)) == NULL)
		goto out;

	/*
	 * Get the dir and base name of the executable.
	 */
	(void) strcpy(pathname, execname);
	if ((str = strrchr(pathname, '/')) != NULL) {
		*++str = '\0';
		fname = execname + (str - pathname);
	} else {
		fname = execname;
		*pathname = '\0';
	}
	len = strlen(pathname);

	/*
	 * Search ABI dirs.  If ABI isn't set in the environment, default to
	 * 32-bit to avoid relying on the isaexec(3C) default which is currently
	 * 'amd64'.  This ensures a consistent default across abiexec and GCC.
	 */
	if ((abi = getenv("ABI")) == NULL)
		abi = default_abi;

	if ((strcmp(abi, "32") == 0 || strcmp(abi, "i86") == 0)) {
		isadir = "i86/";
	} else if ((strcmp(abi, "64") == 0 ||strcmp(abi, "amd64") == 0)) {
		isadir = "amd64/";
	}

	if (isadir) {
		(void) strcpy(pathname + len, isadir);
		(void) strcat(pathname + len, fname);
		if (access(pathname, X_OK) == 0)
			(void) execve(pathname, argv, envp);
		free(pathname);
	}
out:
	(void) fprintf(stderr,
			gettext("%s: abiexec(\"%s\") failed\n"),
			argv[0], fname);
	return (1);
}
