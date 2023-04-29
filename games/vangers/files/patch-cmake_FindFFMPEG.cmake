--- cmake/FindFFMPEG.cmake.orig	2023-04-29 11:16:08 UTC
+++ cmake/FindFFMPEG.cmake
@@ -6,6 +6,8 @@
 # FFMPEG_LIBRARIES
 #
 
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
+
 FIND_PATH(AVUTIL_INCLUDE_DIR
 	NAMES
 		avutil.h
