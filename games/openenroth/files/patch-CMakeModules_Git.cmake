--- CMakeModules/Git.cmake.orig	2026-07-15 21:30:22 UTC
+++ CMakeModules/Git.cmake
@@ -1,5 +1,5 @@ if(NOT PROJECT_VERSION)
 if(NOT PROJECT_VERSION)
-    set(PROJECT_VERSION "unknown")
+    set(PROJECT_VERSION "git-c96180b")
 endif()
 
 find_package(Git)
@@ -13,11 +13,6 @@ if(GIT_FOUND)
   if(NOT "${GIT_VERSION}" STREQUAL "")
     set(PROJECT_VERSION ${GIT_VERSION})
   endif()
-
-  execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
-    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
-    OUTPUT_VARIABLE OPENENROTH_VERSION
-    OUTPUT_STRIP_TRAILING_WHITESPACE)
 endif()
 
 message(STATUS "OpenEnroth version: ${PROJECT_VERSION}")
