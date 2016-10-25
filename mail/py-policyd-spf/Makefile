# $NetBSD$

VERSION=	1.3.2
DISTNAME=	pypolicyd-spf-${VERSION}
PKGNAME=	${PYPKGPREFIX}-policyd-spf-${VERSION}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypolicyd-spf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pypolicyd-spf
COMMENT=	Python based policy daemon for Postfix SPF checking
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-spf>=0:../py-spf
DEPENDS+=	${PYPKGPREFIX}-ipaddress>0:../../net/py-ipaddress
DEPENDS+=	${PYPKGPREFIX}-authres>0:../py-authres

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-ipaddress

TXTDOCS=	README README.per_user_whitelisting \
		policyd-spf.conf.commented


post-install:
	mkdir -p ${DESTDIR}/${DOCDIR}
	mkdir -p ${DESTDIR}${PREFIX}/${PKGMANDIR}/man{1,5}
.for h in ${TXTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${h} ${DESTDIR}${DOCDIR}/
.endfor
	${INSTALL_MAN} ${WRKSRC}/policyd-spf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/policyd-spf.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/policyd-spf.peruser.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../lang/python/distutils.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
