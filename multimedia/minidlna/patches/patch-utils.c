$NetBSD$

If MIN macro isn't available I define it by myself

--- utils.c.orig	2013-10-20 17:24:21.963392570 +0000
+++ utils.c
@@ -33,6 +33,10 @@
 #include "upnpglobalvars.h"
 #include "log.h"
 
+#ifndef MIN
+# define MIN(a,b) (((a)<(b))?(a):(b))
+#endif
+
 inline int
 strcatf(struct string_s *str, const char *fmt, ...)
 {
