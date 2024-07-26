PORTNAME=	taisei
PORTVERSION=	1.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source Touhou clone
WWW=		https://taisei-project.org/ \
		https://github.com/taisei-project/taisei

LICENSE=	MIT CC0-1.0 PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libzip.so:archivers/libzip \
		libwebp.so:graphics/webp \
		libfreetype.so:print/freetype2 \
		libopusfile.so:audio/opusfile \
		libcglm.so:math/cglm \
		libzstd.so:archivers/zstd

BUILD_DEPENDS=	glslc:graphics/shaderc \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.15:archivers/py-zstandard@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	taisei-project taisei-project:koishi taisei-project:gc taisei-project:bu \
		taisei-project:zstd
GH_PROJECT=	taisei koishi:koishi SDL_GameControllerDB:gc basis_universal:bu \
		python-zipfile-zstd:zstd
GH_TAGNAME=	13aef2d 232c738:gc 4adb182:koishi 960a57a:bu e596dd8:zstd
GH_SUBDIR=	external/gamecontrollerdb:gc external/koishi:koishi \
		external/basis_universal:bu external/python-zipfile-zstd:zstd

USES=		compiler:c11 desktop-file-utils meson pkgconfig \
		python:build sdl ssl shebangfix shared-mime-info
SHEBANG_FILES=	scripts/*.py
MESON_ARGS=	-Db_lto=false --wrap-mode=nofallback -DOPENSSLLIB="${OPENSSLLIB}" \
		-Dinstall_macos_bundle=disabled -Dshader_transpiler=disabled \
		-Dinstall_relocatable=disabled -Dgamemode=disabled
USE_SDL=	sdl2# ttf2 mixer2

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	rst2html5:textproc/py-docutils
DOCS_MESON_TRUE=	docs

post-patch:
	@${ECHO} "v1.4" > ${WRKSRC}/.VERSION

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING.txt

.include <bsd.port.mk>
