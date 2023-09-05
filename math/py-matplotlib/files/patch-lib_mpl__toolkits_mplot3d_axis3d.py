--- lib/mpl_toolkits/mplot3d/axis3d.py.orig	2023-09-05 07:39:02 UTC
+++ lib/mpl_toolkits/mplot3d/axis3d.py
@@ -348,6 +348,7 @@ class Axis(maxis.XAxis):
     @artist.allow_rasterization
     def draw(self, renderer):
         self.label._transform = self.axes.transData
+        self.offsetText._transform = self.axes.transData
         renderer.open_group("axis3d", gid=self.get_gid())
 
         ticks = self._update_ticks()
