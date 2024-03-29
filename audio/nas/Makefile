PORTNAME=	nas
PORTVERSION=	1.9.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}%20%28stable%29
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Network Audio System
WWW=		https://radscan.com/nas.html

USES=		imake perl5 shebangfix xorg
SHEBANG_FILES=	clients/audio/auscope/auscope
USE_PERL5=	run
USE_CSTD=	gnu89
USE_XORG=	x11 xext xt xau sm ice xpm xmu xaw
USE_LDCONFIG=	yes
MAKE_ENV+=	COMPRESS_CMD="${COMPRESS_CMD:S/c//}"
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	nas.pc

.include <bsd.port.pre.mk>

post-configure:
# Work around shortcomings of the Imake.rules et. al:
	${REINPLACE_CMD} -e 's:-fPIC:${FPIC} -DPIC:g' \
	    -e 's,-c \$$(CCOPTIONS),-c $$(CFLAGS),' \
	    -e 's,\(\$$(AR) \$$@ \$$\)(OBJS),\1(OBJS:S|^|unshared/|),' \
		${WRKSRC}/lib/audio/Makefile

.if ${ARCH} == "sparc64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudio.so.2
	${INSTALL_DATA} ${WRKDIR}/nas.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
