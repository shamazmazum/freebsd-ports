--- idlib/Str.h.orig	2026-08-27 06:33:38 UTC
+++ idlib/Str.h
@@ -40,6 +40,7 @@ If you have questions concerning this license or the a
 */
 
 // these library functions should not be used for cross platform compatibility
+#if 0
 #ifndef IDSTR_NO_REDIRECT
 #define strcmp			idStr::Cmp		// use_idStr_Cmp
 #define strncmp			use_idStr_Cmpn
@@ -83,6 +84,7 @@ If you have questions concerning this license or the a
 #define _snprintf		use_idStr_snPrintf
 #define vsnprintf		use_idStr_vsnPrintf
 #define _vsnprintf		use_idStr_vsnPrintf
+#endif
 #endif
 
 class idVec4;
