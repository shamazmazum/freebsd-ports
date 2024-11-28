PORTNAME=	obj2voxel
PORTVERSION=	20220607
CATEGORIES=	misc

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Wavefront OBJ to voxel converter
WWW=		https://github.com/mariogeiger/obj2voxel

LICENSE=        UNKNOWN
LICENSE_NAME=   unknown
LICENSE_TEXT=   Unspecified license, I dunno lol
LICENSE_PERMS=  dist-mirror pkg-mirror auto-accept

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mariogeiger
GH_TAGNAME=	afe3c06

CARGO_FEATURES+=      --no-default-features

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
