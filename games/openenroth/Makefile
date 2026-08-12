PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	g20260716
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Open reimplementation of Might and Magic VI-VIII game engine
WWW=		https://github.com/OpenEnroth/OpenEnroth

LICENSE=	LGPL3

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog \
		libpng16.so:graphics/png
BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		glm>0:math/glm \
		fast_float>0:math/fast_float \
		cli11>0:devel/cli11 \
		magic_enum>0:devel/magic_enum

USES=		cmake gl openal sdl pkgconfig:build
USE_GL=		gl
USE_SDL=	sdl3
SUB_FILES=	pkg-message

CMAKE_OFF=	OE_USE_PREBUILT_DEPENDENCIES \
		OE_BUILD_TESTS
CMAKE_ARGS=	-DFETCHCONTENT_SOURCE_DIR_ZTD.CMAKE="${WRKSRC}/_deps/ztd.cmake-src" \
		-DFETCHCONTENT_SOURCE_DIR_ZTD.IDK="${WRKSRC}/_deps/ztd.idk-src" \
		-DFETCHCONTENT_SOURCE_DIR_ZTD.INLINE_CONTAINERS="${WRKSRC}/_deps/ztd.inline_containers-src" \
		-DFETCHCONTENT_SOURCE_DIR_ZTD.ENCODING_TABLES="${WRKSRC}/_deps/ztd.encoding_tables-src" \
		-DFETCHCONTENT_SOURCE_DIR_ZTD.CUNEICODE="${WRKSRC}/_deps/ztd.cuneicode-src" \
		-DFETCHCONTENT_SOURCE_DIR_ZTD.PLATFORM="${WRKSRC}/_deps/ztd.platform-src"

USE_GITHUB=	yes
GH_ACCOUNT=	OpenEnroth OpenEnroth:bwcpp vector-of-bool:cmrc Rookfighter:ini \
		mandreyel:mio gharveymn:sv ocornut:imgui TartanLlama:gen \
		ThePhD:sol LuaJIT:lua zhaozg:luacmake boostorg:lambda \
		bnoazx005:tcpp captainurist:ztd \
		soasis:ztdcmake soasis:ztdidk soasis:ztdic soasis:ztdet \
		soasis:ztdcuneicode soasis:ztdplatform
GH_PROJECT=	OpenEnroth backward-cpp:bwcpp cmrc:cmrc inifile-cpp:ini \
		mio:mio small_vector:sv imgui:imgui generator:gen \
		sol2:sol LuaJIT:lua luajit-cmake:luacmake lambda2:lambda \
		tcpp:tcpp ztd_text:ztd \
		cmake:ztdcmake idk:ztdidk inline_containers:ztdic encoding_tables:ztdet \
		cuneicode:ztdcuneicode platform:ztdplatform
GH_TAGNAME=	c96180b 51f0700:bwcpp 952ffdd:cmrc 7bb1ec3:ini \
		8b6b7d8:mio e8e63fe:sv 1f7f1f5:imgui 2a91250:gen 336f76c3:sol \
		97813fb:lua 6446221:luacmake dddfec6:lambda 8041d01:tcpp \
		c7b7cd6:ztd \
		382e34f:ztdcmake a8f2f9d:ztdidk 80c5acb:ztdic c0c5de5:ztdet \
		8ed6b88:ztdcuneicode d03b150:ztdplatform
GH_SUBDIR=	thirdparty/backward_cpp:bwcpp thirdparty/cmrc:cmrc \
		thirdparty/inifile_cpp:ini thirdparty/mio:mio \
		thirdparty/small_vector:sv thirdparty/imgui/imgui:imgui \
		thirdparty/generator:gen thirdparty/sol2:sol thirdparty/luajit:lua \
		thirdparty/luajit-cmake:luacmake thirdparty/lambda2:lambda \
		thirdparty/tcpp:tcpp thirdparty/ztd_text:ztd \
		_deps/ztd.cmake-src:ztdcmake _deps/ztd.idk-src:ztdidk \
		_deps/ztd.inline_containers-src:ztdic _deps/ztd.encoding_tables-src:ztdet \
		_deps/ztd.cuneicode-src:ztdcuneicode _deps/ztd.platform-src:ztdplatform

PLIST_FILES=	bin/OpenEnroth

post-patch:
	@${REINPLACE_CMD} -e \
	    '/PROJECT_VERSION/s,unknown,git-${GH_TAGNAME:[1]},' \
		${WRKSRC}/CMakeModules/Git.cmake

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/Bin/OpenEnroth/OpenEnroth \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
