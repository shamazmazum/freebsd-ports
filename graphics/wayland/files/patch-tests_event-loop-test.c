--- tests/event-loop-test.c.orig	2020-01-27 20:18:20.671549000 +0300
+++ tests/event-loop-test.c	2020-01-27 20:20:16.981160000 +0300
@@ -168,10 +168,10 @@
 					  signal_callback, &got_it);
 	assert(source);
 
-	wl_event_loop_dispatch(loop, 0);
+    assert(wl_event_loop_dispatch(loop, 0) == 0);
 	assert(!got_it);
-	kill(getpid(), SIGUSR1);
-	wl_event_loop_dispatch(loop, 0);
+	assert(kill(getpid(), SIGUSR1) == 0);
+	assert(wl_event_loop_dispatch(loop, 0) == 0);
 	assert(got_it == 1);
 
 	wl_event_source_remove(source);
