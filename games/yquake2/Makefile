# Created by: Vasily Postnicov <shamaz.mazum@gmail.com>
# $FreeBSD$

PORTNAME=	yquake2
DISTVERSION=	8.0
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Yamagi QuakeII is an improved version of Icculus Quake II

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	quake2lnx quake2max quake2sdl

USES=		cmake openal gl sdl
USE_GL=		gl
USE_SDL=	sdl2
CMAKE_ON=	SYSTEMWIDE_SUPPORT

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	f648378

OPTIONS_SUB=		yes
.include <bsd.port.options.mk>

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${Q2DIR}| ; \
		s|%%LIBDIR%%|${PREFIX}/lib|' ${WRKSRC}/src/common/filesystem.c

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
