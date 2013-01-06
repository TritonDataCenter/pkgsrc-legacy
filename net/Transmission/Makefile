# $NetBSD: Makefile,v 1.81 2013/01/06 01:12:33 wiz Exp $

PKGNAME=		${DISTNAME:C:t:T:}

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--without-gtk

.include "../../net/Transmission/Makefile.common"

.include "../../mk/bsd.pkg.mk"
