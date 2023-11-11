--- src/Platform/Sdl/SdlWindow.cpp.orig	2023-07-07 12:32:43 UTC
+++ src/Platform/Sdl/SdlWindow.cpp
@@ -162,23 +162,7 @@ uintptr_t SdlWindow::systemHandle() const {
 }
 
 uintptr_t SdlWindow::systemHandle() const {
-    SDL_SysWMinfo info;
-    SDL_VERSION(&info.version);
-
-    if (SDL_GetWindowWMInfo(_window, &info) != SDL_TRUE) {
-        _state->logSdlError("SDL_GetWindowWMInfo");
-        return 0;
-    }
-
-#ifdef _WINDOWS
-    return reinterpret_cast<uintptr_t>(info.info.win.window);
-#elif __APPLE__
-    return reinterpret_cast<uintptr_t>(info.info.cocoa.window);
-#elif ANDROID
-    return reinterpret_cast<uintptr_t>(info.info.android.window);
-#else
-    return static_cast<uintptr_t>(info.info.x11.window);
-#endif
+    return 0;
 }
 
 void SdlWindow::activate() {
