--- thirdparty/luajit-cmake/LuaJIT.cmake.orig	2025-09-01 05:09:20 UTC
+++ thirdparty/luajit-cmake/LuaJIT.cmake
@@ -409,7 +409,7 @@ add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/
 endif()
 
 add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/luajit_relver.txt
-  COMMAND git show -s --format=${GIT_FORMAT} > ${CMAKE_CURRENT_BINARY_DIR}/luajit_relver.txt
+  COMMAND echo "1727870382" > ${CMAKE_CURRENT_BINARY_DIR}/luajit_relver.txt
   WORKING_DIRECTORY ${LUAJIT_DIR}
 )
 
