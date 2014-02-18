$NetBSD$

TIOCOUTQ is defined in termios.h on SunOS and required by ioctl().

--- main.c.orig	2013-06-07 13:18:52.000000000 +0000
+++ main.c
@@ -45,6 +45,10 @@
 #endif
 #include "cookies.h"
 
+#ifdef __sun
+#include <sys/termios.h>
+#endif
+
 volatile int stop = 0;
 
 int quiet = 0;
