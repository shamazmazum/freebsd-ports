PORTNAME=	data
PORTVERSION=	1.0
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://files3.bungie.org/trilogy/
PKGNAMEPREFIX=	alephone-
DISTFILES=	# empty by default
DIST_SUBDIR=	alephone

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Released Marathon data files for the Aleph One port
WWW=		http://source.bungie.org/

# Converted from NO_CDROM
LICENSE=	alephone-data
LICENSE_NAME=	alephone-data
LICENSE_TEXT=	Bungie/Microsoft do not allow charging for Marathon data files
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	alephone:games/alephone

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

USES=		zip

DATADIR=	${PREFIX}/share/AlephOne

OPTIONS_MULTI=	AO
OPTIONS_MULTI_AO=	MARATHON DURANDAL INFINITY
OPTIONS_DEFAULT=	MARATHON DURANDAL INFINITY
OPTIONS_SUB=	yes

AO_DESC=		Data package selection

MARATHON_DESC=		Install Marathon data
MARATHON_DISTFILES=	M1A1${EXTRACT_SUFX}

DURANDAL_DESC=		Install Marathon 2: Durandal data
DURANDAL_DISTFILES=	Marathon2${EXTRACT_SUFX}

INFINITY_DESC=		Install Marathon Infinity data
INFINITY_DISTFILES=	MarathonInfinity${EXTRACT_SUFX}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

do-install-MARATHON-on:
	@cd ${WRKSRC}/M1A1 && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/marathon

do-install-DURANDAL-on:
	@cd "${WRKSRC}/Marathon 2" && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/durandal

do-install-INFINITY-on:
	@cd "${WRKSRC}/Marathon Infinity" && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/infinity

.include <bsd.port.mk>
