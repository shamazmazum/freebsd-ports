--- code/sys/sys_main.c.orig	2025-06-17 16:44:57 UTC
+++ code/sys/sys_main.c
@@ -810,7 +810,7 @@ int main( int argc, char **argv )
 #endif
 
 	Sys_ParseArgs( argc, argv );
-	Sys_SetBinaryPath( Sys_Dirname( argv[ 0 ] ) );
+	Sys_SetBinaryPath( %%BINARYPATH%% );
 	Sys_SetDefaultInstallPath( DEFAULT_BASEDIR );
 
 	// Concatenate the command line for passing to Com_Init
