--- Source_Files/GameWorld/effects.h.orig	2025-02-16 13:23:37 UTC
+++ Source_Files/GameWorld/effects.h
@@ -153,7 +153,7 @@ extern std::vector<effect_data> EffectList;
 // Turned the list of active effects into a variable array
 
 extern std::vector<effect_data> EffectList;
-#define effects (EffectList.data())
+#define __effects (EffectList.data())
 
 // extern struct effect_data *effects;
 
