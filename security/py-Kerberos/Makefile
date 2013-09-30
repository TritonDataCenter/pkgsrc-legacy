# $NetBSD: Makefile,v 1.1 2013/09/30 17:17:57 wiz Exp $

DISTNAME=	PyKerberos-1.1
PKGNAME=	${DISTNAME:S/Py/${PYPKGPREFIX}-/}
CATEGORIES=	security
MASTER_SITES=	# manually packaged from SVN and uploaded to nbftp

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://svn.calendarserver.org/repository/calendarserver/PyKerberos/tags/release/PyKerberos-1.1/README.txt
COMMENT=	Python Kerberos implementation
LICENSE=	apache-2.0

EGG_NAME=	kerberos-1.0

.include "../../lang/python/distutils.mk"
# only supports this Kerberos implementation
.include "../../security/mit-krb5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
