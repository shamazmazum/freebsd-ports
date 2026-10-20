--- src/Library/Platform/Sdl/SdlPlatform.cpp.orig	2026-10-20 04:27:34 UTC
+++ src/Library/Platform/Sdl/SdlPlatform.cpp
@@ -28,7 +28,7 @@ SdlPlatform::SdlPlatform() {
 
     SDL_SetLogOutputFunction(&sdlLogCallback, _state.get());
 
-    _initialized = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);
+    _initialized = SDL_Init(SDL_INIT_VIDEO);
     if (!_initialized) {
         _state->logSdlError("SDL_Init");
         return;
