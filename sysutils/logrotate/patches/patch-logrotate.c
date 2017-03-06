$NetBSD$

Fixes GCC error:
"error: missing sentinel in function call [-Werror=format=]"


--- logrotate.c.orig    2016-08-03 09:01:44.000000000 +0000
+++ logrotate.c
@@ -352,7 +352,7 @@ static int runScript(struct logInfo *log
                                DOEXIT(1);
                        }
                }
-               execl("/bin/sh", "sh", "-c", script, "logrotate_script", logfn, NULL);
+               execl("/bin/sh", "sh", "-c", script, "logrotate_script", logfn, (char *)NULL);
                DOEXIT(1);
        }

@@ -672,7 +672,7 @@ static int mailLog(struct logInfo *log,
                                DOEXIT(1);
                        }

-                       execlp(uncompressCommand, uncompressCommand, NULL);
+                       execlp(uncompressCommand, uncompressCommand, (char *)NULL);
                        DOEXIT(1);
                }

