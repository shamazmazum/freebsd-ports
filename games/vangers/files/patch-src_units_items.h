--- src/units/items.h.orig
+++ src/units/items.h
@@ -81,6 +81,7 @@ struct StuffObject : Object
 	virtual void DeviceQuant(void);	
 	virtual void DeviceLoad(Parser& in);
 	virtual void GetDevice(StuffObject* p);
+	using Object::NetEvent;
 	void NetEvent(int type,int id,int creator,int x,int y);
 	void NetDeviceEvent(int type,int id,int creator,int x,int y);
 	void NetOwnerQuant(int impulse = 0);
