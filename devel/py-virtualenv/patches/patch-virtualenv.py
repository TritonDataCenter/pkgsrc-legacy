$NetBSD$

Add basic multiarch support to virtualenv. Creates copies of real binaries (in addition to the abiexec wrapper.)

--- virtualenv.py.orig	2016-11-16 02:39:30.000000000 +0000
+++ virtualenv.py
@@ -1230,6 +1230,20 @@ def install_python(home_dir, lib_dir, in
         executable = sys.executable
         shutil.copyfile(executable, py_executable)
         make_exe(py_executable)
+        # Handle multiarch case
+        binarch32 = '@BINARCHSUFFIX32@'
+        binarch64 = '@BINARCHSUFFIX64@'
+        if binarch32 != binarch64:
+            mkdir(join(bin_dir, binarch32))
+            mkdir(join(bin_dir, binarch64))
+            executable32 = os.path.join(os.path.dirname(executable), binarch32, os.path.basename(executable))
+            executable64 = os.path.join(os.path.dirname(executable), binarch64, os.path.basename(executable))
+            py_executable32 = os.path.join(os.path.dirname(py_executable), binarch32, os.path.basename(py_executable))
+            py_executable64 = os.path.join(os.path.dirname(py_executable), binarch64, os.path.basename(py_executable))
+            shutil.copyfile(executable32, py_executable32)
+            shutil.copyfile(executable64, py_executable64)
+            make_exe(py_executable32)
+            make_exe(py_executable64)
         if is_win or is_cygwin:
             pythonw = os.path.join(os.path.dirname(sys.executable), 'pythonw.exe')
             if os.path.exists(pythonw):
