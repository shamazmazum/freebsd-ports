--- tests/test-helpers.c.orig	2020-01-21 17:18:48.000000000 +0300
+++ tests/test-helpers.c	2020-01-27 20:40:20.673482000 +0300
@@ -25,6 +25,10 @@
 
 #include "config.h"
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 #include <assert.h>
 #include <errno.h>
 #include <dirent.h>
@@ -41,6 +45,16 @@
 
 #include "test-runner.h"
 
+#ifdef __FreeBSD__
+/* FreeBSD uses fdescfs (which must be mounted using:
+ *    mount -t fdescfs fdescfs /dev/fd
+ * before the test suite can be run). */
+#define OPEN_FDS_DIR "/dev/fd"
+#else
+/* Linux. */
+#define OPEN_FDS_DIR "/proc/self/fd"
+#endif
+
 int
 count_open_fds(void)
 {
@@ -48,8 +62,8 @@
 	struct dirent *ent;
 	int count = 0;
 
-	dir = opendir("/proc/self/fd");
-	assert(dir && "opening /proc/self/fd failed.");
+	dir = opendir(OPEN_FDS_DIR);
+	assert(dir && "opening " OPEN_FDS_DIR " failed.");
 
 	errno = 0;
 	while ((ent = readdir(dir))) {
@@ -58,8 +72,8 @@
 			continue;
 		count++;
 	}
-	assert(errno == 0 && "reading /proc/self/fd failed.");
-
+    assert(errno == 0 && "reading " OPEN_FDS_DIR " failed.");
+	
 	closedir(dir);
 
 	return count;
