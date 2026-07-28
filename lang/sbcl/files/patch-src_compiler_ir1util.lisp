--- src/compiler/ir1util.lisp.orig	2026-07-17 09:29:03 UTC
+++ src/compiler/ir1util.lisp
@@ -2582,10 +2582,13 @@
                    (let ((first (first path)))
                      (or (eq first 'original-source-start)
                          (and (atom first)
+                              #+nil
                               (or (not (symbolp first))
                                   (let ((pkg (cl:symbol-package first)))
                                     (and pkg (neq pkg *keyword-package*))))
+                              #+nil
                               (not (member first '(t nil)))
+                              #+nil
                               (not (cl:typep first '(or fixnum character
                                                      #+64-bit single-float)))
                               (every (lambda (x)
