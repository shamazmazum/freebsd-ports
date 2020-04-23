# Created by: Vasily Postnicov <shamaz.mazum@gmail.com>
# $FreeBSD$

PORTNAME=	clunk-sdl2
DISTVERSION=	1.0
CATEGORIES=	audio

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Real-time binaural sound generation library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL= clunk

USES=		cmake sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	stalkerg
GH_PROJECT=	clunk

OPTIONS_DEFINE=		SSE
SSE_DESC=		Use highly optimized SSE FFT/MDCT routines
SSE_CMAKE_BOOL_ON=	WITH_SSE

.include <bsd.port.options.mk>
.include <bsd.port.mk>
