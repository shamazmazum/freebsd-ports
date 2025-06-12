--- components/crashcatcher/crashcatcher.cpp.orig	2025-06-12 10:36:54 UTC
+++ components/crashcatcher/crashcatcher.cpp
@@ -86,7 +86,6 @@ namespace
     };
 
     constexpr SignalInfo sigIllCodes[] = {
-#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__)
         { ILL_ILLOPC, "Illegal opcode" },
         { ILL_ILLOPN, "Illegal operand" },
         { ILL_ILLADR, "Illegal addressing mode" },
@@ -95,7 +94,6 @@ namespace
         { ILL_PRVREG, "Privileged register" },
         { ILL_COPROC, "Coprocessor error" },
         { ILL_BADSTK, "Internal stack error" },
-#endif
     };
 
     constexpr SignalInfo sigFpeCodes[] = {
@@ -110,18 +108,14 @@ namespace
     };
 
     constexpr SignalInfo sigSegvCodes[] = {
-#ifndef __FreeBSD__
         { SEGV_MAPERR, "Address not mapped to object" },
         { SEGV_ACCERR, "Invalid permissions for mapped object" },
-#endif
     };
 
     constexpr SignalInfo sigBusCodes[] = {
-#ifndef __FreeBSD__
         { BUS_ADRALN, "Invalid address alignment" },
         { BUS_ADRERR, "Non-existent physical address" },
         { BUS_OBJERR, "Object specific hardware error" },
-#endif
     };
 
     const char* findSignalDescription(std::span<const SignalInfo> info, int code)
@@ -371,26 +365,26 @@ static void crash_catcher(int signum, siginfo_t* sigin
         exit(1);
     }
 
-    const char* sigdesc = findSignalDescription(signals, crash_info.signum);
+    const char* sigdesc = findSignalDescription(std::span(signals), crash_info.signum);
 
     if (crash_info.siginfo.has_value())
     {
         switch (crash_info.signum)
         {
             case SIGSEGV:
-                sigdesc = findSignalDescription(sigSegvCodes, crash_info.siginfo->si_code);
+                sigdesc = findSignalDescription(std::span(sigSegvCodes), crash_info.siginfo->si_code);
                 break;
 
             case SIGFPE:
-                sigdesc = findSignalDescription(sigFpeCodes, crash_info.siginfo->si_code);
+                sigdesc = findSignalDescription(std::span(sigFpeCodes), crash_info.siginfo->si_code);
                 break;
 
             case SIGILL:
-                sigdesc = findSignalDescription(sigIllCodes, crash_info.siginfo->si_code);
+                sigdesc = findSignalDescription(std::span(sigIllCodes), crash_info.siginfo->si_code);
                 break;
 
             case SIGBUS:
-                sigdesc = findSignalDescription(sigBusCodes, crash_info.siginfo->si_code);
+                sigdesc = findSignalDescription(std::span(sigBusCodes), crash_info.siginfo->si_code);
                 break;
         }
     }
