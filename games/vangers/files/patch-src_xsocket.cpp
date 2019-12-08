--- src/xsocket.cpp.orig
+++ src/xsocket.cpp
@@ -392,7 +392,8 @@ int XSocket::receive(char* buffer, int size_of_buffer, int ms_time)
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
@@ -459,13 +472,17 @@ int XSocket::sendto(const char* buffer, int size, unsigned int IP)
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
@@ -474,7 +491,8 @@ int XSocket::receivefrom(char* buffer, int size_of_buffer, int ms_time
 			return 0;
 			}
 		}
-	return status;*/
+#endif
+	return status;
 }
 
 // WTF?
