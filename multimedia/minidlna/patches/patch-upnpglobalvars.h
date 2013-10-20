$NetBSD$

On Solaris limits.h is required for PATH_MAX / _MIN

--- upnpglobalvars.h.orig	2013-04-04 23:39:12.000000000 +0000
+++ upnpglobalvars.h
@@ -55,6 +55,10 @@
 #include "clients.h"
 #include "config.h"
 
+#if defined(__sun)
+#include <limits.h>
+#endif
+
 #include <sqlite3.h>
 
 #define MINIDLNA_VERSION "1.1.0"
