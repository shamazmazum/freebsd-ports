--- src/Utility/String/Format.h.orig	2025-06-25 22:14:11 UTC
+++ src/Utility/String/Format.h
@@ -1,8 +1,22 @@
 #pragma once
 
+#define FMT_USE_NONTYPE_TEMPLATE_ARGS true
 #include <fmt/printf.h>
 #include <fmt/format.h>
 #include <fmt/compile.h>
+
+// https://stackoverflow.com/questions/76932476/how-to-write-format-as-for-enums-of-external-namespaces-in-fmt-10-0/77007114#77007114
+template <typename EnumType>
+requires std::is_enum_v<EnumType>
+struct fmt::formatter<EnumType> : fmt::formatter<std::underlying_type_t<EnumType>>
+{
+    // Forwards the formatting by casting the enum to it's underlying type
+    auto format(const EnumType& enumValue, format_context& ctx) const
+    {
+        return fmt::formatter<std::underlying_type_t<EnumType>>::format(
+            static_cast<std::underlying_type_t<EnumType>>(enumValue), ctx);
+    }
+};
 #include <fmt/chrono.h>
 
 using namespace fmt::literals; // NOLINT
