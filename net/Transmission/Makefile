# $NetBSD: Makefile,v 1.80 2012/12/16 01:52:27 obache Exp $

PKGNAME=		${DISTNAME:C:t:T:}
PKGREVISION=		1

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--without-gtk

.include "../../net/Transmission/Makefile.common"

.include "../../mk/bsd.pkg.mk"
