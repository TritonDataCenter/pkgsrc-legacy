$NetBSD$

Support setting -m32/-m64 via ${ABI} environment variable.

--- gcc/config/i386/i386.h.orig	2014-08-21 18:03:49.000000000 +0000
+++ gcc/config/i386/i386.h
@@ -573,11 +573,18 @@ extern tree x86_mfence;
 #if defined(__i386__) || defined(__x86_64__)
 /* In driver-i386.c.  */
 extern const char *host_detect_local_cpu (int argc, const char **argv);
-#define EXTRA_SPEC_FUNCTIONS \
-  { "local_cpu_detect", host_detect_local_cpu },
 #define HAVE_LOCAL_CPU_DETECT
+#define TARGET_EXTRA_SPEC_FUNCTIONS \
+  { "local_cpu_detect", host_detect_local_cpu },
 #endif
 
+#ifndef TARGET_EXTRA_SPEC_FUNCTIONS
+#define TARGET_EXTRA_SPEC_FUNCTIONS
+#endif
+
+#define EXTRA_SPEC_FUNCTIONS \
+  TARGET_EXTRA_SPEC_FUNCTIONS
+
 #if TARGET_64BIT_DEFAULT
 #define OPT_ARCH64 "!m32"
 #define OPT_ARCH32 "m32"
