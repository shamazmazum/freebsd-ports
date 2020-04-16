--- src/Libraries/RES/Source/caseless.c.orig	2020-01-18 07:05:35.000000000 +0300
+++ src/Libraries/RES/Source/caseless.c	2020-04-16 08:44:02.713028000 +0300
@@ -20,6 +20,7 @@
 // DG 2018: a case-insensitive fopen() wrapper, and functions used by it
 
 #include <assert.h>
+#include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 #include <sys/stat.h>
@@ -241,18 +242,35 @@
 
 FILE *fopen_caseless(const char *path, const char *mode) {
     FILE *ret = NULL;
+    char fullpath[PATH_MAX];
+    char *home = getenv("HOME");
 
     if (path == NULL || mode == NULL)
         return NULL;
 
-    ret = fopen(path, mode);
+    if (strcmp (path, "CurrentGame.dat") == 0 ||
+        strncmp (path, "savgam", strlen ("savgam")) == 0) {
+        if (home == NULL)
+            return NULL;
 
+        snprintf (fullpath, PATH_MAX, "%s/.sshock/", home);
+        if (strstr (mode, "w") != NULL) {
+            /* Ensure the local directory exists */
+            mkdir (fullpath, 0755);
+        }
+
+        strlcat (fullpath, path, PATH_MAX);
+    } else {
+        snprintf (fullpath, PATH_MAX, "%%DATADIR%%%s", path);
+    }
+
+    ret = fopen(fullpath, mode);
 #ifndef _WIN32 // not windows
     if (ret == NULL) {
         char fixedpath[PATH_MAX];
-        size_t pathlen = strlen(path);
+        size_t pathlen = strlen(fullpath);
 
-        if (pathlen < sizeof(fixedpath) && caselesspath(path, fixedpath, 0)) {
+        if (pathlen < sizeof(fixedpath) && caselesspath(fullpath, fixedpath, 0)) {
             ret = fopen(fixedpath, mode);
         }
     }
