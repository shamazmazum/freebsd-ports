# Created by: stas

PORTNAME=	libdispatch
DISTVERSIONPREFIX= v
DISTVERSION=	210
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Grand Central Dispatch API support library
WWW=		http://libdispatch.macosforge.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USES=		libtool tar:bzip2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	${PORTNAME}-legacy

.include <bsd.port.mk>
