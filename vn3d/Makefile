PORTNAME=	vn3d
DISTVERSION=	0.4
CATEGORIES=	graphics
MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Value noise library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_TAGNAME=	v0.4

OPTIONS_DEFINE=	LINEAR_INTERPOLATION DOCS
LINEAR_INTERPOLATION_DESC= Use more faster linear interpolation
LINEAR_INTERPOLATION_CMAKE_BOOL= LINEAR_INTERPOLATION
DOCS_DESC= Build documentation (requires Doxygen)
DOCS_BUILD_DEPENDS= doxygen:devel/doxygen
OPTIONS_SUB=	yes
.include <bsd.port.options.mk>

post-install-DOCS-on:
	${MAKE_CMD} doc -C ${BUILD_WRKSRC}
	cd ${BUILD_WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
