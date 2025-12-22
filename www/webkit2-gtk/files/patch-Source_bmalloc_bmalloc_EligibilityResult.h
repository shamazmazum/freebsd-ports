--- Source/bmalloc/bmalloc/EligibilityResult.h.orig	2025-08-08 09:17:56 UTC
+++ Source/bmalloc/bmalloc/EligibilityResult.h
@@ -39,7 +39,7 @@ enum class EligibilityKind {
 namespace bmalloc {
 
 enum class EligibilityKind {
-    Success,
+    BmSuccess,
     Full,
     OutOfMemory
 };
@@ -51,7 +51,7 @@ struct EligibilityResult {
     EligibilityResult(EligibilityKind);
     EligibilityResult(IsoPage<Config>*);
     
-    EligibilityKind kind { EligibilityKind::Success };
+    EligibilityKind kind { EligibilityKind::BmSuccess };
     IsoPage<Config>* page { nullptr };
 };
 
