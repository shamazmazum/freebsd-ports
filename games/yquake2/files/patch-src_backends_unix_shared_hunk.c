--- src/backends/unix/shared/hunk.c.orig	2021-02-17 18:36:14 UTC
+++ src/backends/unix/shared/hunk.c
@@ -73,12 +73,6 @@ Hunk_Begin(int maxsize)
 	}
 #endif
 
-#if defined(PROT_MAX)
-	/* For now it is FreeBSD exclusif but could possibly be extended
-	   to other like DFBSD for example */
-	prot = PROT_MAX(prot);
-#endif
-
 	membase = mmap(0, maxhunksize, prot,
 			flags, -1, 0);
 
