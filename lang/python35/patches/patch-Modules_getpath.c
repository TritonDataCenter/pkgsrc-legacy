$NetBSD: patch-Modules_getpath.c,v 1.3 2015/04/24 03:01:36 rodent Exp $

* from cygport 2.7.3-getpath-exe-extension.patch

--- Modules/getpath.c.orig	2016-06-25 21:38:38.000000000 +0000
+++ Modules/getpath.c
@@ -393,7 +393,7 @@ search_for_exec_prefix(wchar_t *argv0_pa
             wcsncpy(exec_prefix, home, MAXPATHLEN);
         exec_prefix[MAXPATHLEN] = L'\0';
         joinpath(exec_prefix, lib_python);
-        joinpath(exec_prefix, L"lib-dynload");
+        joinpath(exec_prefix, L"lib-dynload@LIBARCHSUFFIX@");
         return 1;
     }
 
@@ -436,7 +436,7 @@ search_for_exec_prefix(wchar_t *argv0_pa
     do {
         n = wcslen(exec_prefix);
         joinpath(exec_prefix, lib_python);
-        joinpath(exec_prefix, L"lib-dynload");
+        joinpath(exec_prefix, L"lib-dynload@LIBARCHSUFFIX@");
         if (isdir(exec_prefix))
             return 1;
         exec_prefix[n] = L'\0';
@@ -447,7 +447,7 @@ search_for_exec_prefix(wchar_t *argv0_pa
     wcsncpy(exec_prefix, _exec_prefix, MAXPATHLEN);
     exec_prefix[MAXPATHLEN] = L'\0';
     joinpath(exec_prefix, lib_python);
-    joinpath(exec_prefix, L"lib-dynload");
+    joinpath(exec_prefix, L"lib-dynload@LIBARCHSUFFIX@");
     if (isdir(exec_prefix))
         return 1;
 
@@ -471,6 +471,7 @@ calculate_path(void)
     wchar_t *prog = Py_GetProgramName();
     wchar_t argv0_path[MAXPATHLEN+1];
     wchar_t zip_path[MAXPATHLEN+1];
+    char *libarchsuffix = "@LIBARCHSUFFIX@";
     int pfound, efound; /* 1 if found; -1 if found build directory */
     wchar_t *buf;
     size_t bufsz;
@@ -695,7 +696,7 @@ calculate_path(void)
             fprintf(stderr,
                 "Could not find platform dependent libraries <exec_prefix>\n");
         wcsncpy(exec_prefix, _exec_prefix, MAXPATHLEN);
-        joinpath(exec_prefix, L"lib/lib-dynload");
+        joinpath(exec_prefix, L"lib/lib-dynload@LIBARCHSUFFIX@");
     }
     /* If we found EXEC_PREFIX do *not* reduce it!  (Yet.) */
 
@@ -805,6 +806,11 @@ calculate_path(void)
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
