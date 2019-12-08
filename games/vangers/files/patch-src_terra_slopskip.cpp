--- src/terra/slopskip.cpp.orig
+++ src/terra/slopskip.cpp
@@ -122,10 +122,10 @@ void SlopTurnSkip(int Turn,int Slop,int H,int F,int cx,int cy,int xc,int yc,int
 		char* vpp = vp + XGR_MAXX*i;
 		int u = -XDstSize/2;
 		int v = -YDstSize/2 + i;
-		int z = v*Avz + F*Awz >> 16;
+		int z = (v*Avz + F*Awz) >> 16;
 		if(!z) z = 1;
-		fx = H*(u*Aux + v*Avx + F*Awx >> 4)/z << 4;
-		fy = H*(u*Auy + v*Avy + F*Awy >> 4)/z << 4;
+		fx = H*((u*Aux + v*Avx + F*Awx) >> 4)/z << 4;
+		fy = H*((u*Auy + v*Avy + F*Awy) >> 4)/z << 4;
 
 		k_xscr_x = H*Aux/z;
 		k_xscr_y = H*Auy/z;
