--- src/xsocket.cpp.orig
+++ src/xsocket.cpp
@@ -22,7 +22,7 @@
 #endif
 
 #include "xsocket.h"
-#define  KDWIN
+#define	 KDWIN
 #include "global.h"
 
 #define XSOCKET_ERROR(str, code) do { \
@@ -47,7 +47,7 @@ IPaddress XSocketLocalHostExternADDR;
 static char XSocketLocalHostName[HOST_NAME_MAX+1];
 
 /*****************************************************************
-    Initialization
+	Initialization
 *****************************************************************/
 
 int XSocketInit(int ErrHUsed)
@@ -85,7 +85,7 @@ int XSocketInit(int ErrHUsed)
 }
 
 /*****************************************************************
-    Constructor
+	Constructor
 *****************************************************************/
 
 XSocket::XSocket()
@@ -129,7 +129,7 @@ XSocket& XSocket::operator = (XSocket& donor)
 }
 
 /*****************************************************************
-    Connect functions
+	Connect functions
 *****************************************************************/
 
 int XSocket::tcp_open()
@@ -174,7 +174,7 @@ int XSocket::open(char* name,int port)
 }
 
 /*****************************************************************
-    UDP connection function
+	UDP connection function
 *****************************************************************/
 
 int XSocket::openUDP(int port)
@@ -243,7 +243,7 @@ void XSocket::close()
 }
 
 /*****************************************************************
-    Listen - Accept functions
+	Listen - Accept functions
 *****************************************************************/
 
 int XSocket::listen(int port)
@@ -291,7 +291,7 @@ int XSocket::set_nonblocking_mode(int enable_nonblocking)
 }
 
 /*****************************************************************
-    Send and Receive functions
+	Send and Receive functions
 *****************************************************************/
 
 int XSocket::send(const char* buffer, int size)
@@ -313,7 +313,7 @@ int XSocket::send(const char* buffer, int size)
 		UDPpacket *pkt = SDLNet_AllocPacket(size);
 		if (!pkt) // TODO: report oom
 			return 0;
-// 		pkt->data = buffer; // FIXME: FreePacket deletes this memory?
+//		pkt->data = buffer; // FIXME: FreePacket deletes this memory?
 		memcpy(pkt->data, buffer, size);
 		if (!SDLNet_UDP_Send(udpSock, -1, pkt))
 		{
@@ -367,7 +367,7 @@ int XSocket::receive(char* buffer, int size_of_buffer, int ms_time)
 		UDPpacket *pkt = SDLNet_AllocPacket(size_of_buffer);
 		if (!pkt) // TODO: report oom
 			return 0;
-// 		pkt->data = buffer; // FIXME: FreePacket deletes this memory?
+//		pkt->data = buffer; // FIXME: FreePacket deletes this memory?
 		if ((status = SDLNet_UDP_Recv(udpSock, pkt)) == -1)
 		{
 			SDLNet_FreePacket(pkt);
@@ -385,14 +385,15 @@ int XSocket::receive(char* buffer, int size_of_buffer, int ms_time)
 }
 
 /*****************************************************************
-    Select functions
+	Select functions
 *****************************************************************/
 
 // TODO: MODIFY
 fd_set XSocketSet;
 int XSocket::check_socket(int ms_time)
 {
-/*	if(sock == INVALID_SOCKET)
+#if 0
+	if(sock == INVALID_SOCKET)
 		return 0;
 	int val;
 	FD_ZERO(&XSocketSet);
@@ -405,13 +406,17 @@ int XSocket::check_socket(int ms_time)
 		}
 	if(val)
 		sock = INVALID_SOCKET;
-	return !val;*/
+	return !val;
+#else
+	return 0;
+#endif
 }
 
 // TODO: MODIFY
 int XSocket::check_readability(int ms_time)
 {
-/*	if(sock == INVALID_SOCKET)
+#if 0
+	if(sock == INVALID_SOCKET)
 		return 0;
 	int val;
 	FD_ZERO(&XSocketSet);
@@ -421,13 +426,17 @@ int XSocket::check_readability(int ms_time)
 		XSOCKET_ERROR("select() failed",SDLNet_GetError());
 		return 0;
 		}
-	return val;*/
+	return val;
+#else
+	return 0;
+#endif
 }
 
 // TODO: MODIFY
 int XSocket::check_writeability(int ms_time)
 {
-/*	if(sock == INVALID_SOCKET)
+#if 0
+	if(sock == INVALID_SOCKET)
 		return 0;
 	int val;
 	FD_ZERO(&XSocketSet);
@@ -437,7 +446,10 @@ int XSocket::check_writeability(int ms_time)
 		XSOCKET_ERROR("select() failed",SDLNet_GetError());
 		return 0;
 		}
-	return val;*/
+	return val;
+#else
+	return 0;
+#endif
 }
 
 /*****************************************************************
@@ -446,7 +458,8 @@ int XSocket::check_writeability(int ms_time)
 // DO NOT USE?
 int XSocket::sendto(const char* buffer, int size, unsigned int IP)
 {
-/*	SOCKADDR_IN addr;
+#if 0
+	SOCKADDR_IN addr;
 	addr.sin_family = AF_INET;
 	addr.sin_addr.s_addr = IP;
 	addr.sin_port = htons(port);
@@ -455,17 +468,21 @@ int XSocket::sendto(const char* buffer, int size, unsigned int IP)
 		int err_code;
 		if((err_code = SDLNet_GetError()) == WSAEWOULDBLOCK)
 			return 0;
-// 		XSOCKET_ERROR("sendto() failed",err_code);
+//		XSOCKET_ERROR("sendto() failed",err_code);
 		sock = INVALID_SOCKET;
 		return 0;
 		}
-	return status;*/
+	return status;
+#else
+	return 0;
+#endif
 }
 
 // DO NOT USE
 int XSocket::receivefrom(char* buffer, int size_of_buffer, int ms_time)
 {
-/*	int status = 0;
+	int status = 0;
+#if 0
 	if(check_readability(ms_time)){
 		status = recvfrom(sock, buffer, size_of_buffer, 0,0,0);
 		if(status == SOCKET_ERROR){
@@ -474,7 +491,8 @@ int XSocket::receivefrom(char* buffer, int size_of_buffer, int ms_time)
 			return 0;
 			}
 		}
-	return status;*/
+#endif
+	return status;
 }
 
 // WTF?
