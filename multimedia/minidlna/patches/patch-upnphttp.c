$NetBSD$

On Solaris limits.h is required for PATH_MAX / _MIN

--- upnphttp.c.orig	2013-03-18 05:37:46.000000000 +0000
+++ upnphttp.c
@@ -62,6 +62,10 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 
+#if defined(__sun)
+#include <limits.h>
+#endif
+
 #include "config.h"
 #include "upnpglobalvars.h"
 #include "upnphttp.h"
