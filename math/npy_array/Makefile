PORTNAME=	npy_array
PORTVERSION=	20250525
CATEGORIES=	math

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Simple library for reading and writing numpy arrays in C code
WWW=		https://github.com/oysteijo/npy_array

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libzip.so:archivers/libzip

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	oysteijo
GH_TAGNAME=	c739d79

.include <bsd.port.mk>
