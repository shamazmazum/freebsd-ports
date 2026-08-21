PORTNAME=	glsl-mode.el
PORTVERSION=	20260603
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Emacs major mode for GLSL
WWW=		https://github.com/jimhourihan/glsl-mode

LICENSE=	GPLv3

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
