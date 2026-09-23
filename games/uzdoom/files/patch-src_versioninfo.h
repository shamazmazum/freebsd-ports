--- src/versioninfo.h.orig	2026-09-23 07:34:37 UTC
+++ src/versioninfo.h
@@ -19,6 +19,9 @@
 
 #include <string>
 
+#undef major
+#undef minor
+
 class FString;
 
 struct VersionInfo
