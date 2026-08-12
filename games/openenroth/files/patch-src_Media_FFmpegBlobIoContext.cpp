--- src/Media/FFmpegBlobIoContext.cpp.orig	2026-07-15 21:30:22 UTC
+++ src/Media/FFmpegBlobIoContext.cpp
@@ -10,6 +10,8 @@ extern "C" {
 #include <libavutil/mem.h> // NOLINT: not a C system header.
 }
 
+#define AV_INPUT_BUFFER_MIN_SIZE 16384
+
 int ffRead(void *opaque, uint8_t *buf, int size) {
     FFmpegBlobIoContext *ctx = static_cast<FFmpegBlobIoContext *>(opaque);
     size_t bytes = ctx->_stream.read(buf, static_cast<size_t>(size));
