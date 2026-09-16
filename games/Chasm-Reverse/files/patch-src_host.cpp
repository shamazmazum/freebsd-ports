--- src/host.cpp.orig	2026-09-16 15:07:55 UTC
+++ src/host.cpp
@@ -91,7 +91,7 @@ Host::Host( const int argc, const char* const* const a
 	{
 		Log::Info( "Read game archive" );
 
-		const char* csm_file= "CSM.BIN";
+		const char* csm_file= "%%DATADIR%%/CSM.BIN";
 		if( const char* const overrided_csm_file = program_arguments_.GetParamValue( "csm" ) )
 		{
 			csm_file= overrided_csm_file;
@@ -526,7 +526,7 @@ void Host::DoVidRestart()
 	{
 		r_OGLStateManager::ResetState();
 
-		rSetShadersDir( "shaders" );
+		rSetShadersDir( "%%DATADIR%%/shaders" );
 		{
 			const auto shaders_log_callback=
 			[]( const char* const log_data )
