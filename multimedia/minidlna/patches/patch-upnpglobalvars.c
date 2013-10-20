$NetBSD$

On Solaris limits.h is required for PATH_MAX / _MIN

--- upnpglobalvars.c.orig	2013-10-20 16:01:13.721574238 +0000
+++ upnpglobalvars.c
@@ -50,6 +50,10 @@
 #include <netinet/in.h>
 #include <sys/param.h>
 
+#if defined(__sun)
+#include <limits.h>
+#endif
+
 #include "config.h"
 #include "upnpglobalvars.h"
 
