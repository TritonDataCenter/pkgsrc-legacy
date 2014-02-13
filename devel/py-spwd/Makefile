# $NetBSD: Makefile,v 1.29 2014/01/25 10:30:04 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-spwd-${PY_DISTVERSION}
CATEGORIES=	devel misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/current/tut/node15.html
COMMENT=	Line editing support for Python

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/spwdmodule.c

MULTIARCH_DIRS.lib=	${PYLIB}/lib-dynload
USE_GCC_RUNTIME=	yes

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload${LIBARCHSUFFIX}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || ${TRUE}; \
	done)

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
