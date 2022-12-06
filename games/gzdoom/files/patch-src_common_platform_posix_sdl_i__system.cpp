--- src/common/platform/posix/sdl/i_system.cpp.orig	2022-12-04 14:35:20 UTC
+++ src/common/platform/posix/sdl/i_system.cpp
@@ -47,13 +47,18 @@
 #include <unistd.h>
 #include <sys/ioctl.h>
 
-#ifdef __linux__
+#if defined(__linux__)
 #include <asm/unistd.h>
 #include <linux/perf_event.h>
 #include <sys/mman.h>
 #include "printf.h"
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include "printf.h"
+#endif
+
 #include <SDL.h>
 
 #include "version.h"
@@ -408,7 +413,7 @@ FString I_GetFromClipboard (bool use_primary_selection
 
 FString I_GetCWD()
 {
-	char* curdir = get_current_dir_name();
+	char* curdir = getcwd(NULL, MAXPATHLEN);
 	if (!curdir) 
 	{
 		return "";
@@ -447,7 +452,7 @@ unsigned int I_MakeRNGSeed()
 
 void I_OpenShellFolder(const char* infolder)
 {
-	char* curdir = get_current_dir_name();
+	char* curdir = getcwd(NULL, MAXPATHLEN);
 
 	if (!chdir(infolder))
 	{
