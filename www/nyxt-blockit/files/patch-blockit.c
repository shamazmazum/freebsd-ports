--- blockit.c.orig	2024-11-17 06:52:55 UTC
+++ blockit.c
@@ -242,27 +242,13 @@ G_MODULE_EXPORT void webkit_web_extension_initialize(W
 	memset(addr.sun_path, 0, sizeof(addr.sun_path));
 	strcpy(addr.sun_path, "/tmp/ars");
 
-	// Spawn server if it's not running.
 	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
 	{
-		gchar *argv[] = {"adblock-rust-server", NULL};
-		gint out;
-
-		// "disable" extension if server can't be started.
-		if (!g_spawn_async_with_pipes(NULL, argv, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL, &out, NULL, NULL)) {
-			GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_WARNING, GTK_BUTTONS_NONE, "adblock-rust-server could not be started");
-			gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), "adblock-rust-server isn't running and couldn't be started. Please check that it is installed and accessible from $PATH. You can install it with cargo: 'cargo install adblock-rust-server'.");
-			gtk_widget_show(dialog);
-			return;
-		}
-
-		// Wait until server prints out the 'init-done' line and try connecting to the server again.
-		GIOChannel *out_chan = g_io_channel_unix_new(out);
-		gchar *line;
-		g_io_channel_read_line(out_chan, &line, NULL, NULL, NULL);
-		g_free(line);
-		g_io_channel_unref(out_chan);
-		connect(sock, (struct sockaddr *)&addr, sizeof(addr));
+		// "disable" extension if server is not running.
+		GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_WARNING, GTK_BUTTONS_NONE, "adblock-rust-server is not running");
+		gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), "adblock-rust-server isn't running. You can install it with cargo: 'cargo install adblock-rust-server'.");
+		gtk_widget_show(dialog);
+		return;
 	}
 
 	config_dir = g_get_user_config_dir();
