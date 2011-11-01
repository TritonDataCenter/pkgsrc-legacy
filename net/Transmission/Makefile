# $NetBSD: Makefile,v 1.76 2011/11/01 06:11:56 sbd Exp $
#
DISTNAME=		transmission-2.42
PKGNAME=		Transmission-2.42
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://download.m0k.org/transmission/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.transmissionbt.com/
COMMENT=		Free, lightweight BitTorrent client

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt
EXTRACT_USING=		bsdtar

LICENSE=		gnu-gpl-v2 AND mit

GNU_CONFIGURE=		yes
LDFLAGS+=		${BUILDLINK_LDADD.getopt} ${BUILDLINK_LDADD.gettext}

.include "../../mk/bsd.prefs.mk"
.if !empty(OPSYS:M*BSD) || !empty(OPSYS:MDragonFly)
CPPFLAGS+=		-DBSD
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.common

.include "options.mk"

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.10
.include "../../devel/libevent/buildlink3.mk"
ALL_ENV+=		"OPENSSL_CFLAGS=-I${SSLBASE}/include"
ALL_ENV+=		"OPENSSL_LIBS=-L${SSLBASE}/lib -lcrypto -lssl"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
