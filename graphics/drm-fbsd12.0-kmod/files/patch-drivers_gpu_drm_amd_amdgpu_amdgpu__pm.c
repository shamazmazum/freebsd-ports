--- drivers/gpu/drm/amd/amdgpu/amdgpu_pm.c.orig	2019-01-20 17:26:16.729407000 +0300
+++ drivers/gpu/drm/amd/amdgpu/amdgpu_pm.c	2019-01-20 17:29:24.264815000 +0300
@@ -31,8 +31,11 @@
 #include <linux/power_supply.h>
 #include <linux/hwmon.h>
 #include <linux/hwmon-sysfs.h>
+#ifndef __linux__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 
-
 static int amdgpu_debugfs_pm_init(struct amdgpu_device *adev);
 
 static const struct cg_flag_name clocks[] = {
@@ -1313,6 +1316,38 @@
 
 }
 
+#ifndef __linux__
+static int sysctl_amdgpu_temp (SYSCTL_HANDLER_ARGS)
+{
+	struct device *dev = oidp->oid_arg1;
+	struct drm_device *ddev = dev_get_drvdata(dev);
+	struct amdgpu_device *adev = ddev->dev_private;
+	int temp, err;
+
+	/* Can't get temperature when the card is off */
+	if	((adev->flags & AMD_IS_PX) &&
+		 (ddev->switch_power_state != DRM_SWITCH_POWER_ON))
+		return EINVAL;
+
+	if (!adev->powerplay.pp_funcs->get_temperature)
+		temp = 0;
+	else
+		temp = amdgpu_dpm_get_temperature(adev) + 273150;
+
+	err = sysctl_handle_int (oidp, &temp, 0, req);
+	return err;
+}
+
+static void freebsd_pm_hook (struct amdgpu_device *adev)
+{
+	dev_info (adev->dev, "Adding temperature sysctls\n");
+	SYSCTL_ADD_PROC (device_get_sysctl_ctx (adev->dev->bsddev),
+					 SYSCTL_CHILDREN (device_get_sysctl_tree (adev->dev->bsddev)), OID_AUTO,
+					 "temperature", CTLFLAG_RD | CTLTYPE_INT, adev->dev, sizeof (adev->dev),
+					 sysctl_amdgpu_temp, "IK3", "AMDGPU card temperature");
+}
+#endif
+
 int amdgpu_pm_sysfs_init(struct amdgpu_device *adev)
 {
 	int ret;
@@ -1416,6 +1451,10 @@
 	}
 
 	adev->pm.sysfs_initialized = true;
+
+#ifndef __linux__
+    freebsd_pm_hook (adev);
+#endif
 
 	return 0;
 }
