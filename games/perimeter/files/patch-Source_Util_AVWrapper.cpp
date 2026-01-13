--- Source/Util/AVWrapper.cpp.orig	2024-05-11 10:43:20 UTC
+++ Source/Util/AVWrapper.cpp
@@ -25,7 +25,7 @@ size_t AVWrapperFrame::getBufferSize() const {
     } else if (AVWrapperType::Audio) {
         AVSampleFormat format = static_cast<AVSampleFormat>(frame->format);
         //return av_samples_get_buffer_size(nullptr, frame->channels, frame->nb_samples, format, 1);
-        int planes = av_sample_fmt_is_planar(format) ? frame->channels : 1;
+        int planes = av_sample_fmt_is_planar(format) ? frame->ch_layout.nb_channels : 1;
         return frame->linesize[0] * planes;
     } else {
         xassert(0);
@@ -49,9 +49,9 @@ size_t AVWrapperFrame::copyBuffer(uint8_t** buffer) co
         return buffer_size;
     } else if (AVWrapperType::Audio) {
         AVSampleFormat format = static_cast<AVSampleFormat>(frame->format);
-        if (av_sample_fmt_is_planar(format) && 1 < frame->channels) {
+        if (av_sample_fmt_is_planar(format) && 1 < frame->ch_layout.nb_channels) {
             //We need to pack planar audio
-            int planes = frame->channels;
+            int planes = frame->ch_layout.nb_channels;
             size_t bytes_sample = av_get_bytes_per_sample(format);
             xassert(buffer_size == frame->linesize[0] * planes);
             //Store each plane sample as interleaved
@@ -708,11 +708,19 @@ int AVWrapper::getVideoWidth() const {
 }
 
 int AVWrapper::getVideoWidth() const {
+#ifdef PERIMETER_FFMPEG_MOVIE
     return swsCtx ? swsWidth : videoCodecCtx->width;
+#else
+    return 0;
+#endif
 }
 
 int AVWrapper::getVideoHeight() const {
+#ifdef PERIMETER_FFMPEG_MOVIE
     return swsCtx ? swsHeight : videoCodecCtx->height;
+#else
+    return 0;
+#endif
 }
 
 int AVWrapper::getVideoBPP() const {
@@ -772,4 +780,4 @@ AVSampleFormat AVWrapper::fromSDLAudioFormat(SDL_Audio
     return result;
 }
 
-#endif //PERIMETER_FFMPEG
\ No newline at end of file
+#endif //PERIMETER_FFMPEG
