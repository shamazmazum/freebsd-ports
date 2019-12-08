--- src/3d/3dobject.h.orig
+++ src/3d/3dobject.h
@@ -88,6 +88,7 @@ struct BaseObject : GeneralObject
 	int radius;
 
 	BaseObject(){ dynamic_state = Visibility = MapLevel = ez = radius = 0; }
+	virtual ~BaseObject() {};
 
 	BaseObject* NextBaseList;
 	BaseObject* PrevBaseList;
