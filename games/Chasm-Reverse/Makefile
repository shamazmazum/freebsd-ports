PORTNAME=	Chasm-Reverse
DISTVERSION=	0.3-78
DISTVERSIONSUFFIX=	-gf3a80d7
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Opensource recreation of Chasm: The Rift game
WWW=		https://github.com/Panzerschrek/Chasm-Reverse

LICENSE=	GPLv3+

USES=		cmake sdl gl
USE_SDL=	sdl2
USE_GL=		gl

#LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	Panzerschrek
GH_TUPLE=	Panzerschrek:panzer_ogl_lib:34d342d:ogl/src/panzer_ogl_lib

SUB_FILES=	pkg-message

#DESKTOP_ENTRIES="dhewm 3" \
#		"" \
#		"doom3" \
#		"${PORTNAME}" \
#		"Game;ActionGame;" \
#		""

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/src/host.cpp

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ArchiveDepacker   ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/BlendtabAnalyzer  ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/CarToTGAConverter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/CelDepacker       ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/FloorsExtractor   ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/MapToTGAConverter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ObjToTGAConverter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/PaletteExtractor  ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/PanzerChasm       ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} shaders ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
