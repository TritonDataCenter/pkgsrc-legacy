# $NetBSD: Makefile,v 1.27 2014/05/05 00:48:08 ryoon Exp $

DISTNAME=	wxMaxima-12.09.0
PKGREVISION=	11
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxmaxima/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://wxmaxima.sourceforge.net/wiki/index.php/Main_Page
COMMENT=	Graphical UI for maxima
LICENSE=	gnu-gpl-v2

DEPENDS+=	maxima>=5.15.0:../../math/maxima
DEPENDS+=	wxGTK28>=2.8.0:../../x11/wxGTK28
DEPENDS+=	libxml2>=2.7.3:../../textproc/libxml2
DEPENDS+=	gnuplot>=4.2.3:../../graphics/gnuplot

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
