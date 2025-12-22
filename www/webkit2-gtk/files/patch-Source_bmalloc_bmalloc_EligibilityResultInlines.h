--- Source/bmalloc/bmalloc/EligibilityResultInlines.h.orig	2025-08-08 09:17:56 UTC
+++ Source/bmalloc/bmalloc/EligibilityResultInlines.h
@@ -41,7 +41,7 @@ EligibilityResult<Config>::EligibilityResult(IsoPage<C
 
 template<typename Config>
 EligibilityResult<Config>::EligibilityResult(IsoPage<Config>* page)
-    : kind(EligibilityKind::Success)
+    : kind(EligibilityKind::BmSuccess)
     , page(page)
 {
 }
