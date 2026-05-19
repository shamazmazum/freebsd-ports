PORTNAME=	ref_vk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
PKGNAMEPREFIX=	yquake2-

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Vulkan renderer for Yamagi Quake II

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
RUN_DEPENDS=	yquake2:games/yquake2

USES=		sdl gmake pkgconfig
USE_SDL=	sdl3

MAKE_ARGS=	WITH_SDL3=yes

USE_GITHUB=	yes
GH_ACCOUNT=	yquake2

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/yquake2
	${INSTALL_LIB} ${BUILD_WRKSRC}/release/ref_vk.so ${STAGEDIR}${PREFIX}/lib/yquake2

.include <bsd.port.mk>
