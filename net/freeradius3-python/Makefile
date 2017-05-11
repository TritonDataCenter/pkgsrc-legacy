# $NetBSD$

.include "../../net/freeradius3/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/3-python/}
PKGREVISION=	1
COMMENT=		Free RADIUS rlm_python module
CATEGORIES=		net python

CONFIGURE_ARGS+=    --with-rlm_python

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_python.so ${DESTDIR}${PREFIX}/lib

.include "../../lang/python/application.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
