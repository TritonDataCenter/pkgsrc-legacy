# $NetBSD$

.include "../../net/freeradius3/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/3-mysql/}
PKGREVISION=	1
COMMENT=		FreeRADIUS MySQL support
CATEGORIES=		databases

CONFIGURE_ARGS+=    --with-rlm_sql_mysql

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_mysql.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/mysql.buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
