--- src/Library/Logger/Logger.cpp.orig	2025-06-25 22:14:11 UTC
+++ src/Library/Logger/Logger.cpp
@@ -28,11 +28,8 @@ Logger::~Logger() {
     logger = nullptr;
 }
 
-void Logger::logV(const LogCategory &category, LogLevel level, fmt::string_view fmt, fmt::format_args args) {
-    std::string message = fmt::vformat(fmt, args);
-
-    auto guard = std::lock_guard(_mutex);
-    _sink->write(category, level, message);
+void Logger::writeToSink(const LogCategory &category, LogLevel level, std::string output) {
+    _sink->write(category, level, output);
 }
 
 LogLevel Logger::level() const {
