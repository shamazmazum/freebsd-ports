PORTNAME=	fallout1-ce
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Open source reimplementation of Fallout

LICENSE=	${PORTNAME}
LICENSE_NAME=	Sustainable Use License
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		cmake sdl
USE_SDL=	sdl2

PLIST_FILES=	bin/fallout-ce

CMAKE_ON=	FETCHCONTENT_FULLY_DISCONNECTED
CMAKE_ARGS+=	-DFETCHCONTENT_SOURCE_DIR_FPATTERN="${WRKSRC}/_deps/fpattern-src"

USE_GITHUB=	yes
GH_ACCOUNT=	alexbatalov
GH_TUPLE=	LoadMaster:fpattern:96f42d0:fpattern/_deps/fpattern-src

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/fallout-ce ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
