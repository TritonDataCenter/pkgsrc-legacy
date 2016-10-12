$NetBSD$

Support multiarch site-packages.

--- Lib/site.py.orig	2015-12-05 19:47:02.000000000 +0000
+++ Lib/site.py
@@ -288,9 +288,13 @@ def getsitepackages():
         if sys.platform in ('os2emx', 'riscos'):
             sitepackages.append(os.path.join(prefix, "Lib", "site-packages"))
         elif os.sep == '/':
+            if sys.maxsize > 2**32:
+              libarchsuffix = "@LIBARCHSUFFIX.64@".lstrip('/')
+            else:
+              libarchsuffix = "@LIBARCHSUFFIX.32@".lstrip('/')
             sitepackages.append(os.path.join(prefix, "lib",
                                         "python" + sys.version[:3],
-                                        "site-packages"))
+                                        "site-packages", libarchsuffix).rstrip('/'))
             sitepackages.append(os.path.join(prefix, "lib", "site-python"))
         else:
             sitepackages.append(prefix)
