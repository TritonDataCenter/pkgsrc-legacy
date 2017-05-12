# $NetBSD$

.include "../../net/freeradius3/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/3-memcached/}
PKGREVISION=	1
COMMENT=		FreeRADIUS support for memcached 
CATEGORIES=		databases

CONFIGURE_ARGS+=    --with-rlm_cache_memcached

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_cache_memcached.so ${DESTDIR}${PREFIX}/lib

.include "../../devel/libmemcached/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
