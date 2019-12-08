--- src/actint/ascr_fnc.cpp.orig
+++ src/actint/ascr_fnc.cpp
@@ -7157,6 +7157,7 @@ int sdlEventToCode(SDL_Event *event) {
 				return iMOUSE_RIGHT_MOVE;
 			else
 				return iMOUSE_MOVE_CODE;
+		default:
+			return 0;
 	}
 }
-
