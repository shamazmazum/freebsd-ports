--- src/Library/Serialization/EnumSerialization.h.orig	2026-07-15 21:30:22 UTC
+++ src/Library/Serialization/EnumSerialization.h
@@ -7,7 +7,7 @@
 
 #define MAGIC_ENUM_RANGE_MIN (-256)
 #define MAGIC_ENUM_RANGE_MAX (255)
-#include <magic_enum.hpp>
+#include <magic_enum/magic_enum.hpp>
 
 #include "Utility/Preprocessor.h"
 
