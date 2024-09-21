PORTNAME=	xatrix
PORTVERSION=	2.13
CATEGORIES=	games
PKGNAMEPREFIX=	yquake2-

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Improved version of Icculus Quake II (The Reconing mission pack)
WWW=		https://www.yamagi.org/quake2/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	yquake2:games/yquake2

USES=		gmake tar:xz

USE_GITHUB=	yes
MAKE_ARGS=	VERBOSE=1

GH_ACCOUNT=	yquake2
GH_TAGNAME=	XATRIX_2_12

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/yquake2/xatrix
	${INSTALL_LIB} ${WRKSRC}/release/game.so \
		${STAGEDIR}${PREFIX}/lib/yquake2/xatrix

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
