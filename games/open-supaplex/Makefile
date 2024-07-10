PORTNAME=	open-supaplex
PORTVERSION=	7.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Opensource reimplementation of Supaplex game
WWW=		https://github.com/sergiou87/open-supaplex

LICENSE=	GPLv3

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

USES=		gmake sdl
USE_SDL=	sdl2 mixer2

USE_GITHUB=	yes
GH_ACCOUNT=	sergiou87

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/linux/Makefile

do-build:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} -C ${WRKSRC}/linux

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linux/opensupaplex ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
