$NetBSD$

Support setting -m32/-m64 via ${ABI} environment variable.

--- gcc/config/i386/sol2-bi.c.orig	2014-07-23 21:48:12.270236541 +0000
+++ gcc/config/i386/sol2-bi.c
@@ -0,0 +1,42 @@
+/* Multilib support for illumos
+   Copyright (C) 2015 Free Software Foundation, Inc.
+
+This file is part of GCC.
+
+GCC is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 3, or (at your option)
+any later version.
+
+GCC is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with GCC; see the file COPYING3.  If not see
+<http://www.gnu.org/licenses/>.  */
+
+#include "config.h"
+#include "system.h"
+#include "coretypes.h"
+#include "tm.h"
+#include "target.h"
+
+const char *
+illumos_abi_bits (int argc, const char **argv)
+{
+  const char *env_abi;
+
+  if (argc != 1)
+    return NULL;
+
+  if ((env_abi = getenv("ABI")) == NULL)
+    return argv[0];
+  if (strcmp(env_abi, "32") == 0 || strcmp(env_abi, "i86") == 0)
+    return "32";
+  else if (strcmp(env_abi, "64") == 0 || strcmp(env_abi, "amd64") == 0)
+    return "64";
+
+  return argv[0];
+}
