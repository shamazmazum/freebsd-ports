--- src/GameSrc/setup.c.orig	2020-04-16 09:23:31.515350000 +0300
+++ src/GameSrc/setup.c	2020-04-16 09:29:18.433353000 +0300
@@ -25,6 +25,7 @@
 
 #define __SETUP_SRC
 
+#include <stdlib.h>
 #include <string.h>
 
 // TODO: extract this into a compatibility header
@@ -36,6 +37,10 @@
 	#include <unistd.h>
 #endif
 
+#ifndef PATH_MAX
+#define PATH_MAX 4096
+#endif
+
 #include "archiveformat.h"
 #include "ShockDialogs.h"
 #include "setup.h"
@@ -1304,8 +1309,21 @@
   return (main_kb_callback(ev, r, user_data));
 }
 
+static int file_exists_in_homedir_p (const char *filename)
+{
+    char *home = getenv ("HOME");
+    char path[PATH_MAX];
+    int res = 0;
 
+    if (home != NULL) {
+        snprintf (path, PATH_MAX, "%s/.sshock/%s",
+                  home, filename);
+        res = access (path, F_OK) != -1;
+    }
 
+    return res;
+}
+
 errtype load_savegame_names(void)
 {
   int i;
@@ -1319,7 +1337,7 @@
   {
     Poke_SaveName(i);
 
-    if (access(save_game_name, F_OK) != -1)
+    if (file_exists_in_homedir_p (save_game_name))
     {
       file = ResOpenFile(save_game_name);
       if (ResInUse(OLD_SAVE_GAME_ID_BASE))
