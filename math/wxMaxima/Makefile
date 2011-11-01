# $NetBSD: Makefile,v 1.9 2011/11/01 06:02:03 sbd Exp $

DISTNAME=	wxMaxima-0.8.6
PKGREVISION=	5
CATEGORIES=	math
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=wxmaxima/)

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://wxmaxima.sourceforge.net/wiki/index.php/Main_Page
COMMENT=	Graphical UI for maxima
LICENSE=	gnu-gpl-v2

DEPENDS+=	maxima>=5.15.0:../../math/maxima
DEPENDS+=	wxGTK28>=2.8.0:../../x11/wxGTK28
DEPENDS+=	libxml2>=2.7.3:../../textproc/libxml2
DEPENDS+=	gnuplot>=4.2.3:../../graphics/gnuplot

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
