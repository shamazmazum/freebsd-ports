--- src/Library/Color/Color.h.orig	2025-08-18 20:25:46 UTC
+++ src/Library/Color/Color.h
@@ -103,8 +103,10 @@ struct fmt::formatter<ColorTag> {
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
 
