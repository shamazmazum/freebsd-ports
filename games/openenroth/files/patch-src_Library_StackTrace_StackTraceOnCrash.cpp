--- src/Library/StackTrace/StackTraceOnCrash.cpp.orig	2026-10-20 04:31:47 UTC
+++ src/Library/StackTrace/StackTraceOnCrash.cpp
@@ -9,7 +9,7 @@
 #include <utility>
 #include <vector>
 
-#ifndef __ANDROID__
+#if !defined(__ANDROID__) && 0
 #   include <cpptrace/cpptrace.hpp>
 #endif
 
@@ -19,7 +19,7 @@
 #   include <csignal>
 #   include <exception>
 #   include <mutex>
-#elif !defined(__ANDROID__)
+#elif !defined(__ANDROID__) && 0
 #   include <unistd.h> // NOLINT: not a C++ system header.
 #   include <sys/mman.h> // NOLINT: not a C++ system header.
 #   include <sys/ucontext.h> // NOLINT: not a C++ system header.
@@ -37,7 +37,7 @@
 
 #include "Utility/String/Format.h"
 
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || 1
 
 StackTraceOnCrash::StackTraceOnCrash(void (*)(), StackTraceSymbolLoading) {}
 
