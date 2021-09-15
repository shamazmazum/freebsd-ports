PORTNAME=	amnesia-tdd
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Amnesia: The Dark Descent

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

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
GH_PROJECT=	AmnesiaTheDarkDescent

CMAKE_ON=	SYSTEMWIDE_RESOURCES
CMAKE_ARGS=	-DSYSTEMWIDE_RESOURCES_LOCATION=${PREFIX}/share/${PORTNAME}
CMAKE_SOURCE_PATH=	${WRKSRC}/amnesia/src

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
