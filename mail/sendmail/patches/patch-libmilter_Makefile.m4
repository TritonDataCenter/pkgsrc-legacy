$NetBSD$

--- libmilter/Makefile.m4.orig	2013-04-16 20:19:54.000000000 +0000
+++ libmilter/Makefile.m4
@@ -10,6 +10,7 @@ SMSRCDIR=ifdef(`confSMSRCDIR', `confSMSR
 PREPENDDEF(`confINCDIRS', `-I${SMSRCDIR} ')
 
 bldPRODUCT_START(`library', `libmilter')
+APPENDDEF(`confOPTIMIZE', `-fPIC')
 define(`bldINSTALLABLE', `true')
 define(`LIBMILTER_EXTRAS', `errstring.c strl.c')
 APPENDDEF(`confENVDEF', `-DNOT_SENDMAIL -Dsm_snprintf=snprintf')
