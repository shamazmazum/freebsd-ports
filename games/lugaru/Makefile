# Created by: Vasily Postnicov <shamaz.mazum@gmail.com>

PORTNAME=	lugaru
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	3D arcade with unique fighting system and anthropomorphic characters
WWW=		https://bitbucket.org/osslugaru/lugaru/wiki/Home

LICENSE=	GPLv2+ CC-BY-SA-3.0 CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libjsoncpp.so:devel/jsoncpp

USES=		cmake compiler:c++11-lang gl jpeg openal:soft pkgconfig sdl
USE_GL=		gl glu
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum

OPTIONS_DEFINE=	DOCS

CMAKE_ON=	SYSTEM_INSTALL

post-patch:
	${REINPLACE_CMD} -e 's|%%DATA_DIR%%|${DATADIR}|' \
		${WRKSRC}/Source/Utils/Folders.cpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${RLN} ${STAGEDIR}${DATADIR}/Textures/Lugaru.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKSRC}/Dist/Linux/lugaru.6 ${STAGEDIR}${PREFIX}/share/man/man6/lugaru.6

.include <bsd.port.mk>
