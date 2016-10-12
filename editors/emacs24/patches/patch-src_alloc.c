$NetBSD$

Workaround for libumem.

--- src/alloc.c.orig	2014-06-13 17:34:33.000000000 +0000
+++ src/alloc.c
@@ -19,6 +19,7 @@ You should have received a copy of the G
 along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
+#include <dlfcn.h>
 
 #include <stdio.h>
 #include <limits.h>		/* For CHAR_BIT.  */
@@ -729,8 +730,14 @@ xrealloc (void *block, size_t size)
 void
 xfree (void *block)
 {
+  Dl_info_t inf;
+
   if (!block)
     return;
+
+  if (dladdr(block, &inf) != 0)
+    return;
+
   MALLOC_BLOCK_INPUT;
   free (block);
   MALLOC_UNBLOCK_INPUT;
@@ -941,6 +948,11 @@ lisp_malloc (size_t nbytes, enum mem_typ
 static void
 lisp_free (void *block)
 {
+  Dl_info_t inf;
+
+  if (dladdr(block, &inf) != 0)
+    return;
+
   MALLOC_BLOCK_INPUT;
   free (block);
 #if GC_MARK_STACK && !defined GC_MALLOC_CHECK
