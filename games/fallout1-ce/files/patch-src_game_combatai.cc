--- src/game/combatai.cc.orig	2024-05-08 18:38:33 UTC
+++ src/game/combatai.cc
@@ -533,7 +533,7 @@ static int ai_find_attackers(Object* critter, Object**
         *a3 = NULL;
     }
 
-    if (*a4 != NULL) {
+    if (a4 != NULL) {
         *a4 = NULL;
     }
 
