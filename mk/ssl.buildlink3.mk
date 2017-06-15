# $NetBSD$
#
# This Makefile fragment is meant to be included by packages that
# require a libcrypto/libssl implementation.
#
# User-settable variables:
#
# SSL_DEFAULT
#	The default SSL implementation to use.
#
#	Possible values: openssl libressl
#
# Package-settable variables:
#
# SSL_ACCEPTED
#	The list of SSL implementations that can be used by the package.
#
#	Possible values: (see SSL_DEFAULT)
#
# Keywords: 

SSL_BUILDLINK3_MK:=	${SSL_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(SSL_BUILDLINK3_MK:M+)
SSL_DEFAULT?=	openssl
SSL_ACCEPTED?=	${_SSL_PKGS}

# This is an exhaustive list of all of the SSL implementations that may be
# used with ssl.buildlink3.mk, in order of precedence.
#
_SSL_PKGS?=	openssl libressl

_SSL_DEFAULT=	${SSL_DEFAULT}
_SSL_ACCEPTED=	${SSL_ACCEPTED}

_SSL_TYPE?=	${_SSL_DEFAULT}

.  if !empty(_SSL_ACCEPTED:M${_SSL_TYPE})
SSL_TYPE=	${_SSL_TYPE}
.  else
SSL_TYPE=	none
.  endif
BUILDLINK_PREFIX.ssl=	${BUILDLINK_PREFIX.${SSL_TYPE}}

BUILD_DEFS+=		SSL_DEFAULT
BUILD_DEFS_EFFECTS+=	SSL_TYPE

.endif	# SSL_BUILDLINK3_MK

.if ${SSL_TYPE} == "none"
PKG_FAIL_REASON+=	"${_SSL_TYPE} is not an acceptable SSL type for ${PKGNAME}."
.elif ${SSL_TYPE} == "libressl"
.  include "../../security/libressl/buildlink3.mk"
.elif ${SSL_TYPE} == "openssl"
.  include "../../security/openssl/buildlink3.mk"
.endif
