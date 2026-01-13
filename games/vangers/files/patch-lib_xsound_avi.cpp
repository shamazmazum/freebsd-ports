--- lib/xsound/avi.cpp.orig	2026-01-13 09:43:26 UTC
+++ lib/xsound/avi.cpp
@@ -176,7 +176,7 @@ void AVIFile::draw(void) {
 		}
 		if(frame<0 && (flags & AVI_LOOPING)) {
 				// Close the codec
-				avcodec_close(pCodecCtx);
+				avcodec_free_context(&pCodecCtx);
 				// Close the video file
 				//av_close_input_file(pFormatCtx);
 				avformat_close_input(&pFormatCtx);
@@ -234,7 +234,7 @@ void AVIFile::close(void)
 	// Free the YUV frame
 	av_free(pFrame);
 	// Close the codec
-	avcodec_close(pCodecCtx);
+	avcodec_free_context(&pCodecCtx);
 	// Close the video file
 	//av_close_input_file(pFormatCtx);
 	//avformat_free_context(pFormatCtx);
