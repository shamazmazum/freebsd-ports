--- code/gamespy/common/gsPlatform.h.orig	2025-01-04 17:01:52 UTC
+++ code/gamespy/common/gsPlatform.h
@@ -23,7 +23,9 @@
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 // Set the platform define
-#ifdef __mips64
+#if defined (__linux__) || defined(_LINUX) || defined(_MACOSX) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+	#define _UNIX
+#elif __mips64
 	#ifndef _PS2
 		#define _PS2
 	#endif
@@ -32,10 +34,6 @@
 	#if !defined(SN_SYSTEMS) && !defined(EENET) && !defined(INSOCK)
 		#error "PlayStation2 network stack was not defined!"
 	#endif
-#endif
-
-#if defined(_LINUX) || defined(_MACOSX) || defined(__APPLE__)
-	#define _UNIX
 #endif
 
 #if defined(_XBOX) || defined (_X360)
