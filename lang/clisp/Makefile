PORTNAME=	clisp
PORTVERSION=	2.49
PORTREVISION=	8
CATEGORIES=	lang lisp
MASTER_SITES=	SF

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	A Common Lisp implementation

LICENSE=	GPLv2
LICENSE_FILE= ${WRKSRC}/GNU-GPL

LIB_DEPENDS=	libsigsegv.so:devel/libsigsegv \
		libavcall.so:devel/libffcall

USES=		tar:bz2 iconv

USE_GCC=	yes
USE_LDCONFIG= yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --mandir="${MANPREFIX}/man" \
		--docdir="${DOCSDIR}" --with-libiconv=${ICONV_PREFIX}
CONFIGURE_TARGET= ${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+= --disable-mmap --without-readline
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+= -L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE= yes

MAN1= clisp.1 clisp-link.1

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/freebsd3\*/freebsd\*/' \
		${WRKSRC}/src/makemake.in

.include <bsd.port.mk>
