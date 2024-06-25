--- HPL2/core/sources/graphics/RendererDeferred.cpp.orig	2024-06-25 11:44:28 UTC
+++ HPL2/core/sources/graphics/RendererDeferred.cpp
@@ -1892,6 +1892,7 @@ namespace hpl {
 			// Test if query has any samples.
 			//  Only check if the query is done, else skip so we do not have a stop-and-wait.
 			iOcclusionQuery *pQuery = pLightData->mpQuery;
+#if 0
 			if(pQuery)
 			{
 				bool bLightInvisible = false;
@@ -1915,6 +1916,7 @@ namespace hpl {
 					continue;
 				}
 			}
+#endif
 
 			mpCurrentSettings->mlNumberOfLightsRendered++;
 
