# $NetBSD: options.mk,v 1.17 2011/10/28 13:09:06 tnn Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.Transmission
PKG_SUPPORTED_OPTIONS=	gtk qt
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
. include "../../graphics/hicolor-icon-theme/buildlink3.mk"
. include "../../sysutils/libnotify/buildlink3.mk"
. include "../../x11/gtk2/buildlink3.mk"
. include "../../sysutils/desktop-file-utils/desktopdb.mk"
CONFIGURE_ARGS+=	--with-gtk
PLIST_SRC+=		${PKGDIR}/PLIST.gtk
.else
CONFIGURE_ARGS+=	--without-gtk
pre-configure:
	touch ${WRKSRC}/po/Makefile
.endif

.if !empty(PKG_OPTIONS:Mqt)
.  if empty(PKG_OPTIONS:Mgtk)
PKG_FAIL_REASON=	"qt needs gtk option (for now)"
.  endif
USE_LANGUAGES+=		c c++
PLIST_SRC+=		${PKGDIR}/PLIST.qt
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}${PREFIX}
. include "../../x11/qt4-tools/buildlink3.mk"
. include "../../x11/qt4-qdbus/buildlink3.mk"
.PHONY:		build-qt-client
post-build:	build-qt-client
build-qt-client:
	cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake qtr.pro
	cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} make
.PHONY:		install-qt-client
post-install:	install-qt-client
install-qt-client:
	cd ${WRKSRC}/qt && ${SETENV} ${INSTALL_ENV} make install
.endif
