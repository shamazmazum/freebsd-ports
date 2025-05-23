PORTNAME=	gzdoom
PORTVERSION=	4.11.3
DISTVERSIONPREFIX=	g
CATEGORIES=	games

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	GL-enhanced source port for Doom-engine games
WWW=		https://zdoom.org/

LICENSE=	BSD3CLAUSE GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/docs/licenses/bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/docs/licenses/gpl.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/docs/licenses/lgpl.txt

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libzmusic.so:audio/zmusic \
		libvpx.so:multimedia/libvpx \
		libvulkan.so:graphics/vulkan-loader \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++11-lang gl gnome jpeg pkgconfig sdl

DATADIR=	${DMDIR}/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	ZDoom

CMAKE_ARGS=	-DINSTALL_DOCS_PATH=${DOCSDIR}	\
		-DINSTALL_PK3_PATH=${DMDIR}	\
		-DINSTALL_SOUNDFONT_PATH=${DMDIR}

USE_GNOME=	atk cairo gdkpixbuf gtk30 pango
USE_SDL=	sdl2
USE_GL=		gl glu glesv2
CXXFLAGS+=	-DSHARE_DIR=\\\"${DATADIR}\\\"
LDFLAGS+=	-Wl,--as-needed

DESKTOP_ENTRIES=	"GZDoom" "" "${PORTNAME}" "${PORTNAME}" "Game;Shooter;" ""

.include "${.CURDIR}/../doom-data/Makefile.include"

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xpm \
	    ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
