--- src/Engine/Objects/Chest.cpp.orig	2023-07-07 12:32:43 UTC
+++ src/Engine/Objects/Chest.cpp
@@ -298,11 +298,11 @@ int Chest::PutItemInChest(int position, ItemGen *put_i
 
 int Chest::PutItemInChest(int position, ItemGen *put_item, int uChestID) {
     int item_in_chest_count = CountChestItems(uChestID);
-    int test_pos = 0;
 
     int max_size = pChestWidthsByType[vChests[uChestID].uChestBitmapID] *
                    pChestHeightsByType[vChests[uChestID].uChestBitmapID];
     int chest_width = pChestWidthsByType[vChests[uChestID].uChestBitmapID];
+    int test_pos = max_size;
 
     if (item_in_chest_count == -1) return 0;
 
@@ -335,7 +335,6 @@ int Chest::PutItemInChest(int position, ItemGen *put_i
     unsigned int slot_height = GetSizeInInventorySlots(texture->height());
 
     Assert(slot_height > 0 && slot_width > 0, "Items should have nonzero dimensions");
-
     // set inventory indices - memset was eratic??
     for (unsigned int x = 0; x < slot_width; x++) {
         for (unsigned int y = 0; y < slot_height; y++) {
@@ -345,6 +344,7 @@ int Chest::PutItemInChest(int position, ItemGen *put_i
 
     vChests[uChestID].pInventoryIndices[test_pos] = item_in_chest_count + 1;
     vChests[uChestID].igChestItems[item_in_chest_count] = *put_item;
+    vChests[uChestID].igChestItems[item_in_chest_count].placedInChest = true;
 
     return (test_pos + 1);
 }
@@ -375,6 +375,7 @@ void Chest::PlaceItemAt(unsigned int put_cell_pos, uns
         chest_cell_row_pos += chest_cell_width;
     }
     vChests[uChestID].pInventoryIndices[put_cell_pos] = item_at_cell + 1;
+    vChests[uChestID].igChestItems[item_at_cell].placedInChest = true;
 }
 
 void Chest::PlaceItems(int uChestID) {  // only sued for setup
@@ -497,7 +498,7 @@ void Chest::OnChestLeftClick() {
 
             if (chestindex > 0) {
                 int itemindex = chestindex - 1;
-
+                chest->igChestItems[itemindex].placedInChest = false;
                 if (chest->igChestItems[itemindex].isGold()) {
                     pParty->partyFindsGold(chest->igChestItems[itemindex].special_enchantment, GOLD_RECEIVE_SHARE);
                 } else {
@@ -531,6 +532,7 @@ void Chest::GrabItem(bool all) {  // new fucntion to g
 
         int itemindex = chestindex - 1;
         ItemGen chestitem = chest->igChestItems[itemindex];
+        chestitem.placedInChest = false;
         if (chestitem.isGold()) {
             pParty->partyFindsGold(chestitem.special_enchantment, GOLD_RECEIVE_SHARE);
             goldamount += chestitem.special_enchantment;
