PORTNAME=	adblock-rust-server
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	net

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Ads filtering server with support of Adblock rules
WWW=		https://crates.io/crates/adblock-rust-server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	dudik

#CARGO_INSTALL_PATH=	${PORTNAME}
#CARGO_FEATURES+=	--no-default-features
#CARGO_CARGOTOML=	${WRKSRC}/Cargo.toml
#CARGO_CARGOLOCK=	${WRKSRC}/Cargo.lock

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
