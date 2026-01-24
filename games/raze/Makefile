PORTNAME=	raze
PORTVERSION=	1.11.0
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Build engine remake based on ZDoom
WWW=		https://raze.zdoom.org/about

LICENSE=	BUILDLIC GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_BUILDLIC=	Build Engine License
LICENSE_FILE_BUILDLIC=	${FILESDIR}/BUILDLIC.TXT
LICENSE_PERMS_BUILDLIC=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
		libzmusic.so:audio/zmusic \
		libvpx.so:multimedia/libvpx \
		libwebpmux.so:graphics/webp \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake gl sdl pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ZDoom
GH_PROJECT=	Raze

USE_GL=		gl glu glesv2
USE_SDL=	sdl2

CXXFLAGS+=	-DSHARE_DIR=\\\"${DATADIR}\\\"

# Fixme: Make options
CMAKE_OFF=	VULKAN_USE_XLIB
CMAKE_ON=	VULKAN_USE_WAYLAND

post-extract:
	${RM} -rf ${WRKSRC}/libraries/ZVulkan/include/vulkan
	${RM} -rf ${WRKSRC}/libraries/bzip2
	${RM} -rf ${WRKSRC}/libraries/webp

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/soundfonts
	${INSTALL_DATA} ${BUILD_WRKSRC}/soundfonts/raze.sf2 ${STAGEDIR}${DATADIR}/soundfonts

.include <bsd.port.mk>
