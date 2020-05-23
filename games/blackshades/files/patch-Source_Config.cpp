--- Source/Config.cpp.orig	2020-05-11 05:59:08 UTC
+++ Source/Config.cpp
@@ -45,7 +45,8 @@ Config::Config()
   azertykeyboard = 0;
   invertmouse = 0;
   
-  const char *cfgFile = "config.txt";
+  std::string cfgFile = getenv ("HOME");
+  cfgFile += "/.blackshades.config";
 
   if(!ConfigExist(cfgFile)) {
     WriteConfig(cfgFile);
@@ -67,7 +68,7 @@ Config::Config()
   ReadHighScore();
 }
 
-bool Config::ConfigExist(const char *configFile)
+bool Config::ConfigExist(const std::string configFile)
 {
   std::ifstream ipstream(configFile);
 
@@ -79,7 +80,7 @@ bool Config::ConfigExist(const char *configFile)
   return false;
 }
 
-bool Config::ReadConfig(const char *configFile)
+bool Config::ReadConfig(const std::string configFile)
 {
   //Read config
   std::ifstream ipstream(configFile);
@@ -131,7 +132,7 @@ bool Config::ReadConfig(const char *configFile)
   return false;
 }
 
-void Config::WriteConfig(const char *configFile)
+void Config::WriteConfig(const std::string configFile)
 {
   std::ofstream opstream(configFile);
   opstream << "Screenwidth:\n";
