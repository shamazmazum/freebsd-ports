# All *-sbcl ports and any other port with SBCL fasl files must get a
# PORTREVISION bump when lang/sbcl is updated.  The compiled fasl files are
# pinned to exact versions of everything used to build them.

PORTNAME=	sbcl
DISTVERSION=	2.3.3
DISTVERSIONSUFFIX=	-source
PORTEPOCH=	1
CATEGORIES=	lang lisp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Common Lisp development system derived from the CMU CL system
WWW=		http://sbcl.sourceforge.net/

LICENSE=	BSD2CLAUSE PD
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	cl-asdf>=0:devel/cl-asdf

USES=		gmake makeinfo tar:bzip2

SUB_FILES=	pkg-message sbclrc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

# All options explained into file: ${WRKSRC}/base-target-features.lisp-expr
OPTIONS_DEFINE=		DOCS LINKABLE_RUNTIME QSHOW SAFEPOINT THREADS UNICODE \
			XREF ZSTD SIMD
OPTIONS_DEFAULT=	SBCL THREADS UNICODE

OPTIONS_SINGLE=			BOOTSTRAP
OPTIONS_SINGLE_BOOTSTRAP=	ABCL CCL CMUCL CLISP
OPTIONS_EXCLUDE=		ABCL CMUCL

ABCL_DESC=		Armed Bear Common Lisp
BOOTSTRAP_DESC=		Supported languages of the build host
CCL_DESC=		Clozure Common Lisp
CMUCL_DESC=		Carnegie Mellon University Common Lisp
CLISP_DESC=		GNU CLISP
LINKABLE_RUNTIME_DESC=	Enable SB-LINKABLE-RUNTIME feature (experimental)
QSHOW_DESC=		C runtime with low-level debugging output
SAFEPOINT_DESC=		Using safepoints instead of signals
XREF_DESC=		XREF data for SBCL internals
SIMD_DESC=		Enable SB-SIMD (requires CPUs supporting AVX2)

ABCL_BUILD_DEPENDS=	abcl:lang/abcl
ABCL_VARS=		XC_HOST="abcl"

CCL_BUILD_DEPENDS=	ccl:lang/ccl
CCL_VARS=		XC_HOST="ccl --no-init --batch --quiet"

CMUCL_BUILD_DEPENDS=	lisp:lang/cmucl
CMUCL_VARS=		XC_HOST="lisp -nositeinit -noinit -batch -quiet"

CLISP_BUILD_DEPENDS=	clisp:lang/clisp
CLISP_VARS=		XC_HOST="clisp -ansi -on-error abort -norc"

DOCS_VARS=	INFO="asdf sbcl"

LINKABLE_RUNTIME_VARS=		MAKE_SH_ARGS+="--with-sb-linkable-runtime"
LINKABLE_RUNTIME_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-linkable-runtime"

QSHOW_VARS=	MAKE_SH_ARGS+="--with-sb-qshow"
QSHOW_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-qshow"

SAFEPOINT_IMPLIES=	THREADS
SAFEPOINT_VARS=		MAKE_SH_ARGS+="--with-sb-safepoint --with-sb-thruption --with-sb-wtimer"
SAFEPOINT_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-safepoint --without-sb-thruption --without-sb-wtimer"

THREADS_VARS=		MAKE_SH_ARGS+="--with-sb-thread"
THREADS_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-thread"

UNICODE_VARS=		MAKE_SH_ARGS+="--with-sb-unicode"
UNICODE_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-unicode"

XREF_VARS=	MAKE_SH_ARGS+="--with-sb-xref-for-internals"
XREF_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-xref-for-internals"

ZSTD_VARS=	MAKE_SH_ARGS+="--with-sb-core-compression"
ZSTD_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-core-compression"
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

SIMD_VARS=	MAKE_SH_ARGS+="--with-sb-simd"
SIMD_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-simd"

MAKE_SH_ARGS?=	--prefix="${PREFIX}" --xc-host="${XC_HOST}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLINKABLE_RUNTIME}
PLIST_SUB+=	LINKABLE_RUNTIME=""
.else
PLIST_SUB+=	LINKABLE_RUNTIME="@comment "
.endif

.if ${PORT_OPTIONS:MSIMD}
PLIST_SUB+=	SIMD=""
.else
PLIST_SUB+=	SIMD="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/src/code/toplevel.lisp \
		${WRKSRC}/doc/${PORTNAME}.1 \
		${WRKSRC}/doc/manual/start-stop.texinfo

do-build:
	(cd ${WRKSRC} && ${SH} make.sh ${MAKE_SH_ARGS})

post-build-DOCS-on:
	${DO_MAKE_BUILD} -C ${WRKSRC}/doc/manual info html

do-install:
	(cd ${WRKSRC} && ${SETENV} \
	INSTALL_ROOT="${STAGEDIR}${PREFIX}" \
	MAN_DIR="${STAGEDIR}${MANPREFIX}/man" \
	INFO_DIR="${STAGEDIR}${PREFIX}/${INFO_PATH}" \
	DOC_DIR="${STAGEDIR}${DOCSDIR}" \
	SBCL_HOME="" \
	${SH} install.sh)
	${INSTALL_DATA} ${WRKDIR}/sbclrc ${STAGEDIR}${PREFIX}/etc/sbclrc.sample

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	${RM} ${STAGEDIR}${PREFIX}/${INFO_PATH}/dir # don't requered with INFO=
	${RM} -r ${STAGEDIR}${DOCSDIR}/html # empty directory created by install.sh

check regression-test test: build
	(cd ${WRKSRC}/tests && ${SH} run-tests.sh)

.include <bsd.port.mk>
