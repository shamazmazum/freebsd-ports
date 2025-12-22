--- Source/WTF/wtf/RAMSize.cpp.orig	2025-08-08 09:17:54 UTC
+++ Source/WTF/wtf/RAMSize.cpp
@@ -31,8 +31,11 @@
 #if OS(WINDOWS)
 #include <windows.h>
 #elif USE(SYSTEM_MALLOC)
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX)
 #include <sys/sysinfo.h>
+#elif OS(FREEBSD)
+#include <sys/sysctl.h>
+#include <sys/types.h>
 #elif OS(UNIX) || OS(HAIKU)
 #include <unistd.h>
 #endif // OS(LINUX) || OS(FREEBSD) || OS(UNIX) || OS(HAIKU)
@@ -60,10 +63,18 @@ static size_t computeRAMSize()
         return ramSizeGuess;
     return status.ullTotalPhys;
 #elif USE(SYSTEM_MALLOC)
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX)
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
+#elif OS(FREEBSD)
+    size_t physmem, len;
+    int mib[2] = { CTL_HW, HW_PHYSMEM };
+    if (sysctl(mib, 2, &physmem, &len, NULL, 0) == 0 && len == sizeof(physmem)) {
+        return physmem;
+    } else {
+        return 512 * MB;
+    }
 #elif OS(UNIX) || OS(HAIKU)
     long pages = sysconf(_SC_PHYS_PAGES);
     long pageSize = sysconf(_SC_PAGE_SIZE);
