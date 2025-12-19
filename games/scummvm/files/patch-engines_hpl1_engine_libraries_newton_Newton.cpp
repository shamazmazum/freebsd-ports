--- engines/hpl1/engine/libraries/newton/Newton.cpp.orig	2025-11-14 20:55:34 UTC
+++ engines/hpl1/engine/libraries/newton/Newton.cpp
@@ -25,6 +25,16 @@
 #include "NewtonStdAfx.h"
 #include "hpl1/debug.h"
 
+static dgMatrix array2matrix(const dFloat *array) {
+	dgVector row1(array[0],  array[1],  array[2],  array[3]);
+	dgVector row2(array[4],  array[5],  array[6],  array[7]);
+	dgVector row3(array[8],  array[9],  array[10], array[11]);
+	dgVector row4(array[12], array[13], array[14], array[15]);
+	dgMatrix mat(row1, row2, row3, row4);
+
+	return mat;
+}
+
 void NewtonInitGlobals() {
 	dgInitMemoryGlobals();
 }
@@ -3951,8 +3961,8 @@ int NewtonCollisionCollide(NewtonWorld *const newtonWo
 	world = (Newton *)newtonWorld;
 
 	TRACE_FUNTION(__FUNCTION__);
-	return world->Collide((dgCollision *)collisionA, *((const dgMatrix *)matrixA),
-	                      (dgCollision *)collisionB, *((const dgMatrix *)matrixB), (dgTriplex *)contacts,
+	return world->Collide((dgCollision *)collisionA, array2matrix(matrixA),
+	                      (dgCollision *)collisionB, array2matrix(matrixB), (dgTriplex *)contacts,
 	                      (dgTriplex *)normals, penetration, maxSize, threadIndex);
 }
 
@@ -4486,7 +4496,7 @@ NewtonBody *NewtonCreateBody(NewtonWorld *const newton
 	SaveCollision(collisionPtr);
 #endif
 
-	dgMatrix matrix(*((const dgMatrix *)matrixPtr));
+	dgMatrix matrix = array2matrix(matrixPtr);
 #ifdef _DEBUG
 	//  matrix.m_front = matrix.m_front.Scale (dgRsqrt (matrix.m_front % matrix.m_front));
 	//  matrix.m_right = matrix.m_front * matrix.m_up;
@@ -4850,7 +4860,7 @@ void NewtonBodySetMatrix(NewtonBody *const bodyPtr,
                          dFloat *const matrixPtr) {
 	dgBody *body;
 	body = (dgBody *)bodyPtr;
-	dgMatrix matrix(*((dgMatrix *)matrixPtr));
+	dgMatrix matrix = array2matrix(matrixPtr);
 
 	TRACE_FUNTION(__FUNCTION__);
 
