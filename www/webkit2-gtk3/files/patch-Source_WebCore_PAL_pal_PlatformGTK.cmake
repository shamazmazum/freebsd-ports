--- Source/WebCore/PAL/pal/PlatformGTK.cmake.orig	2024-08-19 03:08:33 UTC
+++ Source/WebCore/PAL/pal/PlatformGTK.cmake
@@ -4,9 +4,26 @@ list(APPEND PAL_PUBLIC_HEADERS
     crypto/gcrypt/Utilities.h
 
     crypto/tasn1/Utilities.h
+)
 
+if (ENABLE_WAYLAND_TARGET)
+  list(APPEND PAL_PUBLIC_HEADERS
+    system/wayland/SleepDisablerWayland.h
+  )
+  list(APPEND PAL_SOURCES
+    system/wayland/SleepDisablerWayland.cpp
+  )
+  list(APPEND PAL_DERIVED_SOURCES
+    ${PAL_DERIVED_SOURCES_DIR}/idle-inhibit-unstable-v1-protocol.c
+  )
+else (ENABLE_WAYLAND_TARGET)
+  list(APPEND PAL_PUBLIC_HEADERS
     system/glib/SleepDisablerGLib.h
-)
+  )
+  list(APPEND PAL_SOURCES
+    system/glib/SleepDisablerGLib.cpp
+  )
+endif (ENABLE_WAYLAND_TARGET)
 
 list(APPEND PAL_SOURCES
     crypto/gcrypt/CryptoDigestGCrypt.cpp
@@ -23,6 +40,16 @@ list(APPEND PAL_SOURCES
 
     unix/LoggingUnix.cpp
 )
+
+if (ENABLE_WAYLAND_TARGET)
+  add_custom_command(
+    OUTPUT ${PAL_DERIVED_SOURCES_DIR}/idle-inhibit-unstable-v1-protocol.c
+    DEPENDS ${WAYLAND_PROTOCOLS_DATADIR}/unstable/idle-inhibit/idle-inhibit-unstable-v1.xml
+    COMMAND ${WAYLAND_SCANNER} private-code ${WAYLAND_PROTOCOLS_DATADIR}/unstable/idle-inhibit/idle-inhibit-unstable-v1.xml ${PAL_DERIVED_SOURCES_DIR}/idle-inhibit-unstable-v1-protocol.c
+    COMMAND ${WAYLAND_SCANNER} client-header ${WAYLAND_PROTOCOLS_DATADIR}/unstable/idle-inhibit/idle-inhibit-unstable-v1.xml ${PAL_DERIVED_SOURCES_DIR}/idle-inhibit-unstable-v1-client-protocol.h
+    VERBATIM
+  )
+ endif ()
 
 list(APPEND PAL_LIBRARIES
     GTK::GTK
