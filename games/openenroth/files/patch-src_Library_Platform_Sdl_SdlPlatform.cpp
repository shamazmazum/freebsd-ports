--- src/Library/Platform/Sdl/SdlPlatform.cpp.orig	2025-12-20 18:26:31 UTC
+++ src/Library/Platform/Sdl/SdlPlatform.cpp
@@ -31,7 +31,8 @@ SdlPlatform::SdlPlatform() {
 
     SDL_SetLogOutputFunction(&sdlLogCallback, _state.get());
 
-    _initialized = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);
+    // The game crashes with SDL_INIT_GAMEPAD on FreeBSD
+    _initialized = SDL_Init(SDL_INIT_VIDEO/* | SDL_INIT_GAMEPAD*/);
     if (!_initialized) {
         _state->logSdlError("SDL_Init");
         return;
