--- src/3d/optimize.cpp.orig
+++ src/3d/optimize.cpp
@@ -2167,7 +2167,7 @@ void CastArbitraryShadow(int x,int y,int zg,int size,int shift,unsigned char* bu
 	x0 = SHL16(X1) - x_bmp_corner_16;
 	y0 = (Y0 << 16) - y_bmp_corner_16;
 	dx0 = 0;
-	dy0 = dy <= 0 ? 1 << 16 : -1 << 16;
+	dy0 = dy <= 0 ? 1 << 16 : -(1 << 16);
 	bmp_len = 0;
 	d_bmp_len = d_1_y;
