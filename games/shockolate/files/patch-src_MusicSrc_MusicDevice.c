--- src/MusicSrc/MusicDevice.c.orig	2020-01-18 07:05:35.000000000 +0300
+++ src/MusicSrc/MusicDevice.c	2020-04-16 07:10:01.418420000 +0300
@@ -1184,7 +1184,7 @@
         FindClose(hFind);
     }
 #else
-    DIR *dirp = opendir("res");
+    DIR *dirp = opendir("%%DATADIR%%res");
     struct dirent *dp = 0;
     while (dp = readdir(dirp))
     {
@@ -1237,7 +1237,7 @@
     unsigned int outputCount = 0; // subtract 1 to get index
     // count .sf2 files in res/ subdirectory until we find the one that the user
     //  probably wants
-    DIR *dirp = opendir("res");
+    DIR *dirp = opendir("%%DATADIR%%res");
     struct dirent *dp = 0;
     while ((outputCount <= outputIndex) &&
            (dp = readdir(dirp)))
