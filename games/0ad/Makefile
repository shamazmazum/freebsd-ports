PORTNAME=	0ad
PORTVERSION=	0.27.0
CATEGORIES=	games
MASTER_SITES=	http://releases.wildfiregames.com/ \
		SF/zero-ad/releases
DISTFILES=	${PORTNAME}-${PORTVERSION}-unix-build.tar.xz \
		${PORTNAME}-${PORTVERSION}-unix-data.tar.xz

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Real-time strategy (RTS) game of ancient warfare
WWW=		https://play0ad.com/

LICENSE=	GPLv2 CC-BY-SA-3.0
LICENSE_COMB=	multi

BUILD_DEPENDS=	zip:archivers/zip \
		cmake:devel/cmake-core \
		cxxtestgen:devel/cxxtest \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		libpng16.so:graphics/png \
		libvorbisfile.so:audio/libvorbis \
		libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libgloox.so:net-im/gloox \
		libminiupnpc.so:net/miniupnpc \
		libenet.so:net/enet \
		libsodium.so:security/libsodium \
		libfmt.so:devel/libfmt \
		libmozjs-115.so:lang/spidermonkey115 \
		libvulkan.so:graphics/vulkan-loader

USES=		compiler:c++11-lib desktop-file-utils dos2unix gmake gnome \
		iconv openal:al perl5 pkgconfig python:3.9,build sdl tar:xz \
		xorg
USE_GNOME=	libxml2
USE_GL=		gl
USE_SDL=	sdl2
USE_XORG=	x11 xcursor
USE_PERL5=	build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/build/workspaces/gcc
MAKE_ARGS=	config=release verbose=1
CPPFLAGS+=	-DU_USING_ICU_NAMESPACE=1
BUNDLE_LIBS=	yes
DOS2UNIX_REGEX=	.*\.([ch]p{0,2}|make)
BINARY_ALIAS=	python3=${PYTHON_CMD}

MAKE_ENV+=	JOBS=${_MAKE_JOBS}
PREBUILD_ENV=	MAKE=gmake

PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/build/premake/extern_libs5.lua

pre-build:
	(cd ${WRKSRC}/libraries/source/fcollada && ${SETENV} ${MAKE_ENV} ${PREBUILD_ENV} ${SH} build.sh)
	(cd ${WRKSRC}/libraries/source/nvtt && ${SETENV} ${MAKE_ENV} ${PREBUILD_ENV} ${SH} build.sh)
	(cd ${WRKSRC}/libraries/source/premake-core && ${SETENV} ${PREBUILD_ENV} ${MAKE_ENV} ${SH} build.sh)
	(cd ${WRKSRC}/libraries/source/spirv-reflect && ${SETENV} ${PREBUILD_ENV} ${MAKE_ENV} ${SH} build.sh)
	(cd ${WRKSRC}/build/workspaces && ${SETENV} ${MAKE_ENV} ./update-workspaces.sh \
		--bindir=${PREFIX}/bin --datadir=${DATADIR} --libdir=${PREFIX}/lib/${PORTNAME} --without-atlas --with-system-mozjs --with-system-cxxtest)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/pyrogenesis ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/resources/0ad.sh ${STAGEDIR}${PREFIX}/bin/0ad
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/binaries/system && ${INSTALL_LIB} libCollada.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	(cd ${WRKSRC}/libraries/source/nvtt/lib && ${INSTALL_LIB} libnvcore.so libnvimage.so libnvmath.so libnvtt.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/binaries/data && ${COPYTREE_SHARE} "config l10n tests tools" ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${DATADIR}/mods/public ${STAGEDIR}${DATADIR}/mods/mod
	${TAR} xf ${WRKSRC}/binaries/data/mods/public/public.zip -C ${STAGEDIR}${DATADIR}/mods/public --no-same-permissions
	${TAR} xf ${WRKSRC}/binaries/data/mods/mod/mod.zip -C ${STAGEDIR}${DATADIR}/mods/mod --no-same-permissions

.include <bsd.port.mk>
