# $NetBSD: Makefile,v 1.24 2016/08/28 15:48:35 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-expat-${PY_DISTVERSION}
CATEGORIES=	textproc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Python interface to expat

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/pyexpat.c

USE_GCC_RUNTIME=	yes
USE_MULTIARCH=		lib
MULTIARCH_DIRS.lib=	${PYLIB}/lib-dynload

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PY_SETUP_SUBST+= EXPATPREFIX=${BUILDLINK_DIR}
PY_SETUP_SUBST+= EXPATRTPREFIX=${BUILDLINK_PREFIX.expat}
PY_SETUP_SUBST+= LIBARCHSUFFIX=${LIBARCHSUFFIX}

PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload${LIBARCHSUFFIX}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || ${TRUE}; \
	done)

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
