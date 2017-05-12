# $NetBSD$

.include "../../net/freeradius3/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/3-unixodbc/}
PKGREVISION=	1
COMMENT=		FreeRADIUS UNIXODBC support
CATEGORIES=		databases

CONFIGURE_ARGS+=    --with-rlm_sql_unixodbc

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_unixodbc.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/unixodbc/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
