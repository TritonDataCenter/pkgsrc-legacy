# $NetBSD: Makefile,v 1.79 2012/07/12 18:29:46 wiz Exp $

PKGNAME=		${DISTNAME:C:t:T:}

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--without-gtk

.include "../../net/Transmission/Makefile.common"

.include "../../mk/bsd.pkg.mk"
