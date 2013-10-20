$NetBSD$

If MAX macro isn't available define it by myself

--- utils.h.orig	2012-11-03 09:45:45.000000000 +0000
+++ utils.h
@@ -26,6 +26,10 @@
 
 #include "minidlnatypes.h"
 
+#ifndef MAX
+# define MAX(a,b) (((a)>(b))?(a):(b))
+#endif
+
 /* String functions */
 int strcatf(struct string_s *str, char *fmt, ...);
 void strncpyt(char *dst, const char *src, size_t len);
