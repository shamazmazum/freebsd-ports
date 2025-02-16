--- Source_Files/Lua/lua_objects.cpp.orig	2025-02-16 13:18:26 UTC
+++ Source_Files/Lua/lua_objects.cpp
@@ -321,7 +321,7 @@ bool Lua_Effect_Valid(int32 index)
 	if (index < 0 || index >= MAXIMUM_EFFECTS_PER_MAP)
 		return false;
 
-	effect_data *effect = GetMemberWithBounds(effects, index, MAXIMUM_EFFECTS_PER_MAP);
+	effect_data *effect = GetMemberWithBounds(__effects, index, MAXIMUM_EFFECTS_PER_MAP);
 	return SLOT_IS_USED(effect);
 }
 
@@ -384,7 +384,7 @@ int Lua_Item_Delete(lua_State* L)
 	{
 		for (auto i = 0; i < MAXIMUM_EFFECTS_PER_MAP; ++i)
 		{
-			auto effect = &effects[i];
+			auto effect = &__effects[i];
 			if (SLOT_IS_USED(effect) &&
 				effect->type == _effect_teleport_object_in &&
 				effect->data == object_index)
