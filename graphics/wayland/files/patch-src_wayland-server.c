--- src/wayland-server.c.orig	2020-01-27 07:39:13.213281000 +0300
+++ src/wayland-server.c	2020-01-27 07:42:04.651147000 +0300
@@ -25,6 +25,8 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <stdbool.h>
 #include <stdlib.h>
 #include <stdint.h>
@@ -44,6 +46,11 @@
 #include <sys/file.h>
 #include <sys/stat.h>
 
+#ifdef HAVE_SYS_UCRED_H
+#include <sys/types.h>
+#include <sys/ucred.h>
+#endif
+
 #include "wayland-util.h"
 #include "wayland-private.h"
 #include "wayland-server-private.h"
@@ -79,7 +86,13 @@
 	struct wl_list link;
 	struct wl_map objects;
 	struct wl_priv_signal destroy_signal;
-	struct ucred ucred;
+#ifdef HAVE_SYS_UCRED_H
+	/* FreeBSD */
+	struct xucred xucred;
+#else
+	/* Linux */
+ 	struct ucred ucred;
+#endif
 	int error;
 	struct wl_priv_signal resource_created_signal;
 };
@@ -315,7 +328,13 @@
 static void
 destroy_client_with_error(struct wl_client *client, const char *reason)
 {
-	wl_log("%s (pid %u)\n", reason, client->ucred.pid);
+#ifdef HAVE_SYS_UCRED_H
+	/* FreeBSD */
+	wl_log("%s\n", reason);
+#else
+	/* Linux */
+ 	wl_log("%s (pid %u)\n", reason, client->ucred.pid);
+#endif
 	wl_client_destroy(client);
 }
 
@@ -529,10 +548,20 @@
 	if (!client->source)
 		goto err_client;
 
+#if defined(SO_PEERCRED)
+	/* Linux */
 	len = sizeof client->ucred;
 	if (getsockopt(fd, SOL_SOCKET, SO_PEERCRED,
 		       &client->ucred, &len) < 0)
 		goto err_source;
+#elif defined(LOCAL_PEERCRED)
+	/* FreeBSD */
+	len = sizeof client->xucred;
+	if (getsockopt(fd, SOL_SOCKET, LOCAL_PEERCRED,
+		       &client->xucred, &len) < 0 ||
+		       client->xucred.cr_version != XUCRED_VERSION)
+		goto err_source;
+#endif
 
 	client->connection = wl_connection_create(fd);
 	if (client->connection == NULL)
@@ -586,12 +615,23 @@
 wl_client_get_credentials(struct wl_client *client,
 			  pid_t *pid, uid_t *uid, gid_t *gid)
 {
-	if (pid)
-		*pid = client->ucred.pid;
+#ifdef HAVE_SYS_UCRED_H
+	/* FreeBSD */
+ 	if (pid)
+		*pid = 0; /* FIXME: not defined on FreeBSD */
 	if (uid)
-		*uid = client->ucred.uid;
+		*uid = client->xucred.cr_uid;
 	if (gid)
-		*gid = client->ucred.gid;
+		*gid = client->xucred.cr_gid;
+#else
+	/* Linux */
+	if (pid)
+ 		*pid = client->ucred.pid;
+ 	if (uid)
+ 		*uid = client->ucred.uid;
+ 	if (gid)
+ 		*gid = client->ucred.gid;
+#endif
 }
 
 /** Get the file descriptor for the client
