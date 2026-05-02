PORTNAME=	mesh-repair
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
CATEGORIES=	graphics

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Polygonal mesh repair program
WWW=		https://github.com/fatimp/mesh-repair

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cgal>0:math/cgal
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	fatimp

PLIST_FILES=	bin/mesh-repair

.include <bsd.port.mk>
