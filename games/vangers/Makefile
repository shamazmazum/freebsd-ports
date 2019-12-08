PORTNAME=	vangers
DISTVERSION=	1.0.0-78
DISTVERSIONSUFFIX=	-gb395e55
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

#post-patch:
#	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
#		${WRKSRC}/src/road.cpp
#	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
#		${WRKSRC}/src/iscreen/ivmap.cpp
#	@${ICONV_CMD} -f CP866 -t UTF-8 ${WRKSRC}/src/actint/aci_str.h > \
#		${WRKSRC}/src/actint/aci_str.h.utf-8
#	@${MV} ${WRKSRC}/src/actint/aci_str.h.utf-8 ${WRKSRC}/src/actint/aci_str.h
#	@${ICONV_CMD} -f CP866 -t UTF-8 ${WRKSRC}/src/iscreen/i_str.h > \
#		${WRKSRC}/src/iscreen/i_str.h.utf-8
#	@${MV} ${WRKSRC}/src/iscreen/i_str.h.utf-8 ${WRKSRC}/src/iscreen/i_str.h
#	@${ICONV_CMD} -f CP866 -t UTF-8 ${WRKSRC}/src/units/magnum.h > \
#		${WRKSRC}/src/units/magnum.h.utf-8
#	@${MV} ${WRKSRC}/src/units/magnum.h.utf-8 ${WRKSRC}/src/units/magnum.h
#	@${ICONV_CMD} -f WINDOWS-1251 -t UTF-8 ${WRKSRC}/src/zmod_client.h > \
#		${WRKSRC}/src/zmod_client.h.utf-8
#	@${MV} ${WRKSRC}/src/zmod_client.h.utf-8 ${WRKSRC}/src/zmod_client.h

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/vangers ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})


.include <bsd.port.mk>
