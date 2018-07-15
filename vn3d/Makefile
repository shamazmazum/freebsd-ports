PORTNAME=	vn3d
DISTVERSION=	0.1
CATEGORIES=	graphics
MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Value noise library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	vn3d
GH_TAGNAME=	v0.1

OPTIONS_DEFINE=	LINEAR_INTERPOLATION
LINEAR_INTERPOLATION_DESC= Use more faster linear interpolation
LINEAR_INTERPOLATION_CMAKE_BOOL= LINEAR_INTERPOLATION

.include <bsd.port.options.mk>
.include <bsd.port.mk>
