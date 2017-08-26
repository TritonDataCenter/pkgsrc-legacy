# $NetBSD$

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-ldap/}
PKGREVISION=	1
COMMENT=		Free RADIUS rlm_ldap module
CATEGORIES=		databases

CONFIGURE_ARGS+=    --with-rlm_ldap

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_ldap.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/openldap-client/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
