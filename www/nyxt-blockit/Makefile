PORTNAME=	blockit
DISTVERSION=	20241117
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	nyxt-

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	WebKitGTK adblock extension for the Nyxt browser
WWW=		https://github.com/dudik/blockit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	webkit2-gtk_41>0:www/webkit2-gtk@41

USES=		gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	dudik
GH_TAGNAME=	be185b4

PLIST_FILES=	lib/nyxt/blockit.so

post-patch:
	${REINPLACE_CMD} -e 's|4.0|4.1|g' ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/nyxt
	${INSTALL_LIB} ${BUILD_WRKSRC}/blockit.so ${STAGEDIR}${PREFIX}/lib/nyxt

.include <bsd.port.mk>
