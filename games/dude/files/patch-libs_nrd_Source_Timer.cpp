--- libs/nrd/Source/Timer.cpp.orig	2026-09-18 16:01:13 UTC
+++ libs/nrd/Source/Timer.cpp
@@ -4,7 +4,7 @@
 
 #if defined(_WIN32)
 #    include <windows.h>
-#elif defined(__linux__) || defined(__SCE__) || defined(__APPLE__)
+#elif defined(__linux__) || defined(__SCE__) || defined(__APPLE__) || defined(__FreeBSD__)
 #    include <time.h>
 #    ifdef USE_MONOTONIC_TIMER
 constexpr clockid_t CLOCKID = CLOCK_MONOTONIC;
@@ -23,7 +23,7 @@ inline uint64_t _GetTicks() {
     uint64_t ticks;
     QueryPerformanceCounter((LARGE_INTEGER*)&ticks);
     return ticks;
-#elif defined(__linux__) || defined(__SCE__) || defined(__APPLE__)
+#elif defined(__linux__) || defined(__SCE__) || defined(__APPLE__) || defined(__FreeBSD__)
     struct timespec spec;
     clock_gettime(CLOCKID, &spec);
     return uint64_t(spec.tv_sec) * 1000000000ull + spec.tv_nsec;
@@ -36,7 +36,7 @@ nrd::Timer::Timer() {
     QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);
 
     m_InvTicksPerMs = 1000.0 / ticksPerSecond;
-#elif defined(__linux__) || defined(__SCE__) || defined(__APPLE__)
+#elif defined(__linux__) || defined(__SCE__) || defined(__APPLE__) || defined(__FreeBSD__)
     m_InvTicksPerMs = 1.0 / 1000000.0;
 #endif
 
