# $NetBSD: Makefile,v 1.22 2014/02/12 23:18:31 tron Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-gssapi-heimdal/}
PKGREVISION=	2
COMMENT=	Cyrus SASL GSSAPI authentication plugin (Heimdal)
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1 mit-krb5 cy2-gssapi-mit

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE:Q}
CONFIGURE_ARGS+=	--with-gss_impl=heimdal

BUILD_DIRS=	plugins
BUILD_TARGET=	libgssapiv2.la
KRB5_DEFAULT=	heimdal
KRB5_ACCEPTED=	heimdal

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && \
	${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libgssapiv2.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
