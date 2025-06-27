--- src/Library/Logger/Logger.h.orig	2025-06-25 22:14:11 UTC
+++ src/Library/Logger/Logger.h
@@ -46,10 +46,15 @@ class Logger {
     template<class... Args>
     void log(const LogCategory &category, LogLevel level, fmt::format_string<Args...> fmt, Args &&... args) {
         if (shouldLog(category, level))
-            logV(category, level, fmt, fmt::make_format_args(args...));
+            logV(category, level, fmt, std::forward<Args>(args)...);
     }
 
     template<class... Args>
+    void logV(const LogCategory &category, LogLevel level, fmt::string_view fmt, Args&&... args) {
+        writeToSink(category, level, fmt::format(fmt::runtime(fmt), args...));
+    }
+
+    template<class... Args>
     void trace(const LogCategory &category, fmt::format_string<Args...> fmt, Args &&... args) {
         log(category, LOG_TRACE, fmt, std::forward<Args>(args)...);
     }
@@ -134,7 +139,7 @@ class Logger {
     void setSink(LogSink *sink);
 
  private:
-    void logV(const LogCategory &category, LogLevel level, fmt::string_view fmt, fmt::format_args args);
+    void writeToSink(const LogCategory &category, LogLevel level, std::string output);
 
  private:
     std::mutex _mutex;
