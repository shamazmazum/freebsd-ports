# $FreeBSD$

PORTNAME=	zmusic
DISTVERSION=	1.1.3
CATEGORIES=	audio

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Music library for GZDoom

LICENSE=	BSD3CLAUSE GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/licenses/bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/licenses/gplv3.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/licenses/lgplv3.txt

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libmpg123.so:audio/mpg123 \
		libfluidsynth.so:audio/fluidsynth

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	coelckers
GH_PROJECT=	ZMusic

.include <bsd.port.mk>
