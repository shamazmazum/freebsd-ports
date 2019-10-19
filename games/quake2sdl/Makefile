# Created by: Vasily Postnicov <shamaz.mazum@gmail.com>
# $FreeBSD$

PORTNAME=	quake2sdl
PORTVERSION=	g20191019
CATEGORIES=	games
CONFLICTS_INSTALL=	quake2lnx quake2max

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	18b181c
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	SDL2 version of Icculus Quake II
LICENSE=	GPLv2

USE_GL=		gl
USE_SDL=	sdl2
USES=		cmake

OPTIONS_DEFINE=	RETEX QMAX
RETEX_DESC=	Build with support for retexturing
QMAX_DESC=	Build with improved OpenGL renderer

QMAX_USES=		jpeg
QMAX_USE=		gl=glu
QMAX_CMAKE_BOOL_ON=	WITH_QMAX
QMAX_MASTER_SITES=	http://offload1.icculus.org/quake2/files/
QMAX_DISTFILES=		maxpak.pak
RETEX_CMAKE_BOOL_ON=	WITH_RETEX
RETEX_RUN_DEPENDS=	${Q2DIR}/baseq2/pak10.pak:games/quake2-extras
OPTIONS_SUB=		yes
.include <bsd.port.options.mk>

do-install-QMAX-on:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/maxpak.pak \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/baseq2
.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
