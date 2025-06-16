--- code/renderercommon/tr_image_jpg.c.orig	2025-01-04 17:01:52 UTC
+++ code/renderercommon/tr_image_jpg.c
@@ -35,6 +35,7 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #ifdef USE_INTERNAL_JPEG
 #  define JPEG_INTERNALS
 #endif
+#undef JPEG_INTERNALS
 
 #include <jpeglib.h>
 
