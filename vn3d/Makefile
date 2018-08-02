PORTNAME=	vn3d
DISTVERSION=	0.3.1
CATEGORIES=	graphics
MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Value noise library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	vn3d
GH_TAGNAME=	v0.3.1

OPTIONS_DEFINE=	LINEAR_INTERPOLATION DOC
LINEAR_INTERPOLATION_DESC= Use more faster linear interpolation
LINEAR_INTERPOLATION_CMAKE_BOOL= LINEAR_INTERPOLATION
DOC_DESC= Build documentation (requires Doxygen)
DOC_BUILD_DEPENDS= doxygen:devel/doxygen
OPTIONS_SUB=	yes
.include <bsd.port.options.mk>

do-install-DOC-on:
	${MAKE_CMD} doc -C ${BUILD_WRKSRC}
	cd ${BUILD_WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
