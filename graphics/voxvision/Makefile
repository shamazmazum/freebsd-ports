PORTNAME=	voxvision
DISTVERSIONPREFIX=	v
DISTVERSION=	0.37-56
DISTVERSIONSUFFIX=	-gff49d47
CATEGORIES=	graphics

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Voxel visualisation library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libiniparser.so:devel/iniparser \
		libdispatch.so:devel/libdispatch \
		libvn3d.so:graphics/vn3d \
		libnpy_array.so:math/npy_array

USES=		lua:53 cmake sdl pkgconfig
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_TUPLE=	shamazmazum:luasdl2:3e0db9e:luasdl2/src/voxengine/modules/luasdl2

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_DESC=	Install Doxygen-generated documentation
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
OPTIONS_SUB=	yes
.include <bsd.port.options.mk>

post-build-DOCS-on:
	${MAKE_CMD} doc -C ${BUILD_WRKSRC}

post-install-DOCS-on:
	(cd ${BUILD_WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

.include <bsd.port.mk>
