PORTNAME=	n-body-sim
DISTVERSION=	g20190915
#PORTREVISION=	1
CATEGORIES=	math
MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	N-body simulation in two dimensions

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	n-body-sim
GH_TAGNAME=	991b2a6

USES=		cmake
LIB_DEPENDS=	libiniparser.so:devel/iniparser \
		libprogram-map.so:devel/program-map \
		libOpenCL.so:devel/ocl-icd

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_DESC= Install example configuration file
OPTIONS_SUB=	yes
.include <bsd.port.options.mk>
.include <bsd.port.mk>
