$NetBSD$

Make sure rhino.jar is loaded too.

--- hotspot/src/share/vm/runtime/os.cpp.orig	2014-05-01 13:10:09.000000000 +0000
+++ hotspot/src/share/vm/runtime/os.cpp
@@ -1125,6 +1125,7 @@ bool os::set_boot_path(char fileSep, cha
     // aligned with install/install/make/common/Pack.gmk. Note: boot class
     // path class JARs, are stripped for StackMapTable to reduce download size.
     static const char classpath_format[] =
+        "%/lib/rhino.jar:"
         "%/lib/resources.jar:"
         "%/lib/rt.jar:"
         "%/lib/sunrsasign.jar:"
