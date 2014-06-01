# $NetBSD: Makefile,v 1.3 2014/06/01 16:35:31 wiz Exp $
#

DISTNAME=	Symbola702
PKGNAME=	${DISTNAME:S/Symbola/Symbola-ttf-/}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://users.teilar.gr/~g1951d/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.teilar.gr/~g1951d/
COMMENT=	Unicode font for symbols
#LICENSE=	In lieu of a licence: Fonts in this site are offered free for any use; they may be opened, edited, modified, regenerated, posted, packaged and redistributed.

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR} share/doc/Symbola-ttf

do-build:
do-install:
	${INSTALL_DATA} ${WRKSRC}/Symbola.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/Symbola.pdf ${DESTDIR}${PREFIX}/share/doc/Symbola-ttf

.include "../../mk/bsd.pkg.mk"
