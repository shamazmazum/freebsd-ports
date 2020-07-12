# $FreeBSD$

PORTNAME=	voxcube
PORTVERSION=	20200712
CATEGORIES=	graphics

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Volume renderer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp

USES=		cmake compiler:c++17-lang gl sdl
USE_GL=		gl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_TAGNAME=	e65ff0c

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

CMAKE_ON=	SYSTEM_WIDE

.include <bsd.port.mk>
