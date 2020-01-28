# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	wayland
PORTVERSION=	1.17.91
#PORTREVISION=	1
CATEGORIES=	graphics wayland
MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wayland composite "server"

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libepoll-shim.so:devel/libepoll-shim

USE_GITHUB=	yes
GH_ACCOUNT=	wayland-project

CFLAGS+=	"-I${LOCALBASE}/include/libepoll-shim"

USES=		autoreconf gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	libxslt:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-documentation
CONFIGURE_ENV=	ac_cv_func_posix_fallocate=no # EINVAL for many FS on 12.0
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
