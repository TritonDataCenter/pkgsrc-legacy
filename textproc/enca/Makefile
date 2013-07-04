# $NetBSD: Makefile,v 1.8 2015/04/11 02:26:02 mef Exp $

DISTNAME=		enca-1.15
CATEGORIES=		converters
MASTER_SITES=		http://dl.cihar.com/enca/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/nijel/enca
COMMENT=		Extremely Naive Charset Analyser
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_MULTIARCH=		lib
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/enca.pc.in

# XXX: multiarch
SUBST_CLASSES+=		lns
SUBST_STAGE.lns=	pre-build
SUBST_FILES.lns=	Makefile src/Makefile
SUBST_SED.lns=		-e '/^LN_S =/s/-s/-sf/'

.include "../../mk/bsd.pkg.mk"
