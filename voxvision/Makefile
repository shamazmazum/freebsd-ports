PORTNAME=	voxvision
DISTVERSION=	0.34-4
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-gb6c042c
PORTREVISION=	1
CATEGORIES=	graphics
MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Voxel visualisation library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libiniparser.so:devel/iniparser \
		libdispatch.so:devel/libdispatch \
		libvn3d.so:graphics/vn3d

USE_SDL=	sdl2
USES=		lua:53 cmake python:build

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_TUPLE=	shamazmazum:voxvision:b6c042c:voxvision \
		shamazmazum:luasdl2:37f2163:voxvision/src/voxengine/modules/luasdl2

OPTIONS_DEFINE=	DOCS NO_SSE EXAMPLES
DOCS_DESC=	Install Doxygen-generated documentation
NO_SSE_DESC=	Disable SSE SIMD intrinsics (for running on old CPUs)
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
NO_SSE_CMAKE_BOOL_OFF=	SSE_INTRIN
OPTIONS_SUB=	yes
.include <bsd.port.options.mk>

post-install-DOCS-on:
	${MAKE_CMD} doc -C ${BUILD_WRKSRC}
	cd ${BUILD_WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${RM} ${WRKDIR}/PLIST.txt
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' \
		>> ${WRKDIR}/PLIST.txt ; \
	(cd ${WRKDIR} ; ${CAT} ${WRKDIR}/PLIST.txt >> ${TMPPLIST})

.include <bsd.port.mk>
