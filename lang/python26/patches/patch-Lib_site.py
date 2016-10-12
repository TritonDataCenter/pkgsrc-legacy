$NetBSD$

Support multiarch site-packages.

--- Lib/site.py.orig	2012-04-10 15:32:06.000000000 +0000
+++ Lib/site.py	2012-12-13 09:41:52.556961721 +0000
@@ -265,9 +265,13 @@
         if sys.platform in ('os2emx', 'riscos'):
             sitedirs.append(os.path.join(prefix, "Lib", "site-packages"))
         elif os.sep == '/':
+            if sys.maxsize > 2**32:
+                libarchsuffix = "@LIBARCHSUFFIX.64@".lstrip('/')
+            else:
+                libarchsuffix = "@LIBARCHSUFFIX.32@".lstrip('/')
             sitedirs.append(os.path.join(prefix, "lib",
                                         "python" + sys.version[:3],
-                                        "site-packages"))
+                                        "site-packages", libarchsuffix).rstrip('/'))
             sitedirs.append(os.path.join(prefix, "lib", "site-python"))
         else:
             sitedirs.append(prefix)
