--- Source/WebCore/platform/MediaSample.h.orig	2025-01-29 14:32:09 UTC
+++ Source/WebCore/platform/MediaSample.h
@@ -42,7 +42,24 @@ namespace WebCore {
 typedef const struct opaqueCMFormatDescription *CMFormatDescriptionRef;
 
 namespace WebCore {
+template<class _T1, class _T2>
+struct mypair {
+    typedef _T1 first_type;    ///<  @c first_type is the first bound type
+    typedef _T2 second_type;   ///<  @c second_type is the second bound type
 
+    _T1 first;                 ///< @c first is a copy of the first object
+    _T2 second;                ///< @c second is a copy of the second object
+
+    // _GLIBCXX_RESOLVE_LIB_DEFECTS
+    // 265.  std::pair::pair() effects overly restrictive
+    /** The default constructor creates @c first and @c second using their
+     *  respective default constructors.  */
+    mypair() : first(), second() { }
+ 
+    /** Two objects may be passed to a @c pair constructor to be copied.  */
+    mypair(const _T1& __a, const _T2& __b) : first(__a), second(__b) { }
+};
+
 class FragmentedSharedBuffer;
 class MockSampleBox;
 class ProcessIdentity;
@@ -63,7 +80,7 @@ struct PlatformSample {
         const MockSampleBox* mockSampleBox;
         CMSampleBufferRef cmSampleBuffer;
         GstSample* gstSample;
-        std::pair<MTPluginByteSourceRef, std::reference_wrapper<const TrackInfo>> byteRangeSample;
+        mypair<MTPluginByteSourceRef, std::reference_wrapper<const TrackInfo>> byteRangeSample;
     } sample;
 };
 
