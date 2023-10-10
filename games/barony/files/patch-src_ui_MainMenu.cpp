--- src/ui/MainMenu.cpp.orig	2023-10-10 05:33:41 UTC
+++ src/ui/MainMenu.cpp
@@ -21299,7 +21299,9 @@ failed:
 #elif defined(LINUX)
 	    char path[PATH_MAX];
 	    completePath(path, "editor &");
+#ifdef SOUND
 	    stopMusic();
+#endif
 	    system(path);
 #else
         return;
