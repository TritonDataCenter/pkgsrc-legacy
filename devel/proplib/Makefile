# $NetBSD: Makefile,v 1.2 2015/06/28 14:53:16 kirussel Exp $

DISTNAME=	proplib-0.6.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=xtraeme/}
GITHUB_PROJECT=	portableproplib
GITHUB_TAG=	0.6.4

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/xtraeme/portableproplib/
COMMENT=	Portable Property container object library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf pkg-config

PKGCONFIG_OVERRIDE+=	proplib.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

BUILDLINK_ABI_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
