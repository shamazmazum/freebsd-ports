--- src/MacSrc/OpenGL.cc.orig	2020-01-18 07:05:35.000000000 +0300
+++ src/MacSrc/OpenGL.cc	2020-04-16 07:23:52.285448000 +0300
@@ -195,7 +195,7 @@
     DEBUG("Loading shader %s", filename);
 
     char fb[256];
-    sprintf(fb, "shaders/%s", filename);
+    sprintf(fb, "%%DATADIR%%shaders/%s", filename);
 
     FILE* file = fopen(fb, "r");
     if(file == nullptr) {
