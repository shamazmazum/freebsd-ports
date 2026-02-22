--- lib/network/NetworkConnection.cpp.orig	2025-04-24 19:50:03 UTC
+++ lib/network/NetworkConnection.cpp
@@ -7,6 +7,9 @@
  * Full text of license available in license.txt file, in main folder
  *
  */
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 #include "StdInc.h"
 #include "NetworkConnection.h"
 
@@ -19,8 +22,15 @@ NetworkConnection::NetworkConnection(INetworkConnectio
 {
 	socket->set_option(boost::asio::ip::tcp::no_delay(true));
 
+#ifdef __FreeBSD__
+	unsigned long sb_max;
+	size_t len = sizeof(sb_max);
+	(void)sysctlbyname("kern.ipc.maxsockbuf", &sb_max, &len, NULL, 0);
+	int bufferSize = sb_max * MCLBYTES / (MSIZE + MCLBYTES);
+#else
 	// iOS throws exception on attempt to set buffer size
 	constexpr auto bufferSize = 4 * 1024 * 1024;
+#endif
 
 	try
 	{
