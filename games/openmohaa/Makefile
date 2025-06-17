PORTNAME=	openmohaa
DISTVERSIONPREFIX=	v
DISTVERSION=	0.81.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Opensource reimplementation of Medal of Honor: Allied Assault

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libjpeg.so:graphics/jpeg-turbo \
		libmad.so:audio/libmad

USES=		cmake sdl gl bison openal
USE_SDL=	sdl2
USE_GL=		gl

CMAKE_OFF=	USE_INTERNAL_JPEG USE_INTERNAL_MAD USE_INTERNAL_ZLIB

USE_GITHUB=	yes
GH_ACCOUNT=	openmoh

ARCH_SUB=	${ARCH:S/amd64/x86_64/:S/i386/x86/:S/powerpc$/ppc/:S/powerpc64$/ppc64/}
PLIST_SUB=	ARCH="${ARCH:S/amd64/x86_64/:S/i386/x86/:S/powerpc$/ppc/:S/powerpc64$/ppc64/}"

post-patch:
	${REINPLACE_CMD} -e 's|%%BINARYPATH%%|"${PREFIX}/libexec/openmohaa"|' \
		${WRKSRC}/code/sys/sys_main.c

.include <bsd.port.mk>
