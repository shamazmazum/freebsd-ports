--- src/client/vid/vid.c.orig
+++ src/client/vid/vid.c
@@ -348,6 +348,7 @@ VID_LoadRenderer(void)
 
 	char reflib_name[64] = {0};
 	char reflib_path[MAX_OSPATH] = {0};
+    char *next_path = NULL;
 
 	// If the refresher is already active we need
 	// to shut it down before loading a new one
@@ -356,21 +357,20 @@ VID_LoadRenderer(void)
 	// Log what we're doing.
 	Com_Printf("----- refresher initialization -----\n");
 
-	snprintf(reflib_name, sizeof(reflib_name), "ref_%s.%s", vid_renderer->string, lib_ext);
-	snprintf(reflib_path, sizeof(reflib_path), "%s%s", Sys_GetBinaryDir(), reflib_name);
-	Com_Printf("LoadLibrary(%s)\n", reflib_name);
+    snprintf(reflib_name, sizeof(reflib_name), "ref_%s.%s", vid_renderer->string, lib_ext);
+    while ((next_path = FS_GetNextRawPath (next_path)) != NULL) {
+        snprintf(reflib_path, sizeof(reflib_path), "%s%s", next_path, reflib_name);
+        Com_Printf("LoadLibrary(%s)\n", reflib_name);
 
-	// Mkay, let's load the requested renderer.
-	GetRefAPI = Sys_LoadLibrary(reflib_path, "GetRefAPI", &reflib_handle);
+        // Mkay, let's load the requested renderer.
+        GetRefAPI = Sys_LoadLibrary(reflib_path, "GetRefAPI", &reflib_handle);
 
-	// Okay, we couldn't load it. It's up to the
-	// caller to recover from this.
-	if (GetRefAPI == NULL)
-	{
-		Com_Printf("Loading %s as renderer lib failed!", reflib_path);
-
-		return false;
-	}
+        // Okay, we couldn't load it. It's up to the
+        // caller to recover from this.
+        if (GetRefAPI == NULL) Com_Printf("Loading %s as renderer lib failed!\n", reflib_path);
+        else break;
+    }
+    if (next_path == NULL) return false;
 
 	// Fill in the struct exported to the renderer.
 	// FIXME: Do we really need all these?
