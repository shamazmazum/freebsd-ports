PORTNAME=	n-body-sim
DISTVERSIONPREFIX= v
DISTVERSION=	0.2
CATEGORIES=	science

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	N-body simulation in two dimensions

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprogram-map.so:devel/program-map \
		libOpenCL.so:devel/ocl-icd
BUILD_DEPENDS=	opencl>0:devel/opencl

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_DESC= Install example configuration file
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>
.include <bsd.port.mk>
