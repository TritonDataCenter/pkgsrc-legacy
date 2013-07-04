$NetBSD$

--- gcc/config/sol2-bi.h.orig	2011-07-07 09:24:16.000000000 +0000
+++ gcc/config/sol2-bi.h	2012-08-23 09:22:45.070296391 +0000
@@ -74,8 +74,9 @@
   "%{G:-G} \
    %{YP,*} \
    %{R*} \
-   %{!YP,*:%{p|pg:-Y P,%R/usr/lib/libp/" ARCH64_SUBDIR ":%R/lib/" ARCH64_SUBDIR ":%R/usr/lib/" ARCH64_SUBDIR "}	\
-	   %{!p:%{!pg:-Y P,%R/lib/" ARCH64_SUBDIR ":%R/usr/lib/" ARCH64_SUBDIR "}}}"
+   -R@PREFIX@/lib/" @MARCH64_SUBDIR@ " \
+   %{!YP,*:%{p|pg:-Y P,%R/usr/lib/libp/" ARCH64_SUBDIR ":%R/lib/" ARCH64_SUBDIR ":%R/usr/lib/" ARCH64_SUBDIR ":%R@PREFIX@/lib/" @MARCH64_SUBDIR@ "}	\
+	   %{!p:%{!pg:-Y P,%R/lib/" ARCH64_SUBDIR ":%R/usr/lib/" ARCH64_SUBDIR ":%R@PREFIX@/lib/" @MARCH64_SUBDIR@ "}}}"
 
 #undef LINK_ARCH64_SPEC
 #ifndef USE_GLD
