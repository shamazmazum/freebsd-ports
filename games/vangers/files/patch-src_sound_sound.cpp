--- src/sound/sound.cpp.orig
+++ src/sound/sound.cpp
@@ -444,40 +444,45 @@ void SoundQuant(void)
 	int DiffSound = SoundFlag ^ lastSoundFlag;
 	
 	if (DiffSound){
-		if (DiffSound & SoundCopterig)
+		if (DiffSound & SoundCopterig) {
 			if (SoundFlag & SoundCopterig){
 				SOUND_COPTERIG_START()
 			}else{
 				SOUND_COPTERIG_STOP()
 			}
+		}
 
-		if (DiffSound & SoundCrotrig)
+		if (DiffSound & SoundCrotrig) {
 			if (SoundFlag & SoundCrotrig){
 				SOUND_CROTRIG_START()
 			}else {
 				SOUND_CROTRIG_STOP()
 			}
+		}
 
-		if (DiffSound & SoundCutterig)
+		if (DiffSound & SoundCutterig) {
 			if (SoundFlag & SoundCutterig){
 				SOUND_CUTTERIG_START()
 			}else{
 				SOUND_CUTTERIG_STOP()
 			}
+		}
 
-		if (DiffSound & SoundUnderWater)
+		if (DiffSound & SoundUnderWater) {
 			if (SoundFlag & SoundUnderWater){
 				SOUND_UNDERWATER_START()
 			}else{
 				SOUND_UNDERWATER_STOP()
 			}
+		}
 
-		if (DiffSound & SoundMotor)
+		if (DiffSound & SoundMotor) {
 			if (SoundFlag & SoundMotor){
 				SOUND_START_MOTOR()
 			}else {
 				SOUND_STOP_MOTOR()
 			}
+		}
 	}
 		
 	lastSoundFlag = SoundFlag;
