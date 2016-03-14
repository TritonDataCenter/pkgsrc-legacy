# $NetBSD: Makefile,v 1.16 2015/10/07 11:26:22 fhajny Exp $
PKGNAME=	tesseract-data-3.04.00
DISTNAME=	tessdata-${PKGVERSION_NOREV}
PKGREVISION=	1
CATEGORIES=	graphics

DISTFILES=	${DISTNAME}.tar.gz


MASTER_SITES=   ${MASTER_SITE_GITHUB:=tesseract-ocr/}
GITHUB_PROJECT=tessdata
GITHUB_TAG=     ${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tesseract-ocr/tessdata
COMMENT=	Commercial quality open source OCR engine
LICENSE=	apache-2.0

WRKSRC=			${WRKDIR}/tessdata-${PKGVERSION_NOREV}
NO_BUILD=       yes

do-install:
	mkdir -p  ${DESTDIR}/opt/local/share/tessdata/
	mv ${WRKDIR}/${DISTNAME}/* ${DESTDIR}/opt/local/share/tessdata/

.include "../../mk/bsd.pkg.mk"
