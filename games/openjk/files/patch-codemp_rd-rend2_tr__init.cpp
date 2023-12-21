--- codemp/rd-rend2/tr_init.cpp.orig	2023-11-22 23:32:10 UTC
+++ codemp/rd-rend2/tr_init.cpp
@@ -1858,7 +1858,7 @@ static void R_InitStaticConstants()
 		GL_UNIFORM_BUFFER, tr.defaultShaderInstanceUboOffset, sizeof(shaderInstanceBlock), &shaderInstanceBlock);
 	alignedBlockSize += (sizeof(ShaderInstanceBlock) + alignment) & ~alignment;
 
-	qglBindBuffer(GL_UNIFORM_BUFFER, NULL);
+	qglBindBuffer(GL_UNIFORM_BUFFER, 0);
 	glState.currentGlobalUBO = -1;
 
 	GL_CheckErrors();
