# Created by: Vasily Postnicov <shamaz.mazum@gmail.com>
# $FreeBSD$

PORTNAME=	yquake2-ref_vk
DISTVERSION=	1.0.12
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Vulkan renderer for Yamagi Quake II

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		sdl gmake
USE_SDL=	sdl2

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
RUN_DEPENDS=	${LOCALBASE}/bin/yquake2:games/yquake2

USE_GITHUB=	yes
GH_ACCOUNT=	yquake2
GH_PROJECT=	ref_vk
GH_TAGNAME=	6729698

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/yquake2
	${INSTALL_LIB} ${BUILD_WRKSRC}/release/ref_vk.so ${STAGEDIR}${PREFIX}/lib/yquake2

.include <bsd.port.mk>
