--- src/uvs/univang.h.orig
+++ src/uvs/univang.h
@@ -504,6 +504,7 @@ struct listElem {
 	listElem* prev;
 
 	listElem(void){ next = prev = NULL;};
+	virtual ~listElem() {};
 
 	void link(listElem*& tail);		// добавляет объект (this) в список с хвостом на tail (обычно глобальный указатель) в конец
 	listElem* seekName(const char* name);  // ищет по списку (this как хвост) name, сравнивая его со значением виртуального метода GetName()
@@ -1055,6 +1056,7 @@ struct uvsFlyFarmer : uvsTarget, uvsElement {
 				pos_y = RND( pw -> y_size );  setSpeed();
 	};
 	uvsFlyFarmer( XStream& );
+	virtual ~uvsFlyFarmer () {};
 
 	virtual void Quant(void);
 	virtual void emuQuant(void){};
@@ -1085,6 +1087,7 @@ struct uvsDolly : uvsElement, uvsTarget, listElem {
 	}
 	uvsDolly(uvsWorld* pw,int biosInd);
 	uvsDolly(XStream &);
+	virtual ~uvsDolly() {};
 
 	void save( XStream&);
 
@@ -1129,7 +1132,7 @@ struct uvsVanger : uvsElement, uvsTarget {
 
 	uvsVanger(uvsEscave* pe);
 	uvsVanger(XStream&);
-	~uvsVanger(void);
+	virtual ~uvsVanger(void);
 
 	void save( XStream&);
