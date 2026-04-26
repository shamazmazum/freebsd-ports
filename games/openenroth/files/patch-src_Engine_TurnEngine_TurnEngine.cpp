--- src/Engine/TurnEngine/TurnEngine.cpp.orig	2026-04-26 05:53:54 UTC
+++ src/Engine/TurnEngine/TurnEngine.cpp
@@ -517,7 +517,7 @@ void stru262_TurnBased::SetAIRecoveryTimes() {
     Actor *monster;  // eax@5
 
     for (i = 0; i < this->pQueue.size(); ++i) {
-        if (pQueue[i].actor_initiative == 0) {
+        if (pQueue[i].actor_initiative == 0 && pQueue[i].uActionLength > 0_ticks) {
             if (pQueue[i].uPackedID.type() == OBJECT_Character) break;
             monster = &pActors[pQueue[i].uPackedID.id()];
             monster_ai_state = monster->aiState;
