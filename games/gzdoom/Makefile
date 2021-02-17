# $FreeBSD$

PORTNAME=	gzdoom
PORTVERSION=	4.5.0
DISTVERSIONPREFIX=	g
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	GL-enhanced source port for Doom-engine games

LICENSE=	BSD3CLAUSE GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/docs/licenses/bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/docs/licenses/gpl.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/docs/licenses/lgpl.txt

BUILD_DEPENDS=	zip:archivers/zip \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libzmusic.so:audio/zmusic \
		libgme.so:audio/libgme \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++11-lang gettext gl gnome jpeg openal \
		pkgconfig sdl

DATADIR=	${DMDIR}/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	coelckers

USE_GNOME=	atk cairo gdkpixbuf2 gtk30 pango
USE_SDL=	sdl2
USE_GL=		gl glu
CXXFLAGS+=	-DSHARE_DIR=\\\"${DATADIR}\\\"
LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=	DOCS
.include <bsd.port.options.mk>

DESKTOP_ENTRIES=	"GZDoom" "" "${PORTNAME}" "${PORTNAME}" "Game;Shooter;" ""

.include "${.CURDIR}/../doom-data/Makefile.include"

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
