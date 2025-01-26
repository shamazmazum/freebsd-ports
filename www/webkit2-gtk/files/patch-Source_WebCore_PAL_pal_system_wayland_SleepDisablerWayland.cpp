--- Source/WebCore/PAL/pal/system/wayland/SleepDisablerWayland.cpp.orig	2024-08-12 06:05:37 UTC
+++ Source/WebCore/PAL/pal/system/wayland/SleepDisablerWayland.cpp
@@ -0,0 +1,89 @@
+#include <mutex>
+
+#include "config.h"
+#include "SleepDisablerWayland.h"
+
+namespace PAL {
+    std::unique_ptr<SleepDisabler> SleepDisabler::create(const String& reason, Type type) {
+        return std::unique_ptr<SleepDisabler>(new SleepDisablerWayland(reason, type));
+    }
+
+    SleepDisablerWayland::SleepDisablerWayland(const String& reason, Type type)
+        : SleepDisabler(reason, type) {
+        // We ignore Type because we always want to inhibit both screen lock and
+        // suspend, but only when idle. There is no reason for WebKit to ever block
+        // a user from manually suspending the computer, so inhibiting idle
+        // suffices. There's also probably no good reason for code taking a sleep
+        // disabler to differentiate between lock and suspend on our platform. If we
+        // ever need this distinction, which seems unlikely, then we'll need to
+        // audit all use of SleepDisabler.
+        SleepDisablerWaylandState state = disablerState();
+
+        if (state.initialized) {
+            idle = zwp_idle_inhibit_manager_v1_create_inhibitor (
+                state.wl_idle_inhibit_manager, state.surface);
+            wl_display_roundtrip (state.display);
+        }
+    }
+
+    SleepDisablerWayland::~SleepDisablerWayland() {
+        SleepDisablerWaylandState state = disablerState();
+
+        if (idle != nullptr) {
+            zwp_idle_inhibitor_v1_destroy (idle);
+            wl_display_roundtrip (state.display);
+        }
+    }
+
+    void global_add(void *data, struct wl_registry *registry, uint32_t name,
+                    const char *interface, uint32_t) {
+        SleepDisablerWaylandState *state = (SleepDisablerWaylandState *)data;
+
+        if (strcmp (interface, wl_compositor_interface.name) == 0) {
+            state->compositor = (struct wl_compositor*) wl_registry_bind (
+                registry, name, &wl_compositor_interface, 1);
+        } else if (strcmp (interface, zwp_idle_inhibit_manager_v1_interface.name) == 0) {
+            state->wl_idle_inhibit_manager =
+                (struct zwp_idle_inhibit_manager_v1*) wl_registry_bind (
+                    registry, name, &zwp_idle_inhibit_manager_v1_interface, 1);
+        }
+    }
+
+    void global_remove(void*, struct wl_registry*, uint32_t) {}
+
+    // FIXME: How to use PlatformDisplay here?
+    SleepDisablerWaylandState& SleepDisablerWayland::disablerState() {
+        static std::once_flag onceFlag;
+        static SleepDisablerWaylandState state;
+        std::call_once(onceFlag, []{
+            state.display = wl_display_connect(NULL);
+            if (state.display != nullptr) {
+                const struct wl_registry_listener registry_listener = {
+                    .global = global_add,
+                    .global_remove = global_remove,
+                };
+
+                struct wl_registry *registry = wl_display_get_registry (state.display);
+                wl_registry_add_listener (registry, &registry_listener, &state);
+                wl_display_roundtrip (state.display);
+            }
+
+            if (state.display != nullptr && state.wl_idle_inhibit_manager == nullptr) {
+                wl_display_disconnect(state.display);
+                state.display = nullptr;
+            }
+
+            if (state.display != nullptr && state.compositor == nullptr) {
+                wl_display_disconnect(state.display);
+                state.display = nullptr;
+            }
+
+            if (state.display != nullptr) {
+                state.surface = wl_compositor_create_surface (state.compositor);
+                state.initialized = true;
+            }
+        });
+        return state;
+    }
+
+} // namespace PAL
