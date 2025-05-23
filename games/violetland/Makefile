# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>

PORTNAME=	violetland
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Top-down survival shoot'em 'up
WWW=		https://violetland.github.io/

LICENSE=	GPLv3 CC-BY-SA-3.0
LICENSE_COMB=	multi
#LICENSE_FILE_GPLv3=		"${WRKSRC}/LICENSE (code)" # framework doesn't handle these properly
#LICENSE_FILE_CC-BY-SA-3.0=	"${WRKSRC}/LICENSE (content)"

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		cmake compiler:c++11-lang gettext gl sdl
USE_SDL=	sdl2 mixer2 image2 ttf2
USE_GL=		gl glu
USE_CXXSTD=	c++14
CMAKE_ARGS=	-DDATA_INSTALL_DIR="${DATADIR}" \
		-DLOCALE_INSTALL_DIR="${PREFIX}/share/locale"

USE_GITHUB=	yes
GH_PROJECT=	violetland
GH_ACCOUNT=	shamazmazum
GH_TUPLE=	ooxi:CMake-Gettext:c7acd17:cmake_gettext/lib/CMake-Gettext

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icon-light.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG.md README.md README_RU.TXT \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
