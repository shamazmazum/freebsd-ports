PORTNAME=	glsl-mode.el
PORTVERSION=	20260603
CATEGORIES=	lang

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Emacs major mode for GLSL
WWW=		https://github.com/jimhourihan/glsl-mode

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_TEXT=	License is unknown, honestly
LICENSE_PERMS=  dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	jimhourihan
GH_PROJECT=	glsl-mode
GH_TAGNAME=	515a2ba

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	README.md

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
