--- Source/WebCore/platform/MediaSample.h.orig	2024-08-19 06:28:39 UTC
+++ Source/WebCore/platform/MediaSample.h
@@ -42,6 +42,11 @@ namespace WebCore {
 typedef const struct opaqueCMFormatDescription *CMFormatDescriptionRef;
 
 namespace WebCore {
+template<class _T1, class _T2>
+struct mypair {
+    _T1 x; _T2 y;
+    mypair() : x(), y() { }
+};
 
 class FragmentedSharedBuffer;
 class MockSampleBox;
@@ -63,7 +68,7 @@ struct PlatformSample {
         const MockSampleBox* mockSampleBox;
         CMSampleBufferRef cmSampleBuffer;
         GstSample* gstSample;
-        std::pair<MTPluginByteSourceRef, std::reference_wrapper<const TrackInfo>> byteRangeSample;
+        mypair<MTPluginByteSourceRef, std::reference_wrapper<const TrackInfo>> byteRangeSample;
     } sample;
 };
 
