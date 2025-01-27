--- Source/WebCore/platform/graphics/PlatformDisplay.cpp.orig	2024-08-22 11:14:10 UTC
+++ Source/WebCore/platform/graphics/PlatformDisplay.cpp
@@ -87,28 +87,29 @@ PlatformDisplay::PlatformDisplay(std::unique_ptr<GLDis
     RELEASE_ASSERT(m_eglDisplay);
 
     eglDisplays().add(this);
+}
 
+// EGL registers atexit handlers to cleanup its global display list.
+// Since the global PlatformDisplay instance is created before,
+// when the PlatformDisplay destructor is called, EGL has already removed the
+// display from the list, causing eglTerminate() to crash. So, here we register
+// our own atexit handler, after EGL has been initialized and after the global
+// instance has been created to ensure we call eglTerminate() before the other
+// EGL atexit handlers and the PlatformDisplay destructor.
+// See https://bugs.webkit.org/show_bug.cgi?id=157973.
 #if !PLATFORM(WIN)
-    static bool eglAtexitHandlerInitialized = false;
-    if (!eglAtexitHandlerInitialized) {
-        // EGL registers atexit handlers to cleanup its global display list.
-        // Since the global PlatformDisplay instance is created before,
-        // when the PlatformDisplay destructor is called, EGL has already removed the
-        // display from the list, causing eglTerminate() to crash. So, here we register
-        // our own atexit handler, after EGL has been initialized and after the global
-        // instance has been created to ensure we call eglTerminate() before the other
-        // EGL atexit handlers and the PlatformDisplay destructor.
-        // See https://bugs.webkit.org/show_bug.cgi?id=157973.
-        eglAtexitHandlerInitialized = true;
-        std::atexit([] {
-            while (!eglDisplays().isEmpty()) {
-                auto* display = eglDisplays().takeAny();
-                display->terminateEGLDisplay();
-            }
-        });
+void PlatformDisplay::displayCleanupWorkaround() {
+    while (!eglDisplays().isEmpty()) {
+        auto* display = eglDisplays().takeAny();
+        display->terminateEGLDisplay();
     }
-#endif
 }
+
+__attribute__((destructor))
+static void terminateDisplays() {
+    PlatformDisplay::displayCleanupWorkaround();
+}
+#endif
 
 PlatformDisplay::~PlatformDisplay()
 {
