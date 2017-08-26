# $NetBSD$

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-rest/}
PKGREVISION=	1
COMMENT=		Free RADIUS rlm_rest module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_rest

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_rest.so ${DESTDIR}${PREFIX}/lib


# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
