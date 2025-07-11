PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	g20250415
PORTREVISION=	1
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
		sol2>0:devel/sol2 \
		fast_float>0:math/fast_float \
		cli11>0:devel/cli11

USES=		cmake gl openal sdl luajit pkgconfig:build
USE_GL=		gl
USE_SDL=	sdl2
SUB_FILES=	pkg-message

CMAKE_OFF=	OE_USE_PREBUILT_DEPENDENCIES \
		OE_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	OpenEnroth OpenEnroth:bwcpp vector-of-bool:cmrc Rookfighter:ini \
		Neargye:me mandreyel:mio gharveymn:sv ocornut:imgui TartanLlama:gen
GH_PROJECT=	OpenEnroth backward-cpp:bwcpp cmrc:cmrc inifile-cpp:ini \
		magic_enum:me mio:mio small_vector:sv imgui:imgui generator:gen
GH_TAGNAME=	b6fd866 51f0700:bwcpp 952ffdd:cmrc 7bb1ec3:ini d01a4f9:me \
		8b6b7d8:mio 6b054e7:sv f5d18523:imgui 2a91250:gen
GH_SUBDIR=	thirdparty/backward_cpp:bwcpp thirdparty/cmrc:cmrc \
		thirdparty/inifile_cpp:ini thirdparty/magic_enum:me thirdparty/mio:mio \
		thirdparty/small_vector:sv thirdparty/imgui/imgui:imgui \
		thirdparty/generator:gen

PLIST_FILES=	bin/OpenEnroth

post-patch:
	@${REINPLACE_CMD} -e \
	    '/PROJECT_VERSION/s,unknown,git-${GH_TAGNAME:[1]},' \
		${WRKSRC}/CMakeModules/Git.cmake

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/Bin/OpenEnroth/OpenEnroth \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
