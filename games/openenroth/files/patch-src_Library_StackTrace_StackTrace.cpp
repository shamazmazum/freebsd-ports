--- src/Library/StackTrace/StackTrace.cpp.orig	2026-10-20 04:31:37 UTC
+++ src/Library/StackTrace/StackTrace.cpp
@@ -3,13 +3,13 @@
 #include <cstdio>
 #include <string>
 
-#ifndef __ANDROID__
+#if !defined(__ANDROID__) && 0
 #   include <cpptrace/cpptrace.hpp>
 #endif
 
 #include "Utility/String/Format.h"
 
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || 1
 
 std::string stackTraceToString() {
     return "Stack traces not supported on Android...";
