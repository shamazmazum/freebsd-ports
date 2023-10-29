--- src/engine/audio/music.cpp.orig	2023-10-29 15:17:42 UTC
+++ src/engine/audio/music.cpp
@@ -26,53 +26,53 @@ bool loadMusic()
 {
     if ( NUMMINESMUSIC > 0 )
     {
-        minesmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMMINESMUSIC);
-        memset(minesmusic, 0, sizeof(FMOD::Sound*) * NUMMINESMUSIC);
+        minesmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMMINESMUSIC);
+        memset(minesmusic, 0, sizeof(OPENAL_BUFFER*) * NUMMINESMUSIC);
     }
     if ( NUMSWAMPMUSIC > 0 )
     {
-        swampmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMSWAMPMUSIC);
-        memset(swampmusic, 0, sizeof(FMOD::Sound*) * NUMSWAMPMUSIC);
+        swampmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMSWAMPMUSIC);
+        memset(swampmusic, 0, sizeof(OPENAL_BUFFER*) * NUMSWAMPMUSIC);
     }
     if ( NUMLABYRINTHMUSIC > 0 )
     {
-        labyrinthmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMLABYRINTHMUSIC);
-        memset(labyrinthmusic, 0, sizeof(FMOD::Sound*) * NUMLABYRINTHMUSIC);
+        labyrinthmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMLABYRINTHMUSIC);
+        memset(labyrinthmusic, 0, sizeof(OPENAL_BUFFER*) * NUMLABYRINTHMUSIC);
     }
     if ( NUMRUINSMUSIC > 0 )
     {
-        ruinsmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMRUINSMUSIC);
-        memset(ruinsmusic, 0, sizeof(FMOD::Sound*) * NUMRUINSMUSIC);
+        ruinsmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMRUINSMUSIC);
+        memset(ruinsmusic, 0, sizeof(OPENAL_BUFFER*) * NUMRUINSMUSIC);
     }
     if ( NUMUNDERWORLDMUSIC > 0 )
     {
-        underworldmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMUNDERWORLDMUSIC);
-        memset(underworldmusic, 0, sizeof(FMOD::Sound*) * NUMUNDERWORLDMUSIC);
+        underworldmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMUNDERWORLDMUSIC);
+        memset(underworldmusic, 0, sizeof(OPENAL_BUFFER*) * NUMUNDERWORLDMUSIC);
     }
     if ( NUMHELLMUSIC > 0 )
     {
-        hellmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMHELLMUSIC);
-        memset(hellmusic, 0, sizeof(FMOD::Sound*) * NUMHELLMUSIC);
+        hellmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMHELLMUSIC);
+        memset(hellmusic, 0, sizeof(OPENAL_BUFFER*) * NUMHELLMUSIC);
     }
     if ( NUMMINOTAURMUSIC > 0 )
     {
-        minotaurmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMMINOTAURMUSIC);
-        memset(minotaurmusic, 0, sizeof(FMOD::Sound*) * NUMMINOTAURMUSIC);
+        minotaurmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMMINOTAURMUSIC);
+        memset(minotaurmusic, 0, sizeof(OPENAL_BUFFER*) * NUMMINOTAURMUSIC);
     }
     if ( NUMCAVESMUSIC > 0 )
     {
-        cavesmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMCAVESMUSIC);
-        memset(cavesmusic, 0, sizeof(FMOD::Sound*) * NUMCAVESMUSIC);
+        cavesmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMCAVESMUSIC);
+        memset(cavesmusic, 0, sizeof(OPENAL_BUFFER*) * NUMCAVESMUSIC);
     }
     if ( NUMCITADELMUSIC > 0 )
     {
-        citadelmusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMCITADELMUSIC);
-        memset(citadelmusic, 0, sizeof(FMOD::Sound*) * NUMCITADELMUSIC);
+        citadelmusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMCITADELMUSIC);
+        memset(citadelmusic, 0, sizeof(OPENAL_BUFFER*) * NUMCITADELMUSIC);
     }
     if ( NUMINTROMUSIC > 0 )
     {
-        intromusic = (FMOD::Sound**)malloc(sizeof(FMOD::Sound*) * NUMINTROMUSIC);
-        memset(intromusic, 0, sizeof(FMOD::Sound*) * NUMINTROMUSIC);
+        intromusic = (OPENAL_BUFFER**)malloc(sizeof(OPENAL_BUFFER*) * NUMINTROMUSIC);
+        memset(intromusic, 0, sizeof(OPENAL_BUFFER*) * NUMINTROMUSIC);
     }
 	
     bool introMusicChanged;
@@ -162,16 +162,6 @@ void playMusic(FMOD::Sound* sound, bool loop, bool cro
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
