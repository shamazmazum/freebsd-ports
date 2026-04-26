--- src/Library/Platform/Sdl/SdlPlatform.cpp.orig	2026-02-17 22:13:45 UTC
+++ src/Library/Platform/Sdl/SdlPlatform.cpp
@@ -31,7 +31,7 @@ SdlPlatform::SdlPlatform() {
 
     SDL_SetLogOutputFunction(&sdlLogCallback, _state.get());
 
-    _initialized = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);
+    _initialized = SDL_Init(SDL_INIT_VIDEO/* | SDL_INIT_GAMEPAD*/);
     if (!_initialized) {
         _state->logSdlError("SDL_Init");
         return;
