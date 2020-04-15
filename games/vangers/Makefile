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

USE_SDL=	sdl2 net2
USES=		cmake dos2unix iconv:build
DOS2UNIX_GLOB=	*.cpp *.h

USE_GITHUB=	yes
GH_ACCOUNT=	KranX
GH_PROJECT=	Vangers

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/vangers ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vangers-run ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})


.include <bsd.port.mk>
