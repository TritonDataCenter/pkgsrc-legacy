$NetBSD$

Disable -fomit-frame-pointer.
Add support for -fstrict-calling-conventions.

--- gcc/config/i386/i386.c.orig	2013-04-02 16:54:39.000000000 +0000
+++ gcc/config/i386/i386.c
@@ -3547,7 +3547,7 @@ ix86_option_override_internal (bool main
     }
 
   /* Keep nonleaf frame pointers.  */
-  if (flag_omit_frame_pointer)
+  if (0)
     target_flags &= ~MASK_OMIT_LEAF_FRAME_POINTER;
   else if (TARGET_OMIT_LEAF_FRAME_POINTER)
     flag_omit_frame_pointer = 1;
@@ -3685,7 +3685,7 @@ ix86_option_override_internal (bool main
      around edges.  */
   if ((flag_unwind_tables || flag_asynchronous_unwind_tables
        || flag_exceptions || flag_non_call_exceptions)
-      && flag_omit_frame_pointer
+      && 0
       && !(target_flags & MASK_ACCUMULATE_OUTGOING_ARGS))
     {
       if (target_flags_explicit & MASK_ACCUMULATE_OUTGOING_ARGS)
@@ -5171,6 +5171,7 @@ ix86_function_regparm (const_tree type,
   if (decl
       && TREE_CODE (decl) == FUNCTION_DECL
       && optimize
+      && (TARGET_64BIT || !flag_strict_calling_conventions)
       && !(profile_flag && !flag_fentry))
     {
       /* FIXME: remove this CONST_CAST when cgraph.[ch] is constified.  */
@@ -5248,6 +5249,7 @@ ix86_function_sseregparm (const_tree typ
   /* For local functions, pass up to SSE_REGPARM_MAX SFmode
      (and DFmode for SSE2) arguments in SSE registers.  */
   if (decl && TARGET_SSE_MATH && optimize
+      && (TARGET_64BIT || !flag_strict_calling_conventions)
       && !(profile_flag && !flag_fentry))
     {
       /* FIXME: remove this CONST_CAST when cgraph.[ch] is constified.  */
@@ -9973,7 +9975,7 @@ ix86_finalize_stack_realign_flags (void)
       && !crtl->need_drap
       && frame_pointer_needed
       && current_function_is_leaf
-      && flag_omit_frame_pointer
+      && 0
       && current_function_sp_is_unchanging
       && !ix86_current_function_calls_tls_descriptor
       && !crtl->accesses_prior_frames
