--- src/uvs/univang.cpp.orig
+++ src/uvs/univang.cpp
@@ -1455,10 +1455,10 @@ void uvsEscave::link_good(void){
 	uvsSpot* ps;
 
 	while( pt ){
-		if ( ps = (uvsSpot*)SpotTail -> seekName(((uvsTradeItem*)pt ) -> town_name) ){
+		if ((ps = (uvsSpot*)SpotTail -> seekName(((uvsTradeItem*)pt ) -> town_name))) {
 			(pl = new uvsTradeItem) -> link( ps -> Pgood );
 			pl -> type = ((uvsTradeItem*)pt) -> type;
-		} else if ( pe = (uvsEscave*)EscaveTail -> seekName(((uvsTradeItem*)pt ) -> town_name) ){
+		} else if ((pe = (uvsEscave*)EscaveTail -> seekName(((uvsTradeItem*)pt ) -> town_name))) {
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
@@ -6039,14 +6039,14 @@ void uvsVanger::go_from_escave(void){
 		ord -> target = UVS_TARGET::SPOT;
 		ord -> Ptarget = (uvsTarget*)ps;
 		Pspot = ps;
-	} else	if ( ps = (uvsSpot*)SpotTail -> seekName(name) ){
+	} else	if ((ps = (uvsSpot*)SpotTail -> seekName(name))) {
 		uvsOrder* ord = orderT; 		// первый элемент
 		ord -> type = UVS_ORDER::MOVING;
 		ord -> event = UVS_EVENT::GO_SPOT;
 		ord -> target = UVS_TARGET::SPOT;
 		ord -> Ptarget = (uvsTarget*)ps;
 		Pspot = ps;
-	} else if ( pe = (uvsEscave*)EscaveTail -> seekName(name) ){
+	} else if ((pe = (uvsEscave*)EscaveTail -> seekName(name))) {
 		uvsOrder* ord = orderT; 		// первый элемент
 		ord -> type = UVS_ORDER::MOVING;
 		ord -> event = UVS_EVENT::GO_ESCAVE;
@@ -6162,13 +6162,13 @@ void uvsVanger::go_from_spot(void){
 		ord -> target = UVS_TARGET::ESCAVE;
 		ord -> Ptarget = (uvsTarget*)pe;
 		Pescave = pe;
-	} else	if ( ps = (uvsSpot*)SpotTail -> seekName(name) ){
+	} else	if ((ps = (uvsSpot*)SpotTail -> seekName(name))){
 		uvsOrder* ord = orderT; 		// первый элемент
 		ord -> type = UVS_ORDER::MOVING;
 		ord -> event = UVS_EVENT::GO_SPOT;
 		ord -> target = UVS_TARGET::SPOT;
 		ord -> Ptarget = (uvsTarget*)ps;
-	} else if ( pe = (uvsEscave*)EscaveTail -> seekName(name) ){
+	} else if ((pe = (uvsEscave*)EscaveTail -> seekName(name))){
 		uvsOrder* ord = orderT; 		// первый элемент
 		ord -> type = UVS_ORDER::MOVING;
 		ord -> event = UVS_EVENT::GO_ESCAVE;
@@ -6180,7 +6180,7 @@ void uvsVanger::go_from_spot(void){
 }
 
 int uvsVanger::buildWay(uvsWorld* fromW,uvsWorld* toW){
-	uvsWorld* nextW,*tmpW = NULL;
+	uvsWorld* nextW;
 	uvsWorld *lastfromW = NULL, *lasttoW = NULL;
 	uvsOrder* ord;
 	uvsPassage* pp;
@@ -6657,7 +6657,6 @@ void uvsVanger::_sellCirt_(void){
 
 	int last_param2;
 	int cool_index = 0;
-	uvsActInt* pa = GGamer;
 
 	uvsItem *pi;
 
@@ -6913,7 +6912,6 @@ int uvsDolly::getCirt(int x,int y){
 int uvsVanger::emptyContainer( uvsEscave* pe ){
 	uvsItem *pi = (uvsItem*)Pitem;
 	int tmp = 0;
-	int tmp_p = 0;
 	int out = 0;
 
 	if (!pe) ErrH.Abort("uvsVanger:: empty container dont have Escave");
@@ -10721,7 +10719,7 @@ int uvsTabuTaskType::is_able(void){
 	if ((work_on_target == UVS_TABUTASK_WORK::DELIVER_OR) && (uvsMechosTable[20] -> constractor == 3) )
 		return 0;
 
-	if ((target == UVS_TARGET::RACE) ){
+	if (target == UVS_TARGET::RACE){
 		for( i = 0; i < item_number; i++ )
 			if (!uvsCheckItem(item[i]))
 				return 0;
@@ -12029,7 +12027,7 @@ void uvsLuckChange(int delta ){
 int uvsWorldToCross(int fromWID, int toWID){
 	uvsWorld* fromW = WorldTable[fromWID];
 	uvsWorld* toW = WorldTable[toWID];
-	uvsWorld* nextW,*tmpW = NULL;
+	uvsWorld* nextW;
 	uvsWorld *lastfromW = NULL, *lasttoW = NULL;
 	uvsPassage* pp;
 	int i = 0;
