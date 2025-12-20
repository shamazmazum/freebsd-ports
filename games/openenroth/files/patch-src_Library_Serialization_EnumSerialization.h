--- src/Library/Serialization/EnumSerialization.h.orig	2025-12-20 18:25:39 UTC
+++ src/Library/Serialization/EnumSerialization.h
@@ -7,7 +7,7 @@
 
 #define MAGIC_ENUM_RANGE_MIN (-256)
 #define MAGIC_ENUM_RANGE_MAX (255)
-#include <magic_enum.hpp>
+#include <magic_enum/magic_enum.hpp>
 
 #include "Utility/Preprocessor.h"
 
