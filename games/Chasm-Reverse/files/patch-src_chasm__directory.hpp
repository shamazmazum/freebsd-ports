--- src/chasm_directory.hpp.orig	2026-09-16 18:48:47 UTC
+++ src/chasm_directory.hpp
@@ -0,0 +1,10 @@
+#pragma once
+
+#include <string>
+
+namespace PanzerChasm
+{
+
+std::string GetChasmPath (const std::string path);
+
+}
