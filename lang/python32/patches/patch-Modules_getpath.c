$NetBSD$

Multiarch support.

--- Modules/getpath.c.orig	2012-04-11 06:54:07.000000000 +0000
+++ Modules/getpath.c	2012-12-13 15:09:29.380392481 +0000
@@ -123,7 +123,7 @@
 
 #ifndef PYTHONPATH
 #define PYTHONPATH PREFIX "/lib/python" VERSION ":" \
-              EXEC_PREFIX "/lib/python" VERSION "/lib-dynload"
+              EXEC_PREFIX "/lib/python" VERSION "/lib-dynload@LIBARCHSUFFIX@"
 #endif
 
 #ifndef LANDMARK
@@ -339,7 +339,7 @@
         else
             wcsncpy(exec_prefix, home, MAXPATHLEN);
         joinpath(exec_prefix, lib_python);
-        joinpath(exec_prefix, L"lib-dynload");
+        joinpath(exec_prefix, L"lib-dynload@LIBARCHSUFFIX@");
         return 1;
     }
 
@@ -380,7 +380,7 @@
     do {
         n = wcslen(exec_prefix);
         joinpath(exec_prefix, lib_python);
-        joinpath(exec_prefix, L"lib-dynload");
+        joinpath(exec_prefix, L"lib-dynload@LIBARCHSUFFIX@");
         if (isdir(exec_prefix))
             return 1;
         exec_prefix[n] = L'\0';
@@ -390,7 +390,7 @@
     /* Look at configure's EXEC_PREFIX */
     wcsncpy(exec_prefix, _exec_prefix, MAXPATHLEN);
     joinpath(exec_prefix, lib_python);
-    joinpath(exec_prefix, L"lib-dynload");
+    joinpath(exec_prefix, L"lib-dynload@LIBARCHSUFFIX@");
     if (isdir(exec_prefix))
         return 1;
 
@@ -414,6 +414,7 @@
     wchar_t *prog = Py_GetProgramName();
     wchar_t argv0_path[MAXPATHLEN+1];
     wchar_t zip_path[MAXPATHLEN+1];
+    char *libarchsuffix = "@LIBARCHSUFFIX@";
     int pfound, efound; /* 1 if found; -1 if found build directory */
     wchar_t *buf;
     size_t bufsz;
@@ -593,7 +594,7 @@
             fprintf(stderr,
                 "Could not find platform dependent libraries <exec_prefix>\n");
         wcsncpy(exec_prefix, _exec_prefix, MAXPATHLEN);
-        joinpath(exec_prefix, L"lib/lib-dynload");
+        joinpath(exec_prefix, L"lib/lib-dynload@LIBARCHSUFFIX@");
     }
     /* If we found EXEC_PREFIX do *not* reduce it!  (Yet.) */
 
@@ -710,6 +711,11 @@
         reduce(exec_prefix);
         reduce(exec_prefix);
         reduce(exec_prefix);
+        for (; *libarchsuffix != '\0'; *libarchsuffix++) {
+            if (*libarchsuffix == '/') {
+                reduce(exec_prefix);
+            }
+        }
         if (!exec_prefix[0])
                 wcscpy(exec_prefix, separator);
     }
