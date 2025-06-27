--- src/Bin/CodeGen/CodeGen.cpp.orig	2025-06-25 22:14:11 UTC
+++ src/Bin/CodeGen/CodeGen.cpp
@@ -188,7 +188,7 @@ int runBeaconsCodeGen(const CodeGenOptions &options, G
         if (!fileName.ends_with(".odm") && !fileName.ends_with(".blv"))
             continue; // Not a level file.
 
-        fmt::println("    {{MAP_{}, {}}},", mapIdEnumName(mapInfoByFileName(mapStats, fileName)), i);
+        fmt::print("    {{MAP_{}, {}}},\n", mapIdEnumName(mapInfoByFileName(mapStats, fileName)), i);
     }
 
     return 0;
