$NetBSD$

Multiarch support.

--- Modules/getpath.c.orig	Mon Apr  9 23:07:34 2012
+++ Modules/getpath.c	Mon Aug 13 06:37:50 2012
@@ -118,7 +118,7 @@
 
 #ifndef PYTHONPATH
 #define PYTHONPATH PREFIX "/lib/python" VERSION ":" \
-              EXEC_PREFIX "/lib/python" VERSION "/lib-dynload"
+              EXEC_PREFIX "/lib/python" VERSION "/lib-dynload@LIBARCHSUFFIX@"
 #endif
 
 #ifndef LANDMARK
@@ -331,7 +331,7 @@
         else
             strncpy(exec_prefix, home, MAXPATHLEN);
         joinpath(exec_prefix, lib_python);
-        joinpath(exec_prefix, "lib-dynload");
+        joinpath(exec_prefix, "lib-dynload@LIBARCHSUFFIX@");
         return 1;
     }
 
@@ -348,7 +348,7 @@
     do {
         n = strlen(exec_prefix);
         joinpath(exec_prefix, lib_python);
-        joinpath(exec_prefix, "lib-dynload");
+        joinpath(exec_prefix, "lib-dynload@LIBARCHSUFFIX@");
         if (isdir(exec_prefix))
             return 1;
         exec_prefix[n] = '\0';
@@ -358,7 +358,7 @@
     /* Look at configure's EXEC_PREFIX */
     strncpy(exec_prefix, EXEC_PREFIX, MAXPATHLEN);
     joinpath(exec_prefix, lib_python);
-    joinpath(exec_prefix, "lib-dynload");
+    joinpath(exec_prefix, "lib-dynload@LIBARCHSUFFIX@");
     if (isdir(exec_prefix))
         return 1;
 
@@ -381,6 +381,7 @@
     char *prog = Py_GetProgramName();
     char argv0_path[MAXPATHLEN+1];
     char zip_path[MAXPATHLEN+1];
+    char *libarchsuffix = "@LIBARCHSUFFIX@";
     int pfound, efound; /* 1 if found; -1 if found build directory */
     char *buf;
     size_t bufsz;
@@ -538,7 +539,7 @@
             fprintf(stderr,
                 "Could not find platform dependent libraries <exec_prefix>\n");
         strncpy(exec_prefix, EXEC_PREFIX, MAXPATHLEN);
-        joinpath(exec_prefix, "lib/lib-dynload");
+        joinpath(exec_prefix, "lib/lib-dynload@LIBARCHSUFFIX@");
     }
     /* If we found EXEC_PREFIX do *not* reduce it!  (Yet.) */
 
@@ -649,6 +650,11 @@
         reduce(exec_prefix);
         reduce(exec_prefix);
         reduce(exec_prefix);
+        for (; *libarchsuffix != '\0'; *libarchsuffix++) {
+            if (*libarchsuffix == '/') {
+                reduce(exec_prefix);
+            }
+        }
         if (!exec_prefix[0])
                 strcpy(exec_prefix, separator);
     }
