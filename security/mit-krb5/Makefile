# $NetBSD: Makefile,v 1.92 2016/07/09 06:38:55 wiz Exp $

DISTNAME=	krb5-1.14.1
PKGNAME=	mit-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://web.mit.edu/kerberos/dist/krb5/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.gz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

#PATCH_SITES=	http://web.mit.edu/kerberos/advisories/
#PATCHFILES=	2014-001-patch.txt

MAINTAINER=	tez@NetBSD.org
HOMEPAGE=	http://web.mit.edu/kerberos/
COMMENT=	MIT Kerberos 5 authentication system

MAKE_JOBS_SAFE=		no

CONFIGURE_DIRS=	src
BUILD_TARGET=	generate-files-mac all

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_MULTIARCH=		bin lib
USE_TOOLS+=		autoconf gzip m4 perl yacc msgfmt
GNU_CONFIGURE=		yes

# The actual KDC databases are stored in ${MIT_KRB5_STATEDIR}/krb5kdc.
MIT_KRB5_STATEDIR?=	${VARBASE}
FILES_SUBST+=		MIT_KRB5_STATEDIR=${MIT_KRB5_STATEDIR}

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${MIT_KRB5_STATEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-dns-for-realm
CONFIGURE_ARGS+=	--enable-kdc-replay-cache
CONFIGURE_ARGS+=	--disable-thread-support
CONFIGURE_ARGS+=	--without-system-verto
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ARGS+=	--enable-pkgsrc-libtool
CONFIGURE_ARGS+=	--without-system-verto
CONFIGURE_ARGS+=	--disable-aesni
CONFIGURE_ENV+=		BUILDLINK_PREFIX_OPENSSL=${BUILDLINK_PREFIX.openssl:Q}
CONFIGURE_ENV+=		DEFKTNAME=FILE:${PKG_SYSCONFDIR}/krb5.keytab
MAKE_ENV+=		ROOT_USER=${ROOT_USER}
LIBS.SunOS=		-lrt

PATCH_ARGS=		-d ${WRKSRC}/src -p0
PATCH_DIST_ARGS=	-d ${WRKSRC} -p1

INFO_FILES=		YES

OWN_DIRS_PERMS=		${MIT_KRB5_STATEDIR}/krb5kdc			\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
RCD_SCRIPTS=		kadmind kdc

INSTALLATION_DIRS=	bin${BINARCHSUFFIX} include/gssapi include/gssrpc ${PKGINFODIR}	\
			${PKGMANDIR}/man1 ${PKGMANDIR}/man5		\
			${PKGMANDIR}/man8 sbin${BINARCHSUFFIX} share/examples/krb5	\
			share/et share/examples/rc.d share/gnats	\
			lib${LIBARCHSUFFIX}/krb5/plugins/kdb lib${LIBARCHSUFFIX}/krb5/plugins/preauth	\
			lib${LIBARCHSUFFIX}/krb5/plugins/tls include/krb5 include/kadm5 \
			lib${LIBARCHSUFFIX}/pkgconfig

pre-configure:
	@${ECHO} "=> Generating configure"
	cd ${WRKSRC}/src; autoconf -I ${WRKSRC}/src -f;

post-install:
	@${ECHO} "=> Installing info files";				\
	cd ${WRKSRC}/doc;						\
	for f in *.info *.info-[0-9]*; do				\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_MAN} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};	\
	done

BUILDLINK_API_DEPENDS.openssl+= openssl>=1.0.1
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
