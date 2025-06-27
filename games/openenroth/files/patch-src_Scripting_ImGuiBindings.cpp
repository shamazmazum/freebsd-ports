--- src/Scripting/ImGuiBindings.cpp.orig	2025-06-25 22:14:11 UTC
+++ src/Scripting/ImGuiBindings.cpp
@@ -106,7 +106,8 @@ struct ImGuiInputTextUserData {
             break;
         }
 
-        *string = callback->call(data->EventFlag, step);
+        const std::string tmp = callback->call(data->EventFlag, step);
+        *string = tmp;
         data->DeleteChars(0, data->BufTextLen);
         data->InsertChars(0, string->data());
     }
