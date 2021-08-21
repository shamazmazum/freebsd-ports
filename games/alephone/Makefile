# Created by: Michael Alyn Miller <malyn@strangeGizmo.com>
# $FreeBSD: head/games/alephone/Makefile 484273 2018-11-06 01:50:26Z jbeich $

PORTNAME=	alephone
DISTVERSION=	20210408
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	The open source version of Bungies Marathon game
LICENSE=	GPLv3

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libboost_filesystem.so:devel/boost-libs

USES=		compiler:c++11-lang gmake localbase pkgconfig tar:bzip2 autoreconf sdl gl
USE_GITHUB=	yes
GH_ACCOUNT=	Aleph-One-Marathon
GH_TAGNAME=	release-20200904
USE_SDL=	sdl2 image2 net2 ttf2
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa

DATADIR=	${PREFIX}/share/AlephOne

OPTIONS_DEFINE=	MAD FFMPEG OGG SPEEX ZZIP PNG CURL SNDFILE DOCS
OPTIONS_DEFAULT=MAD FFMPEG OGG SPEEX ZZIP PNG CURL SNDFILE

FFMPEG_DESC=	Use ffmpeg for film export and playback
ZZIP_DESC=	Enable zziplib support

MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CONFIGURE_WITH=	mad
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	ffmpeg
OGG_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
OGG_CONFIGURE_WITH=	vorbis
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp
SPEEX_CONFIGURE_WITH=	speex
ZZIP_LIB_DEPENDS=	libzzip.so:devel/zziplib
ZZIP_CONFIGURE_WITH=	zzip
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_WITH=	sndfile

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
