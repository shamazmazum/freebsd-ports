--- src/Boot.cpp.orig	2024-07-05 19:31:14 UTC
+++ src/Boot.cpp
@@ -48,7 +48,7 @@ static fs::path FindGameData()
 	dataPath = pathbuf;
 	dataPath = dataPath.parent_path().parent_path() / "Resources";
 #else
-	dataPath = "Data";
+	dataPath = "%%DATADIR%%";
 #endif
 
 	dataPath = dataPath.lexically_normal();
