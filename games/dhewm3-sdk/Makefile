PORTNAME=	dhewm3-sdk
PORTVERSION=	20260818 # Date of port modification, actually
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Different mods for dhewm3
WWW=		https://github.com/dhewm/dhewm3-sdk \
		https://dhewm3.org/mods.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	dhewm3>0:games/dhewm3

FLAVORS=	rivensin bloodmod bloodmod_roe d3le eoc desolated hardcorps
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake

rivensin_PKGNAMESUFFIX=	-rivensin
bloodmod_PKGNAMESUFFIX=	-bloodmod
bloodmod_roe_PKGNAMESUFFIX=	-bloodmod_roe
d3le_PKGNAMESUFFIX=	-d3le
eoc_PKGNAMESUFFIX=	-eoc
desolated_PKGNAMESUFFIX=	-desolated
hardcorps_PKGNAMESUFFIX=	-hardcorps

.if ${FLAVOR:U} == rivensin
GITTAG=		a4dfc7c
.elif ${FLAVOR:U} == bloodmod
GITTAG=		67bc24c
.elif ${FLAVOR:U} == bloodmod_roe
GITTAG=		67bc24c
.elif ${FLAVOR:U} == d3le
GITTAG=		b6a499a
.elif ${FLAVOR:U} == eoc
GITTAG=		d97448a
.elif ${FLAVOR:U} == desolated
GITTAG=		e550181
.elif ${FLAVOR:U} == hardcorps
GITTAG=		b767e8c
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	dhewm
GH_PROJECT=	dhewm3-sdk
GH_TAGNAME=	${GITTAG}

SUB_FILES=	pkg-message
PLIST_FILES=	lib/dhewm3/${FLAVOR}.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/dhewm3
	${INSTALL_LIB} ${BUILD_WRKSRC}/${FLAVOR}.so ${STAGEDIR}${PREFIX}/lib/dhewm3

.include <bsd.port.mk>
