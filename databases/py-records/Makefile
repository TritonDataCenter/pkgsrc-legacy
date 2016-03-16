# $NetBSD$

DISTNAME=	records-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=r/records/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://pypi.python.org/pypi/records/
COMMENT=	SQL for Humans
LICENSE=	isc

WRKSRC=		${WRKDIR}/records-0.4.3
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-tablib>=0.10.0:../../textproc/py-tablib
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0.9:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
