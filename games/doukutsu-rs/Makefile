PORTNAME=	doukutsu-rs
DISTVERSION=	1.0.0
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Reimplementation of Cave Story game
WWW=		https://doukutsu.rs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cargo sdl
USE_GITHUB=	yes
USE_SDL=	sdl2

SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/game/filesystem_container.rs

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
