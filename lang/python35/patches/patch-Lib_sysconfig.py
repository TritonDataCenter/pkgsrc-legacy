$NetBSD: patch-ax,v 1.6 2015/04/24 03:01:36 rodent Exp $

chop "-RELEASE" or "-DEVELOPMENT" from release for DragonFly.

--- Lib/sysconfig.py.orig	2016-06-25 21:38:36.000000000 +0000
+++ Lib/sysconfig.py
@@ -22,8 +22,8 @@ _INSTALL_SCHEMES = {
     'posix_prefix': {
         'stdlib': '{installed_base}/lib/python{py_version_short}',
         'platstdlib': '{platbase}/lib/python{py_version_short}',
-        'purelib': '{base}/lib/python{py_version_short}/site-packages',
-        'platlib': '{platbase}/lib/python{py_version_short}/site-packages',
+        'purelib': '{base}/lib/python{py_version_short}/site-packages{libarchsuffix}',
+        'platlib': '{platbase}/lib/python{py_version_short}/site-packages{libarchsuffix}',
         'include':
             '{installed_base}/include/python{py_version_short}{abiflags}',
         'platinclude':
@@ -337,7 +337,10 @@ def get_makefile_filename():
         config_dir_name = 'config-%s%s' % (_PY_VERSION_SHORT, sys.abiflags)
     else:
         config_dir_name = 'config'
-    return os.path.join(get_path('stdlib'), config_dir_name, 'Makefile')
+    if sys.maxsize > 2**32:
+        return os.path.join(get_path('stdlib'), config_dir_name, "@LIBARCHSUFFIX.64@".lstrip('/'), "Makefile")
+    else:
+        return os.path.join(get_path('stdlib'), config_dir_name, "@LIBARCHSUFFIX.32@".lstrip('/'), "Makefile")
 
 def _generate_posix_vars():
     """Generate the Python module containing build-time variables."""
@@ -529,6 +532,10 @@ def get_config_vars(*args):
         except AttributeError:
             # sys.abiflags may not be defined on all platforms.
             _CONFIG_VARS['abiflags'] = ''
+        if sys.maxsize > 2**32:
+            _CONFIG_VARS['libarchsuffix'] = "@LIBARCHSUFFIX.64@"
+        else:
+            _CONFIG_VARS['libarchsuffix'] = "@LIBARCHSUFFIX.32@"
 
         if os.name == 'nt':
             _init_non_posix(_CONFIG_VARS)
@@ -674,6 +681,8 @@ def get_platform():
         osname, release, machine = _osx_support.get_platform_osx(
                                             get_config_vars(),
                                             osname, release, machine)
+    elif osname[:9] == "dragonfly":
+        release = str.split(release, '-')[0]
 
     return "%s-%s-%s" % (osname, release, machine)
 
