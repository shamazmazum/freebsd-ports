--- Source/Utils/Folders.cpp.orig	2020-04-21 07:50:34.476506000 +0300
+++ Source/Utils/Folders.cpp	2020-04-21 07:54:42.422477000 +0300
@@ -36,7 +36,7 @@
 #include <windows.h>
 #endif
 
-const std::string Folders::dataDir = DATA_DIR;
+const std::string Folders::dataDir = "%%DATA_DIR%%";
 
 std::string Folders::getScreenshotDir()
 {
