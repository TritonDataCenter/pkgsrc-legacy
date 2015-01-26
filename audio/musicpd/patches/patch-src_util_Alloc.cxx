$NetBSD: patch-src_util_Alloc.cxx,v 1.3 2015/01/26 04:17:53 pho Exp $

Some platforms (e.g. Darwin 9) don't have strndup(3), but the function
xstrndup() isn't used in the first place.

http://bugs.musicpd.org/view.php?id=4289 (rejected)
http://bugs.musicpd.org/view.php?id=4291 (revised; pending)

--- src/util/Alloc.cxx.orig	2014-10-24 22:28:53.000000000 +0000
+++ src/util/Alloc.cxx
@@ -58,19 +58,3 @@ xstrdup(const char *s)
 
 	return p;
 }
-
-char *
-xstrndup(const char *s, size_t n)
-{
-#ifdef WIN32
-	char *p = (char *)xalloc(n + 1);
-	memcpy(p, s, n);
-	p[n] = 0;
-#else
-	char *p = strndup(s, n);
-	if (gcc_unlikely(p == nullptr))
-		oom();
-#endif
-
-	return p;
-}
