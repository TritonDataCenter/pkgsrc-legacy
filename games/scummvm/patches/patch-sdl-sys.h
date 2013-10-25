$NetBSD$

Solaris has typedef __FILE FILE in several places already

--- backends/platform/sdl/sdl-sys.h.orig        2013-05-26 20:21:47.000000000 +0000
+++ backends/platform/sdl/sdl-sys.h
@@ -35,8 +35,11 @@
 // it with an alternate slightly less unfriendly override.
 #if !defined(FORBIDDEN_SYMBOL_ALLOW_ALL) && !defined(FORBIDDEN_SYMBOL_EXCEPTION_FILE)
 #undef FILE
+// Solaris has typedef __FILE FILE in several places already
+#if !defined(__sun)
 typedef struct { int FAKE; } FAKE_FILE;
 #define FILE FAKE_FILE
+#endif   // (__sun)
 #endif
 
 #if !defined(FORBIDDEN_SYMBOL_ALLOW_ALL) && !defined(FORBIDDEN_SYMBOL_EXCEPTION_strcasecmp)
