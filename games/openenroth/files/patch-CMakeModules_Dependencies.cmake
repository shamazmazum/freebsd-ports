--- CMakeModules/Dependencies.cmake.orig	2026-02-17 22:13:45 UTC
+++ CMakeModules/Dependencies.cmake
@@ -116,6 +116,14 @@ macro(resolve_dependencies) # Intentionally a macro - 
         # Prebuilt & user-supplied deps are resolved using the same code here.
         find_package(ZLIB REQUIRED)
         find_package(FFmpeg REQUIRED)
+        find_package(PkgConfig REQUIRED)
+        find_package(GLM REQUIRED)
+        find_package(FastFloat CONFIG REQUIRED)
+        find_package(CLI11 CONFIG REQUIRED)
+        find_package(magic_enum CONFIG REQUIRED)
+        pkg_check_modules(NLOHMANN_JSON REQUIRED nlohmann_json)
+        pkg_check_modules(FMT REQUIRED fmt)
+        pkg_check_modules(SPDLOG REQUIRED spdlog)
 
         find_package(SDL3 CONFIG REQUIRED)
         add_library(SDL3OE INTERFACE)
