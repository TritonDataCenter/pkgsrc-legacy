$NetBSD: patch-main_utils.c,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- main/utils.c.orig	2013-05-02 06:45:31.000000000 +0000
+++ main/utils.c
@@ -194,7 +194,6 @@ static int gethostbyname_r (const char *
 */
 struct hostent *ast_gethostbyname(const char *host, struct ast_hostent *hp)
 {
-	int res;
 	int herrno;
 	int dots = 0;
 	const char *s;
@@ -204,7 +203,6 @@ struct hostent *ast_gethostbyname(const
 	   integers, we break with tradition and refuse to look up a
 	   pure integer */
 	s = host;
-	res = 0;
 	while (s && *s) {
 		if (*s == '.')
 			dots++;
@@ -233,7 +231,7 @@ struct hostent *ast_gethostbyname(const
 	if (!result || !hp->hp.h_addr_list || !hp->hp.h_addr_list[0])
 		return NULL;
 #else
-	res = gethostbyname_r(host, &hp->hp, hp->buf, sizeof(hp->buf), &result, &herrno);
+	int res = gethostbyname_r(host, &hp->hp, hp->buf, sizeof(hp->buf), &result, &herrno);
 
 	if (res || !result || !hp->hp.h_addr_list || !hp->hp.h_addr_list[0])
 		return NULL;
@@ -564,7 +562,7 @@ const char *ast_inet_ntoa(struct in_addr
 static int dev_urandom_fd;
 #endif
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__DragonFly__)
 #undef pthread_create /* For ast_pthread_create function only */
 #endif /* !__linux__ */
 
@@ -1494,13 +1492,13 @@ int ast_false(const char *s)
 static struct timeval tvfix(struct timeval a)
 {
 	if (a.tv_usec >= ONE_MILLION) {
-		ast_log(LOG_WARNING, "warning too large timestamp %ld.%ld\n",
-			(long)a.tv_sec, (long int) a.tv_usec);
+		ast_log(LOG_WARNING, "warning too large timestamp %jd.%ld\n",
+			(intmax_t)a.tv_sec, (long int) a.tv_usec);
 		a.tv_sec += a.tv_usec / ONE_MILLION;
 		a.tv_usec %= ONE_MILLION;
 	} else if (a.tv_usec < 0) {
-		ast_log(LOG_WARNING, "warning negative timestamp %ld.%ld\n",
-			(long)a.tv_sec, (long int) a.tv_usec);
+		ast_log(LOG_WARNING, "warning negative timestamp %jd.%ld\n",
+			(intmax_t)a.tv_sec, (long int) a.tv_usec);
 		a.tv_usec = 0;
 	}
 	return a;
