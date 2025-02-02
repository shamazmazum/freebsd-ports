--- build/workspaces/update-workspaces.sh.orig	2025-02-02 14:14:24 UTC
+++ build/workspaces/update-workspaces.sh
@@ -1,10 +1,5 @@
 #!/bin/sh
 
-if [ "$(id -u)" = "0" ]; then
-	echo "Running as root will mess up file permissions. Aborting ..." 1>&2
-	exit 1
-fi
-
 die()
 {
 	echo ERROR: "$*"
