--- Source/WebCore/PAL/pal/system/wayland/SleepDisablerWayland.h.orig	2024-08-12 06:05:37 UTC
+++ Source/WebCore/PAL/pal/system/wayland/SleepDisablerWayland.h
@@ -0,0 +1,26 @@
+#pragma once
+
+#include "SleepDisabler.h"
+#include "idle-inhibit-unstable-v1-client-protocol.h"
+
+namespace PAL {
+    class SleepDisablerWaylandState {
+    public:
+        struct wl_display *display{};
+        struct wl_compositor *compositor{};
+        struct zwp_idle_inhibit_manager_v1 *wl_idle_inhibit_manager{};
+        struct wl_surface *surface{};
+        bool initialized{false};
+    };
+
+    class SleepDisablerWayland final : public SleepDisabler {
+    public:
+        SleepDisablerWayland(const String&, Type);
+        virtual ~SleepDisablerWayland();
+
+    private:
+        static SleepDisablerWaylandState& disablerState();
+        struct zwp_idle_inhibitor_v1 *idle{};
+    };
+
+} // namespace PAL
