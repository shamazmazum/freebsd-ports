PORTNAME=	blackshades
PORTVERSION=	20200511
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Psychic Bodyguard FPS - protect the VIP
WWW=		http://home.gna.org/blackshadeselite/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:audio/libvorbis

USES=		compiler:c++11-lang gl openal:al,alut sdl cmake
USE_SDL=	sdl2
USE_GL=		gl glu

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	blackshades
GH_TAGNAME=	9b294f6

post-patch:
	@${REINPLACE_CMD} -e '/InitGL/ s|.*|chdir("${DATADIR}"); &|' ${WRKSRC}/Source/Main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/Source/blackshades ${STAGEDIR}${PREFIX}/bin/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} Data ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
