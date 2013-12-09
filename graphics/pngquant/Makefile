# $NetBSD$

DISTNAME=	pngquant-2.0.1-src
PKGNAME=	pngquant-2.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://pngquant.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	i@timothyklim.com
HOMEPAGE=	http://pngquant.org/
COMMENT=	Command-line utility and a library for converting 24/32-bit PNG images to paletted (8-bit) PNGs
LICENSE=	unlicense

USE_LANGUAGES+=	c
USE_TOOLS+=	gmake grep egrep

DEPENDS+=	getopt>=1.0.0:../../misc/getopt

WRKSRC=	${WRKDIR}/pngquant-2.0.1

CFLAGS+=        -DNDEBUG -O3 -fstrict-aliasing -ffast-math -funroll-loops -fomit-frame-pointer -ffinite-math-only

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.2
BUILDLINK_API_DEPENDS.png+=     png>=1.2.9nb2

INSTALLATION_DIRS=              bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"