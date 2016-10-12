$NetBSD: patch-Modules_getpath.c,v 1.3 2015/04/24 03:01:36 rodent Exp $

* from cygport 2.7.3-getpath-exe-extension.patch

--- Modules/getpath.c.orig	2016-06-25 21:49:31.000000000 +0000
+++ Modules/getpath.c
@@ -310,7 +310,7 @@ search_for_exec_prefix(char *argv0_path,
         else
             strncpy(exec_prefix, home, MAXPATHLEN);
         joinpath(exec_prefix, lib_python);
-        joinpath(exec_prefix, "lib-dynload");
+        joinpath(exec_prefix, "lib-dynload@LIBARCHSUFFIX@");
         return 1;
     }
 
@@ -342,7 +342,7 @@ search_for_exec_prefix(char *argv0_path,
     do {
         n = strlen(exec_prefix);
         joinpath(exec_prefix, lib_python);
-        joinpath(exec_prefix, "lib-dynload");
+        joinpath(exec_prefix, "lib-dynload@LIBARCHSUFFIX@");
         if (isdir(exec_prefix))
             return 1;
         exec_prefix[n] = '\0';
@@ -352,7 +352,7 @@ search_for_exec_prefix(char *argv0_path,
     /* Look at configure's EXEC_PREFIX */
     strncpy(exec_prefix, EXEC_PREFIX, MAXPATHLEN);
     joinpath(exec_prefix, lib_python);
-    joinpath(exec_prefix, "lib-dynload");
+    joinpath(exec_prefix, "lib-dynload@LIBARCHSUFFIX@");
     if (isdir(exec_prefix))
         return 1;
 
@@ -375,6 +375,7 @@ calculate_path(void)
     char *prog = Py_GetProgramName();
     char argv0_path[MAXPATHLEN+1];
     char zip_path[MAXPATHLEN+1];
+    char *libarchsuffix = "@LIBARCHSUFFIX@";
     int pfound, efound; /* 1 if found; -1 if found build directory */
     char *buf;
     size_t bufsz;
@@ -430,6 +431,28 @@ calculate_path(void)
                         if (isxfile(progpath))
                                 break;
 
+#ifdef __CYGWIN__
+                        /*
+                         * Cygwin automatically removes the ".exe" extension from argv[0]
+                         * to make programs feel like they are in a more Unix-like
+                         * environment.  Unfortunately, this can make it problemmatic for
+                         * Cygwin to distinguish between a directory and an executable with
+                         * the same name excluding the ".exe" extension.  For example, the
+                         * Cygwin Python build directory has a "Python" directory and a
+                         * "python.exe" executable.  This causes isxfile() to erroneously
+                         * return false.  If isdir() returns true and there is enough space
+                         * to append the ".exe" extension, then we try again with the
+                         * extension appended.
+                         */
+#define EXE ".exe"
+                        if (isdir(progpath) && strlen(progpath) + strlen(EXE) <= MAXPATHLEN)
+                        {
+                            strcat(progpath, EXE);
+                            if (isxfile(progpath))
+                                break;
+                        }
+#endif /* __CYGWIN__ */
+
                         if (!delim) {
                                 progpath[0] = '\0';
                                 break;
@@ -532,7 +555,7 @@ calculate_path(void)
             fprintf(stderr,
                 "Could not find platform dependent libraries <exec_prefix>\n");
         strncpy(exec_prefix, EXEC_PREFIX, MAXPATHLEN);
-        joinpath(exec_prefix, "lib/lib-dynload");
+        joinpath(exec_prefix, "lib/lib-dynload@LIBARCHSUFFIX@");
     }
     /* If we found EXEC_PREFIX do *not* reduce it!  (Yet.) */
 
@@ -643,6 +666,11 @@ calculate_path(void)
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
