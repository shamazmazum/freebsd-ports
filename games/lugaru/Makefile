# Created by: Vasily Postnicov <shamaz.mazum@gmail.com>

PORTNAME=	lugaru
DISTVERSION=	1.3-1
DISTVERSIONSUFFIX=	-g9204227
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	3D arcade with unique fighting system and anthropomorphic characters
LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libjsoncpp.so:devel/jsoncpp

USES=		cmake compiler:c++11-lang gl jpeg openal:soft pkgconfig sdl
USE_GL=		gl glu
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	lugaru

OPTIONS_DEFINE=	DOCS

CMAKE_ON=	SYSTEM_INSTALL

post-patch:
	${REINPLACE_CMD} -e 's|%%DATA_DIR%%|${DATADIR}|' \
		${WRKSRC}/Source/Utils/Folders.cpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${RLN} ${STAGEDIR}${DATADIR}/Textures/Lugaru.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
