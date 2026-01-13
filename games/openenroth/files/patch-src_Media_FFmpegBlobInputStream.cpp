--- src/Media/FFmpegBlobInputStream.cpp.orig	2026-01-13 09:33:28 UTC
+++ src/Media/FFmpegBlobInputStream.cpp
@@ -67,6 +67,8 @@ void FFmpegBlobInputStream::closeInternal() {
     _ctx = nullptr;
 }
 
+#define AV_INPUT_BUFFER_MIN_SIZE 16384
+
 void FFmpegBlobInputStream::resetContext() {
     closeInternal();
     unsigned char* buffer = static_cast<unsigned char*>(av_malloc(AV_INPUT_BUFFER_MIN_SIZE));
