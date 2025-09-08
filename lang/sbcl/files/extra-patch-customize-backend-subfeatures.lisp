--- customize-backend-subfeatures.lisp.orig	2025-09-08 18:22:44 UTC
+++ customize-backend-subfeatures.lisp
@@ -0,0 +1 @@
+(lambda (x) (declare (ignore x)) '(:popcnt :sse4))
