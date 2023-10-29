--- src/init_game.cpp.orig	2023-10-29 04:13:16 UTC
+++ src/init_game.cpp
@@ -533,33 +533,33 @@ void deinitGame()
 #endif
 	if ( !no_sound )
 	{
-		music_channel->stop();
-		music_channel2->stop();
-		introductionmusic->release();
-		intermissionmusic->release();
-		minetownmusic->release();
-		splashmusic->release();
-		librarymusic->release();
-		shopmusic->release();
-		herxmusic->release();
-		templemusic->release();
-		endgamemusic->release();
-		escapemusic->release();
-		devilmusic->release();
-		sanctummusic->release();
-		gnomishminesmusic->release();
-		greatcastlemusic->release();
-		sokobanmusic->release();
-		caveslairmusic->release();
-		bramscastlemusic->release();
-		hamletmusic->release();
-		tutorialmusic->release();
-		introstorymusic->release();
-		gameovermusic->release();
+		FMOD_Channel_Stop(music_channel);
+		FMOD_Channel_Stop(music_channel2);
+		FMOD_Sound_Release(introductionmusic);
+		FMOD_Sound_Release(intermissionmusic);
+		FMOD_Sound_Release(minetownmusic);
+		FMOD_Sound_Release(splashmusic);
+		FMOD_Sound_Release(librarymusic);
+		FMOD_Sound_Release(shopmusic);
+		FMOD_Sound_Release(herxmusic);
+		FMOD_Sound_Release(templemusic);
+		FMOD_Sound_Release(endgamemusic);
+		FMOD_Sound_Release(escapemusic);
+		FMOD_Sound_Release(devilmusic);
+		FMOD_Sound_Release(sanctummusic);
+		FMOD_Sound_Release(gnomishminesmusic);
+		FMOD_Sound_Release(greatcastlemusic);
+		FMOD_Sound_Release(sokobanmusic);
+		FMOD_Sound_Release(caveslairmusic);
+		FMOD_Sound_Release(bramscastlemusic);
+		FMOD_Sound_Release(hamletmusic);
+		FMOD_Sound_Release(tutorialmusic);
+		FMOD_Sound_Release(introstorymusic);
+		FMOD_Sound_Release(gameovermusic);
 
 		for ( int c = 0; c < NUMMINESMUSIC; c++ )
 		{
-			minesmusic[c]->release();
+			FMOD_Sound_Release(minesmusic[c]);
 		}
 		if ( minesmusic )
 		{
@@ -567,7 +567,7 @@ void deinitGame()
 		}
 		for ( int c = 0; c < NUMSWAMPMUSIC; c++ )
 		{
-			swampmusic[c]->release();
+			FMOD_Sound_Release(swampmusic[c]);
 		}
 		if ( swampmusic )
 		{
@@ -575,7 +575,7 @@ void deinitGame()
 		}
 		for ( int c = 0; c < NUMLABYRINTHMUSIC; c++ )
 		{
-			labyrinthmusic[c]->release();
+			FMOD_Sound_Release(labyrinthmusic[c]);
 		}
 		if ( labyrinthmusic )
 		{
@@ -583,7 +583,7 @@ void deinitGame()
 		}
 		for ( int c = 0; c < NUMRUINSMUSIC; c++ )
 		{
-			ruinsmusic[c]->release();
+			FMOD_Sound_Release(ruinsmusic[c]);
 		}
 		if ( ruinsmusic )
 		{
@@ -591,7 +591,7 @@ void deinitGame()
 		}
 		for ( int c = 0; c < NUMUNDERWORLDMUSIC; c++ )
 		{
-			underworldmusic[c]->release();
+			FMOD_Sound_Release(underworldmusic[c]);
 		}
 		if ( underworldmusic )
 		{
@@ -599,7 +599,7 @@ void deinitGame()
 		}
 		for ( int c = 0; c < NUMHELLMUSIC; c++ )
 		{
-			hellmusic[c]->release();
+			FMOD_Sound_Release(hellmusic[c]);
 		}
 		if ( hellmusic )
 		{
@@ -607,7 +607,7 @@ void deinitGame()
 		}
 		for ( int c = 0; c < NUMMINOTAURMUSIC; c++ )
 		{
-			minotaurmusic[c]->release();
+			FMOD_Sound_Release(minotaurmusic[c]);
 		}
 		if ( minotaurmusic )
 		{
@@ -615,7 +615,7 @@ void deinitGame()
 		}
 		for ( int c = 0; c < NUMCAVESMUSIC; c++ )
 		{
-			cavesmusic[c]->release();
+			FMOD_Sound_Release(cavesmusic[c]);
 		}
 		if ( cavesmusic )
 		{
@@ -623,7 +623,7 @@ void deinitGame()
 		}
 		for ( int c = 0; c < NUMCITADELMUSIC; c++ )
 		{
-			citadelmusic[c]->release();
+			FMOD_Sound_Release(citadelmusic[c]);
 		}
 		if ( citadelmusic )
 		{
@@ -631,7 +631,7 @@ void deinitGame()
 		}
 		for ( int c = 0; c < NUMINTROMUSIC; c++ )
 		{
-			intromusic[c]->release();
+			FMOD_Sound_Release(intromusic[c]);
 		}
 		if ( intromusic )
 		{
