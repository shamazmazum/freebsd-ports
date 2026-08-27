PORTNAME=	dude
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Doom3 Unified Development Engine (Doom 3 port)
WWW=		https://github.com/Inkub0/dude \
		https://dhewm3.org

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/../COPYING.txt

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake openal:al sdl
CMAKE_ON=	REPRODUCIBLE_BUILD

USE_GITHUB=	yes
GH_ACCOUNT=	Inkub0

WRKSRC_SUBDIR=	neo

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="Dude Doom 3" \
		"" \
		"dude-doom3" \
		"${PORTNAME}" \
		"Game;ActionGame;" \
		""

#OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DEDICATED SDL3 DOCS
#OPTIONS_DEFAULT=OPTIMIZED_CFLAGS DEDICATED
#OPTIONS_SUB=	yes

# Dedicated is broken
OPTIONS_DEFINE=	SDL3 VULKAN

SDL3_DESC=	Use SDL3 instead of SDL2
SDL3_USE=	SDL=sdl3
SDL3_USE_OFF=	SDL=sdl2
SDL3_CMAKE_ON=	-DSDL2=OFF -DSDL3=ON
SDL3_CMAKE_OFF=	-DSDL2=ON -DSDL3=OFF

VULKAN_DESC=		Build Vulkan renderer
VULKAN_CMAKE_ON=	-DDHEWM3_VULKAN=ON
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_BUILD_DEPENDS=	vulkan-headers>=1.4:graphics/vulkan-headers \
			glslang>0:graphics/glslang

post-install:
	${INSTALL_DATA} ${WRKSRC}/sys/linux/setup/image/doom3.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/dude-doom3.png

.include <bsd.port.mk>
