PORTNAME=	sift3d
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0
CATEGORIES=	graphics

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Scale invariant feature transform for 3D images
WWW=		https://github.com/bbrister/SIFT3D

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		cmake

USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	fatimp
GH_PROJECT=	SIFT3D

OPTIONS_DEFINE=		EXAMPLES DOCS
OPTIONS_DEFAULT=	EXAMPLES
OPTIONS_SUB=		yes

# Built as a static library
EXAMPLES_BUILD_DEPENDS=	nifticlib>0:science/nifticlib
EXAMPLES_CMAKE_BOOL=	WITH_EXAMPLES

DOCS_BUILD_DEPENDS=	doxygen>0:devel/doxygen
DOCS_ALL_TARGET=	doc

post-install-DOCS-on:
	(cd ${INSTALL_WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${FIND} ${STAGEDIR}${DOCSDIR} -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

.include <bsd.port.mk>
