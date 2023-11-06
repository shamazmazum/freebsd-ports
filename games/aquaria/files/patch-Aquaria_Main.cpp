--- Aquaria/Main.cpp.orig	2023-11-06 05:34:37 UTC
+++ Aquaria/Main.cpp
@@ -19,9 +19,9 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
 
+#include <stdlib.h>
 #include "DSQ.h"
 
-
 #ifdef BBGE_BUILD_WINDOWS
 	#include <shellapi.h>
 #endif
@@ -103,6 +103,9 @@ static void CheckConfig(void)
 #endif
 
 #endif
+
+        // FTGL fix
+        setenv ("LANG", "C", 1);
 
         CheckConfig();
 
