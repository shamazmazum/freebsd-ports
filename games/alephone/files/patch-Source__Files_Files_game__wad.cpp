--- Source_Files/Files/game_wad.cpp.orig	2025-02-16 13:17:56 UTC
+++ Source_Files/Files/game_wad.cpp
@@ -1887,7 +1887,7 @@ bool process_map_wad(
 		assert(count*SIZEOF_effect_data==data_length);
 		vassert(count <= MAXIMUM_EFFECTS_PER_MAP,
 			csprintf(temporary,"Number of effects %zu > limit %u",count,MAXIMUM_EFFECTS_PER_MAP));
-		unpack_effect_data(data,effects,count);
+		unpack_effect_data(data,__effects,count);
 
 		data= (uint8 *)extract_type_from_wad(wad, PROJECTILES_STRUCTURE_TAG, &data_length);
 		count= data_length/SIZEOF_projectile_data;
@@ -2463,7 +2463,7 @@ static uint8 *tag_to_global_array_and_size(
 			pack_monster_data(array,monsters,count);
 			break;
 		case EFFECTS_STRUCTURE_TAG:
-			pack_effect_data(array,effects,count);
+			pack_effect_data(array,__effects,count);
 			break;
 		case PROJECTILES_STRUCTURE_TAG:
 			pack_projectile_data(array,projectiles,count);
