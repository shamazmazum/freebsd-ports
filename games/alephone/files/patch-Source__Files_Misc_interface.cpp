--- Source_Files/Misc/interface.cpp.old	2018-12-08 19:45:11.741197000 +0300
+++ Source_Files/Misc/interface.cpp	2018-12-08 19:44:48.700131000 +0300
@@ -150,7 +150,7 @@
 #include "Statistics.h"
 
 #ifdef HAVE_SMPEG
-#include <smpeg/smpeg.h>
+#include <smpeg2/smpeg.h>
 #endif
 #ifdef HAVE_FFMPEG
 #include "SDL_ffmpeg.h"
