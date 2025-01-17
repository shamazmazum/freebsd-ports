--- src/compiler/array-tran.lisp.orig	2024-12-29 10:12:03 UTC
+++ src/compiler/array-tran.lisp
@@ -2168,9 +2168,10 @@
            ;; correctly. We can wrap all the interior arithmetic with
            ;; TRULY-THE INDEX because we know the resultant
            ;; row-major index must be an index.
-           (with-row-major-index ((array indices index &optional new-value)
-                                  &rest body)
-             `(let (n-indices dims)
+           (with-row-major-index ((node array indices index &optional new-value)
+                  &rest body)
+             `(let ((bounds-check-p (policy ,node (plusp insert-array-bounds-checks)))
+                    n-indices dims)
                 (dotimes (i (length ,indices))
                   (push (make-symbol (format nil "INDEX-~D" i)) n-indices)
                   (push (make-symbol (format nil "DIM-~D" i)) dims))
@@ -2191,35 +2192,40 @@
                                 (do* ((dims dims (cdr dims))
                                       (indices n-indices (cdr indices))
                                       (last-dim nil (car dims))
-                                      (form `(check-bound ,',array
-                                                          ,(car dims)
-                                                          ,(car indices))
+                                      (form (if bounds-check-p
+                                                `(check-bound ,',array
+                                                              ,(car dims)
+                                                              ,(car indices))
+                                                `(identity ,(car indices)))
                                             `(truly-the
-                                              index
-                                              (+ (truly-the index
-                                                            (* ,form
-                                                               ,last-dim))
-                                                 (check-bound
-                                                  ,',array
-                                                  ,(car dims)
-                                                  ,(car indices))))))
-                                    ((null (cdr dims)) form)))))
+                                                 index
+                                               (+ (truly-the index
+                                                    (* ,form
+                                                       ,last-dim))
+                                                  ,(if bounds-check-p
+                                                       `(check-bound
+                                                         ,',array
+                                                         ,(car dims)
+                                                         ,(car indices))
+                                                       `(identity ,(car indices)))))))
+                                     ((null (cdr dims)) form)))))
+                     (declare (ignorable ,@dims))
                      ,',@body)))))
 
   ;; Just return the index after computing it.
-  (deftransform array-row-major-index ((array &rest indices))
-    (with-row-major-index (array indices index)
+  (deftransform array-row-major-index ((array &rest indices) (t &rest t) * :node node)
+    (with-row-major-index (node array indices index)
       index))
 
   ;; Convert AREF and (SETF AREF) into a HAIRY-DATA-VECTOR-REF (or
   ;; HAIRY-DATA-VECTOR-SET) with the set of indices replaced with the an
   ;; expression for the row major index.
-  (deftransform aref ((array &rest indices))
-    (with-row-major-index (array indices index)
+  (deftransform aref ((array &rest indices) (t &rest t) * :node node)
+    (with-row-major-index (node array indices index)
       (hairy-data-vector-ref array index)))
 
-  (deftransform (setf aref) ((new-value array &rest subscripts))
-    (with-row-major-index (array subscripts index new-value)
+  (deftransform (setf aref) ((new-value array &rest subscripts) (t t &rest t) * :node node)
+    (with-row-major-index (node array subscripts index new-value)
       (hairy-data-vector-set array index new-value))))
 
 ;; For AREF of vectors we do the bounds checking in the callee. This
