--- code/qcommon/q_platform.h.orig	2025-01-04 17:01:52 UTC
+++ code/qcommon/q_platform.h
@@ -99,6 +99,8 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 // alloca
 #ifdef _MSC_VER
 #  include <malloc.h>
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#  include <stdlib.h>
 #else
 #  include <alloca.h>
 #endif
@@ -318,16 +320,36 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#ifdef __i386__
-#define ARCH_STRING "i386"
-#elif defined __axp__
-#define ARCH_STRING "alpha"
+#if defined(__i386__) || defined(__i386)
+#define ARCH_STRING "x86"
+#elif defined(__amd64__) || defined(__x86_64__)
+#define ARCH_STRING "x86_64"
+#elif defined(__arm__)
+#define ARCH_STRING "arm"
+#elif defined(__aarch64__)
+#define ARCH_STRING "arm64"
+#elif defined(__powerpc__) || defined(__ppc__)
+#define ARCH_STRING "ppc"
+#elif defined(__powerpc64__)
+#define ARCH_STRING "ppc64"
+#elif defined(__sparc64__)
+#define ARCH_STRING "sparc64"
+#elif defined(__mips__)
+#define ARCH_STRING "mips"
+#elif defined(__riscv)
+#if __SIZEOF_POINTER__ == 8
+#define ARCH_STRING "riscv64"
+#else
+#define ARCH_STRING "riscv"
 #endif
+#else
+#define ARCH_STRING "unknown"
+#endif
 
-#if __BIG_ENDIAN__
-#  define Q3_BIG_ENDIAN
+#if BYTE_ORDER == BIG_ENDIAN
+#define Q3_BIG_ENDIAN
 #else
-#  define Q3_LITTLE_ENDIAN
+#define Q3_LITTLE_ENDIAN
 #endif
 
 #define DLL_EXT ".so"
@@ -433,6 +455,10 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #error "DLL_EXT not defined"
 #endif
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 //endianness
 void CopyShortSwap(void* dest, const void* src);
 void CopyLongSwap(void* dest, const void* src);
@@ -448,6 +474,10 @@ void SwapValue(void* dest, size_t size);
 float FloatSwapPtr(const void* l);
 float FloatNoSwapPtr(const void* l);
 void SwapValue(void* dest, size_t size);
+
+#ifdef __cplusplus
+}
+#endif
 
 #if defined( Q3_BIG_ENDIAN ) && defined( Q3_LITTLE_ENDIAN )
 #error "Endianness defined as both big and little"
