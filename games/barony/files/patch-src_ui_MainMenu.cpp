--- src/ui/MainMenu.cpp.orig	2025-01-30 16:46:20 UTC
+++ src/ui/MainMenu.cpp
@@ -2871,12 +2871,12 @@ namespace MainMenu {
             fpsLimit = std::min(std::max(MIN_FPS, *cvar_desiredFps), MAX_FPS);
         }
 		current_audio_device = audio_device;
-        if (fmod_speakermode != speaker_mode) {
-            fmod_speakermode = (FMOD_SPEAKERMODE)speaker_mode;
-            if (initialized) {
-                restartPromptRequired = true;
-            }
-        }
+        // if (fmod_speakermode != speaker_mode) {
+        //     fmod_speakermode = (FMOD_SPEAKERMODE)speaker_mode;
+        //     if (initialized) {
+        //         restartPromptRequired = true;
+        //     }
+        // }
 		MainMenu::master_volume = std::min(std::max(0.f, master_volume / 100.f), 1.f);
 		sfxvolume = std::min(std::max(0.f, gameplay_volume / 100.f), 1.f);
 		sfxAmbientVolume = std::min(std::max(0.f, ambient_volume / 100.f), 1.f);
@@ -2976,7 +2976,7 @@ namespace MainMenu {
 		settings.fov = ::fov;
 		settings.fps = *cvar_desiredFps;
 		settings.audio_device = current_audio_device;
-        settings.speaker_mode = (int)fmod_speakermode;
+        settings.speaker_mode = (int)/*fmod_speakermode*/0;
 		settings.master_volume = MainMenu::master_volume * 100.f;
 		settings.gameplay_volume = (float)sfxvolume * 100.f;
 		settings.ambient_volume = (float)sfxAmbientVolume * 100.f;
@@ -6446,6 +6446,7 @@ bind_failed:
 #endif
 
 #ifndef NINTENDO
+        int num_drivers = 0;
 		if ( num_drivers > 0 )
 		{
 			hookSettings(*settings_subwindow,
