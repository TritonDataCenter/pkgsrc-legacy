$NetBSD$

stdarg.h is required to build on Solaris/SmartOS because of va_list 

--- Lrzip.h.orig	2012-05-10 12:45:41.000000000 +0000
+++ Lrzip.h
@@ -28,6 +28,10 @@
 # include <inttypes.h>
 #endif
 
+#if defined(__sun)
+#include <stdarg.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
