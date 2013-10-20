$NetBSD$

Replace not standard DT_ macros

--- scanner.c.orig	2013-01-02 21:00:52.000000000 +0000
+++ scanner.c
@@ -597,18 +597,22 @@ sql_failed:
 static int
 filter_type(scan_filter *d)
 {
+	struct stat s;
+	stat(d->d_name, &s);
 	return ( (*d->d_name != '.') &&
-	         ((d->d_type == DT_DIR) ||
-	          (d->d_type == DT_LNK) ||
-	          (d->d_type == DT_UNKNOWN))
+	         ((S_ISDIR(s.st_mode)) ||
+	          (S_ISLNK(s.st_mode)) ||
+	          (s.st_mode & 0 /* DT_UNKNOWN */))
 	       );
 }
 
 static int
 filter_a(scan_filter *d)
 {
+	struct stat s;
+	stat(d->d_name, &s);
 	return ( filter_type(d) ||
-		 ((d->d_type == DT_REG) &&
+		 ((S_ISREG(s.st_mode)) &&
 		  (is_audio(d->d_name) ||
 	           is_playlist(d->d_name))
 	       ) );
@@ -617,8 +621,10 @@ filter_a(scan_filter *d)
 static int
 filter_av(scan_filter *d)
 {
+	struct stat s;
+	stat(d->d_name, &s);
 	return ( filter_type(d) ||
-		 ((d->d_type == DT_REG) &&
+		 ((S_ISREG(s.st_mode)) &&
 		  (is_audio(d->d_name) ||
 		   is_video(d->d_name) ||
 	           is_playlist(d->d_name)))
@@ -628,8 +634,10 @@ filter_av(scan_filter *d)
 static int
 filter_ap(scan_filter *d)
 {
+	struct stat s;
+	stat(d->d_name, &s);
 	return ( filter_type(d) ||
-		 ((d->d_type == DT_REG) &&
+		 ((S_ISREG(s.st_mode)) &&
 		  (is_audio(d->d_name) ||
 		   is_image(d->d_name) ||
 	           is_playlist(d->d_name)))
@@ -639,8 +647,10 @@ filter_ap(scan_filter *d)
 static int
 filter_v(scan_filter *d)
 {
+	struct stat s;
+	stat(d->d_name, &s);
 	return ( filter_type(d) ||
-		 (d->d_type == DT_REG &&
+		 ((S_ISREG(s.st_mode)) &&
 	          is_video(d->d_name))
 	       );
 }
@@ -648,8 +658,10 @@ filter_v(scan_filter *d)
 static int
 filter_vp(scan_filter *d)
 {
+	struct stat s;
+	stat(d->d_name, &s);
 	return ( filter_type(d) ||
-		 ((d->d_type == DT_REG) &&
+		 ((S_ISREG(s.st_mode)) &&
 		  (is_video(d->d_name) ||
 	           is_image(d->d_name)))
 	       );
@@ -658,8 +670,10 @@ filter_vp(scan_filter *d)
 static int
 filter_p(scan_filter *d)
 {
+	struct stat s;
+	stat(d->d_name, &s);
 	return ( filter_type(d) ||
-		 (d->d_type == DT_REG &&
+		 ((S_ISREG(s.st_mode)) &&
 		  is_image(d->d_name))
 	       );
 }
@@ -667,8 +681,10 @@ filter_p(scan_filter *d)
 static int
 filter_avp(scan_filter *d)
 {
+	struct stat s;
+	stat(d->d_name, &s);
 	return ( filter_type(d) ||
-		 ((d->d_type == DT_REG) &&
+		 ((S_ISREG(s.st_mode)) &&
 		  (is_audio(d->d_name) ||
 		   is_image(d->d_name) ||
 		   is_video(d->d_name) ||
@@ -725,6 +741,7 @@ ScanDirectory(const char *dir, const cha
 		startID = get_next_available_id("OBJECTS", BROWSEDIR_ID);
 	}
 
+	struct stat s;
 	for (i=0; i < n; i++)
 	{
 #if !USE_FORK
@@ -734,11 +751,12 @@ ScanDirectory(const char *dir, const cha
 		type = TYPE_UNKNOWN;
 		sprintf(full_path, "%s/%s", dir, namelist[i]->d_name);
 		name = escape_tag(namelist[i]->d_name, 1);
-		if( namelist[i]->d_type == DT_DIR )
+		stat(namelist[i]->d_name, &s);
+		if( S_ISDIR(s.st_mode) )
 		{
 			type = TYPE_DIR;
 		}
-		else if( namelist[i]->d_type == DT_REG )
+		else if( S_ISREG(s.st_mode) )
 		{
 			type = TYPE_FILE;
 		}
