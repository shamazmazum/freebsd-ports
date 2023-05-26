--- Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2023-05-22 08:56:15 UTC
+++ Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -44,7 +44,7 @@
 #import <mach/mach_error.h>
 #import <math.h>
 #elif BOS(UNIX)
-#if BOS(FREEBSD) || BOS(LINUX)
+#if BOS(LINUX)
 #include <sys/sysinfo.h>
 #endif
 #if BOS(LINUX)
@@ -161,17 +161,19 @@ static size_t computeAvailableMemory()
     // Round up the memory size to a multiple of 128MB because max_mem may not be exactly 512MB
     // (for example) and we have code that depends on those boundaries.
     return ((sizeAccordingToKernel + multiple - 1) / multiple) * multiple;
-#elif BOS(FREEBSD) || BOS(LINUX)
+#elif BOS(LINUX)
     struct sysinfo info;
     if (!sysinfo(&info))
         return info.totalram * info.mem_unit;
     return availableMemoryGuess;
 #elif BOS(UNIX)
-    long pages = sysconf(_SC_PHYS_PAGES);
-    long pageSize = sysconf(_SC_PAGE_SIZE);
-    if (pages == -1 || pageSize == -1)
+    size_t physmem, len;
+    int mib[2] = {CTL_HW, HW_PHYSMEM};
+    if (sysctl(mib, 2, &physmem, &len, NULL, 0) == 0 && len == sizeof(physmem)) {
+        return physmem;
+    } else {
         return availableMemoryGuess;
-    return pages * pageSize;
+    }
 #else
     return availableMemoryGuess;
 #endif
