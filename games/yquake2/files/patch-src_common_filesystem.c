--- src/common/filesystem.c.orig	2021-02-11 16:28:18 UTC
+++ src/common/filesystem.c
@@ -37,8 +37,9 @@
 #define MAX_PAKS 100
 
 #ifdef SYSTEMWIDE
- #ifndef SYSTEMDIR
-  #define SYSTEMDIR "/usr/share/games/quake2"
+#if !defined(SYSTEMDATADIR) || !defined(SYSTEMLIBDIR)
+  #define SYSTEMDATADIR "/usr/local/share/quake2/"
+  #define SYSTEMLIBDIR "/usr/local/lib/yquake2/"
  #endif
 #endif
 
@@ -1881,7 +1882,8 @@ void FS_BuildRawPath(void) {
 
 	// Add SYSTEMDIR
 #ifdef SYSTEMWIDE
-	FS_AddDirToRawPath(SYSTEMDIR, false);
+	FS_AddDirToRawPath(SYSTEMDATADIR, false);
+	FS_AddDirToRawPath(SYSTEMLIBDIR, false);
 #endif
 
 	// The CD must be the last directory of the path,
