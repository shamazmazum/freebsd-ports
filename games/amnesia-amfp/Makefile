PORTNAME=	amnesia-amfp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Amnesia: A Machine For Pigs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	The game is completely untested on this architecture

LIB_DEPENDS=	libIL.so:graphics/devil \
		libvorbis.so:audio/libvorbis \
		libtheora.so:multimedia/libtheora \
		libogg.so:audio/libogg

USES=		cmake gl sdl openal perl5
USE_GL=		gl glew glu
USE_SDL=	sdl2
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	AmnesiaAMachineForPigs

SUB_FILES=	pkg-message

CMAKE_ON=	SYSTEMWIDE_RESOURCES
CMAKE_ARGS=	-DSYSTEMWIDE_RESOURCES_LOCATION=${PREFIX}/share/${PORTNAME}
CMAKE_SOURCE_PATH=	${WRKSRC}/Game/src

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
