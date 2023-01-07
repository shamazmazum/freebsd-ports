PORTNAME=	rogue
PORTVERSION=	2.10
CATEGORIES=	games
PKGNAMEPREFIX=	yquake2-

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Improved version of Icculus Quake II (Ground Zero mission pack)
WWW=		https://www.yamagi.org/quake2/

LICENSE=	UNKNOWN
LICENSE_NAME=	LIMITED PROGRAM SOURCE CODE LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept no-pkg-sell no-dist-sell

RUN_DEPENDS=	yquake2:games/yquake2

USES=		gmake tar:xz

USE_GITHUB=	yes
MAKE_ARGS=	VERBOSE=1

GH_ACCOUNT=	yquake2
GH_TAGNAME=	ROGUE_2_10

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/yquake2/rogue
	${INSTALL_LIB} ${WRKSRC}/release/game.so \
		${STAGEDIR}${PREFIX}/lib/yquake2/rogue

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
