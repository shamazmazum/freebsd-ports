--- src/game/filesystem_container.rs.orig	2026-09-23 12:57:03 UTC
+++ src/game/filesystem_container.rs
@@ -24,44 +24,7 @@ impl FilesystemContainer {
 
     pub fn mount_fs(&mut self, context: &mut Context) -> GameResult {
         #[cfg(not(any(target_os = "android", target_os = "horizon")))]
-        let resource_dir = if let Ok(data_dir) = std::env::var("CAVESTORY_DATA_DIR") {
-            PathBuf::from(data_dir)
-        } else {
-            let mut resource_dir = std::env::current_exe()?;
-            if resource_dir.file_name().is_some() {
-                let _ = resource_dir.pop();
-            }
-
-            #[cfg(target_os = "macos")]
-            {
-                let mut bundle_dir = resource_dir.clone();
-                let _ = bundle_dir.pop();
-                let mut bundle_exec_dir = bundle_dir.clone();
-                let mut csplus_data_dir = bundle_dir.clone();
-                let _ = csplus_data_dir.pop();
-                let _ = csplus_data_dir.pop();
-                let mut csplus_data_base_dir = csplus_data_dir.clone();
-                csplus_data_base_dir.push("data");
-                csplus_data_base_dir.push("base");
-
-                bundle_exec_dir.push("MacOS");
-                bundle_dir.push("Resources");
-
-                if bundle_exec_dir.is_dir() && bundle_dir.is_dir() {
-                    log::info!("Running in macOS bundle mode");
-
-                    if csplus_data_base_dir.is_dir() {
-                        log::info!("Cave Story+ Steam detected");
-                        resource_dir = csplus_data_dir;
-                    } else {
-                        resource_dir = bundle_dir;
-                    }
-                }
-            }
-
-            resource_dir.push("data");
-            resource_dir
-        };
+        let resource_dir = PathBuf::from("%%DATADIR%%/data");
 
         #[cfg(not(any(target_os = "android", target_os = "horizon")))]
         log::info!("Resource directory: {:?}", resource_dir);
