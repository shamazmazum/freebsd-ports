PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	g20231110
PORTREVISION=	4
CATEGORIES=	games

PATCH_SITES=	https://github.com/shamazmazum/${GH_PROJECT}/commit/
PATCHFILES=	038126f9d75c.patch:-p1
PATCHFILES+=	8b7803c6d5d4.patch:-p1
PATCHFILES+=	9e82f4681add.patch:-p1
PATCHFILES+=	6c1dfd3661d4.patch:-p1
PATCHFILES+=	638abe4baf97.patch:-p1
PATCHFILES+=	d48e47f6f651.patch:-p1
PATCHFILES+=	a3768fdf56ed.patch:-p1
PATCHFILES+=	66f4b104391a.patch:-p1
PATCHFILES+=	cccee7eafe67.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open reimplementation of Might and Magic VI-VIII game engine
WWW=		https://github.com/OpenEnroth/OpenEnroth

LICENSE=	LGPL3

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog
BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		glm>0:math/glm

USES=		cmake gl openal sdl luajit pkgconfig:build
USE_GL=		gl
USE_SDL=	sdl2
SUB_FILES=	pkg-message

CMAKE_OFF=	OE_USE_PREBUILT_DEPENDENCIES \
		OE_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	OpenEnroth CLIUtils:cli11 fastfloat:ff Neargye:me \
		pulzed:mini mandreyel:mio
GH_PROJECT=	OpenEnroth CLI11:cli11 fast_float:ff magic_enum:me \
		mINI:mini mio:mio
GH_TAGNAME=	f3bf460 9532482:cli11 1ea4f27:ff d01a4f9:me \
		a1ff72e:mini 8b6b7d8:mio
GH_SUBDIR=	thirdparty/cli11:cli11 thirdparty/fast_float:ff \
		thirdparty/magic_enum:me thirdparty/mini:mini \
		thirdparty/mio:mio

.include <bsd.port.options.mk>

.if ${ARCH} == i386
LLD_UNSAFE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
	    '/PROJECT_VERSION/s,unknown,git-${GH_TAGNAME:[1]},' \
		${WRKSRC}/CMakeModules/Git.cmake

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/Bin/OpenEnroth/OpenEnroth \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/resources/shaders ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
