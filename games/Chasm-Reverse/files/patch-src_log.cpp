--- src/log.cpp.orig	2025-12-09 18:56:31 UTC
+++ src/log.cpp
@@ -1,12 +1,13 @@
 #include <SDL_messagebox.h>
 
+#include "chasm_directory.hpp"
 #include "log.hpp"
 
 namespace PanzerChasm
 {
 
 Log::LogCallback Log::log_callback_;
-std::ofstream Log::log_file_{ "panzer_chasm.log" };
+std::ofstream Log::log_file_{ GetChasmPath("panzer_chasm.log") };
 
 void Log::SetLogCallback( LogCallback callback )
 {
