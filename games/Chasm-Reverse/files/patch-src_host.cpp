--- src/host.cpp.orig	2025-12-09 18:56:31 UTC
+++ src/host.cpp
@@ -1,5 +1,5 @@
 #include <cstring>
-
+#include <climits>
 #include <framebuffer.hpp>
 #include <glsl_program.hpp>
 #include <ogl_state_manager.hpp>
@@ -13,6 +13,7 @@
 #include "log.hpp"
 #include "map_loader.hpp"
 #include "shared_drawers.hpp"
+#include "chasm_directory.hpp"
 #include "save_load.hpp"
 #include "sound/sound_engine.hpp"
 
@@ -66,7 +67,7 @@ Host::Host( const int argc, const char* const* const a
 
 Host::Host( const int argc, const char* const* const argv )
 	: program_arguments_( argc, argv )
-	, settings_( "PanzerChasm.cfg" )
+	, settings_( GetChasmPath ("PanzerChasm.cfg").c_str() )
 	, commands_processor_( settings_ )
 {
 	{ // Register host commands
@@ -91,7 +92,7 @@ Host::Host( const int argc, const char* const* const a
 	{
 		Log::Info( "Read game archive" );
 
-		const char* csm_file= "CSM.BIN";
+		const char* csm_file= "%%DATADIR%%/CSM.BIN";
 		if( const char* const overrided_csm_file = program_arguments_.GetParamValue( "csm" ) )
 		{
 			csm_file= overrided_csm_file;
@@ -398,7 +399,7 @@ void Host::GetSavesNames( SavesNames& out_saves_names 
 	{
 		SaveComment& out_save_comment= out_saves_names[slot];
 
-		char file_name[32];
+		char file_name[PATH_MAX];
 		GetSaveFileNameForSlot( slot, file_name, sizeof(file_name) );
 
 		if( LoadSaveComment( file_name, out_save_comment ) )
@@ -526,7 +527,7 @@ void Host::DoVidRestart()
 	{
 		r_OGLStateManager::ResetState();
 
-		rSetShadersDir( "shaders" );
+		rSetShadersDir( "%%DATADIR%%/shaders" );
 		{
 			const auto shaders_log_callback=
 			[]( const char* const log_data )
