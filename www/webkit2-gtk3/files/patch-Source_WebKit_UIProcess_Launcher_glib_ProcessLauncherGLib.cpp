--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2023-05-04 08:46:16 UTC
+++ Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp
@@ -91,7 +91,7 @@ static int connectionOptions()
 
 static bool isSandboxEnabled(const ProcessLauncher::LaunchOptions& launchOptions)
 {
-#if !USE(SYSTEM_MALLOC)
+#if !USE(SYSTEM_MALLOC) && OS(LINUX)
     if (RUNNING_ON_VALGRIND)
         return false;
 #endif
