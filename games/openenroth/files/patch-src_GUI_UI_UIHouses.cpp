--- src/GUI/UI/UIHouses.cpp.orig	2023-07-07 12:32:43 UTC
+++ src/GUI/UI/UIHouses.cpp
@@ -1206,12 +1206,10 @@ void GUIWindow_House::initializeProprietorDialogue() {
 
     std::vector<DIALOGUE_TYPE> optionList = listDialogueOptions(dialog_menu_id);
 
-    if (optionList.size()) {
-        for (int i = 0; i < optionList.size(); i++) {
-            pDialogueWindow->CreateButton({480, 146 + 30 * i}, {140, 30}, 1, 0, UIMSG_SelectProprietorDialogueOption, optionList[i], Io::InputAction::Invalid, "");
-        }
-        pDialogueWindow->_41D08F_set_keyboard_control_group(optionList.size(), 1, 0, 2);
+    for (int i = 0; i < optionList.size(); i++) {
+        pDialogueWindow->CreateButton({480, 146 + 30 * i}, {140, 30}, 1, 0, UIMSG_SelectProprietorDialogueOption, optionList[i], Io::InputAction::Invalid, "");
     }
+    pDialogueWindow->_41D08F_set_keyboard_control_group(optionList.size(), 1, 0, 2);
     _savedButtonsNum = pDialogueWindow->pNumPresenceButton;
 }
 
@@ -1247,12 +1245,10 @@ void GUIWindow_House::initializeNPCDialogue(int npc) {
 
 #undef ADD_NPC_SCRIPTED_DIALOGUE
 
-    if (optionList.size()) {
-        for (int i = 0; i < optionList.size(); i++) {
-            pDialogueWindow->CreateButton({480, 160 + 30 * i}, {140, 30}, 1, 0, UIMSG_SelectHouseNPCDialogueOption, optionList[i], Io::InputAction::Invalid, "");
-        }
-        pDialogueWindow->_41D08F_set_keyboard_control_group(optionList.size(), 1, 0, 2);
+    for (int i = 0; i < optionList.size(); i++) {
+        pDialogueWindow->CreateButton({480, 160 + 30 * i}, {140, 30}, 1, 0, UIMSG_SelectHouseNPCDialogueOption, optionList[i], Io::InputAction::Invalid, "");
     }
+    pDialogueWindow->_41D08F_set_keyboard_control_group(optionList.size(), 1, 0, 2);
     _savedButtonsNum = pDialogueWindow->pNumPresenceButton;
 }
 
