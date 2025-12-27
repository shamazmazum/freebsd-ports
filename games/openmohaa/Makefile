PORTNAME=	openmohaa
DISTVERSIONPREFIX=	v
PORTVERSION=	0.82.1
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Opensource reimplementation of Medal of Honor: Allied Assault

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libjpeg.so:graphics/jpeg-turbo \
		libmad.so:audio/libmad \
		libRecast.so:graphics/recastnavigation

USES=		cmake sdl gl bison openal
USE_SDL=	sdl2
USE_GL=		gl

CMAKE_OFF=	USE_INTERNAL_JPEG USE_INTERNAL_MAD USE_INTERNAL_ZLIB

USE_GITHUB=	yes
GH_ACCOUNT=	openmoh

post-patch:
	${REINPLACE_CMD} -e 's|%%BINARYPATH%%|"${PREFIX}/libexec/openmohaa"|' \
		${WRKSRC}/code/sys/sys_main.c

.include <bsd.port.mk>
