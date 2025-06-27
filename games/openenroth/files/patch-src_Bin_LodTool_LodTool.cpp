--- src/Bin/LodTool/LodTool.cpp.orig	2025-06-25 22:14:11 UTC
+++ src/Bin/LodTool/LodTool.cpp
@@ -82,10 +82,10 @@ int runDump(const LodToolOptions &options) {
 int runDump(const LodToolOptions &options) {
     LodReader reader(options.lodPath, LOD_ALLOW_DUPLICATES);
 
-    fmt::println("Lod file: {}", options.lodPath);
-    fmt::println("Version: {}", toString(reader.info().version));
-    fmt::println("Description: {}", reader.info().description);
-    fmt::println("Root folder: {}", reader.info().rootName);
+    fmt::print("Lod file: {}\n", options.lodPath);
+    fmt::print("Version: {}\n", toString(reader.info().version));
+    fmt::print("Description: {}\n", reader.info().description);
+    fmt::print("Root folder: {}\n", reader.info().rootName);
 
     for (const std::string &name : reader.ls()) {
         Blob data = reader.read(name);
@@ -94,17 +94,17 @@ int runDump(const LodToolOptions &options) {
         if (isCompressed)
             data = lod::decodeCompressed(data);
 
-        fmt::println("");
-        fmt::println("Entry: {}", name);
-        fmt::println("Format: {}", toString(lod::magic(data, name)));
-        fmt::println("Size{}: {}", isCompressed ? " (uncompressed)" : "", data.size());
-        fmt::println("Data{}:", isCompressed ? " (uncompressed)" : "");
+        fmt::print("\n");
+        fmt::print("Entry: {}\n", name);
+        fmt::print("Format: {}\n", toString(lod::magic(data, name)));
+        fmt::print("Size{}: {}\n", isCompressed ? " (uncompressed)" : "", data.size());
+        fmt::print("Data{}\n:", isCompressed ? " (uncompressed)" : "");
 
         std::string line;
         for (size_t offset = 0; offset < data.size(); offset += 16) {
             std::string_view chunk = data.string_view().substr(offset, 16);
 
-            fmt::println("    {:08X}: {: <40}  {}", offset, toHexDump(chunk), ascii::toPrintable(chunk, '.'));
+            fmt::print("    {:08X}: {: <40}  {}\n", offset, toHexDump(chunk), ascii::toPrintable(chunk, '.'));
         }
     }
 
