# $NetBSD$

.include "../../net/freeradius3/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/3-sqlite3/}
PKGREVISION=	1
COMMENT=		FreeRADIUS SQLite support
CATEGORIES=		databases

CONFIGURE_ARGS+=    --with-rlm_sql_iodbc

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_sqlite.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/sqlite3/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
