--- Source/WebCore/platform/graphics/PlatformDisplay.h.orig	2024-08-26 05:35:50 UTC
+++ Source/WebCore/platform/graphics/PlatformDisplay.h
@@ -63,6 +63,7 @@ class PlatformDisplay { (public)
 #if !PLATFORM(WIN)
     WEBCORE_EXPORT static void setSharedDisplay(std::unique_ptr<PlatformDisplay>&&);
     WEBCORE_EXPORT static PlatformDisplay* sharedDisplayIfExists();
+    static void displayCleanupWorkaround();
 #endif
     virtual ~PlatformDisplay();
 
