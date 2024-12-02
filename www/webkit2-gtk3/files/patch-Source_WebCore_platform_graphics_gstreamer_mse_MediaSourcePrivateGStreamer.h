--- Source/WebCore/platform/graphics/gstreamer/mse/MediaSourcePrivateGStreamer.h.orig	2024-12-02 10:53:04 UTC
+++ Source/WebCore/platform/graphics/gstreamer/mse/MediaSourcePrivateGStreamer.h
@@ -94,12 +94,12 @@ class MediaSourcePrivateGStreamer final : public Media
     Ref<const Logger> m_logger;
     const void* m_logIdentifier;
     uint64_t m_nextSourceBufferID { 0 };
+#endif
 
     // Stores known track IDs, so we can work around ID collisions between multiple source buffers.
     // The registry is placed here to enforce ID uniqueness specifically by player, not by process,
     // since its not an issue if multiple players use the same ID, and we want to preserve IDs as much as possible.
     HashSet<TrackID, WTF::IntHash<TrackID>, WTF::UnsignedWithZeroKeyHashTraits<TrackID>> m_trackIdRegistry;
-#endif
 };
 
 } // namespace WebCore
