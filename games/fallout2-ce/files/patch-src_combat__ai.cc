--- src/combat_ai.cc.orig	2024-04-21 05:42:30 UTC
+++ src/combat_ai.cc
@@ -1440,7 +1440,7 @@ static int aiFindAttackers(Object* critter, Object** w
         *whoHitFriendPtr = NULL;
     }
 
-    if (*whoHitByFriendPtr != NULL) {
+    if (whoHitByFriendPtr != NULL) {
         *whoHitByFriendPtr = NULL;
     }
 
