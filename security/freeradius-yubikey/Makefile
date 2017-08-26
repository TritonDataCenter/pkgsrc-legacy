# $NetBSD$

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-yubikey/}
PKGREVISION=	1
COMMENT=		Free RADIUS rlm_yubikey module
CATEGORIES=		security

CONFIGURE_ARGS+=    --with-rlm_yubikey

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_yubikey.so ${DESTDIR}${PREFIX}/lib

.include "../../security/libyubikey/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
