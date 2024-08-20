--- Source/WebCore/PAL/pal/PlatformGTK.cmake.orig	2023-09-19 08:27:49 UTC
+++ Source/WebCore/PAL/pal/PlatformGTK.cmake
@@ -8,18 +8,25 @@ list(APPEND PAL_SOURCES
 
 list(APPEND PAL_SOURCES
     crypto/gcrypt/CryptoDigestGCrypt.cpp
-
     system/ClockGeneric.cpp
-
-    system/glib/SleepDisablerGLib.cpp
-
     system/gtk/SoundGtk.cpp
-
     text/KillRing.cpp
-
     unix/LoggingUnix.cpp
 )
 
+if (ENABLE_WAYLAND_TARGET)
+  list(APPEND PAL_SOURCES
+    system/wayland/SleepDisablerWayland.cpp
+  )
+  list(APPEND PAL_DERIVED_SOURCES
+    ${PAL_DERIVED_SOURCES_DIR}/idle-inhibit-unstable-v1-protocol.c
+  )
+else (ENABLE_WAYLAND_TARGET)
+  list(APPEND PAL_SOURCES
+    system/glib/SleepDisablerGLib.cpp
+  )
+endif (ENABLE_WAYLAND_TARGET)
+
 if (ENABLE_WEB_CRYPTO)
     list(APPEND PAL_PUBLIC_HEADERS
         crypto/tasn1/Utilities.h
@@ -28,6 +35,16 @@ if (ENABLE_WEB_CRYPTO)
     list(APPEND PAL_SOURCES
         crypto/tasn1/Utilities.cpp
     )
+endif ()
+
+if (ENABLE_WAYLAND_TARGET)
+  add_custom_command(
+    OUTPUT ${PAL_DERIVED_SOURCES_DIR}/idle-inhibit-unstable-v1-protocol.c
+    DEPENDS ${WAYLAND_PROTOCOLS_DATADIR}/unstable/idle-inhibit/idle-inhibit-unstable-v1.xml
+    COMMAND ${WAYLAND_SCANNER} private-code ${WAYLAND_PROTOCOLS_DATADIR}/unstable/idle-inhibit/idle-inhibit-unstable-v1.xml ${PAL_DERIVED_SOURCES_DIR}/idle-inhibit-unstable-v1-protocol.c
+    COMMAND ${WAYLAND_SCANNER} client-header ${WAYLAND_PROTOCOLS_DATADIR}/unstable/idle-inhibit/idle-inhibit-unstable-v1.xml ${PAL_DERIVED_SOURCES_DIR}/idle-inhibit-unstable-v1-client-protocol.h
+    VERBATIM
+  )
 endif ()
 
 list(APPEND PAL_LIBRARIES
