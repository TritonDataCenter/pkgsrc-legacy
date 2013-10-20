$NetBSD$

Fix endian.h include for BSD and other systems

--- tagutils/misc.c.orig	2012-03-28 08:15:15.000000000 +0000
+++ tagutils/misc.c
@@ -24,7 +24,9 @@
 #include <string.h>
 #ifdef HAVE_MACHINE_ENDIAN_H
 #include <machine/endian.h>
-#else
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#include <sys/endian.h>
+#elif HAVE_ENDIAN_H
 #include <endian.h>
 #endif
 
