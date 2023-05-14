--- Source/WebCore/platform/network/DNS.h.orig	2023-05-14 08:00:46 UTC
+++ Source/WebCore/platform/network/DNS.h
@@ -34,6 +34,7 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #else
+#include <sys/socket.h>
 #include <netinet/in.h>
 #endif
 
