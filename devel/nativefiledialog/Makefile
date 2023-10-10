PORTNAME=	nativefiledialog
PORTVERSION=	116
CATEGORIES=	devel

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Tiny library which invokes file open and save dialogs
WWW=		https://github.com/mlabbe/nativefiledialog

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Do not know how to install files

USES=		gmake pkgconfig gnome
USE_GNOME=	gtk30
USE_GITHUB=	yes
GH_ACCOUNT=	mlabbe
GH_PROJECT=	nativefiledialog
GH_TAGNAME=	release_${PORTVERSION}

BUILD_WRKSRC=	${WRKSRC}/build/gmake_linux

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/nfd
	${INSTALL_DATA} ${WRKSRC}/src/include/nfd.h ${STAGEDIR}${PREFIX}/include/nfd
	${INSTALL_DATA} ${WRKSRC}/build/lib/Release/x64/libnfd.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
