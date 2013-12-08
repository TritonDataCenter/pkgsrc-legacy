$NetBSD$

--- src/lst_string.c.orig	2004-01-13 14:14:26.000000000 +0000
+++ src/lst_string.c
@@ -26,6 +26,10 @@ CONNECTION WITH THE SOFTWARE OR THE USE
 #  include <config.h>
 #endif
 
+#ifndef MIN
+#  define MIN(a,b) (((a)<(b))?(a):(b))
+#endif
+
 #include <sys/param.h>
 
 #include "lst_string.h"
