--- xonar.c.orig	2023-10-27 10:04:55 UTC
+++ xonar.c
@@ -1409,6 +1409,6 @@ static driver_t cmi8788_driver = {
     PCM_SOFTC_SIZE,
 };
 
-DRIVER_MODULE(snd_cmi8788, pci, cmi8788_driver, pcm_devclass, NULL, NULL);
+DRIVER_MODULE(snd_cmi8788, pci, cmi8788_driver, NULL, NULL);
 MODULE_DEPEND(snd_cmi8788, sound, SOUND_MINVER, SOUND_PREFVER, SOUND_MAXVER);
 MODULE_VERSION(snd_cmi8788, 0);
