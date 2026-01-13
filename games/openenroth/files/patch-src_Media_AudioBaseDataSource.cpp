--- src/Media/AudioBaseDataSource.cpp.orig	2025-12-19 21:35:54 UTC
+++ src/Media/AudioBaseDataSource.cpp
@@ -88,7 +88,7 @@ void AudioBaseDataSource::Close() {
     }
 
     if (pCodecContext) {
-        avcodec_close(pCodecContext);
+        avcodec_free_context(&pCodecContext);
         pCodecContext = nullptr;
     }
 
