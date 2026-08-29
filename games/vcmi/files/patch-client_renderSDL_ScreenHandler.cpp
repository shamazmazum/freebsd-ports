--- client/renderSDL/ScreenHandler.cpp.orig	2026-08-13 14:13:18 UTC
+++ client/renderSDL/ScreenHandler.cpp
@@ -150,10 +150,10 @@ Point ScreenHandler::getRenderResolution() const
 
 Point ScreenHandler::getRenderResolution() const
 {
-	assert(mainRenderer != nullptr);
+	assert(mainWindow != nullptr);
 
 	Point result;
-	SDL_GetRendererOutputSize(mainRenderer, &result.x, &result.y);
+	SDL_GetWindowSize(mainWindow, &result.x, &result.y);
 
 	return result;
 }
