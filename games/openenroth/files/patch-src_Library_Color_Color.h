--- src/Library/Color/Color.h.orig	2025-12-19 21:35:54 UTC
+++ src/Library/Color/Color.h
@@ -107,8 +107,10 @@ struct fmt::formatter<ColorTag> {
         // for ColorTag. Also makes it easier to distinguish color tags in the format string.
         auto pos = ctx.begin();
         auto end = ctx.end();
-        if (pos == end || *pos != ':' || ++pos == end || *pos != '}')
-            fmt::detail::throw_format_error("ColorTag needs {::} format specifier");
+        if (pos == end || *pos != ':' || ++pos == end || *pos != '}') {
+            throw std::runtime_error("ColorTag needs {::} format specifier");
+            //fmt::detail::throw_format_error("ColorTag needs {::} format specifier");
+        }
         return pos; // pos points to '}'
     }
 
