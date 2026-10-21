--- src/versioninfo.h.orig	2026-10-21 12:25:05 UTC
+++ src/versioninfo.h
@@ -19,6 +19,9 @@
 
 #include <string>
 
+#undef major
+#undef minor
+
 class FString;
 
 struct VersionInfo
