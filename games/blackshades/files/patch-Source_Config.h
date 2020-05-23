--- Source/Config.h.orig	2020-05-11 05:59:08 UTC
+++ Source/Config.h
@@ -20,12 +20,14 @@
 #ifndef _CONFIG_H_
 #define _CONFIG_H_
 
+#include <string>
+
 class Config {
 public:
   Config();
-  bool ConfigExist(const char *configFile);
-  bool ReadConfig(const char *configFile);
-  void WriteConfig(const char *configFile);
+  bool ConfigExist(const std::string configFile);
+  bool ReadConfig (const std::string configFile);
+  void WriteConfig(const std::string configFile);
 
   bool ReadHighScore();
   void WriteHighScore(int score);
