$NetBSD$

Support multiarch site-packages.

--- Lib/site.py.orig	2014-10-08 08:18:12.000000000 +0000
+++ Lib/site.py
@@ -304,9 +304,13 @@ def getsitepackages(prefixes=None):
         seen.add(prefix)
 
         if os.sep == '/':
+            if sys.maxsize > 2**32:
+                libarchsuffix = "@LIBARCHSUFFIX.64@".lstrip('/')
+            else:
+                libarchsuffix = "@LIBARCHSUFFIX.32@".lstrip('/')
             sitepackages.append(os.path.join(prefix, "lib",
                                         "python" + sys.version[:3],
-                                        "site-packages"))
+                                        "site-packages", libarchsuffix).rstrip('/'))
             sitepackages.append(os.path.join(prefix, "lib", "site-python"))
         else:
             sitepackages.append(prefix)
