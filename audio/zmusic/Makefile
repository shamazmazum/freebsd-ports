PORTNAME=	zmusic
DISTVERSION=	1.3.0
CATEGORIES=	audio

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	GZDoom's music system as a standalone library
WWW=		https://github.com/ZDoom/ZMusic

LICENSE=	BSD3CLAUSE GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/licenses/bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/licenses/gplv3.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/licenses/lgplv3.txt

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libgme.so:audio/libgme \
		libmpg123.so:audio/mpg123 \
		libsndfile.so:audio/libsndfile

USES=		cmake localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ZDoom
GH_PROJECT=	ZMusic

USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS+=	--exclude thirdparty/fluidsynth \
			--exclude thirdparty/game-music-emu \
			--exclude thirdparty/zlib

CMAKE_OFF=	DYN_MPG123 DYN_SNDFILE 

.include <bsd.port.mk>
