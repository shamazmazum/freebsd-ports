--- CMakeModules/Dependencies.cmake.orig	2026-10-20 04:22:21 UTC
+++ CMakeModules/Dependencies.cmake
@@ -94,6 +94,14 @@ macro(resolve_dependencies) # Intentionally a macro - 
     # Prebuilt & user-supplied deps are resolved using the same code here.
     find_package(ZLIB REQUIRED)
     find_package(FFmpeg REQUIRED)
+    find_package(PkgConfig REQUIRED)
+    find_package(glm CONFIG REQUIRED)
+    find_package(FastFloat CONFIG REQUIRED)
+    find_package(CLI11 CONFIG REQUIRED)
+    find_package(magic_enum CONFIG REQUIRED)
+    find_package(fmt CONFIG REQUIRED)
+    find_package(nlohmann_json CONFIG REQUIRED)
+    pkg_check_modules(SPDLOG REQUIRED spdlog)
 
     find_package(SDL3 CONFIG REQUIRED)
     add_library(SDL3OE INTERFACE)
