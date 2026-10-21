--- tools/zipdir/zipdir.c.orig	2026-10-21 12:24:43 UTC
+++ tools/zipdir/zipdir.c
@@ -44,7 +44,7 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <time.h>
-#include <miniz.h>
+#include "miniz.h"
 #include "bzlib.h"
 #include "LzmaEnc.h"
 #include "7zVersion.h"
