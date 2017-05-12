# $NetBSD$

.include "../../net/freeradius3/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/3-krb5/}
PKGREVISION=	1
COMMENT=		Free RADIUS rlm_krb5 module
CATEGORIES=		security

CONFIGURE_ARGS+=    --with-rlm_krb5

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_krb5.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/krb5.buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
