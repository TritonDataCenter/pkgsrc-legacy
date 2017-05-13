# $NetBSD$

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-perl/}
PKGREVISION=	1
COMMENT=		Free RADIUS rlm_perl module
CATEGORIES=		net perl

CONFIGURE_ARGS+=    --with-rlm_perl

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_perl.so ${DESTDIR}${PREFIX}/lib

.include "../../lang/perl5/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
