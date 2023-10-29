--- src/engine/audio/music.cpp.orig	2023-10-29 04:13:44 UTC
+++ src/engine/audio/music.cpp
@@ -27,138 +27,132 @@ bool loadMusic()
 
 	// load music
 #ifdef SOUND
-#ifdef USE_OPENAL
-#define fmod_system 0
-#define FMOD_SOFTWARE 0
-#define fmod_system->createStream(A, B, C, D, E) OPENAL_CreateStreamSound(B, E)
-#define FMOD::Sound OPENAL_BUFFER
-int fmod_result;
-#endif
+    int fmod_result;
 
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_INTRODUCTION, FMOD_DEFAULT, nullptr, &introductionmusic); //TODO: FMOD_SOFTWARE -> FMOD_DEFAULT?
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_INTERMISSION, FMOD_DEFAULT, nullptr, &intermissionmusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_MINETOWN, FMOD_DEFAULT, nullptr, &minetownmusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_SPLASH, FMOD_DEFAULT, nullptr, &splashmusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_LIBRARY, FMOD_DEFAULT, nullptr, &librarymusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_SHOP, FMOD_DEFAULT, nullptr, &shopmusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_HERXBOSS, FMOD_DEFAULT, nullptr, &herxmusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_TEMPLE, FMOD_DEFAULT, nullptr, &templemusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_ENDGAME, FMOD_DEFAULT, nullptr, &endgamemusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_ESCAPE, FMOD_DEFAULT, nullptr, &escapemusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_DEVIL, FMOD_DEFAULT, nullptr, &devilmusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_SANCTUM, FMOD_DEFAULT, nullptr, &sanctummusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_TUTORIAL, FMOD_DEFAULT, nullptr, &tutorialmusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_INTROSTORY, FMOD_DEFAULT, nullptr, &introstorymusic);
-	fmod_result = fmod_system->createStream(MUSIC_FILEPATH_GAMEOVER, FMOD_DEFAULT, nullptr, &gameovermusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_INTRODUCTION, &introductionmusic); //TODO: FMOD_SOFTWARE -> FMOD_DEFAULT?
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_INTERMISSION, &intermissionmusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_MINETOWN, &minetownmusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_SPLASH, &splashmusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_LIBRARY, &librarymusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_SHOP, &shopmusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_HERXBOSS, &herxmusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_TEMPLE, &templemusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_ENDGAME, &endgamemusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_ESCAPE, &escapemusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_DEVIL, &devilmusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_SANCTUM, &sanctummusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_TUTORIAL, &tutorialmusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_INTROSTORY, &introstorymusic);
+	fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_GAMEOVER, &gameovermusic);
 	if ( PHYSFS_getRealDir(MUSIC_FILEPATH_GNOMISH_MINES) != nullptr )
 	{
-		fmod_result = fmod_system->createStream(MUSIC_FILEPATH_GNOMISH_MINES, FMOD_DEFAULT, nullptr, &gnomishminesmusic);
+		fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_GNOMISH_MINES, &gnomishminesmusic);
 	}
 	if ( PHYSFS_getRealDir(MUSIC_FILEPATH_GREATCASTLE) != nullptr )
 	{
-		fmod_result = fmod_system->createStream(MUSIC_FILEPATH_GREATCASTLE, FMOD_DEFAULT, nullptr, &greatcastlemusic);
+		fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_GREATCASTLE, &greatcastlemusic);
 	}
 	if ( PHYSFS_getRealDir(MUSIC_FILEPATH_SOKOBAN) != nullptr )
 	{
-		fmod_result = fmod_system->createStream(MUSIC_FILEPATH_SOKOBAN, FMOD_DEFAULT, nullptr, &sokobanmusic);
+		fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_SOKOBAN, &sokobanmusic);
 	}
 	if ( PHYSFS_getRealDir(MUSIC_FILEPATH_CAVES_LAIR) != nullptr )
 	{
-		fmod_result = fmod_system->createStream(MUSIC_FILEPATH_CAVES_LAIR, FMOD_DEFAULT, nullptr, &caveslairmusic);
+		fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_CAVES_LAIR, &caveslairmusic);
 	}
 	if ( PHYSFS_getRealDir(MUSIC_FILEPATH_BRAMS_CASTLE) != nullptr )
 	{
-		fmod_result = fmod_system->createStream(MUSIC_FILEPATH_BRAMS_CASTLE, FMOD_DEFAULT, nullptr, &bramscastlemusic);
+		fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_BRAMS_CASTLE, &bramscastlemusic);
 	}
 	if ( PHYSFS_getRealDir(MUSIC_FILEPATH_HAMLET) != nullptr )
 	{
-		fmod_result = fmod_system->createStream(MUSIC_FILEPATH_HAMLET, FMOD_DEFAULT, nullptr, &hamletmusic);
+		fmod_result = OPENAL_CreateStreamSound(MUSIC_FILEPATH_HAMLET, &hamletmusic);
 	}
 
 	if ( NUMMINESMUSIC > 0 )
 	{
-		minesmusic = (FMOD::Sound**) malloc(sizeof(FMOD::Sound*)*NUMMINESMUSIC);
+		minesmusic = (OPENAL_BUFFER**) malloc(sizeof(OPENAL_BUFFER*)*NUMMINESMUSIC);
 		for ( c = 0; c < NUMMINESMUSIC; c++ )
 		{
 			snprintf(tempstr, 1000, MUSIC_FILEPATH_MINES, c);
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &minesmusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &minesmusic[c]);
 		}
 	}
 	if ( NUMSWAMPMUSIC > 0 )
 	{
-		swampmusic = (FMOD::Sound**) malloc(sizeof(FMOD::Sound*)*NUMSWAMPMUSIC);
+		swampmusic = (OPENAL_BUFFER**) malloc(sizeof(OPENAL_BUFFER*)*NUMSWAMPMUSIC);
 		for ( c = 0; c < NUMSWAMPMUSIC; c++ )
 		{
 			snprintf(tempstr, 1000, MUSIC_FILEPATH_SWAMP, c);
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &swampmusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &swampmusic[c]);
 		}
 	}
 	if ( NUMLABYRINTHMUSIC > 0 )
 	{
-		labyrinthmusic = (FMOD::Sound**) malloc(sizeof(FMOD::Sound*)*NUMLABYRINTHMUSIC);
+		labyrinthmusic = (OPENAL_BUFFER**) malloc(sizeof(OPENAL_BUFFER*)*NUMLABYRINTHMUSIC);
 		for ( c = 0; c < NUMLABYRINTHMUSIC; c++ )
 		{
 			snprintf(tempstr, 1000, MUSIC_FILEPATH_LABYRINTH, c);
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &labyrinthmusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &labyrinthmusic[c]);
 		}
 	}
 	if ( NUMRUINSMUSIC > 0 )
 	{
-		ruinsmusic = (FMOD::Sound**) malloc(sizeof(FMOD::Sound*)*NUMRUINSMUSIC);
+		ruinsmusic = (OPENAL_BUFFER**) malloc(sizeof(OPENAL_BUFFER*)*NUMRUINSMUSIC);
 		for ( c = 0; c < NUMRUINSMUSIC; c++ )
 		{
 			snprintf(tempstr, 1000, MUSIC_FILEPATH_RUINS, c);
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &ruinsmusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &ruinsmusic[c]);
 		}
 	}
 	if ( NUMUNDERWORLDMUSIC > 0 )
 	{
-		underworldmusic = (FMOD::Sound**) malloc(sizeof(FMOD::Sound*)*NUMUNDERWORLDMUSIC);
+		underworldmusic = (OPENAL_BUFFER**) malloc(sizeof(OPENAL_BUFFER*)*NUMUNDERWORLDMUSIC);
 		for ( c = 0; c < NUMUNDERWORLDMUSIC; c++ )
 		{
 			snprintf(tempstr, 1000, MUSIC_FILEPATH_UNDERWORLD, c);
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &underworldmusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &underworldmusic[c]);
 		}
 	}
 	if ( NUMHELLMUSIC > 0 )
 	{
-		hellmusic = (FMOD::Sound**) malloc(sizeof(FMOD::Sound*)*NUMHELLMUSIC);
+		hellmusic = (OPENAL_BUFFER**) malloc(sizeof(OPENAL_BUFFER*)*NUMHELLMUSIC);
 		for ( c = 0; c < NUMHELLMUSIC; c++ )
 		{
 			snprintf(tempstr, 1000, MUSIC_FILEPATH_HELL, c);
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &hellmusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &hellmusic[c]);
 		}
 	}
 	if ( NUMMINOTAURMUSIC > 0 )
 	{
-		minotaurmusic = (FMOD::Sound**) malloc(sizeof(FMOD::Sound*)*NUMMINOTAURMUSIC);
+		minotaurmusic = (OPENAL_BUFFER**) malloc(sizeof(OPENAL_BUFFER*)*NUMMINOTAURMUSIC);
 		for ( c = 0; c < NUMMINOTAURMUSIC; c++ )
 		{
 			snprintf(tempstr, 1000, MUSIC_FILEPATH_MINOTAUR, c);
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &minotaurmusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &minotaurmusic[c]);
 		}
 	}
 	if ( NUMCAVESMUSIC > 0 )
 	{
-		cavesmusic = (FMOD::Sound**) malloc(sizeof(FMOD::Sound*)*NUMCAVESMUSIC);
+		cavesmusic = (OPENAL_BUFFER**) malloc(sizeof(OPENAL_BUFFER*)*NUMCAVESMUSIC);
 		for ( c = 0; c < NUMCAVESMUSIC; c++ )
 		{
 			snprintf(tempstr, 1000, MUSIC_FILEPATH_CAVES, c);
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &cavesmusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &cavesmusic[c]);
 		}
 	}
 	if ( NUMCITADELMUSIC > 0 )
 	{
-		citadelmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*)*NUMCITADELMUSIC);
+		citadelmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*)*NUMCITADELMUSIC);
 		for ( c = 0; c < NUMCITADELMUSIC; c++ )
 		{
 			snprintf(tempstr, 1000, MUSIC_FILEPATH_CITADEL, c);
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &citadelmusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &citadelmusic[c]);
 		}
 	}
 	if ( NUMINTROMUSIC > 0 )
 	{
-		intromusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*)*NUMINTROMUSIC);
+		intromusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*)*NUMINTROMUSIC);
 		for ( c = 0; c < NUMINTROMUSIC; c++ )
 		{
 			if ( c == 0 )
@@ -169,18 +163,11 @@ int fmod_result;
 			{
 				snprintf(tempstr, 1000, MUSIC_FILEPATH_ADDITIONAL_INTROS, c);
 			}
-			fmod_result = fmod_system->createStream(tempstr, FMOD_DEFAULT, nullptr, &intromusic[c]);
+			fmod_result = OPENAL_CreateStreamSound(tempstr, &intromusic[c]);
 		}
 	}
-#ifdef USE_OPENAL
-#undef fmod_system
-#undef FMOD_SOFTWARE
-#undef fmod_system->createStream
-#undef FMOD::Sound
 #endif
 
-#endif
-
 	return true;
 }
 
@@ -266,16 +253,6 @@ void playMusic(FMOD::Sound* sound, bool loop, bool cro
 	}
 }
 #endif
-
-bool shopmusicplaying = false;
-bool combatmusicplaying = false;
-bool minotaurmusicplaying = false;
-bool herxmusicplaying = false;
-bool devilmusicplaying = false;
-bool olddarkmap = false;
-bool sanctummusicplaying = false;
-
-int currenttrack = -1;
 
 #ifdef USE_FMOD
 void handleLevelMusic()
