--- src/save_load.cpp.orig	2025-12-09 18:56:31 UTC
+++ src/save_load.cpp
@@ -1,5 +1,7 @@
 #include <cctype>
 #include <cstring>
+#include <filesystem>
+#include <format>
 
 // Include OS-dependend stuff for "mkdir".
 #ifdef _WIN32
@@ -13,8 +15,8 @@ using namespace ChasmReverse;
 using namespace ChasmReverse;
 
 #include "log.hpp"
-
 #include "save_load.hpp"
+#include "chasm_directory.hpp"
 
 #define SAVES_DIR "saves"
 
@@ -179,21 +181,24 @@ bool LoadSaveComment(
 	return true;
 }
 
+
 void GetSaveFileNameForSlot(
 	const unsigned int slot_number,
 	char* const out_file_name,
 	const unsigned int out_file_name_max_length )
 {
-	std::snprintf( out_file_name, out_file_name_max_length, SAVES_DIR"/save_%02d.pcs", slot_number );
+	namespace fs = std::filesystem;
+	std::string savename = std::format ("save_{:02}.pcs", slot_number);
+	fs::path save (SAVES_DIR);
+	save /= fs::path (savename);
+	std::snprintf( out_file_name, out_file_name_max_length, "%s", GetChasmPath(save).c_str());
 }
 
 void CreateSlotSavesDir()
 {
-#ifdef _WIN32
-	_mkdir( SAVES_DIR );
-#else
-	mkdir( SAVES_DIR, 0777 );
-#endif
+	namespace fs = std::filesystem;
+	fs::path dir (GetChasmPath (SAVES_DIR));
+	fs::create_directories (dir);
 }
 
 } // namespace PanzerChasm
