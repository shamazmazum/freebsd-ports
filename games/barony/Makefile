PORTNAME=	barony
PORTREVISION=	2
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.2
CATEGORIES=	games

MAINTAINER=	devnexen@gmail.com
COMMENT=	3D roguelike game
WWW=		http://www.baronygame.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	rapidjson>=0:devel/rapidjson \
		nativefiledialog>=116:devel/nativefiledialog
LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libvorbisfile.so:audio/libvorbis

USES=		cmake compiler:c++11-lib dos2unix gl localbase:ldflags \
		openal pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	TurningWheel
GH_PROJECT=	Barony
USE_GL=		gl glu
USE_SDL=	sdl2 image2 net2 ttf2

CMAKE_ON=	DATA_DIR OPENAL_ENABLED
CMAKE_OFF=	FMOD_ENABLED
CMAKE_ARGS=	-DEDITOR_EXE_NAME:STRING="barony-editor"
CONFIGURE_ENV=	OPTIMIZATION_LEVEL=""
DOS2UNIX_FILES=	src/menu.cpp
LDFLAGS+=	-Wl,--as-needed
LDFLAGS_i386=	-Wl,-znotext

SUB_FILES=	pkg-message

PLIST_FILES=	bin/barony \
		bin/barony-editor

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/barony ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/barony-editor ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
