PORTNAME=	taisei
PORTVERSION=	1.4.6
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Open source Touhou clone
WWW=		https://taisei-project.org/ \
		https://github.com/taisei-project/taisei

LICENSE=	MIT CC0-1.0 CC-BY-4.0 PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	glslc:graphics/shaderc \
		${PY_BACKPORTS.ZSTD}

LIB_DEPENDS=	libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libfreetype.so:print/freetype2 \
		libopusfile.so:audio/opusfile \
		libcglm.so:math/cglm \
		libzstd.so:archivers/zstd \
		libunibreak.so:textproc/libunibreak

USES=		compiler:c11 desktop-file-utils meson pkgconfig \
		python:build sdl ssl shebangfix shared-mime-info gettext-tools

USE_GITHUB=	yes
GH_ACCOUNT=	taisei-project taisei-project:koishi taisei-project:gc taisei-project:bu
GH_PROJECT=	taisei koishi:koishi SDL_GameControllerDB:gc basis_universal:bu
GH_TAGNAME=	7988b5e:gc f899ac2:koishi 380ef93:bu
GH_SUBDIR=	external/gamecontrollerdb:gc external/koishi:koishi \
		external/basis_universal:bu

SHEBANG_FILES=	scripts/*.py
MESON_ARGS=	-Db_lto=false --wrap-mode=nofallback -DOPENSSLLIB="${OPENSSLLIB}" \
		-Dinstall_macos_bundle=disabled -Dshader_transpiler=disabled \
		-Dshader_transpiler_dxbc=disabled -Dinstall_relocatable=disabled \
		-Dgamemode=disabled
USE_SDL=	sdl3

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	rst2html5:textproc/py-docutils
DOCS_MESON_TRUE=	docs

post-patch:
	@${ECHO} "${DISTVERSIONPREFIX}${PORTVERSION}" > ${WRKSRC}/.VERSION

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING.txt

.include <bsd.port.mk>
