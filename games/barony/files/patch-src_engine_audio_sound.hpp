--- src/engine/audio/sound.hpp.orig	2025-06-15 02:47:47 UTC
+++ src/engine/audio/sound.hpp
@@ -487,9 +487,12 @@ OPENAL_SOUND* playSound(Uint16 snd, Uint8 vol);
 OPENAL_SOUND* playSoundEntity(Entity* entity, Uint16 snd, Uint8 vol);
 OPENAL_SOUND* playSoundEntityLocal(Entity* entity, Uint16 snd, Uint8 vol);
 OPENAL_SOUND* playSound(Uint16 snd, Uint8 vol);
+OPENAL_SOUND* playSoundNotification(Uint16 snd, Uint8 vol); //TODO: Write.
+OPENAL_SOUND* playSoundNotificationPlayer(int player, Uint16 snd, Uint8 vol); //TODO: Write.
 OPENAL_SOUND* playSoundVelocity(); //TODO: Write.
 
-void playmusic(OPENAL_BUFFER* sound, bool loop, bool crossfade, bool resume); //Automatically crossfades. NOTE: Resets fadein and fadeout increments to the defaults every time it is called. You'll have to change the fadein and fadeout increments AFTER calling this function.
+void stopMusic();
+void playMusic(OPENAL_BUFFER* sound, bool loop, bool crossfade, bool resume); //Automatically crossfades. NOTE: Resets fadein and fadeout increments to the defaults every time it is called. You'll have to change the fadein and fadeout increments AFTER calling this function.
 
 void handleLevelMusic(); //Manages and updates the level music.
 
