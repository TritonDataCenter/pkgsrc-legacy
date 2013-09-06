# $NetBSD: Makefile,v 1.0 2013/08/31 20:19:00 tm Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-sqlite3/}
PKGREVISION=		1
COMMENT=		SQLite version 3 backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gsqlite3"
CONFIGURE_ARGS+=	--with-sqlite3-lib=${BUILDLINK_PREFIX.sqlite3}/lib
CONFIGURE_ARGS+=	--with-sqlite3-includes=${BUILDLINK_PREFIX.sqlite3}/include

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
