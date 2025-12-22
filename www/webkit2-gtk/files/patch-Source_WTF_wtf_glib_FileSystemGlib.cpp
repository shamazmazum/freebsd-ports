--- Source/WTF/wtf/glib/FileSystemGlib.cpp.orig	2025-08-08 09:17:54 UTC
+++ Source/WTF/wtf/glib/FileSystemGlib.cpp
@@ -78,11 +78,7 @@ CString currentExecutablePath()
 #elif OS(UNIX)
 CString currentExecutablePath()
 {
-    static char readLinkBuffer[PATH_MAX];
-    ssize_t result = readlink("/proc/curproc/file", readLinkBuffer, PATH_MAX);
-    if (result == -1)
-        return { };
-    return CString(readLinkBuffer, result);
+    return { };
 }
 #elif OS(WINDOWS)
 CString currentExecutablePath()
