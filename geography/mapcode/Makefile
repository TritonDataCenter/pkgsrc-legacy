# $NetBSD$

VERSION=	2.2.1
GITHUB_PROJECT=	mapcode-cpp
DISTNAME=	v${VERSION}
PKGNAME=	mapcode-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=mapcode-foundation/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://www.mapcode.com/
COMMENT=	Utility to convert mapcodes to lon:lat and back
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/mapcode-cpp-2.2.1
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=bin lib include

do-build:
	cd ${WRKSRC}/mapcodelib && ${SETENV} ${MAKE_ENV} ${CC} -fPIC -shared mapcoder.c -o libmapcode.so
	cd ${WRKSRC}/utility && ${SETENV} ${MAKE_ENV} ${CXX} mapcode.cpp -o mapcode

do-install:
	${INSTALL_DATA} ${WRKSRC}/mapcodelib/mapcoder.h ${DESTDIR}/${PREFIX}/include/mapcode.h
	${INSTALL_LIB} ${WRKSRC}/mapcodelib/libmapcode.so ${DESTDIR}/${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/utility/mapcode ${DESTDIR}/${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
