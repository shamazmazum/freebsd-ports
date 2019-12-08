--- src/uvs/diagen.cpp.orig
+++ src/uvs/diagen.cpp
@@ -595,7 +595,8 @@ int getSpectorsTaskStatus(void)
 	int i,j,res;
 	for(i = 0;i < 4;i++)
 		for(j = 0;j < 7;j++)
-			if(res = getPassangerStats(es[j],ws[i])){
+			// (shamaz) was: if(res = getPassangerStats(es[j],ws[i])){
+			if(getPassangerStats(es[j],ws[i])) {
 				esS[j] = '\0';
 				wsS[i] = '\0';
 				}
