--- Source_Files/GameWorld/effects.cpp.orig	2025-02-16 13:17:47 UTC
+++ Source_Files/GameWorld/effects.cpp
@@ -70,7 +70,7 @@ effect_data *get_effect_data(
 effect_data *get_effect_data(
 	const short effect_index)
 {
-	struct effect_data *effect = GetMemberWithBounds(effects,effect_index,MAXIMUM_EFFECTS_PER_MAP);
+	struct effect_data *effect = GetMemberWithBounds(__effects,effect_index,MAXIMUM_EFFECTS_PER_MAP);
 	
 	vassert(effect, csprintf(temporary, "effect index #%d is out of range", effect_index));
 	vassert(SLOT_IS_USED(effect), csprintf(temporary, "effect index #%d (%p) is unused", effect_index, (void*)effect));
@@ -111,7 +111,7 @@ short new_effect(
 		}
 		else
 		{
-			for (effect_index= 0,effect= effects; effect_index<MAXIMUM_EFFECTS_PER_MAP; ++effect_index, ++effect)
+			for (effect_index= 0,effect= __effects; effect_index<MAXIMUM_EFFECTS_PER_MAP; ++effect_index, ++effect)
 			{
 				if (SLOT_IS_FREE(effect))
 				{
@@ -156,7 +156,7 @@ void update_effects(
 	struct effect_data *effect;
 	short effect_index;
 	
-	for (effect_index= 0, effect= effects; effect_index<MAXIMUM_EFFECTS_PER_MAP; ++effect_index, ++effect)
+	for (effect_index= 0, effect= __effects; effect_index<MAXIMUM_EFFECTS_PER_MAP; ++effect_index, ++effect)
 	{
 		if (SLOT_IS_USED(effect))
 		{
@@ -215,7 +215,7 @@ void remove_all_nonpersistent_effects(
 	struct effect_data *effect;
 	short effect_index;
 	
-	for (effect_index= 0, effect= effects; effect_index<MAXIMUM_EFFECTS_PER_MAP; ++effect_index, ++effect)
+	for (effect_index= 0, effect= __effects; effect_index<MAXIMUM_EFFECTS_PER_MAP; ++effect_index, ++effect)
 	{
 		if (SLOT_IS_USED(effect))
 		{
@@ -284,7 +284,7 @@ void teleport_object_in(
 	struct effect_data *effect;
 	short effect_index;
 
-	for (effect_index= 0, effect= effects; effect_index<MAXIMUM_EFFECTS_PER_MAP; ++effect_index, ++effect)
+	for (effect_index= 0, effect= __effects; effect_index<MAXIMUM_EFFECTS_PER_MAP; ++effect_index, ++effect)
 	{
 		if (SLOT_IS_USED(effect))
 		{
