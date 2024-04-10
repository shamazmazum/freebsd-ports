--- Source/cmake/GStreamerChecks.cmake.orig	2023-10-13 15:24:28.435740000 +0000
+++ Source/cmake/GStreamerChecks.cmake	2023-10-13 15:24:44.212487000 +0000
@@ -58,9 +58,9 @@
               message(FATAL_ERROR "GStreamerGL is needed for USE_GSTREAMER_GL.")
           endif ()

-          if (ENABLE_MEDIA_RECORDER AND USE_GSTREAMER_TRANSCODER AND (NOT PC_GSTREAMER_TRANSCODER_FOUND OR PC_GSTREAMER_TRANSCODER_VERSION VERSION_LESS "1.20"))
-              message(FATAL_ERROR "GStreamerTranscoder >= 1.20 is needed for USE_GSTREAMER_TRANSCODER.")
-          endif ()
+#          if (ENABLE_MEDIA_RECORDER AND USE_GSTREAMER_TRANSCODER AND (NOT PC_GSTREAMER_TRANSCODER_FOUND OR PC_GSTREAMER_TRANSCODER_VERSION VERSION_LESS "1.20"))
+#              message(FATAL_ERROR "GStreamerTranscoder >= 1.20 is needed for USE_GSTREAMER_TRANSCODER.")
+#          endif ()

           if (USE_GSTREAMER_WEBRTC AND (PC_GSTREAMER_VERSION VERSION_LESS "1.20" OR NOT PC_GSTREAMER_WEBRTC_FOUND))
               message(FATAL_ERROR "GStreamerWebRTC >= 1.20 is needed for USE_GSTREAMER_WEBRTC.")
