# $NetBSD$

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-freetds/}
PKGREVISION=	1
COMMENT=		FreeRADIUS FreeTDS support
CATEGORIES=		databases

CONFIGURE_ARGS+=    --with-rlm_sql_freetds

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_freetds.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/freetds/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
