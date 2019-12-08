--- src/particle/bmp2scr.cpp.orig
+++ src/particle/bmp2scr.cpp
@@ -554,12 +554,12 @@ void smart_putspr_f(unsigned char* data,int Xcenter,int Ycenter,int XsizeB,int Y
 	int xt = X + XsizeS;
 	int yt = Y + YsizeS;
 	if(X < UcutLeft){
-		bx = (UcutLeft - X << 15)*XsizeB/ScaleXsize;
+		bx = ((UcutLeft - X) << 15)*XsizeB/ScaleXsize;
 		XsizeS -= UcutLeft - X;
 		X = UcutLeft;
 		}
 	if(Y < VcutUp){
-		by = (VcutUp - Y << 15)*XsizeB/ScaleXsize;
+		by = ((VcutUp - Y) << 15)*XsizeB/ScaleXsize;
 		YsizeS -= VcutUp - Y;
 		Y = VcutUp;
 		}
