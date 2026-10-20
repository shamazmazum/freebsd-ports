--- _deps/ztd.idk-src/include/ztd/idk/endian.h.orig	2026-10-20 03:40:57 UTC
+++ _deps/ztd.idk-src/include/ztd/idk/endian.h
@@ -36,6 +36,9 @@
 #include <ztd/idk/version.h>
 
 #if ZTD_IS_ON(ZTD_HEADER_STDBIT_H)
+#ifndef _Bool
+#define _Bool bool
+#endif
 #include <stdbit.h>
 #endif
 
