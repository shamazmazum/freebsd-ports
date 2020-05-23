--- src/shims/time.h.orig	2020-05-23 14:38:53 UTC
+++ src/shims/time.h
@@ -52,8 +52,8 @@ typedef struct _dispatch_host_time_data_s {
 	bool ratio_1_to_1;
 	dispatch_once_t pred;
 } _dispatch_host_time_data_s;
-__private_extern__ _dispatch_host_time_data_s _dispatch_host_time_data;
-__private_extern__ void _dispatch_get_host_time_init(void *context);
+extern _dispatch_host_time_data_s _dispatch_host_time_data;
+extern void _dispatch_get_host_time_init(void *context);
 
 static inline uint64_t
 _dispatch_time_mach2nano(uint64_t machtime)
