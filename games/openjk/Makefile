PORTNAME=	openjk
PORTVERSION=	g20231123
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Community effort to maintain Jedi Academy + Jedi Outcast
WWW=		https://openjk.org

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++11-lang cmake gl jpeg localbase sdl
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	JACoders
GH_PROJECT=	OpenJK
GH_TAGNAME=	2ed26b3
USE_SDL=	sdl2
#USE_XORG=	x11

OPENJK_ARCH=	${ARCH:S/powerpc64$/ppc64/:S/powerpc$/ppc/:C/armv.*/arm/}
PLIST_SUB=	ARCH="${OPENJK_ARCH}"
SUB_FILES=	jamp \
		jasp
SUB_LIST=	ARCH="${OPENJK_ARCH}"

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jamp ${WRKDIR}/jasp ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
