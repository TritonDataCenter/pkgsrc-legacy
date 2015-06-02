# $NetBSD$

DISTNAME=	nghttp2-0.7.12
CATEGORIES=	www
MASTER_SITES=	https://github.com/tatsuhiro-t/nghttp2/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nghttp2.org/
COMMENT=	nghttp2 is an implementation of HTTP/2 in C
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

#OPENSSL_CFLAGS+=	-I${BUILDLINK_PREFIX.openssl}/include
#OPENSSL_LIBS+=		-L${BUILDLINK_PREFIX.openssl}/lib \
			#-W,-lR${BUILDLINK_PREFIX.openssl}/lib
#MAKE_ENV+=		ZLIB_LIBS=${BUILDLINK_PREFIX.zlib}/lib
#CONFIGURE_ENV+=		OPENSSL_CFLAGS=${OPENSSL_CFLAGS:Q}
#CONFIGURE_ENV+=		OPENSSL_LIBS=${OPENSSL_LIBS:Q}

#CONFIGURE_ARGS+=	--enable-app
#CONFIGURE_ARGS+=	--enable-examples
#CONFIGURE_ARGS+=        --with-spdylay=${BUILDLINK_PREFIX.spdylay}
CONFIGURE_ARGS+=	--enable-boost=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ARGS+=        --with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=        --with-libxml2=${BUILDLINK_PREFIX.libxml2}

PKGCONFIG_OVERRIDE+=	lib/libnghttp2.pc.in
PKGCONFIG_OVERRIDE+=	src/libnghttp2_asio.pc.in

.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/libev/buildlink3.mk"
#.include "../../devel/libevent/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../www/spdylay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
