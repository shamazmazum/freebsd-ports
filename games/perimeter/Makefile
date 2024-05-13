PORTNAME=	perimeter
DISTVERSION=	3.0.10-563
DISTVERSIONSUFFIX=	-gbb7c88b8
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Perimeter RTS game

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		cmake sdl gl
USE_SDL=	sdl2 image2 mixer2 net2
USE_GL=		gl

PLIST_FILES=	bin/perimeter

CMAKE_ON=	FETCHCONTENT_FULLY_DISCONNECTED
CMAKE_OFF=	OPTION_D3D9 OPTION_USE_BACKTRACE
CMAKE_ARGS+=	-DFETCHCONTENT_SOURCE_DIR_SIMPLEINI="${WRKSRC}/_deps/simpleini-src" \
		-DFETCHCONTENT_SOURCE_DIR_PEVENTS="${WRKSRC}/_deps/pevents-src" \
		-DFETCHCONTENT_SOURCE_DIR_SOKOL="${WRKSRC}/_deps/sokol-src"

USE_GITHUB=	yes
GH_ACCOUNT=	KD-lab-Open-Source
GH_PROJECT=	Perimeter
GH_TUPLE=	brofield:simpleini:7350fcc:simpleini/_deps/simpleini-src \
		neosmart:pevents:d6afcbc:pevents/_deps/pevents-src \
		floooh:sokol:6733919:sokol/_deps/sokol-src

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
