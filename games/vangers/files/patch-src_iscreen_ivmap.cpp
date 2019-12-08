--- src/iscreen/ivmap.cpp.orig
+++ src/iscreen/ivmap.cpp
@@ -12,6 +12,7 @@
 
 #include <iostream>
 
+#undef YCYCL
 #define YCYCL(y)	((y) & iclip_mask_y)
 
 
