# $NetBSD$

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-iodbc/}
PKGREVISION=	1
COMMENT=		FreeRADIUS iODBC support
CATEGORIES=		databases

CONFIGURE_ARGS+=    --with-rlm_sql_iodbc

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_iodbc.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/iodbc/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
