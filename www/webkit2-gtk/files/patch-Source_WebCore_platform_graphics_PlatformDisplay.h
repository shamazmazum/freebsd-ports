--- Source/WebCore/platform/graphics/PlatformDisplay.h.orig	2025-10-10 04:49:40 UTC
+++ Source/WebCore/platform/graphics/PlatformDisplay.h
@@ -60,6 +60,7 @@ class PlatformDisplay { (public)
 #if !PLATFORM(WIN)
     WEBCORE_EXPORT static void setSharedDisplay(std::unique_ptr<PlatformDisplay>&&);
     WEBCORE_EXPORT static PlatformDisplay* sharedDisplayIfExists();
+    static void displayCleanupWorkaround();
 #endif
     virtual ~PlatformDisplay();
 
