PORTNAME=	sift3d
DISTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Scale invariant feature transform for 3D images
WWW=		https://github.com/bbrister/SIFT3D

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		cmake

USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bbrister
GH_PROJECT=	SIFT3D

OPTIONS_DEFINE=		NIFTI DICOM
OPTIONS_DEFAULT=	NIFTI

NIFTI_DESC=		NIFTI-1 file format support
DICOM_DESC=		DICOM file format support

# Built as a static library
NIFTI_BUILD_DEPENDS=	nifticlib>0:science/nifticlib
DICOM_LIB_DEPENDS=	libdcmimage.so:graphics/dcmtk

.include <bsd.port.mk>
