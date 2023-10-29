--- src/engine/audio/sound_game.cpp.orig	2023-10-29 15:18:21 UTC
+++ src/engine/audio/sound_game.cpp
@@ -18,6 +18,7 @@ ------------------------------------------------------
 #include "../../entity.hpp"
 #include "../../net.hpp"
 #include "../../player.hpp"
+#include "../../prng.hpp"
 #include "../../ui/GameUI.hpp"
 
 /*-------------------------------------------------------------------------------
@@ -359,6 +360,16 @@ OPENAL_CHANNELGROUP* getChannelGroupForSoundIndex(Uint
 		return soundAmbient_group;
 	}
 	return sound_group;
+}
+
+OPENAL_SOUND* playSoundNotification(Uint16 snd, Uint8 vol)
+{
+    return NULL;
+}
+
+OPENAL_SOUND* playSoundNotificationPlayer(int player, Uint16 snd, Uint8 vol)
+{
+    return nullptr;
 }
 
 OPENAL_SOUND* playSoundPlayer(int player, Uint16 snd, Uint8 vol)
