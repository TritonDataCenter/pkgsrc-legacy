$NetBSD$

Disable -fomit-frame-pointer.
Add support for -fstrict-calling-conventions.

--- gcc/config/i386/i386.c.orig	2015-06-10 09:26:06.000000000 +0000
+++ gcc/config/i386/i386.c
@@ -3857,7 +3857,7 @@ ix86_option_override_internal (bool main
     }
 
   /* Keep nonleaf frame pointers.  */
-  if (opts->x_flag_omit_frame_pointer)
+  if (0)
     opts->x_target_flags &= ~MASK_OMIT_LEAF_FRAME_POINTER;
   else if (TARGET_OMIT_LEAF_FRAME_POINTER_P (opts->x_target_flags))
     opts->x_flag_omit_frame_pointer = 1;
@@ -5636,6 +5636,7 @@ ix86_function_regparm (const_tree type,
 	 and callee not, or vice versa.  Instead look at whether the callee
 	 is optimized or not.  */
       && opt_for_fn (decl, optimize)
+      && (TARGET_64BIT || !flag_strict_calling_conventions)
       && !(profile_flag && !flag_fentry))
     {
       /* FIXME: remove this CONST_CAST when cgraph.[ch] is constified.  */
@@ -5713,6 +5714,7 @@ ix86_function_sseregparm (const_tree typ
   /* For local functions, pass up to SSE_REGPARM_MAX SFmode
      (and DFmode for SSE2) arguments in SSE registers.  */
   if (decl && TARGET_SSE_MATH && optimize
+      && (TARGET_64BIT || !flag_strict_calling_conventions)
       && !(profile_flag && !flag_fentry))
     {
       /* FIXME: remove this CONST_CAST when cgraph.[ch] is constified.  */
@@ -10650,7 +10652,7 @@ ix86_finalize_stack_realign_flags (void)
   if (stack_realign
       && frame_pointer_needed
       && crtl->is_leaf
-      && flag_omit_frame_pointer
+      && 0
       && crtl->sp_is_unchanging
       && !ix86_current_function_calls_tls_descriptor
       && !crtl->accesses_prior_frames
