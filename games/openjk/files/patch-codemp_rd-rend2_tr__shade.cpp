--- codemp/rd-rend2/tr_shade.cpp.orig	2023-11-22 23:32:10 UTC
+++ codemp/rd-rend2/tr_shade.cpp
@@ -1525,7 +1525,7 @@ static void RB_IterateStagesGeneric( shaderCommands_t 
 				vertColor[3] = 0.0f;
 			}
 
-			if (backEnd.currentEntity->e.hModel != NULL)
+			if (backEnd.currentEntity->e.hModel != 0)
 			{
 				model_t *model = R_GetModelByHandle(backEnd.currentEntity->e.hModel);
 				if (model->type != MOD_BRUSH)
