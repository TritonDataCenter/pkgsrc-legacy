$NetBSD$

Fix endian.h include for BSD and other systems

--- tagutils/tagutils-asf.h.orig	2011-09-16 23:39:58.000000000 +0000
+++ tagutils/tagutils-asf.h
@@ -25,7 +25,9 @@
 
 #ifdef HAVE_MACHINE_ENDIAN_H
 #include <machine/endian.h>
-#else
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#include <sys/endian.h>
+#elif HAVE_ENDIAN_H
 #include <endian.h>
 #endif
 
