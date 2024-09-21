--- Source/ThirdParty/libsysprof-capture/sysprof-platform.c.orig	2024-09-21 16:17:48 UTC
+++ Source/ThirdParty/libsysprof-capture/sysprof-platform.c
@@ -60,6 +60,7 @@
 #include <stdlib.h>
 #include <sys/syscall.h>
 #include <unistd.h>
+#include <fcntl.h>
 
 #include "sysprof-capture-util-private.h"
 #include "sysprof-platform.h"
@@ -132,7 +133,7 @@ sysprof_memfd_create (const char *name)
 #ifdef __APPLE__
   flags = 0;
 #else
-  flags = O_BINARY | O_CLOEXEC;
+  flags = O_CLOEXEC;
 #endif
 
   fd = TEMP_FAILURE_RETRY (mkostemp (template, flags));
