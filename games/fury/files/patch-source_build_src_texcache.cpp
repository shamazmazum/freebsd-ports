--- source/build/src/texcache.cpp.orig	2026-01-25 15:20:14 UTC
+++ source/build/src/texcache.cpp
@@ -338,6 +338,8 @@ void texcache_openfiles(void)
 {
     Bassert(!texcache.indexFilePtr && !texcache.dataFilePtr);
 
+// texcache causes a crash
+#if 0
     Bstrcpy(ptempbuf, TEXCACHEFILE);
     Bstrcat(ptempbuf, ".index");
 
@@ -360,6 +362,8 @@ void texcache_openfiles(void)
     }
 
     LOG_F(INFO, "Opened %s as cache file.", TEXCACHEFILE);
+#endif
+    glusetexcache = 0;
 }
 
 
