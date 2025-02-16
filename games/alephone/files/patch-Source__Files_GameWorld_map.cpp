--- Source_Files/GameWorld/map.cpp.orig	2025-02-16 13:18:12 UTC
+++ Source_Files/GameWorld/map.cpp
@@ -416,7 +416,7 @@ void initialize_map_for_new_level(
 	// Clear all these out -- supposed to be none of the contents of these when starting a level.
 	objlist_clear(automap_lines, AutomapLineList.size());
 	objlist_clear(automap_polygons, AutomapPolygonList.size());
-	objlist_clear(effects, EffectList.size());
+	objlist_clear(__effects, EffectList.size());
 	objlist_clear(projectiles,  ProjectileList.size());
 	objlist_clear(monsters,  MonsterList.size());
 	objlist_clear(objects,  ObjectList.size());
@@ -2072,7 +2072,7 @@ void recalculate_map_counts(
 		;
 	dynamic_world->projectile_count= static_cast<int16>(count);
 	
-	for (count=MAXIMUM_EFFECTS_PER_MAP,effect=effects+MAXIMUM_EFFECTS_PER_MAP-1;
+	for (count=MAXIMUM_EFFECTS_PER_MAP,effect=__effects+MAXIMUM_EFFECTS_PER_MAP-1;
 			count>0&&(!SLOT_IS_USED(effect));
 			--count,--effect)
 		;
