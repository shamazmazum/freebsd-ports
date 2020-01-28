--- tests/test-runner.c.orig	2020-01-21 17:18:48.000000000 +0300
+++ tests/test-runner.c	2020-01-27 20:45:18.408586000 +0300
@@ -25,6 +25,10 @@
 
 #define _GNU_SOURCE
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -37,13 +41,23 @@
 #include <errno.h>
 #include <limits.h>
 #include <sys/ptrace.h>
+#ifdef HAVE_SYS_PRCTL_H
 #include <sys/prctl.h>
+#endif
 #ifndef PR_SET_PTRACER
 # define PR_SET_PTRACER 0x59616d61
 #endif
+#include <signal.h>
 
 #include "test-runner.h"
 
+#ifdef __FreeBSD__
+/* XXX review ptrace() usage */
+#define PTRACE_ATTACH PT_ATTACH
+#define PTRACE_CONT PT_CONTINUE
+#define PTRACE_DETACH PT_DETACH
+#endif
+
 /* when set to 1, check if tests are not leaking opened files.
  * It is turned on by default. It can be turned off by
  * WAYLAND_TEST_NO_LEAK_CHECK environment variable. */
@@ -259,13 +273,14 @@
 			_exit(1);
 		if (!waitpid(-1, NULL, 0))
 			_exit(1);
-		ptrace(PTRACE_CONT, NULL, NULL);
+		ptrace(PTRACE_CONT, ppid, NULL, NULL);
 		ptrace(PTRACE_DETACH, ppid, NULL, NULL);
 		_exit(0);
 	} else {
 		close(pipefd[0]);
 
 		/* Enable child to ptrace the parent process */
+#if defined(HAVE_PRCTL)
 		rc = prctl(PR_SET_PTRACER, pid);
 		if (rc != 0 && errno != EINVAL) {
 			/* An error prevents us from telling if a debugger is attached.
@@ -275,7 +290,9 @@
 			 */
 			perror("prctl");
 			write(pipefd[1], "-", 1);
-		} else {
+		} else
+#endif
+        {
 			/* Signal to client that parent is ready by passing '+' */
 			write(pipefd[1], "+", 1);
 		}
@@ -293,7 +310,11 @@
 	const struct test *t;
 	pid_t pid;
 	int total, pass;
+#ifdef HAVE_WAITID
 	siginfo_t info;
+#else
+	int status;
+#endif
 
 	if (isatty(fileno(stderr)))
 		is_atty = 1;
@@ -336,6 +357,7 @@
 		if (pid == 0)
 			run_test(t); /* never returns */
 
+#ifdef HAVE_WAITID
 		if (waitid(P_PID, pid, &info, WEXITED)) {
 			stderr_set_color(RED);
 			fprintf(stderr, "waitid failed: %s\n",
@@ -368,6 +390,25 @@
 
 			break;
 		}
+#else
+               if (waitpid(-1, &status, 0) == -1) {
+                       fprintf(stderr, "waitpid failed: %s\n",
+                               strerror(errno));
+                       abort();
+               }
+
+               fprintf(stderr, "test \"%s\":\t", t->name);
+               if (WIFEXITED(status)) {
+                       fprintf(stderr, "exit status %d", WEXITSTATUS(status));
+                       if (WEXITSTATUS(status) == EXIT_SUCCESS)
+                               success = 1;
+               } else if (WIFSIGNALED(status)) {
+                       fprintf(stderr, "signal %d", WTERMSIG(status));
+               }
+#endif
+
+		if (t->must_fail)
+			success = !success;
 
 		if (success) {
 			pass++;
