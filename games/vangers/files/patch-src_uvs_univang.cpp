--- src/uvs/univang.cpp.orig
+++ src/uvs/univang.cpp
@@ -1455,10 +1455,10 @@ void uvsEscave::link_good(void){
 	uvsSpot* ps;
 
 	while( pt ){
-		if ( ps = (uvsSpot*)SpotTail -> seekName(((uvsTradeItem*)pt ) -> town_name) ){
+		if ( (ps = (uvsSpot*)SpotTail -> seekName(((uvsTradeItem*)pt ) -> town_name)) ){
 			(pl = new uvsTradeItem) -> link( ps -> Pgood );
 			pl -> type = ((uvsTradeItem*)pt) -> type;
-		} else if ( pe = (uvsEscave*)EscaveTail -> seekName(((uvsTradeItem*)pt ) -> town_name) ){
+		} else if ( (pe = (uvsEscave*)EscaveTail -> seekName(((uvsTradeItem*)pt ) -> town_name)) ){
 			(pl = new uvsTradeItem) -> link( pe -> Pgood );
 			pl -> type = ((uvsTradeItem*)pt) -> type;
 		} else
@@ -1514,10 +1514,10 @@ void uvsSpot::link_good(void){
 	uvsSpot* ps;
 
 	while( pt ){
-		if ( ps = (uvsSpot*)SpotTail -> seekName(((uvsTradeItem*)pt ) -> town_name) ){
+		if ( (ps = (uvsSpot*)SpotTail -> seekName(((uvsTradeItem*)pt ) -> town_name)) ){
 			(pl = new uvsTradeItem) -> link( ps -> Pgood );
 			pl -> type = ((uvsTradeItem*)pt) -> type;
-		} else if ( pe = (uvsEscave*)EscaveTail -> seekName(((uvsTradeItem*)pt ) -> town_name) ){
+		} else if ( (pe = (uvsEscave*)EscaveTail -> seekName(((uvsTradeItem*)pt ) -> town_name)) ){
 			(pl = new uvsTradeItem) -> link( pe -> Pgood );
 			pl -> type = ((uvsTradeItem*)pt) -> type;
 		} else
@@ -6039,14 +6039,14 @@ void uvsVanger::go_from_escave(void)
 		ord -> target = UVS_TARGET::SPOT;
 		ord -> Ptarget = (uvsTarget*)ps;
 		Pspot = ps;
-	} else	if ( ps = (uvsSpot*)SpotTail -> seekName(name) ){
+	} else	if ( (ps = (uvsSpot*)SpotTail -> seekName(name)) ){
 		uvsOrder* ord = orderT; 		// первый элемент
 		ord -> type = UVS_ORDER::MOVING;
 		ord -> event = UVS_EVENT::GO_SPOT;
 		ord -> target = UVS_TARGET::SPOT;
 		ord -> Ptarget = (uvsTarget*)ps;
 		Pspot = ps;
-	} else if ( pe = (uvsEscave*)EscaveTail -> seekName(name) ){
+	} else if ( (pe = (uvsEscave*)EscaveTail -> seekName(name)) ){
 		uvsOrder* ord = orderT; 		// первый элемент
 		ord -> type = UVS_ORDER::MOVING;
 		ord -> event = UVS_EVENT::GO_ESCAVE;
@@ -6162,13 +6162,13 @@ void uvsVanger::go_from_spot(void)
 		ord -> target = UVS_TARGET::ESCAVE;
 		ord -> Ptarget = (uvsTarget*)pe;
 		Pescave = pe;
-	} else	if ( ps = (uvsSpot*)SpotTail -> seekName(name) ){
+	} else	if ( (ps = (uvsSpot*)SpotTail -> seekName(name)) ){
 		uvsOrder* ord = orderT; 		// первый элемент
 		ord -> type = UVS_ORDER::MOVING;
 		ord -> event = UVS_EVENT::GO_SPOT;
 		ord -> target = UVS_TARGET::SPOT;
 		ord -> Ptarget = (uvsTarget*)ps;
-	} else if ( pe = (uvsEscave*)EscaveTail -> seekName(name) ){
+	} else if ( (pe = (uvsEscave*)EscaveTail -> seekName(name)) ){
 		uvsOrder* ord = orderT; 		// первый элемент
 		ord -> type = UVS_ORDER::MOVING;
 		ord -> event = UVS_EVENT::GO_ESCAVE;
@@ -10721,7 +10721,7 @@ int uvsTabuTaskType::is_able(void){
 	if ((work_on_target == UVS_TABUTASK_WORK::DELIVER_OR) && (uvsMechosTable[20] -> constractor == 3) )
 		return 0;
 
-	if ((target == UVS_TARGET::RACE) ){
+	if (target == UVS_TARGET::RACE ){
 		for( i = 0; i < item_number; i++ )
 			if (!uvsCheckItem(item[i]))
 				return 0;
