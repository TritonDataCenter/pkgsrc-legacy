# $NetBSD: Makefile,v 1.78 2012/01/16 22:15:00 abs Exp $

PKGNAME=		${DISTNAME:C:t:T:}
PKGREVISION=		3

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--without-gtk

.include "../../net/Transmission/Makefile.common"

.include "../../mk/bsd.pkg.mk"
