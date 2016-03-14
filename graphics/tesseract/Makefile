# $NetBSD: Makefile,v 1.16 2015/10/07 11:26:22 fhajny Exp $
DISTNAME=	tesseract-3.04.01
PKGREVISION=	1
CATEGORIES=	graphics

DISTFILES=	${DISTNAME}.tar.gz


MASTER_SITES=   ${MASTER_SITE_GITHUB:=tesseract-ocr/}
GITHUB_PROJECT=tesseract
GITHUB_TAG=     ${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tesseract-ocr/tesseract
COMMENT=	Commercial quality open source OCR engine
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pax
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIBLEPT_HEADERSDIR=${BUILDLINK_PREFIX.leptonica}/include

WRKSRC=			${WRKDIR}/tesseract-${PKGVERSION_NOREV}

INSTALLATION_DIRS=	libexec share/doc/tesseract share/tesseract

LIBS.SunOS+=		-lsocket -lnsl

DEPENDS+=tesseract-data>=3.04.00:../tesseract-data

.include "../../graphics/leptonica/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
