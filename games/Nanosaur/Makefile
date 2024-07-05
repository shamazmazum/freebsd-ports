PORTNAME=	Nanosaur
DISTVERSIONPREFIX=	v
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Nanosaur source port
WWW=		https://pangeasoft.net/nano/

LICENSE=	CC-BY-NC-SA-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake gl sdl

USE_GITHUB=	yes
GH_ACCOUNT=	jorio
GH_TUPLE=	jorio:Pomme:d57c28e:Pomme/extern/Pomme
USE_GL=		opengl
USE_SDL=	sdl2

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}/Data|' ${WRKSRC}/src/Boot.cpp

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC}/Data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/Data

.include <bsd.port.mk>
