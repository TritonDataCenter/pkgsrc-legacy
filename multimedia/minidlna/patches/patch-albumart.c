$NetBSD$

Replace not standard DT_ macros

--- albumart.c.orig	2013-01-19 01:16:19.000000000 +0000
+++ albumart.c
@@ -128,15 +128,17 @@ update_if_album_art(const char *path)
 	dh = opendir(dir);
 	if( !dh )
 		return;
+	struct stat s;
 	while ((dp = readdir(dh)) != NULL)
 	{
-		switch( dp->d_type )
+		stat(dp->d_name, &s);
+		switch( s.st_mode & S_IFMT )
 		{
-			case DT_REG:
+			case S_IFREG:
 				type = TYPE_FILE;
 				break;
-			case DT_LNK:
-			case DT_UNKNOWN:
+			case S_IFLNK:
+			case 0 /* DT_UNKNOWN */:
 				snprintf(file, sizeof(file), "%s/%s", dir, dp->d_name);
 				type = resolve_unknown_type(file, ALL_MEDIA);
 				break;
