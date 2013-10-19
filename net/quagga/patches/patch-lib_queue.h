$NetBSD$

fix build on SmartOS
--- lib/queue.h.orig   2013-07-30 14:47:01.000000000 +0000
+++ lib/queue.h
@@ -33,7 +33,9 @@
 #ifndef _SYS_QUEUE_H_
 #define       _SYS_QUEUE_H_
 
+#ifndef SUNOS_5
 #include <sys/cdefs.h>
+#endif
 
 /*
  * This file defines four types of data structures: singly-linked lists,
