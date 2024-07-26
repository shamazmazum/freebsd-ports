--- src/demo/main.c.orig	2023-06-18 19:27:28 UTC
+++ src/demo/main.c
@@ -9,7 +9,6 @@
 #include <string.h>
 
 #include <SDL2/SDL.h>
-#include <iniparser.h>
 #ifdef USE_GCD
 #include <dispatch/dispatch.h>
 #else
