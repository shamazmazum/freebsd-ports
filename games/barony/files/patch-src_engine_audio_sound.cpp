--- src/engine/audio/sound.cpp.orig	2025-01-30 16:46:20 UTC
+++ src/engine/audio/sound.cpp
@@ -31,17 +31,30 @@ ------------------------------------------------------
 
 #ifdef USE_FMOD
 #elif defined USE_OPENAL
+void setAudioDevice(const std::string& device)
+{
+	return;
+}
 #else
 void setGlobalVolume(real_t master, real_t music, real_t gameplay, real_t ambient, real_t environment, real_t notification)
 {
 	return;
 }
-void setAudioDevice(const std::string& device) 
+void setAudioDevice(const std::string& device)
 {
 	return;
 }
 #endif
 
+#ifdef USE_OPENAL
+bool FMODErrorCheck()
+{
+	return false;
+}
+
+#define FMOD_OK 1
+#endif
+
 #ifdef USE_FMOD
 
 bool FMODErrorCheck()
@@ -79,11 +92,11 @@ void setGlobalVolume(real_t master, real_t music, real
 }
 
 void setGlobalVolume(real_t master, real_t music, real_t gameplay, real_t ambient, real_t environment, real_t notification) {
-    master = std::min(std::max(0.0, master), 1.0);
-    music = std::min(std::max(0.0, music / 4.0), 1.0); // music volume cut in half because the music is loud...
-    gameplay = std::min(std::max(0.0, gameplay), 1.0);
-    ambient = std::min(std::max(0.0, ambient), 1.0);
-    environment = std::min(std::max(0.0, environment), 1.0);
+	master = std::min(std::max(0.0, master), 1.0);
+	music = std::min(std::max(0.0, music / 4.0), 1.0); // music volume cut in half because the music is loud...
+	gameplay = std::min(std::max(0.0, gameplay), 1.0);
+	ambient = std::min(std::max(0.0, ambient), 1.0);
+	environment = std::min(std::max(0.0, environment), 1.0);
 	notification = std::min(std::max(0.0, notification), 1.0);
 
 	music_group->setVolume(master * music);
@@ -513,7 +526,6 @@ OPENAL_BUFFER** sounds = nullptr;
 //#define openal_maxchannels 100
 
 OPENAL_BUFFER** sounds = nullptr;
-Uint32 numsounds = 0;
 OPENAL_BUFFER** minesmusic = NULL;
 OPENAL_BUFFER** swampmusic = NULL;
 OPENAL_BUFFER** labyrinthmusic = NULL;
@@ -734,12 +746,12 @@ static int get_firstfreechannel()
 	return i;
 }
 
-void setGlobalVolume(real_t master, real_t music, real_t gameplay, real_t ambient, real_t environment) {
-    master = std::min(std::max(0.0, master), 1.0);
-    music = std::min(std::max(0.0, music / 4.0), 1.0); // music volume cut in half because the music is loud...
-    gameplay = std::min(std::max(0.0, gameplay), 1.0);
-    ambient = std::min(std::max(0.0, ambient), 1.0);
-    environment = std::min(std::max(0.0, environment), 1.0);
+void setGlobalVolume(real_t master, real_t music, real_t gameplay, real_t ambient, real_t environment, real_t notification) {
+	master = std::min(std::max(0.0, master), 1.0);
+	music = std::min(std::max(0.0, music / 4.0), 1.0); // music volume cut in half because the music is loud...
+	gameplay = std::min(std::max(0.0, gameplay), 1.0);
+	ambient = std::min(std::max(0.0, ambient), 1.0);
+	environment = std::min(std::max(0.0, environment), 1.0);
 
 	OPENAL_ChannelGroup_SetVolume(music_group, master * music);
 	OPENAL_ChannelGroup_SetVolume(sound_group, master * gameplay);
@@ -1222,9 +1234,9 @@ bool physfsSearchMusicToUpdate()
 	return false;
 }
 
-#ifdef USE_FMOD
-FMOD_RESULT physfsReloadMusic_helper_reloadMusicArray(uint32_t numMusic, const char* filenameTemplate, FMOD::Sound** musicArray, bool reloadAll)
+int physfsReloadMusic_helper_reloadMusicArray(uint32_t numMusic, const char* filenameTemplate, OPENAL_BUFFER** musicArray, bool reloadAll)
 {
+    int fmod_result;
 	for ( int c = 0; c < numMusic; c++ )
 	{
 		snprintf(tempstr, 1000, filenameTemplate, c);
@@ -1237,28 +1249,20 @@ FMOD_RESULT physfsReloadMusic_helper_reloadMusicArray(
 				printlog("[PhysFS]: Loading music file %s...", tempstr);
 				if ( musicArray )
 				{
-					musicArray[c]->release();
+					OPENAL_Sound_Release(musicArray[c]);
 				}
-                if ( musicPreload )
-                {
-                    fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &musicArray[c]); //TODO: Any other FMOD_MODEs should be used here? FMOD_SOFTWARE -> what now? FMOD_2D? LOOP?
-                }
-                else
-                {
-                    fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &musicArray[c]); //TODO: Any other FMOD_MODEs should be used here? FMOD_SOFTWARE -> what now? FMOD_2D? LOOP?
-                }
-                if (fmod_result != FMOD_OK)
-                {
-                    printlog("[PhysFS]: ERROR: Failed reloading music file \"%s\".");
-                    return fmod_result;
-                }
+				fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &musicArray[c]);
+				if (fmod_result != FMOD_OK)
+				{
+					printlog("[PhysFS]: ERROR: Failed reloading music file \"%s\".");
+					return fmod_result;
+				}
 			}
 		}
 	}
 
 	return FMOD_OK;
 }
-#endif
 
 void physfsReloadMusic(bool &introMusicChanged, bool reloadAll) //TODO: This should probably return an error.
 {
@@ -1292,14 +1296,7 @@ void physfsReloadMusic(bool &introMusicChanged, bool r
 	themeMusic.push_back("sound/ui/StoryMusicV3.ogg");
 
 	int index = 0;
-#ifdef USE_OPENAL
-#define FMOD_System_CreateStream(A, B, C, D, E) OPENAL_CreateStreamSound(B, E) //TODO: If this is still needed, it's probably now broke!
-#define FMOD_SOUND OPENAL_BUFFER
-#define fmod_system 0
-#define FMOD_SOFTWARE 0
-#define FMOD_Sound_Release OPENAL_Sound_Release
 	int fmod_result;
-#endif
 	for ( std::vector<std::string>::iterator it = themeMusic.begin(); it != themeMusic.end(); ++it )
 	{
 		std::string filename = *it;
@@ -1315,295 +1312,155 @@ void physfsReloadMusic(bool &introMusicChanged, bool r
 					case 0:
 						if ( introductionmusic )
 						{
-							introductionmusic->release();
+							OPENAL_Sound_Release (introductionmusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &introductionmusic); //TODO: FMOD_SOFTWARE -> what now? FMOD_2D? FMOD_LOOP_NORMAL? More things? Something else?
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &introductionmusic); //TODO: FMOD_SOFTWARE -> what now? FMOD_2D? FMOD_LOOP_NORMAL? More things? Something else?
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &introductionmusic);
 						break;
 					case 1:
 						if ( intermissionmusic )
 						{
-							intermissionmusic->release();
+							OPENAL_Sound_Release (intermissionmusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &intermissionmusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &intermissionmusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &intermissionmusic);
 						break;
 					case 2:
 						if ( minetownmusic )
 						{
-							minetownmusic->release();
+							OPENAL_Sound_Release (minetownmusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &minetownmusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &minetownmusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &minetownmusic);
 						break;
 					case 3:
 						if ( splashmusic )
 						{
-							splashmusic->release();
+							OPENAL_Sound_Release (splashmusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &splashmusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &splashmusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &splashmusic);
 						break;
 					case 4:
 						if ( librarymusic )
 						{
-							librarymusic->release();
+							OPENAL_Sound_Release (librarymusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &librarymusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &librarymusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &librarymusic);
 						break;
 					case 5:
 						if ( shopmusic )
 						{
-							shopmusic->release();
+							OPENAL_Sound_Release (shopmusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &shopmusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &shopmusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &shopmusic);
 						break;
 					case 6:
 						if ( herxmusic )
 						{
-							herxmusic->release();
+							OPENAL_Sound_Release (herxmusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &herxmusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &herxmusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &herxmusic);
 						break;
 					case 7:
 						if ( templemusic )
 						{
-							templemusic->release();
+							OPENAL_Sound_Release (templemusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &templemusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &templemusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &templemusic);
 						break;
 					case 8:
 						if ( endgamemusic )
 						{
-							endgamemusic->release();
+							OPENAL_Sound_Release (endgamemusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &endgamemusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &endgamemusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &endgamemusic);
 						break;
 					case 9:
 						if ( escapemusic )
 						{
-							escapemusic->release();
+							OPENAL_Sound_Release (escapemusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &escapemusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &escapemusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &escapemusic);
 						break;
 					case 10:
 						if ( devilmusic )
 						{
-							devilmusic->release();
+							OPENAL_Sound_Release (devilmusic);
 						}
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &devilmusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &devilmusic);
-                        }
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &devilmusic);
 						break;
 					case 11:
 						if ( sanctummusic )
 						{
-							sanctummusic->release();
-                        }
-                        if ( musicPreload )
-                        {
-                            fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &sanctummusic);
-                        }
-                        else
-                        {
-                            fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &sanctummusic);
-                        }
+							OPENAL_Sound_Release (sanctummusic);
+						}
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &sanctummusic);
 						break;
 					case 12:
 						if ( gnomishminesmusic )
 						{
-							gnomishminesmusic->release();
+							OPENAL_Sound_Release (gnomishminesmusic);
 						}
-						if ( musicPreload )
-						{
-							fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &gnomishminesmusic);
-						}
-						else
-						{
-							fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &gnomishminesmusic);
-						}
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &gnomishminesmusic);
 						break;
 					case 13:
 						if ( greatcastlemusic )
 						{
-							greatcastlemusic->release();
+							OPENAL_Sound_Release (greatcastlemusic);
 						}
-						if ( musicPreload )
-						{
-							fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &greatcastlemusic);
-						}
-						else
-						{
-							fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &greatcastlemusic);
-						}
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &greatcastlemusic);
 						break;
 					case 14:
 						if ( sokobanmusic )
 						{
-							sokobanmusic->release();
+							OPENAL_Sound_Release (sokobanmusic);
 						}
-						if ( musicPreload )
-						{
-							fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &sokobanmusic);
-						}
-						else
-						{
-							fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &sokobanmusic);
-						}
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &sokobanmusic);
 						break;
 					case 15:
 						if ( caveslairmusic )
 						{
-							caveslairmusic->release();
+							OPENAL_Sound_Release (caveslairmusic);
 						}
-						if ( musicPreload )
-						{
-							fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &caveslairmusic);
-						}
-						else
-						{
-							fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &caveslairmusic);
-						}
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &caveslairmusic);
 						break;
 					case 16:
 						if ( bramscastlemusic )
 						{
-							bramscastlemusic->release();
+							OPENAL_Sound_Release (bramscastlemusic);
 						}
-						if ( musicPreload )
-						{
-							fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &bramscastlemusic);
-						}
-						else
-						{
-							fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &bramscastlemusic);
-						}
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &bramscastlemusic);
 						break;
 					case 17:
 						if ( hamletmusic )
 						{
-							hamletmusic->release();
+							OPENAL_Sound_Release (hamletmusic);
 						}
-						if ( musicPreload )
-						{
-							fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &hamletmusic);
-						}
-						else
-						{
-							fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &hamletmusic);
-						}
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &hamletmusic);
 						break;
 					case 18:
 						if ( tutorialmusic )
 						{
-							tutorialmusic->release();
+							OPENAL_Sound_Release (tutorialmusic);
 						}
-						if ( musicPreload )
-						{
-							fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &tutorialmusic);
-						}
-						else
-						{
-							fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &tutorialmusic);
-						}
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &tutorialmusic);
 						break;
 					case 19:
 						if ( gameovermusic )
 						{
-							gameovermusic->release();
+							OPENAL_Sound_Release (gameovermusic);
 						}
-						if ( musicPreload )
-						{
-							fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_DEFAULT, nullptr, &gameovermusic);
-						}
-						else
-						{
-							fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_DEFAULT, nullptr, &gameovermusic);
-						}
+						fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &gameovermusic);
 						break;
 					case 20:
 						if ( introstorymusic )
 						{
-							introstorymusic->release();
+							OPENAL_Sound_Release (introstorymusic);
 						}
 						if ( musicPreload )
 						{
-							fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_DEFAULT, nullptr, &introstorymusic);
+							fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &introstorymusic);
 						}
 						else
 						{
-							fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_DEFAULT, nullptr, &introstorymusic);
+							fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &introstorymusic);
 						}
 						break;
 					default:
@@ -1620,7 +1477,7 @@ void physfsReloadMusic(bool &introMusicChanged, bool r
 	}
 
 	int c;
-	FMOD::Sound** music = nullptr;
+	OPENAL_BUFFER** music = nullptr;
 
 	if (FMOD_OK != (fmod_result = physfsReloadMusic_helper_reloadMusicArray(NUMMINESMUSIC, "music/mines%02d.ogg", minesmusic, reloadAll)) )
 	{
@@ -1682,77 +1539,56 @@ void physfsReloadMusic(bool &introMusicChanged, bool r
 				music = intromusic;
 				if ( music )
 				{
-					music[c]->release();
+					OPENAL_Sound_Release(music[c]);
 				}
-                if ( musicPreload )
-                {
-                    fmod_result = fmod_system->createSound(musicDir.c_str(), FMOD_2D, nullptr, &music[c]);
-                }
-                else
-                {
-                    fmod_result = fmod_system->createStream(musicDir.c_str(), FMOD_2D, nullptr, &music[c]);
-                }
-                introChanged = true;
-                if (fmod_result != FMOD_OK)
-                {
-                    printlog("[PhysFS]: ERROR: Failed reloading music file \"%s\".");
-                    break; //TODO: Handle the error?
-                }
+				fmod_result = OPENAL_CreateStreamSound(musicDir.c_str(), &music[c]);
+				introChanged = true;
+				if (fmod_result != FMOD_OK)
+				{
+					printlog("[PhysFS]: ERROR: Failed reloading music file \"%s\".");
+					break; //TODO: Handle the error?
+				}
 			}
 		}
 	}
 
 	introMusicChanged = introChanged; // use this variable outside of this function to start playing a new fresh list of tracks in the main menu.
-#ifdef USE_OPENAL
-#undef FMOD_System_CreateStream
-#undef FMOD_SOUND
-#undef fmod_system
-#undef FMOD_SOFTWARE
-#undef FMOD_Sound_Release
-#endif
-
 #endif // SOUND
 }
 
 void gamemodsUnloadCustomThemeMusic()
 {
 #ifdef SOUND
-#ifdef USE_OPENAL
-#define FMOD_Sound_Release OPENAL_Sound_Release
-#endif
 	// free custom music slots, not used by official music assets.
 	if ( gnomishminesmusic )
 	{
-		gnomishminesmusic->release();
+		OPENAL_Sound_Release(gnomishminesmusic);
 		gnomishminesmusic = nullptr;
 	}
 	if ( greatcastlemusic )
 	{
-		greatcastlemusic->release();
+		OPENAL_Sound_Release(greatcastlemusic);
 		greatcastlemusic = nullptr;
 	}
 	if ( sokobanmusic )
 	{
-		sokobanmusic->release();
+		OPENAL_Sound_Release(sokobanmusic);
 		sokobanmusic = nullptr;
 	}
 	if ( caveslairmusic )
 	{
-		caveslairmusic->release();
+		OPENAL_Sound_Release(caveslairmusic);
 		caveslairmusic = nullptr;
 	}
 	if ( bramscastlemusic )
 	{
-		bramscastlemusic->release();
+		OPENAL_Sound_Release(bramscastlemusic);
 		bramscastlemusic = nullptr;
 	}
 	if ( hamletmusic )
 	{
-		hamletmusic->release();
+		OPENAL_Sound_Release(hamletmusic);
 		hamletmusic = nullptr;
 	}
-#ifdef USE_OPENAL
-#undef FMOD_Sound_Release
-#endif
 #endif // !SOUND
 }
