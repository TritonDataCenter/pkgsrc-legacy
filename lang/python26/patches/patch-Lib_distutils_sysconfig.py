$NetBSD$

Support multiarch.

--- Lib/distutils/sysconfig.py.orig	2012-04-10 15:32:04.000000000 +0000
+++ Lib/distutils/sysconfig.py	2012-12-13 09:44:24.270222135 +0000
@@ -124,7 +124,10 @@
         if standard_lib:
             return libpython
         else:
-            return os.path.join(libpython, "site-packages")
+            if sys.maxsize > 2**32:
+                return os.path.join(libpython, "site-packages", "@LIBARCHSUFFIX.64@".lstrip('/')).rstrip('/')
+            else:
+                return os.path.join(libpython, "site-packages", "@LIBARCHSUFFIX.32@".lstrip('/')).rstrip('/')
 
     elif os.name == "nt":
         if standard_lib:
@@ -225,7 +228,10 @@
         return os.path.join(os.path.dirname(os.path.realpath(sys.executable)),
                             "Makefile")
     lib_dir = get_python_lib(plat_specific=1, standard_lib=1)
-    return os.path.join(lib_dir, "config", "Makefile")
+    if sys.maxsize > 2**32:
+        return os.path.join(lib_dir, "config", "@LIBARCHSUFFIX.64@".lstrip('/'), "Makefile")
+    else:
+        return os.path.join(lib_dir, "config", "@LIBARCHSUFFIX.32@".lstrip('/'), "Makefile")
 
 
 def parse_config_h(fp, g=None):
