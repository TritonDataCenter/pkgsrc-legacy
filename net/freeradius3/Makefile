# $NetBSD$

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/-server/3/}
PKGREVISION=	1
COMMENT=		Free RADIUS server implementation


BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=    	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=    	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=    	--with-logdir=${VARBASE}/log/radiusd
CONFIGURE_ARGS+=    	--without-rlm_cache_memcached
CONFIGURE_ARGS+=	--without-rlm_eap_ikev2
CONFIGURE_ARGS+=	--without-rlm_eap_tnc
CONFIGURE_ARGS+=    	--without-rlm_krb5
CONFIGURE_ARGS+=    	--without-rlm_ldap
CONFIGURE_ARGS+=    	--without-rlm_perl
CONFIGURE_ARGS+=    	--without-rlm_python
CONFIGURE_ARGS+=    	--without-rlm_redis
CONFIGURE_ARGS+=    	--without-rlm_rediswho
CONFIGURE_ARGS+=    	--without-rlm_ruby
CONFIGURE_ARGS+=    	--without-rlm_sql_oracle
CONFIGURE_ARGS+=    	--without-rlm_sql_unixodbc
CONFIGURE_ARGS+=    	--without-rlm_sql_iodbc
CONFIGURE_ARGS+=    	--without-rlm_sql_mysql
CONFIGURE_ARGS+=    	--without-rlm_sql_postgresql
CONFIGURE_ARGS+=	--without-rlm_sql_sqlite
CONFIGURE_ARGS+=	--without-rlm_sql_freetds
CONFIGURE_ARGS+=    	--without-rlm_rest

RADIUS_GROUP?=		radiusd
RADIUS_USER?=		radiusd
PKG_GROUPS=		${RADIUS_GROUP}
PKG_USERS=		${RADIUS_USER}:${RADIUS_GROUP}

OWN_FILES_PERMS+=	${VARBASE}/log/radiusd \
			${RADIUS_USER} ${RADIUS_GROUP} 0750

PKG_SYSCONFSUBDIR=      raddb

FILES_SUBST+=		RADIUS_USER=${RADIUS_USER} RADIUS_GROUP=${RADIUS_GROUP}
MESSAGE_SUBST+=		BOOTSTRAP=${PKG_SYSCONFDIR:Q}/certs/bootstrap

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/*.a ${DESTDIR}${PREFIX}/lib/*.la



# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
