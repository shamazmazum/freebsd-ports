PORTNAME=	vangers
DISTVERSION=	1.0.0-78
DISTVERSIONSUFFIX=	-gb395e55
PORTREVISION=	2
CATEGORIES=	games
MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	The legendary racing game

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libclunk.so:audio/clunk-sdl2 \
		libavcodec.so:multimedia/ffmpeg

USES=		cmake dos2unix iconv:build sdl gl
USE_SDL=	sdl2 net2
USE_GL=		gl glu
DOS2UNIX_GLOB=	*.cpp *.h

USE_GITHUB=	yes
GH_ACCOUNT=	KranX
GH_PROJECT=	Vangers

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/${PORTNAME} \
			   ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})


.include <bsd.port.mk>
