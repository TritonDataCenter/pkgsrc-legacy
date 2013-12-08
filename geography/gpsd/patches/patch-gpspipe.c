$NetBSD$

--- gpspipe.c.orig	2011-01-13 13:36:18.000000000 +0000
+++ gpspipe.c
@@ -77,7 +77,15 @@ static void open_serial(char *device)
     /*@i@*/ bzero(&newtio, sizeof(newtio));
 
     /* make it raw */
+#if defined(__sun)
+    newtio.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+    newtio.c_oflag &= ~OPOST;
+    newtio.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+    newtio.c_cflag &= ~(CSIZE|PARENB);
+    newtio.c_cflag |= CS8;
+#else
     (void)cfmakeraw(&newtio);
+#endif
     /* set speed */
     /*@i@*/ (void)cfsetospeed(&newtio, BAUDRATE);
 
