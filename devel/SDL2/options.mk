# $NetBSD: options.mk,v 1.3 2015/02/09 08:27:07 snj Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL2
PKG_SUPPORTED_OPTIONS=	alsa arts dbus esound nas opengl oss pulseaudio x11
PKG_SUGGESTED_OPTIONS+=	oss opengl

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=	x11
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnas)
.include "../../audio/nas/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.  if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.  endif
.else
CONFIGURE_ARGS+=	--disable-video-opengl
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-video-x11 --disable-x11-shared
.endif
