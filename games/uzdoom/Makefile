PORTNAME=	uzdoom
PORTVERSION=	4.14.3
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	UZDoom is a feature centric port for all Doom engine games
WWW=		https://zdoom.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
		libzmusic.so:audio/zmusic \
		libvpx.so:multimedia/libvpx \
		libwebpmux.so:graphics/webp \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake gl sdl pkgconfig

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	UZDoom
GH_PROJECT=	UZDoom

USE_GL=		gl glu glesv2
USE_SDL=	sdl2

DATADIR=	${DMDIR}/${PORTNAME}
CMAKE_ARGS=	-DINSTALL_DOCS_PATH=${DOCSDIR}	\
		-DINSTALL_PK3_PATH=${DMDIR}	\
		-DINSTALL_SOUNDFONT_PATH=${DMDIR}
CXXFLAGS+=	-DSHARE_DIR=\\\"${DATADIR}\\\"

# Fixme: Make options
CMAKE_OFF=	VULKAN_USE_XLIB
CMAKE_ON=	VULKAN_USE_WAYLAND

OPTIONS_SUB=	yes

.include "${.CURDIR}/../doom-data/Makefile.include"

post-extract:
	${RM} -rf ${WRKSRC}/libraries/ZVulkan/include/vulkan
	${RM} -rf ${WRKSRC}/libraries/bzip2
	${RM} -rf ${WRKSRC}/libraries/webp

.include <bsd.port.mk>
