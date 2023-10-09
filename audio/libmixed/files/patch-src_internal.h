--- src/internal.h.orig	2023-10-09 18:46:15 UTC
+++ src/internal.h
@@ -30,17 +30,7 @@ static inline void __ignore(char _, ...){(void)_;}
 #define IGNORE(...) __ignore(0, __VA_ARGS__)
 static inline void __ignore(char _, ...){(void)_;}
 
-#if defined(__GNUC__) && !defined(__WIN32__)
-#if defined(__x86_64__)
-#define VECTORIZE __attribute__((target_clones("avx2","avx","sse4.1","default")))
-#elif defined(__arm__)
-#define VECTORIZE __attribute__((target_clones("neon","default")))
-#else
 #define VECTORIZE
-#endif
-#else
-#define VECTORIZE
-#endif
 
 struct bip{
   void *data;
