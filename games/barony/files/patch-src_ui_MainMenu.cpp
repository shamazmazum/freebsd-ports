--- src/ui/MainMenu.cpp.orig	2025-12-27 15:10:51 UTC
+++ src/ui/MainMenu.cpp
@@ -2900,12 +2900,12 @@ namespace MainMenu {
         }
 		current_recording_audio_device = recording_audio_device;
 		current_audio_device = audio_device;
-        if (fmod_speakermode != speaker_mode) {
-            fmod_speakermode = (FMOD_SPEAKERMODE)speaker_mode;
-            if (initialized) {
-                restartPromptRequired = true;
-            }
-        }
+        //if (fmod_speakermode != speaker_mode) {
+        //    fmod_speakermode = (FMOD_SPEAKERMODE)speaker_mode;
+        //    if (initialized) {
+        //        restartPromptRequired = true;
+        //    }
+        //}
 		MainMenu::master_volume = std::min(std::max(0.f, master_volume / 100.f), 1.f);
 		sfxvolume = std::min(std::max(0.f, gameplay_volume / 100.f), 1.f);
 		sfxAmbientVolume = std::min(std::max(0.f, ambient_volume / 100.f), 1.f);
@@ -3029,8 +3029,8 @@ namespace MainMenu {
 		settings.enable_voice_receive = VoiceChat.activeSettings.enable_voice_receive;
 		settings.use_voice_custom_rolloff = VoiceChat.activeSettings.use_custom_rolloff;
 		VoiceChat.mainmenuSettings = VoiceChat.activeSettings;
+		settings.speaker_mode = (int)fmod_speakermode;
 #endif
-        settings.speaker_mode = (int)fmod_speakermode;
 		settings.master_volume = MainMenu::master_volume * 100.f;
 		settings.gameplay_volume = (float)sfxvolume * 100.f;
 		settings.ambient_volume = (float)sfxAmbientVolume * 100.f;
@@ -6465,6 +6465,7 @@ bind_failed:
 	}
 
 	static void settingsAudio(Button& button) {
+		int num_drivers = 0;
 		Frame* settings_subwindow;
 		if ((settings_subwindow = settingsSubwindowSetup(button.getName(), false)) == nullptr) {
 			auto settings = main_menu_frame->findFrame("settings"); assert(settings);
@@ -6480,7 +6481,6 @@ bind_failed:
 
 #if !defined(NINTENDO) && defined(USE_FMOD)
 		int selected_device = 0;
-		int num_drivers = 0;
 		(void)fmod_system->getNumDrivers(&num_drivers);
 		audio_drivers.clear();
 		audio_drivers.reserve(num_drivers);
