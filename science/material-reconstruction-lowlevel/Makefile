PORTNAME=	material-reconstruction-lowlevel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	science

MAINTAINER=	shamazm.mazum@gmail.com
COMMENT=	Low-level part of material-reconstruction library
WWW=		https://github.com/shamazmazum/material-reconstruction-lowlevel

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers \
		fftw3>0:math/fftw3
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libfftw3f.so:math/fftw3-float

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum

.include <bsd.port.mk>
