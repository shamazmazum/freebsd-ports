--- client/widgets/CComponentHolder.cpp.orig	2025-05-07 07:54:45 UTC
+++ client/widgets/CComponentHolder.cpp
@@ -114,7 +114,7 @@ void CArtPlace::setArtifact(const ArtifactID & newArtI
 	if(artId == ArtifactID::SPELL_SCROLL)
 	{
 		spellId = newSpellId;
-		assert(spellId.num > 0);
+		assert(spellId.num != spellID::NONE);
 
 		if(settings["general"]["enableUiEnhancements"].Bool())
 		{
