# $FreeBSD:$

PORTNAME=	libasync-process
DISTVERSION=	20200811
CATEGORIES=	misc devel

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	C part of async-process library
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	cxxxr
GH_PROJECT=	async-process
GH_TAGNAME=	51cc1f5
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/libasyncprocess.so

# FIXME: How can we rework it?
do-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/libasyncprocess.so \
		${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
