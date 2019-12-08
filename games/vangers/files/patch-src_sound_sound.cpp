--- src/sound/sound.cpp.orig
+++ src/sound/sound.cpp
@@ -444,40 +444,45 @@ void SoundQuant(void)
 	int DiffSound = SoundFlag ^ lastSoundFlag;
 	
 	if (DiffSound){
-		if (DiffSound & SoundCopterig)
-			if (SoundFlag & SoundCopterig){
+		if (DiffSound & SoundCopterig) {
+			if (SoundFlag & SoundCopterig) {
 				SOUND_COPTERIG_START()
-			}else{
+			} else {
 				SOUND_COPTERIG_STOP()
 			}
+		}
 
-		if (DiffSound & SoundCrotrig)
-			if (SoundFlag & SoundCrotrig){
+		if (DiffSound & SoundCrotrig) {
+			if (SoundFlag & SoundCrotrig) {
 				SOUND_CROTRIG_START()
-			}else {
+			} else {
 				SOUND_CROTRIG_STOP()
 			}
+		}
 
-		if (DiffSound & SoundCutterig)
-			if (SoundFlag & SoundCutterig){
+		if (DiffSound & SoundCutterig) {
+			if (SoundFlag & SoundCutterig) {
 				SOUND_CUTTERIG_START()
-			}else{
+			} else {
 				SOUND_CUTTERIG_STOP()
 			}
+		}
 
-		if (DiffSound & SoundUnderWater)
-			if (SoundFlag & SoundUnderWater){
+		if (DiffSound & SoundUnderWater) {
+			if (SoundFlag & SoundUnderWater) {
 				SOUND_UNDERWATER_START()
-			}else{
+			} else {
 				SOUND_UNDERWATER_STOP()
 			}
+		}
 
-		if (DiffSound & SoundMotor)
-			if (SoundFlag & SoundMotor){
+		if (DiffSound & SoundMotor) {
+			if (SoundFlag & SoundMotor) {
 				SOUND_START_MOTOR()
-			}else {
+			} else {
 				SOUND_STOP_MOTOR()
 			}
+		}
 	}
 		
 	lastSoundFlag = SoundFlag;
@@ -688,4 +693,3 @@ void LastSoundQuant(void){
 		}
 	} 
 }
-
