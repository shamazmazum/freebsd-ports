--- src/Platform/Sdl/SdlWindow.cpp.orig	2023-02-06 04:44:16 UTC
+++ src/Platform/Sdl/SdlWindow.cpp
@@ -163,23 +163,7 @@ Marginsi SdlWindow::frameMargins() const {
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
