--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2024-08-13 05:20:01 UTC
+++ Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp
@@ -91,7 +91,7 @@ static bool isSandboxEnabled(const ProcessLauncher::La
 
 static bool isSandboxEnabled(const ProcessLauncher::LaunchOptions& launchOptions)
 {
-#if !USE(SYSTEM_MALLOC)
+#if !USE(SYSTEM_MALLOC) && OS(LINUX)
     if (RUNNING_ON_VALGRIND)
         return false;
 #endif
@@ -175,7 +175,7 @@ void ProcessLauncher::launchProcess()
     }
 
     realExecutablePath = FileSystem::fileSystemRepresentation(executablePath);
-    unsigned nargs = 5; // size of the argv array for g_spawn_async()
+    unsigned nargs = 4; // size of the argv array for g_spawn_async()
 
 #if ENABLE(DEVELOPER_MODE)
     Vector<CString> prefixArgs;
@@ -202,7 +202,6 @@ void ProcessLauncher::launchProcess()
     argv[i++] = const_cast<char*>(realExecutablePath.data());
     argv[i++] = processIdentifier.get();
     argv[i++] = webkitSocket.get();
-    argv[i++] = pidSocket.get();
 #if ENABLE(DEVELOPER_MODE)
     if (configureJSCForTesting)
         argv[i++] = const_cast<char*>("--configure-jsc-for-testing");
