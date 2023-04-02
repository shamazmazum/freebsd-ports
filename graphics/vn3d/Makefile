PORTNAME=	vn3d
DISTVERSION=	0.6
CATEGORIES=	graphics

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Value noise library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_TAGNAME=	v0.6

OPTIONS_DEFINE=	LINEAR_INTERPOLATION DOCS EXAMPLES
LINEAR_INTERPOLATION_DESC= Use more faster linear interpolation
LINEAR_INTERPOLATION_CMAKE_BOOL= LINEAR_INTERPOLATION
DOCS_DESC= Build documentation (requires Doxygen)
DOCS_BUILD_DEPENDS= doxygen:devel/doxygen
EXAMPLES_LIB_DEPENDS= libturbojpeg.so:graphics/libjpeg-turbo
OPTIONS_SUB=	yes
.include <bsd.port.options.mk>

post-build-DOCS-on:
	${MAKE_CMD} doc -C ${BUILD_WRKSRC}

post-install-DOCS-on:
	(cd ${BUILD_WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

.include <bsd.port.mk>
