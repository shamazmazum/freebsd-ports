--- source/zmusic/configuration.cpp.orig	2026-09-23 06:56:48 UTC
+++ source/zmusic/configuration.cpp
@@ -166,14 +166,9 @@ int ZMusic_EnumerateMidiDevices()
 
 int ZMusic_EnumerateMidiDevices()
 {
-#ifdef HAVE_SYSTEM_MIDI
-	#ifdef __linux__
-		auto & sequencer = AlsaSequencer::Get();
-		return sequencer.EnumerateDevices();
-	#elif _WIN32
-		// TODO: move the weird stuff from music_midi_base.cpp here, or at least to this lib and call it here
-		return {};
-	#endif
+#if defined(HAVE_SYSTEM_MIDI) && defined(__linux__)
+	auto & sequencer = AlsaSequencer::Get();
+	return sequencer.EnumerateDevices();
 #else
 	return {};
 #endif
