PORTNAME=	cl-webengine-wrapper
PORTVERSION=	20230318
CATEGORIES=	devel www

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Tiny wrapper around WebEngine
WWW=		https://github.com/atlas-engineer/cl-webengine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gl qt:5 gmake
USE_GITHUB=	yes
USE_QT=		buildtools:build qmake:build webengine printsupport widgets declarative \
		gui webchannel network location core
USE_GL=		gl


GH_ACCOUNT=	atlas-engineer
GH_PROJECT=	cl-webengine
GH_TAGNAME=	0fd81be

post-patch:
	${REINPLACE_CMD} -e 's|qmake|qmake-qt5|' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|\<make\>|gmake|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/source/libwebengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -s libwebengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libwebegine.so.1.0
	${LN} -s libwebengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libwebegine.so.1
	${LN} -s libwebengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libwebegine.so

.include <bsd.port.mk>
