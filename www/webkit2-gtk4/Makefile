PORTNAME=	webkit
DISTVERSION=	2.46.0
CATEGORIES=	www
MASTER_SITES=	https://webkitgtk.org/releases/
PKGNAMESUFFIX=	2-gtk4
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK 4 toolkit
WWW=		https://webkitgtk.org/

LICENSE=	GPLv2 BSD2CLAUSE
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/bin/ar:devel/binutils \
		${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR} \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libwebp.so:graphics/webp \
		libpng.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libnotify.so:devel/libnotify \
		libhyphen.so:textproc/hyphen \
		libicutu.so:devel/icu \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libsoup-3.0.so:devel/libsoup3 \
		libgcrypt.so:security/libgcrypt \
		libtasn1.so:security/libtasn1 \
		libwoff2dec.so:devel/woff2 \
		liblcms2.so:graphics/lcms2 \
		libgpg-error.so:security/libgpg-error \
		libavif.so:graphics/libavif \
		libepoxy.so:graphics/libepoxy \
		libdrm.so:graphics/libdrm \
		libjxl.so:graphics/libjxl \
		libgraphene-1.0.so:graphics/graphene \
		libvulkan.so:graphics/vulkan-loader

USES=		bison cmake compiler:c++14-lang cpe gettext gl gnome gperf \
		jpeg localbase:ldflags perl5 pkgconfig python:build \
		sqlite tar:xz xorg ruby:build
USE_GNOME=	cairo gdkpixbuf2 gtk40 introspection:build libxml2 libxslt
USE_GL=		gl egl glesv2 gbm
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	x11

PORTSCOUT=	limitw:1,even

CPE_VENDOR=	webkitgtk
CPE_PRODUCT=	webkitgtk

BINARY_ALIAS=		python=${PYTHON_CMD}
CXXFLAGS_powerpc=	-DENABLE_YARR_JIT=0
CXXFLAGS_powerpc64=	-DENABLE_YARR_JIT=0
CMAKE_ARGS=		-DPORT=GTK
CMAKE_ON=		USE_SYSTEM_MALLOC \
			USE_GTK4
CMAKE_OFF=		ENABLE_MINIBROWSER \
			ENABLE_JOURNALD_LOG \
			ENABLE_GAMEPAD \
			USE_SOUP2 \
			USE_LIBBACKTRACE \
			USE_SYSTEM_SYSPROF_CAPTURE
CMAKE_OFF_armv6=	ENABLE_JIT
CMAKE_OFF_armv7=	ENABLE_JIT
CMAKE_OFF_powerpc=	ENABLE_JIT
CMAKE_OFF_powerpc64=	ENABLE_JIT
INSTALL_TARGET=		install

OPTIONS_DEFINE=		GEOIP GSTREAMER WAYLAND DOCS
OPTIONS_DEFAULT=	GEOIP GSTREAMER WAYLAND DOCS
OPTIONS_SUB=		yes

GEOIP_CMAKE_BOOL=	ENABLE_GEOLOCATION
GEOIP_BUILD_DEPENDS=	geoclue>=2.4.3:net/geoclue
GEOIP_RUN_DEPENDS=	geoclue>=2.4.3:net/geoclue

GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=bad,gl
GSTREAMER_CMAKE_BOOL=	ENABLE_VIDEO ENABLE_WEB_AUDIO

WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND_TARGET
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-egl; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with OPENGL support enabled."; \
		${FALSE}; \
	fi

post-patch:
	${REINPLACE_CMD} -e 's|%%LIBDIR%%|${LOCALBASE}/lib|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/WebKitWebDriver ${STAGEDIR}${PREFIX}/bin/WebKitWebDriver-6
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/webkitgtk-6.0/injected-bundle/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/webkitgtk-6.0/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/WebKitWebDriver-6

.include <bsd.port.mk>
