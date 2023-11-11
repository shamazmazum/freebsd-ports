--- src/Engine/Snapshots/EntitySnapshots.cpp.orig	2023-07-07 12:32:43 UTC
+++ src/Engine/Snapshots/EntitySnapshots.cpp
@@ -1428,6 +1428,20 @@ void reconstruct(const Chest_MM7 &src, Chest *dst) {
     dst->uFlags = ChestFlags(src.uFlags);
     reconstruct(src.igChestItems, &dst->igChestItems);
     reconstruct(src.pInventoryIndices, &dst->pInventoryIndices);
+
+    // fix placedInChest field for old saves
+    int chestArea = dst->pInventoryIndices.size();
+    for (int item = 0; item < chestArea; item++) {
+        if (dst->igChestItems[item].uItemID == ITEM_NULL) {
+            continue;
+        }
+        for (int position = 0; position < chestArea; position++) {
+            if (dst->pInventoryIndices[position] == item + 1) {
+                dst->igChestItems[item].placedInChest = true;
+                break;
+            }
+        }
+    }
 }
 
 void reconstruct(const BLVLight_MM7 &src, BLVLight *dst) {
