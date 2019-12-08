--- src/terra/vmap.cpp.orig
+++ src/terra/vmap.cpp
@@ -855,23 +855,31 @@ void vrtMap::load(const char* name,int nWorld)
 	if(KeepON) {
 		std::cout<<"KeepON"<<std::endl;
 		memset(keepT = new uchar[V_SIZE],0,V_SIZE);
-		int need = 0;
+		int need = 1;
 		if(kmap.open(kname,XS_IN)) {
-			if(kmap.size() != (int)(V_SIZE*H2_SIZE + V_SIZE),XS_BEG) { 
-				kmap.close(); need = 1;
+			/*
+			 * shamaz: Why XS_BEG is here?
+			 */
+			if(kmap.size() != (int)(V_SIZE*H2_SIZE + V_SIZE)/*,XS_BEG*/) { 
+				kmap.close();
 			} else {
 				kmap.seek(V_SIZE*H2_SIZE,XS_BEG);
 				kmap.read(keepT,V_SIZE);
+				need = 0;
 			}
-		} else {
-			need = 1;
 		}
+
 		if(need) {
 			kmap.open(kname,XS_OUT|XS_NOSHARING/*|XS_NOBUFFERING*/);
 			kmap.seek(V_SIZE*H2_SIZE,XS_BEG);
 			kmap.write(keepT,V_SIZE);
+			/*
+			 * shamaz: Why we need the next two lines?
+			 */
+#if 0
 			kmap.close();
 			kmap.open(kname,XS_OUT|XS_NOSHARING);
+#endif
 		}
 		kmap.close();
 		//std::cout<<"KMAP2!!!!"<<std::endl;
@@ -970,18 +978,18 @@ void vrtMap::reload(int nWorld)
 		fmap.open(fname,XS_IN | XS_OUT);
 #else
 	if(!fmap.open(fname,XS_IN|XS_NOSHARING)) ErrH.Abort("WorldData not found");
-	if(KeepON){
-		int need = 0;
-		if(kmap.open(kname,XS_IN)){
-			if(kmap.size() != (int)(V_SIZE*H2_SIZE + V_SIZE),XS_BEG){
-				kmap.close(); need = 1;
-				}
-			else {
+	if(KeepON) {
+		int need = 1;
+		if(kmap.open(kname,XS_IN)) {
+			if(kmap.size() != (int)(V_SIZE*H2_SIZE + V_SIZE)/*,XS_BEG*/) {
+				kmap.close();
+			} else {
 				kmap.seek(V_SIZE*H2_SIZE,XS_BEG);
 				kmap.read(keepT,V_SIZE);
-				}
+				need = 0;
 			}
-		else need = 1;
+		}
+
 		if(need){
 			/*NEED?int h = _open(kname,_O_BINARY|_O_CREAT|_O_WRONLY,_S_IREAD|_S_IWRITE);
 			if(_chsize(h,V_SIZE*H2_SIZE)){
@@ -997,11 +1005,11 @@ void vrtMap::reload(int nWorld
 			kmap.open(kname,XS_OUT|XS_NOSHARING/*|XS_NOBUFFERING*/);
 			kmap.seek(V_SIZE*H2_SIZE,XS_BEG);
 			kmap.write(keepT,V_SIZE);
-			}
+		}
 		kmap.close();
 		//std::cout<<"KMAP1!!!!"<<std::endl;
 		kmap.open(kname,XS_IN|XS_OUT|XS_NOSHARING/*|XS_NOBUFFERING*/);
-		}
+	}
 #endif
 
 #ifdef FILEMAPPING
@@ -2145,8 +2153,8 @@ void vrtMap::turning(int XSrcSize,int Turn,int cx,int cy,int xc,int yc,int XDstS
 	tfx = (cx << 16) - (XSrcSize*cosTurn - YSrcSize*sinTurn)/2 + (1 << 15);
 	int vv0 = XSrcSize*sinTurn;
 	int vv1 = YSrcSize*cosTurn;
-	int v0 = vv0 + vv1 >> 1;
-	int v1 = vv0 - vv1 >> 1;
+	int v0 = (vv0 + vv1) >> 1;
+	int v1 = (vv0 - vv1) >> 1;
 	int vcy = cy << 16;
 	
 	tfy = vcy - v0 + (1 << 15);
@@ -2254,8 +2262,8 @@ void vrtMap::turning(int XSrcSize,int Turn,int cx,int cy,int xc,int yc,int XDstS
 	tfx = (cx << 16) - (XSrcSize*cosTurn - YSrcSize*sinTurn)/2 + (1 << 15);
 	int vv0 = XSrcSize*sinTurn;
 	int vv1 = YSrcSize*cosTurn;
-	int v0 = vv0 + vv1 >> 1;
-	int v1 = vv0 - vv1 >> 1;
+	int v0 = (vv0 + vv1) >> 1;
+	int v1 = (vv0 - vv1) >> 1;
 	int vcy = cy << 16;
 	
 	tfy = vcy - v0 + (1 << 15);
@@ -2699,4 +2707,3 @@ void vrtMap::SlopTurnSkip(int Turn,int Slop,int H,int F,int cx,int cy,int xc,int
 	PerpSlopTurn(Turn,Slop,H,F,cx,cy,xc,yc,XDstSize,YDstSize);
 }
 #endif
-
