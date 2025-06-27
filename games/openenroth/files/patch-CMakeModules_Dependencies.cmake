--- CMakeModules/Dependencies.cmake.orig	2025-06-25 22:14:11 UTC
+++ CMakeModules/Dependencies.cmake
@@ -106,6 +106,15 @@ macro(resolve_dependencies) # Intentionally a macro - 
         # Prebuilt & user-supplied deps are resolved using the same code here.
         find_package(ZLIB REQUIRED)
         find_package(FFmpeg REQUIRED)
+        find_package(PkgConfig REQUIRED)
+        find_package(GLM REQUIRED)
+        find_package(FastFloat CONFIG REQUIRED)
+        find_package(CLI11 CONFIG REQUIRED)
+        pkg_check_modules(LuaJit REQUIRED luajit)
+        pkg_check_modules(NLOHMANN_JSON REQUIRED nlohmann_json)
+        pkg_check_modules(SOL2 REQUIRED sol2)
+        pkg_check_modules(FMT REQUIRED fmt)
+        pkg_check_modules(SPDLOG REQUIRED spdlog)
 
         find_package(SDL2 CONFIG REQUIRED)
         add_library(SDL2OE INTERFACE)
