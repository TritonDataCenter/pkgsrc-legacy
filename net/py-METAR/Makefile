# $NetBSD: Makefile,v 1.19 2011/11/01 12:09:29 obache Exp $
#

DISTNAME=	pymetar-0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	http://www.schwarzvogel.de/pkgs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.schwarzvogel.de/software-pymetar.shtml
COMMENT=	Downloads weather reports
LICENSE=	gnu-gpl-v2 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-extract:
	${MV} ${WRKSRC}/bin/pymetar ${WRKSRC}/bin/pymetar${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
