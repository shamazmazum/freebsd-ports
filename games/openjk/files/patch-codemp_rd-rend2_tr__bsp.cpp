--- codemp/rd-rend2/tr_bsp.cpp.orig	2023-11-22 23:32:10 UTC
+++ codemp/rd-rend2/tr_bsp.cpp
@@ -4017,7 +4017,7 @@ static void R_GenerateSurfaceSprites( const world_t *w
 	for (int i = 0; i < tr.numShaders; i++)
 	{
 		const shader_t *shader = tr.shaders[i];
-		if (shader->spriteUbo != NULL)
+		if (shader->spriteUbo != 0)
 			continue;
 
 		numSpriteStages += shader->numSurfaceSpriteStages;
