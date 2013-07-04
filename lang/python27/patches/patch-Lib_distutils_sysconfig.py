$NetBSD$

Support multiarch.

--- Lib/distutils/sysconfig.py.orig	2015-12-05 19:46:57.000000000 +0000
+++ Lib/distutils/sysconfig.py
@@ -124,7 +124,10 @@ def get_python_lib(plat_specific=0, stan
         if standard_lib:
             return libpython
         else:
-            return os.path.join(libpython, "site-packages")
+            if sys.maxsize > 2**32:
+              return os.path.join(libpython, "site-packages", "@LIBARCHSUFFIX.64@".lstrip('/')).rstrip('/')
+            else:
+              return os.path.join(libpython, "site-packages", "@LIBARCHSUFFIX.32@".lstrip('/')).rstrip('/')
 
     elif os.name == "nt":
         if standard_lib:
@@ -244,7 +247,10 @@ def get_makefile_filename():
     if python_build:
         return os.path.join(project_base, "Makefile")
     lib_dir = get_python_lib(plat_specific=1, standard_lib=1)
-    return os.path.join(lib_dir, "config", "Makefile")
+    if sys.maxsize > 2**32:
+        return os.path.join(lib_dir, "config", "@LIBARCHSUFFIX.64@".lstrip('/'), "Makefile")
+    else:
+        return os.path.join(lib_dir, "config", "@LIBARCHSUFFIX.32@".lstrip('/'), "Makefile")
 
 
 def parse_config_h(fp, g=None):
