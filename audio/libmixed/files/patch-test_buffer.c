--- test/buffer.c.orig	2023-10-09 18:47:43 UTC
+++ test/buffer.c
@@ -369,7 +369,8 @@ define_test(randomized, {
     mixed_free_buffer(&buffer);
   });
 
-void *async_reader(struct mixed_buffer *buffer){
+void *async_reader(void *obj){
+  struct mixed_buffer *buffer = obj;
   uint32_t *status = calloc(sizeof(uint32_t), 1);
   uint32_t size = buffer->size;
   *status = 0;
