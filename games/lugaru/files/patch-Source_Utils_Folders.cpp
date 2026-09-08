--- Source/Utils/Folders.cpp.orig	2026-09-08 07:06:05 UTC
+++ Source/Utils/Folders.cpp
@@ -36,7 +36,7 @@ along with Lugaru.  If not, see <http://www.gnu.org/li
 #include <windows.h>
 #endif
 
-const std::string Folders::dataDir = DATA_DIR;
+const std::string Folders::dataDir = "%%DATA_DIR%%";
 
 std::string Folders::getScreenshotDir()
 {
