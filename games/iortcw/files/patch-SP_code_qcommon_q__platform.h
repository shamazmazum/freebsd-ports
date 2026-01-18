--- SP/code/qcommon/q_platform.h.orig	2024-05-26 20:31:54 UTC
+++ SP/code/qcommon/q_platform.h
@@ -224,20 +224,12 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#ifdef __i386__
-#define ARCH_STRING "i386"
-#elif defined __amd64__
+#if !defined(ARCH_STRING)
+# error ARCH_STRING should be defined by the Makefile
+#endif
+#if defined __x86_64__
 #undef idx64
 #define idx64 1
-#define ARCH_STRING "amd64"
-#elif defined __axp__
-#define ARCH_STRING "alpha"
-#elif defined __powerpc64__
-#define ARCH_STRING "powerpc64"
-#elif defined __powerpc__
-#define ARCH_STRING "powerpc"
-#elif defined __riscv
-#define ARCH_STRING "riscv64"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
