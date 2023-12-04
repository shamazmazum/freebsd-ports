--- src/lib/sendfile.c.orig	2023-12-04 18:57:59 UTC
+++ src/lib/sendfile.c
@@ -48,12 +48,13 @@ lfp_sendfile(int out_fd, int in_fd, off_t offset, size
     off_t off = offset;
     return (ssize_t) sendfile(out_fd, in_fd, &off, nbytes);
 # elif defined(__FreeBSD__) || defined(__DragonFly__)
-    off_t sbytes = 0;
+    off_t sbytes;
     int res = sendfile(in_fd, out_fd, offset, nbytes, NULL, &sbytes, 0);
-    if (res == 0 || (res < 0 && errno == EAGAIN && sbytes > 0)) {
-        return sbytes;
+    if (res == -1 && errno == EAGAIN) {
+        res = 0;
     }
-    return -1;
+    if (res == 0) res = sbytes;
+    return res;
 # elif defined(__APPLE__)
     off_t len = nbytes;
     int res = sendfile(in_fd, out_fd, offset, &len, NULL, 0);
