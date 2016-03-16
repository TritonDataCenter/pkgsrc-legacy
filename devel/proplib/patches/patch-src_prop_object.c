$NetBSD: patch-src_prop_object.c,v 1.1 2015/06/28 14:53:16 kirussel Exp $

Only use fdatasync() if it is in the header files and you can link with it.
This change has alreay been pushed upstream:
    https://github.com/xtraeme/portableproplib/pull/1

--- src/prop_object.c.orig	2014-05-17 18:15:13.000000000 +0000
+++ src/prop_object.c
@@ -859,7 +859,7 @@ _prop_object_externalize_write_file(cons
 			goto bad;
 	}
 
-#ifdef HAVE_FDATASYNC
+#if defined(HAVE_FDATASYNC) && HAVE_DECL_FDATASYNC
 	if (fdatasync(fd) == -1)
 #else
 	if (fsync(fd) == -1)
