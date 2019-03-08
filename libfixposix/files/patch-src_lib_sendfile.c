--- src/lib/sendfile.c.orig	2019-03-08 21:49:06.283494000 +0300
+++ src/lib/sendfile.c	2019-03-08 21:53:21.814671000 +0300
@@ -23,6 +23,7 @@
 /*******************************************************************************/
 
 #include <lfp/sendfile.h>
+#include <errno.h>
 
 #if defined(HAVE_SENDFILE)
 # if defined(__linux__)
@@ -46,10 +47,13 @@
 # if defined(__linux__)
     off_t off = offset;
     return (ssize_t) sendfile(out_fd, in_fd, &off, nbytes);
-# elif defined(__FreeBSD__)
-    return (ssize_t) sendfile(in_fd, out_fd, offset, nbytes, NULL, NULL, SF_MNOWAIT);
-# elif defined(__DragonFly__)
-    return (ssize_t) sendfile(in_fd, out_fd, offset, nbytes, NULL, NULL, 0);
+# elif defined(__FreeBSD__) || defined(__DragonFly__)
+    off_t sbytes;
+    int res = sendfile(in_fd, out_fd, offset, nbytes, NULL, &sbytes, 0);
+    if (res == -1 && errno == EAGAIN)
+        res = 0;
+    if (res == 0) res = sbytes;
+    return res;
 # elif defined(__APPLE__)
     off_t len = nbytes;
     return (ssize_t) sendfile(in_fd, out_fd, offset, &len, NULL, 0);
