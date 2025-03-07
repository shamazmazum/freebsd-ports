PORTNAME=	arx-libertatis
DISTVERSION=	1.2-2756
DISTVERSIONSUFFIX=	-g5b95e4c5c
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Cross-platform port of Arx Fatalis
WWW=		https://arx-libertatis.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libepoxy.so:graphics/libepoxy
BUILD_DEPENDS=	${LOCALBASE}/include/boost/foreach.hpp:devel/boost-libs \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/bin/inkscape:graphics/inkscape \
		${LOCALBASE}/bin/convert:graphics/ImageMagick7 \
		${LOCALBASE}/bin/optipng:graphics/optipng

USES=		cmake compiler:c++17-lang openal sdl tar:xz llvm:build
USE_SDL=	sdl2
USE_GITHUB=	yes
GH_ACCOUNT=	arx
GH_PROJECT=	ArxLibertatis
CMAKE_OFF=	INSTALL_BLENDER_PLUGIN \
		SET_OPTIMIZATION_FLAGS
CMAKE_ARGS=	-DWITH_SDL=2 \
		-DDATA_DIR:STRING=arx \
		-DDATA_DIR_PREFIXES:STRING="\$${XDG_DATA_DIRS:-${PREFIX}/share/}" \
		-DINSTALL_DATADIR:STRING="${DATADIR}" \
		-DIGNORE_EXE_DIR:STRING="${PREFIX}/bin:${LOCABASE}/bin" \
		-DCMAKE_INSTALL_MANDIR="${PREFIX}/share/man"

LDFLAGS_i386=	-Wl,-znotext

CONFLICTS_INSTALL=	rnv

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS CHANGELOG README.md
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/cmake/*.cmake

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
