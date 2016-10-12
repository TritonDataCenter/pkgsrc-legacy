$NetBSD$

Support setting -m32/-m64 via ${ABI} environment variable.

--- gcc/config/i386/sol2-bi.h.orig	2014-01-02 22:23:26.000000000 +0000
+++ gcc/config/i386/sol2-bi.h
@@ -28,6 +28,31 @@ along with GCC; see the file COPYING3.
 #define SUBTARGET_OPTIMIZATION_OPTIONS				\
   { OPT_LEVELS_1_PLUS, OPT_momit_leaf_frame_pointer, NULL, 1 }
 
+/* All of this is needed to allow ABI={32|64|i86|amd64} in the environment to
+   provide an alternate default value for -m32/-m64.  The compiler default is
+   always 32-bit; in the absence of this variable, we will do nothing.  If the
+   variable is set to a bogus value, we'll also ignore it.  And any option on
+   the command line overrides ABI.  The only exception here is if ABI is set
+   and neither -m32 nor -m64 is specified on the command line, if a -mcpu or
+   -mtune option is provided that is inconsistent with the ABI setting, the
+   compiler will fail exactly as it would have if -m32 or -m64 were explicitly
+   provided on the command line.  */
+#undef EXTRA_SPEC_FUNCTIONS
+extern const char *illumos_abi_bits (int argc, const char **argv);
+#define EXTRA_SPEC_FUNCTIONS \
+  TARGET_EXTRA_SPEC_FUNCTIONS \
+  { "env_abi_bits", illumos_abi_bits },
+
+#undef OPTION_DEFAULT_SPECS
+#define OPTION_DEFAULT_SPECS \
+  {"abi", "%{!m32:%{!m64:-m%:env_abi_bits(%(VALUE))}}" }, \
+  {"tune_32", "%{" OPT_ARCH32 ":%{!mtune=*:%{!mcpu=*:%{!march=*:-mtune=%(VALUE)}}}}" }, \
+  {"tune_64", "%{" OPT_ARCH64 ":%{!mtune=*:%{!mcpu=*:%{!march=*:-mtune=%(VALUE)}}}}" }, \
+  {"cpu_32", "%{" OPT_ARCH32 ":%{!mtune=*:%{!mcpu=*:%{!march=*:-mtune=%(VALUE)}}}}" }, \
+  {"cpu_64", "%{" OPT_ARCH64 ":%{!mtune=*:%{!mcpu=*:%{!march=*:-mtune=%(VALUE)}}}}" }, \
+  {"arch_32", "%{" OPT_ARCH32 ":%{!march=*:-march=%(VALUE)}}"}, \
+  {"arch_64", "%{" OPT_ARCH64 ":%{!march=*:-march=%(VALUE)}}"},
+
 /* GNU as understands --32 and --64, but the native Solaris
    assembler requires -xarch=generic or -xarch=generic64 instead.  */
 #ifdef USE_GAS
