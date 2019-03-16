PORTNAME=	xonar-kmod
PORTVERSION=	1.0
CATEGORIES=	audio

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Audio driver for Asus Xonar Essence ST card

LICENSE=	BSD2CLAUSE

USES=		kmod

USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	xonar-dragonfly
GH_TAGNAME=	v1.0

PLIST_FILES=	/${KMODDIR}/snd_xonar.ko \
		man/man4/snd_xonar.4.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/snd_xonar.4 \
		${STAGEDIR}${MAN4PREFIX}/man/man4

.include <bsd.port.mk>
