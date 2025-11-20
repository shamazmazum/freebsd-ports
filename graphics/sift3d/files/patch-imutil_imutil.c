--- imutil/imutil.c.orig	2025-11-20 16:26:32 UTC
+++ imutil/imutil.c
@@ -848,7 +848,7 @@ int resize_Mat_rm(Mat_rm *const mat) {
     const int num_rows = mat->num_rows;
     const int num_cols = mat->num_cols;
     double **const data = &mat->u.data_double;
-    const size_t numel = num_rows * num_cols;
+    const size_t numel = (size_t)num_rows * (size_t)num_cols;
     const Mat_rm_type type = mat->type;
 
     // Get the size of the underyling datatype
@@ -1530,7 +1530,7 @@ int im_resize(Image *const im)
 	int i;
 
 	//FIXME: This will not work for strange strides
-	const size_t size = im->nx * im->ny * im->nz * im->nc;
+	const size_t size = (size_t)im->nx * (size_t)im->ny * (size_t)im->nz * (size_t)im->nc;
 
 	// Verify inputs
 	for (i = 0; i < IM_NDIMS; i++) {
