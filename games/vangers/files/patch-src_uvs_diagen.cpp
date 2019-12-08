--- src/uvs/diagen.cpp.orig
+++ src/uvs/diagen.cpp
@@ -158,9 +158,10 @@ char* ConvertUTF8(const char* s,int back = 0) {
 	int len = strlen(s);
 	buffer = new char[len+2];
 	memset( buffer, 0, len+2);
-	dual_char dc;
-	bool get_dual=false;
-	int i_dual_char=0, i;
+	//dual_char dc;
+	//bool get_dual=false;
+	int i;
+	// int i_dual_char=0;
 	if (!back)
 		for (i=0;i<len;i++)
 			{
@@ -595,7 +596,7 @@ int getSpectorsTaskStatus(void)
 	int i,j,res;
 	for(i = 0;i < 4;i++)
 		for(j = 0;j < 7;j++)
-			if(res = getPassangerStats(es[j],ws[i])){
+			if(getPassangerStats(es[j],ws[i])){
 				esS[j] = '\0';
 				wsS[i] = '\0';
 				}
@@ -2291,7 +2292,8 @@ void dgRoom::load(XStream& ff)
 	ff > visitCounter > comingCounter;
 
 	char buf[256];
-	int n = gridSX*gridSY,i,ind;
+	int i, ind;
+//	int n = gridSX*gridSY;
 	short cnt;
 	uchar l;
 
@@ -2424,7 +2426,6 @@ void DiagenDispatcher::init(void)
 #endif	
 	dgFile* pf = new dgFile(getDGname("room",".lst"));
 	
-	char* p = NULL;
 	dgRoom* pr;
 	int i,j;
 	int max  = oldVersion ? 8 : DG_ESCAVE_MAX;
