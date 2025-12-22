--- Source/WebCore/platform/network/DNS.h.orig	2025-08-08 09:17:55 UTC
+++ Source/WebCore/platform/network/DNS.h
@@ -35,6 +35,7 @@
 #include <ws2tcpip.h>
 #else
 #include <netinet/in.h>
+#include <sys/socket.h> /* AF_INET, AF_INET6 */
 #endif
 
 namespace WebCore {
