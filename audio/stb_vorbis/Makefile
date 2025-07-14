PORTNAME=	stb_vorbis
DISTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Stb vorbis decoder
WWW=		https://github.com/nothings/stb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	YES
GH_ACCOUNT=	nothings
GH_PROJECT=	stb
GH_TAGNAME=	f58f558

PLIST_FILES=	lib/libstb_vorbis.so.1.22 \
		lib/libstb_vorbis.so.1 \
		lib/libstb_vorbis.so

do-build:
	${CC} -fpic -shared -o ${WRKDIR}/libstb_vorbis.so.1.22 ${WRKSRC}/stb_vorbis.c

do-install:
	${INSTALL_LIB} ${WRKDIR}/libstb_vorbis.so.1.22 ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libstb_vorbis.so.1.22 \
		${STAGEDIR}${PREFIX}/lib/libstb_vorbis.so.1
	${RLN} ${STAGEDIR}${PREFIX}/lib/libstb_vorbis.so.1.22 \
		${STAGEDIR}${PREFIX}/lib/libstb_vorbis.so

.include <bsd.port.mk>
