$NetBSD$

Support multiarch.

--- Lib/distutils/sysconfig.py.orig	2014-10-08 08:18:12.000000000 +0000
+++ Lib/distutils/sysconfig.py
@@ -146,7 +146,10 @@ def get_python_lib(plat_specific=0, stan
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
             return os.path.join(prefix, "Lib")
@@ -251,7 +254,10 @@ def get_makefile_filename():
         return os.path.join(_sys_home or project_base, "Makefile")
     lib_dir = get_python_lib(plat_specific=0, standard_lib=1)
     config_file = 'config-{}{}'.format(get_python_version(), build_flags)
-    return os.path.join(lib_dir, config_file, 'Makefile')
+    if sys.maxsize > 2**32:
+        return os.path.join(lib_dir, config_file, "@LIBARCHSUFFIX.64@".lstrip('/'), 'Makefile')
+    else:
+        return os.path.join(lib_dir, config_file, "@LIBARCHSUFFIX.32@".lstrip('/'), 'Makefile')
 
 
 def parse_config_h(fp, g=None):
