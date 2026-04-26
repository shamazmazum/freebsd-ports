--- src/Media/MediaPlayer.cpp.orig	2026-02-17 22:13:45 UTC
+++ src/Media/MediaPlayer.cpp
@@ -75,7 +75,7 @@ class AVStreamWrapper {
         dec = nullptr;
         if (dec_ctx != nullptr) {
             // Close the codec
-            avcodec_close(dec_ctx);
+            avcodec_free_context(&dec_ctx);
             logger->trace("ffmpeg: close decoder context file");
             dec_ctx = nullptr;
         }
