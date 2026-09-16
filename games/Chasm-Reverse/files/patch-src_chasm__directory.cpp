--- src/chasm_directory.cpp.orig	2026-09-16 18:38:38 UTC
+++ src/chasm_directory.cpp
@@ -0,0 +1,24 @@
+#include <filesystem>
+#include <cstdlib>
+#include "chasm_directory.hpp"
+
+namespace PanzerChasm
+{
+
+namespace fs = std::filesystem;
+
+std::string GetChasmPath (const std::string path) {
+    auto home = std::string (std::getenv ("HOME"));
+
+    if (home.empty()) {
+        return path;
+    }
+
+    fs::path result(home);
+    result /= fs::path (".chasm");
+    result /= fs::path (path);
+
+    return result.string();
+}
+
+}
