PORTNAME=	fury
PORTVERSION=	20251111
CATEGORIES=	games
MASTER_SITES=	http://dukeworld.com/eduke32/synthesis/${PORTVERSION}-${GITREVISION}/
DISTFILES=	eduke32_src_${PORTVERSION}-${GITREVISION}${EXTRACT_SUFX}

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Ion Fury first person shooter game based on eduke32
WWW=		https://eduke32.com/

LICENSE=	GPLv2 BUILDLIC
LICENSE_COMB=	multi
LICENSE_NAME_BUILDLIC=	BUILD SOURCE CODE LICENSE
LICENSE_FILE_BUILDLIC=	${WRKSRC}/source/build/buildlic.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/source/duke3d/gpl-2.0.txt
LICENSE_PERMS_BUILDLIC=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libFLAC.so:audio/flac

USES=		compiler:c11 dos2unix gl gmake localbase pkgconfig sdl tar:xz
USE_GL=		gl glu
USE_SDL=	sdl2 mixer2
WRKSRC=		${WRKDIR}/eduke32_${PORTVERSION}-${GITREVISION}
GITREVISION=	10652-39967d866
DATADIR=	${PREFIX}/share/fury
MAKEFILE=	GNUmakefile
MAKE_ARGS=	CC=${CC} CXX=${CXX} CLANG=1 PRETTY_OUTPUT=0 \
		USE_MIMALLOC=0 HAVE_GTK2=0 FURY=1 NOASM=1

# Because of mapster32
CONFLICTS_INSTALL=eduke32

PLIST_FILES=	bin/fury bin/mapster32

# Do I really need it?
post-patch:
	@${REINPLACE_CMD} \
		's|"/usr/local/share/games/" APPBASENAME|"${DATADIR}"|' \
		${WRKSRC}/source/duke3d/src/common.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fury ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/mapster32 ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
