# Created by: Vasily Postnicov <shamaz.mazum@gmail.com>

PORTNAME=	shockolate
DISTVERSION=	0.8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Open source and cross-platform remake of a cult game System Shock
LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USE_GITHUB=	yes
GH_ACCOUNT=	Interrupt
GH_PROJECT=	systemshock

USES=		cmake gl sdl
USE_GL=		gl glu
USE_SDL=	sdl2 mixer2

CMAKE_ON=	ENABLE_SDL2 ENABLE_SOUND ENABLE_FLUIDSYNTH

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${LOCALBASE}/share/shockolate/|' \
		${WRKSRC}/src/Libraries/RES/Source/caseless.c \
		${WRKSRC}/src/MusicSrc/MusicDevice.c \
		${WRKSRC}/src/MacSrc/OpenGL.cc

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/systemshock ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} shaders ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${DATADIR}/res

.include <bsd.port.mk>
