--- source/duke3d/src/common.cpp.orig	2024-03-19 07:29:39 UTC
+++ source/duke3d/src/common.cpp
@@ -640,11 +640,7 @@ void G_AddSearchPaths(void)
 
     Xfree(homepath);
 
-    addsearchpath("/usr/share/games/jfduke3d");
-    addsearchpath("/usr/local/share/games/jfduke3d");
-    addsearchpath("/usr/share/games/" APPBASENAME);
-    addsearchpath("/usr/local/share/games/" APPBASENAME);
-    addsearchpath("/app/extensions/extra");
+    addsearchpath("%%DATADIR%%");
 #elif defined EDUKE32_OSX
     char buf[BMAX_PATH];
     int32_t i;
