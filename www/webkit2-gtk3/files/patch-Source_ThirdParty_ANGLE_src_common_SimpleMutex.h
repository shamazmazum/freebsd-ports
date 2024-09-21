--- Source/ThirdParty/ANGLE/src/common/SimpleMutex.h.orig	2024-09-21 16:12:17 UTC
+++ Source/ThirdParty/ANGLE/src/common/SimpleMutex.h
@@ -26,23 +26,7 @@
 #include <atomic>
 #include <mutex>
 
-// Enable futexes on:
-//
-// - Linux and derivatives (Android, ChromeOS, etc)
-// - Windows 8+
-//
-// There is no TSAN support for futex currently, so it is disabled in that case
-#if !defined(ANGLE_WITH_TSAN)
-#    if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_ANDROID)
-// Linux has had futexes for a very long time.  Assume support.
-#        define ANGLE_USE_FUTEX 1
-#    elif defined(ANGLE_PLATFORM_WINDOWS) && !defined(ANGLE_ENABLE_WINDOWS_UWP) && \
-        !defined(ANGLE_WINDOWS_NO_FUTEX)
-// Windows has futexes since version 8, which is already end of life (let alone older versions).
-// Assume support.
-#        define ANGLE_USE_FUTEX 1
-#    endif  // defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_ANDROID)
-#endif      // !defined(ANGLE_WITH_TSAN)
+#define ANGLE_USE_FUTEX 0
 
 namespace angle
 {
