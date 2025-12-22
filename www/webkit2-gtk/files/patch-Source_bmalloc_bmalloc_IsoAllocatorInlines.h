--- Source/bmalloc/bmalloc/IsoAllocatorInlines.h.orig	2025-08-08 09:17:56 UTC
+++ Source/bmalloc/bmalloc/IsoAllocatorInlines.h
@@ -78,7 +78,7 @@ BNO_INLINE void* IsoAllocator<Config>::allocateSlow(Is
     BASSERT(allocationMode == AllocationMode::Fast);
     
     EligibilityResult<Config> result = heap.takeFirstEligible(locker);
-    if (result.kind != EligibilityKind::Success) {
+    if (result.kind != EligibilityKind::BmSuccess) {
         RELEASE_BASSERT(result.kind == EligibilityKind::OutOfMemory);
         RELEASE_BASSERT(!abortOnFailure);
         return nullptr;
