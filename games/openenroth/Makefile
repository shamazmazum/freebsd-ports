PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	g20260217
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

USE_GITHUB=	yes
GH_ACCOUNT=	OpenEnroth OpenEnroth:bwcpp vector-of-bool:cmrc Rookfighter:ini \
		mandreyel:mio gharveymn:sv ocornut:imgui TartanLlama:gen \
		ThePhD:sol LuaJIT:lua zhaozg:luacmake boostorg:lambda \
		bnoazx005:tcpp
GH_PROJECT=	OpenEnroth backward-cpp:bwcpp cmrc:cmrc inifile-cpp:ini \
		mio:mio small_vector:sv imgui:imgui generator:gen \
		sol2:sol LuaJIT:lua luajit-cmake:luacmake lambda2:lambda \
		tcpp:tcpp
GH_TAGNAME=	cc437b7 51f0700:bwcpp 952ffdd:cmrc 7bb1ec3:ini \
		8b6b7d8:mio e8e63fe:sv 1f7f1f5:imgui 2a91250:gen 336f76c3:sol \
		97813fb:lua 6446221:luacmake dddfec6:lambda 8041d01:tcpp
GH_SUBDIR=	thirdparty/backward_cpp:bwcpp thirdparty/cmrc:cmrc \
		thirdparty/inifile_cpp:ini thirdparty/mio:mio \
		thirdparty/small_vector:sv thirdparty/imgui/imgui:imgui \
		thirdparty/generator:gen thirdparty/sol2:sol thirdparty/luajit:lua \
		thirdparty/luajit-cmake:luacmake thirdparty/lambda2:lambda \
		thirdparty/tcpp:tcpp

PLIST_FILES=	bin/OpenEnroth

post-patch:
	@${REINPLACE_CMD} -e \
	    '/PROJECT_VERSION/s,unknown,git-${GH_TAGNAME:[1]},' \
		${WRKSRC}/CMakeModules/Git.cmake

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/Bin/OpenEnroth/OpenEnroth \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
