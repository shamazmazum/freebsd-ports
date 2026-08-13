PORTNAME=	dhewm3-rivensin
PORTVERSION=	20260607
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Scarlet Rivensin: The Ruiner mod for dhewm3
WWW=		https://www.moddb.com/mods/ruiner

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	dhewm3>0:games/dhewm3

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	dhewm
GH_PROJECT=	dhewm3-sdk
GH_TAGNAME=	a4dfc7c

SUB_FILES=	pkg-message
PLIST_FILES=	lib/dhewm3/rivensin.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/dhewm3
	${INSTALL_LIB} ${BUILD_WRKSRC}/rivensin.so ${STAGEDIR}${PREFIX}/lib/dhewm3

.include <bsd.port.mk>
