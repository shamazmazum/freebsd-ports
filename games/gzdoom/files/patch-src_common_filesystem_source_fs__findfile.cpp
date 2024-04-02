--- src/common/filesystem/source/fs_findfile.cpp.orig	2024-04-02 13:06:21 UTC
+++ src/common/filesystem/source/fs_findfile.cpp
@@ -65,7 +65,6 @@ enum
 
 #include <limits.h>
 #include <stdlib.h>
-#include <unistd.h>
 #include <fnmatch.h>
 #include <sys/stat.h>
 
