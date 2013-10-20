# $NetBSD: Makefile,v 1.4 2013/05/09 07:40:19 adam Exp $
#

DISTNAME=	minidlna-1.1.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minidlna/1.1.0/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minidlna.sourceforge.net/
COMMENT=	DLNA server
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=			pkg-config
USE_LANGUAGES=	c c++

LDFLAGS+=					-lsendfile
LDFLAGS.SunOS+=		-lsocket -lnsl

EGDIR=			${PREFIX}/share/examples/minidlna
CONF_FILES=	${EGDIR}/minidlna.conf \
		${PKG_SYSCONFDIR}/minidlna.conf
INSTALLATION_DIRS=	sbin share/examples/minidlna

RCD_SCRIPTS=	minidlna

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minidlnad ${DESTDIR}${PREFIX}/sbin/minidlna
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf ${DESTDIR}${EGDIR}

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
