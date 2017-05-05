# $NetBSD$

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/-server/3/}
PKGREVISION=	1
COMMENT=		Free RADIUS server implementation


BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=    	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=    	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=    	--with-logdir=${VARBASE}/log/radiusd
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

# These files get created by the bootstrap process during make, but shouldn't
# be part of the package
CHECK_FILES_SKIP+= 	${PKG_SYSCONFBASEDIR}/raddb/certs/*.crt
CHECK_FILES_SKIP+= 	${PKG_SYSCONFBASEDIR}/raddb/certs/*.csr
CHECK_FILES_SKIP+= 	${PKG_SYSCONFBASEDIR}/raddb/certs/*.der
CHECK_FILES_SKIP+= 	${PKG_SYSCONFBASEDIR}/raddb/certs/*.key
CHECK_FILES_SKIP+= 	${PKG_SYSCONFBASEDIR}/raddb/certs/*.pem
CHECK_FILES_SKIP+= 	${PKG_SYSCONFBASEDIR}/raddb/certs/index.*
CHECK_FILES_SKIP+= 	${PKG_SYSCONFBASEDIR}/raddb/certs/serial.*
CHECK_FILES_SKIP+= 	${PKG_SYSCONFBASEDIR}/raddb/certs/dh
CHECK_FILES_SKIP+= 	${PKG_SYSCONFBASEDIR}/raddb/certs/random

PKG_SYSCONFSUBDIR=      raddb

post-install:
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/*.crt
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/*.csr
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/*.der
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/*.key
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/*.pem
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/*.p12
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/index.*
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/serial.*
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/dh
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/random
	touch  ${DESTDIR}${PKG_SYSCONFBASEDIR}/raddb/certs/index.txt


# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
