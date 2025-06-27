--- src/Bin/CodeGen/CodeGenFunctions.h.orig	2025-06-25 22:14:11 UTC
+++ src/Bin/CodeGen/CodeGenFunctions.h
@@ -42,6 +42,6 @@ void dumpAligned(FILE *file, std::string_view prefix, 
         }
         while (output.ends_with(' ')) // Note that we don't trim front.
             output.pop_back();
-        fmt::println(file, "{}", output);
+        fmt::print(file, "{}\n", output);
     }
 }
