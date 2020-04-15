PORTNAME=	n-body-sim
DISTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	science
MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	N-body simulation in two dimensions

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	n-body-sim
GH_TAGNAME=	v0.1

USES=		cmake
LIB_DEPENDS=	libprogram-map.so:devel/program-map \
		libOpenCL.so:devel/ocl-icd
BUILD_DEPENDS=	opencl>0:devel/opencl

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_DESC= Install example configuration file
OPTIONS_SUB=	yes
.include <bsd.port.options.mk>
.include <bsd.port.mk>
