# $NetBSD: Makefile,v 1.2 2012/10/03 18:28:16 asau Exp $
#

DISTNAME=	Symbola702
PKGNAME=	${DISTNAME:S/Symbola/Symbola-ttf-/}
CATEGORIES=	fonts
MASTER_SITES=	http://users.teilar.gr/~g1951d/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.teilar.gr/~g1951d/
COMMENT=	Unicode font for symbols
#LICENSE=	In lieu of a licence: Fonts in this site are offered free for any use; they may be opened, edited, modified, regenerated, posted, packaged and redistributed.

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR} share/doc/Symbola-ttf

do-build:
do-install:
	${INSTALL_DATA} ${WRKSRC}/Symbola.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/Symbola.pdf ${DESTDIR}${PREFIX}/share/doc/Symbola-ttf

.include "../../mk/bsd.pkg.mk"
