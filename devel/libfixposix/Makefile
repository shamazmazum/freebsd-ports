PORTNAME=	libfixposix
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
#PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	ports@shiori.com.br
COMMENT=	Replacement for inconsistent parts of POSIX
WWW=		https://github.com/sionescu/libfixposix

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		autoreconf libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sionescu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
