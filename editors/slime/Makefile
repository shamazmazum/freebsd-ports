PORTNAME=	slime
DISTVERSIONPREFIX=	v
DISTVERSION=	2.32
PORTREVISION=	1
CATEGORIES=	editors elisp

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Superior Lisp Interaction Mode for Emacs
WWW=		https://common-lisp.net/project/slime/

LICENSE=	PD

USES=		emacs

USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

SLIME_LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/slime

NO_BUILD=	yes
PORTDOCS=	CONTRIBUTING.md NEWS PROBLEMS README.md
SUB_FILES=	pkg-message
SUB_LIST=	SLIME_LISPDIR="${SLIME_LISPDIR}"

do-install:
	@${MKDIR} ${STAGEDIR}${SLIME_LISPDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${SLIME_LISPDIR} \
		"! ( -name CONTRIBUTING.md -o -name NEWS -o -name PROBLEMS \
		-o -name README.md -o -name Makefile -o -name doc \
		-o -path \./doc/* )")
	(cd ${STAGEDIR}${SLIME_LISPDIR} && ${RM} -rf .github .gitref)

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
