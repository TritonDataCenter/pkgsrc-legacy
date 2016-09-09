$NetBSD$

Avoid a crash in "status.diskusage" when not on Linux or FreeBSD

--- salt/modules/status.py.orig	2016-08-24 16:25:25.000000000 +0000
+++ salt/modules/status.py
@@ -504,6 +504,8 @@ def diskusage(*args):
                 return {}
         elif __grains__['kernel'] == 'FreeBSD':
             ifile = __salt__['cmd.run']('mount -p').splitlines()
+        else:
+            ifile = []
 
         for line in ifile:
             comps = line.split()
