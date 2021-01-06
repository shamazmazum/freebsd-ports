--- src/client/vid/vid.c.orig	2021-01-06 09:50:18.455692000 +0300
+++ src/client/vid/vid.c	2021-01-06 09:56:19.922122000 +0300
@@ -348,6 +348,7 @@
 
 	char reflib_name[64] = {0};
 	char reflib_path[MAX_OSPATH] = {0};
+	char *next_path = NULL;
 
 	// If the refresher is already active we need
 	// to shut it down before loading a new one
@@ -357,11 +358,19 @@
 	Com_Printf("----- refresher initialization -----\n");
 
 	snprintf(reflib_name, sizeof(reflib_name), "ref_%s.%s", vid_renderer->string, lib_ext);
-	snprintf(reflib_path, sizeof(reflib_path), "%s%s", Sys_GetBinaryDir(), reflib_name);
-	Com_Printf("Loading library: %s\n", reflib_name);
+	while ((next_path = FS_GetNextRawPath (next_path)) != NULL) {
+		snprintf(reflib_path, sizeof(reflib_path), "%s%s", next_path, reflib_name);
+		Com_Printf("LoadLibrary(%s)\n", reflib_name);
 
-	// Mkay, let's load the requested renderer.
-	GetRefAPI = Sys_LoadLibrary(reflib_path, "GetRefAPI", &reflib_handle);
+		// Mkay, let's load the requested renderer.
+		GetRefAPI = Sys_LoadLibrary(reflib_path, "GetRefAPI", &reflib_handle);
+
+		// Okay, we couldn't load it. It's up to the
+		// caller to recover from this.
+		if (GetRefAPI != NULL) {
+			break;
+		}
+	}
 
 	// Okay, we couldn't load it. It's up to the
 	// caller to recover from this.
