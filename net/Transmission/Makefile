# $NetBSD: Makefile,v 1.82 2013/02/06 23:23:09 jperkin Exp $

PKGNAME=		${DISTNAME:C:t:T:}
PKGREVISION=		1

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--without-gtk

.include "../../net/Transmission/Makefile.common"

.include "../../mk/bsd.pkg.mk"
