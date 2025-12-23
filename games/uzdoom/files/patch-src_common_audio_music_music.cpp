--- src/common/audio/music/music.cpp.orig	2025-11-28 23:13:58 UTC
+++ src/common/audio/music/music.cpp
@@ -785,11 +785,11 @@ bool S_ChangeMusic(const char* musicname, int order, b
 		}
 		auto mreader = GetMusicReader(reader);	// this passes the file reader to the newly created wrapper.
 		int mod_player = mplay? *mplay : *mod_preferred_player;
-		int scratch;
+		//int scratch;
 
 		// This config var is only effective when opening a music stream so there's no need for active synchronization. Setting it here is sufficient.
 		// Ideally this should have been a parameter to ZMusic_OpenSong, but that would have necessitated an API break.
-		ChangeMusicSettingInt(zmusic_mod_preferredplayer, mus_playing.handle, mod_player, &scratch);
+		//ChangeMusicSettingInt(zmusic_mod_preferredplayer, mus_playing.handle, mod_player, &scratch);
 		mus_playing.handle = ZMusic_OpenSong(mreader, devp ? (EMidiDevice)devp->device : MDEV_DEFAULT, devp ? devp->args.GetChars() : "");
 		if (mus_playing.handle == nullptr)
 		{
