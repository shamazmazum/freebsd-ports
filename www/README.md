# FAQ

## How to build webkit?

In order to build `www/webkit2-gtk3` port you need to apply the following patch
to FreeBSD's source tree and a default LLVM version in the ports tree and
**rebuild the whole system (userland) and ports**.

~~~~{.diff}
--- a/contrib/llvm-project/libcxx/include/__config
+++ b/contrib/llvm-project/libcxx/include/__config
@@ -127,9 +127,9 @@
 #  endif
 // Feature macros for disabling pre ABI v1 features. All of these options
 // are deprecated.
-#  if defined(__FreeBSD__)
-#    define _LIBCPP_DEPRECATED_ABI_DISABLE_PAIR_TRIVIAL_COPY_CTOR
-#  endif
+//#  if defined(__FreeBSD__)
+//#    define _LIBCPP_DEPRECATED_ABI_DISABLE_PAIR_TRIVIAL_COPY_CTOR
+//#  endif
 #endif
~~~~

WebKit version present here is compatible with `cl-webkit` Common Lisp system
which allows user to run Nyxt.
