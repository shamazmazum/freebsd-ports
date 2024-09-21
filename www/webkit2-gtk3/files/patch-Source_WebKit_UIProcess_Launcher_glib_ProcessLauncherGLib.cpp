--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2024-09-21 16:06:53 UTC
+++ Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp
@@ -150,7 +150,7 @@ void ProcessLauncher::launchProcess()
     }
 
     realExecutablePath = FileSystem::fileSystemRepresentation(executablePath);
-    unsigned nargs = 5; // size of the argv array for g_spawn_async()
+    unsigned nargs = 4; // size of the argv array for g_spawn_async()
 
 #if ENABLE(DEVELOPER_MODE)
     Vector<CString> prefixArgs;
@@ -177,7 +177,6 @@ void ProcessLauncher::launchProcess()
     argv[i++] = const_cast<char*>(realExecutablePath.data());
     argv[i++] = processIdentifier.get();
     argv[i++] = webkitSocket.get();
-    argv[i++] = pidSocketString.get();
 #if ENABLE(DEVELOPER_MODE)
     if (configureJSCForTesting)
         argv[i++] = const_cast<char*>("--configure-jsc-for-testing");
