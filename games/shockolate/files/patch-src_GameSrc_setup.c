--- src/GameSrc/setup.c.orig	2020-09-21 19:33:33 UTC
+++ src/GameSrc/setup.c
@@ -23,6 +23,7 @@ along with this program.  If not, see <http://www.gnu.
  * $Date: 1994/11/23 00:05:51 $
  */
 
+#include <stdlib.h>
 #include <string.h>
 #include <SDL.h>
 
@@ -39,6 +40,10 @@ along with this program.  If not, see <http://www.gnu.
 #include "fullscrn.h"
 #endif
 
+#ifndef PATH_MAX
+#define PATH_MAX 4096
+#endif
+
 #include "archiveformat.h"
 #include "setup.h"
 #include "colors.h"
@@ -1196,6 +1201,21 @@ uchar intro_key_handler(uiEvent *ev, LGRegion *r, intp
     return (main_kb_callback(ev, r, user_data));
 }
 
+static int file_exists_in_homedir_p (const char *filename)
+{
+    char *home = getenv ("HOME");
+    char path[PATH_MAX];
+    int res = 0;
+ 
+    if (home != NULL) {
+        snprintf (path, PATH_MAX, "%s/.sshock/%s",
+                  home, filename);
+        res = access (path, F_OK) != -1;
+    }
+
+    return res;
+}
+
 errtype load_savegame_names(void) {
     int i;
     int file;
@@ -1207,7 +1227,7 @@ errtype load_savegame_names(void) {
     for (i = 0; i < NUM_SAVE_SLOTS; i++) {
         Poke_SaveName(i);
 
-        if (access(save_game_name, F_OK) != -1) {
+        if (file_exists_in_homedir_p (save_game_name)) {
             file = ResOpenFile(save_game_name);
             if (ResInUse(OLD_SAVE_GAME_ID_BASE)) {
 #ifdef OLD_SG_FORMAT
