--- Modules/FindVorbisFile.cmake.orig	2020-04-21 06:59:49.414357000 +0300
+++ Modules/FindVorbisFile.cmake	2020-04-21 06:55:50.956913000 +0300
@@ -0,0 +1,12 @@
+FIND_PATH(VORBISFILE_INCLUDE_DIR NAMES vorbis/vorbisfile.h)
+MARK_AS_ADVANCED(VORBISFILE_INCLUDE_DIR)
+ 
+FIND_LIBRARY(VORBISFILE_LIBRARIES NAMES
+  vorbisfile
+  libvorbisfile
+  vorbisfilelib)
+MARK_AS_ADVANCED(VORBISFILE_LIBRARIES)
+ 
+INCLUDE(FindPackageHandleStandardArgs)
+FIND_PACKAGE_HANDLE_STANDARD_ARGS (VorbisFile DEFAULT_MSG
+                                   VORBISFILE_LIBRARIES VORBISFILE_INCLUDE_DIR)
