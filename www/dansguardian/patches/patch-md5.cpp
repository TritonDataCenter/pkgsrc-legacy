$NetBSD$

--- md5.cpp.orig	2005-08-13 23:47:57.000000000 +0000
+++ md5.cpp
@@ -30,7 +30,9 @@
 //These lines modified Tue 24th February 2004 by Daniel Barron
 #include "autoconf/platform.h"
 #ifdef __ENDIANH
-    #include __ENDIANH
+    #if !defined(__sun)
+        #include __ENDIANH
+    #endif
 #else
     #include <endian.h>
 #endif
