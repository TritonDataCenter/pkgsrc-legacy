# $NetBSD$

DISTNAME=	ChezScheme-9.4
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}
DIST_SUBDIR=	ChezScheme
GITHUB_TAG=     v${PKGVERSION_NOREV}
DISTFILES=      ${DEFAULT_DISTFILES}
DISTFILES+=     zlib-1.2.8.tar.gz
DISTFILES+=     nanopass-framework-scheme-1.9.tar.gz
DISTFILES+=     stex-1.2.1.tar.gz
SITES.zlib-1.2.8.tar.gz=			-${MASTER_SITE_GITHUB:=madler/zlib/archive/v1.2.8.tar.gz}
SITES.nanopass-framework-scheme-1.9.tar.gz=	-${MASTER_SITE_GITHUB:=nanopass/nanopass-framework-scheme/archive/v1.9.tar.gz}
SITES.stex-1.2.1.tar.gz=			-${MASTER_SITE_GITHUB:=dybvig/stex/archive/v1.2.1.tar.gz}

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://scheme.com/
COMMENT=	A powerful implementation of Scheme
LICENSE=	apache-2.0

ONLY_FOR_PLATFORM=	Linux-*-*
WRKSRC=		${WRKDIR}/ChezScheme-9.4
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--threads --installprefix=${DESTDIR}${PREFIX}

USE_TOOLS+=	gmake
BUILD_TARGET=	build

post-extract:
	cd ${WRKSRC} && \
        rmdir zlib && mv ../zlib-1.2.8 zlib && \
        rmdir stex && mv ../stex-1.2.1 stex && \
        rmdir nanopass && mv ../nanopass-framework-scheme-1.9 nanopass

.include "../../mk/bsd.pkg.mk"
