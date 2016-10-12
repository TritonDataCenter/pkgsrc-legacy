$NetBSD$

Support multiarch.

--- Lib/sysconfig.py.orig	2012-09-29 08:00:31.000000000 +0000
+++ Lib/sysconfig.py	2012-12-14 14:49:45.294023933 +0000
@@ -23,8 +23,8 @@
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
@@ -359,7 +359,10 @@
         config_dir_name = 'config-%s%s' % (_PY_VERSION_SHORT, sys.abiflags)
     else:
         config_dir_name = 'config'
-    return os.path.join(get_path('stdlib'), config_dir_name, 'Makefile')
+    if sys.maxsize > 2**32:
+        return os.path.join(get_path('stdlib'), config_dir_name, "@LIBARCHSUFFIX.64@".lstrip('/'), 'Makefile')
+    else:
+        return os.path.join(get_path('stdlib'), config_dir_name, "@LIBARCHSUFFIX.32@".lstrip('/'), 'Makefile')
 
 def _generate_posix_vars():
     """Generate the Python module containing build-time variables."""
@@ -518,6 +521,10 @@
         _CONFIG_VARS['installed_platbase'] = _BASE_EXEC_PREFIX
         _CONFIG_VARS['platbase'] = _EXEC_PREFIX
         _CONFIG_VARS['projectbase'] = _PROJECT_BASE
+        if sys.maxsize > 2**32:
+            _CONFIG_VARS['libarchsuffix'] = "@LIBARCHSUFFIX.64@"
+        else:
+            _CONFIG_VARS['libarchsuffix'] = "@LIBARCHSUFFIX.32@"
         try:
             _CONFIG_VARS['abiflags'] = sys.abiflags
         except AttributeError:
