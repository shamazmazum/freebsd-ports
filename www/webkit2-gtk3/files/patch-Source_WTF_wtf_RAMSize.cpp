--- Source/WTF/wtf/RAMSize.cpp.orig	2023-05-14 07:57:21 UTC
+++ Source/WTF/wtf/RAMSize.cpp
@@ -31,10 +31,12 @@
 #if OS(WINDOWS)
 #include <windows.h>
 #elif USE(SYSTEM_MALLOC)
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX)
 #include <sys/sysinfo.h>
 #elif OS(UNIX)
 #include <unistd.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #endif // OS(LINUX) || OS(FREEBSD) || OS(UNIX)
 #else
 #include <bmalloc/bmalloc.h>
@@ -56,14 +58,18 @@ static size_t computeRAMSize()
         return ramSizeGuess;
     return status.ullTotalPhys;
 #elif USE(SYSTEM_MALLOC)
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX)
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
 #elif OS(UNIX)
-    long pages = sysconf(_SC_PHYS_PAGES);
-    long pageSize = sysconf(_SC_PAGE_SIZE);
-    return pages * pageSize;
+    size_t physmem, len;
+    int mib[2] = {CTL_HW, HW_PHYSMEM};
+    if (sysctl(mib, 2, &physmem, &len, NULL, 0) == 0 && len == sizeof(physmem)) {
+        return physmem;
+    } else {
+        return 512 * MB;
+    }
 #else
 #error "Missing a platform specific way of determining the available RAM"
 #endif // OS(LINUX) || OS(FREEBSD) || OS(UNIX)
