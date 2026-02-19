--- client/renderSDL/ScreenHandler.cpp.orig	2025-05-07 07:53:39 UTC
+++ client/renderSDL/ScreenHandler.cpp
@@ -141,10 +141,10 @@ Point ScreenHandler::getRenderResolution() const
 
 Point ScreenHandler::getRenderResolution() const
 {
-	assert(mainRenderer != nullptr);
+	assert(mainWindow != nullptr);
 
 	Point result;
-	SDL_GetRendererOutputSize(mainRenderer, &result.x, &result.y);
+	SDL_GetWindowSize(mainWindow, &result.x, &result.y);
 
 	return result;
 }
