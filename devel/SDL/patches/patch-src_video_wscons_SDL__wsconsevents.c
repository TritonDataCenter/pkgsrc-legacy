$NetBSD: patch-src_video_wscons_SDL__wsconsevents.c,v 1.6 2015/01/29 01:56:02 jmcneill Exp $

--- src/video/wscons/SDL_wsconsevents.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/wscons/SDL_wsconsevents.c
@@ -47,6 +47,13 @@ int WSCONS_InitKeyboard(_THIS)
     return -1;
   }
 
+#if defined(__NetBSD__)
+  if (private->kbdType == 0) {
+    /* wsmux with no keyboard attached, assumed USB */
+    private->kbdType = WSKBD_TYPE_USB;
+  }
+#endif
+
   if (tcgetattr(private->fd, &private->saved_tty) == -1) {
     WSCONS_ReportError("cannot get terminal attributes: %s", strerror(errno));
     return -1;
@@ -65,6 +72,7 @@ int WSCONS_InitKeyboard(_THIS)
     WSCONS_ReportError("cannot set terminal attributes: %s", strerror(errno));
     return -1;
   }
+
   if (ioctl(private->fd, KDSKBMODE, K_RAW) == -1) {
     WSCONS_ReportError("cannot set raw keyboard mode: %s", strerror(errno));
     return -1;
@@ -89,8 +97,57 @@ void WSCONS_ReleaseKeyboard(_THIS)
   }
 }
 
-static void updateMouse()
+int WSCONS_InitMouse(_THIS)
+{
+  if (private->mouseFd != -1) {
+#if defined(WSMOUSEIO_SETVERSION)
+    int version = WSMOUSE_EVENT_VERSION;
+    if (ioctl(private->mouseFd, WSMOUSEIO_SETVERSION, &version) == -1) {
+      WSCONS_ReportError("cannot set mouse API version: %s", strerror(errno));
+      return -1;
+    }
+#endif
+  }
+  return 0;
+}
+
+void WSCONS_ReleaseMouse(_THIS)
+{
+}
+
+#define NUMEVENTS 64
+
+static void updateMouse(_THIS)
 {
+  struct wscons_event evlist[NUMEVENTS];
+  struct wscons_event *ev = evlist;
+  int nev, i;
+  ssize_t len;
+
+  len = read(private->mouseFd, evlist, sizeof(evlist));
+  if (len == -1) {
+    WSCONS_ReportError("Failed to read wsmouse event: %s", strerror(errno));
+    return;
+  }
+
+  nev = len / sizeof(*ev);
+
+  for (i = 0; i < nev; i++, ev++) {
+    switch (ev->type) {
+    case WSCONS_EVENT_MOUSE_UP:
+      posted += SDL_PrivateMouseButton(SDL_RELEASED, ev->value+1, 0, 0);
+      break;
+    case WSCONS_EVENT_MOUSE_DOWN:
+      posted += SDL_PrivateMouseButton(SDL_PRESSED, ev->value+1, 0, 0);
+      break;
+    case WSCONS_EVENT_MOUSE_DELTA_X:
+      posted += SDL_PrivateMouseMotion(0, 1, ev->value, 0);
+      break;
+    case WSCONS_EVENT_MOUSE_DELTA_Y:
+      posted += SDL_PrivateMouseMotion(0, 1, 0, -ev->value);
+      break;
+    }
+  }
 }
 
 static SDLKey keymap[128];
@@ -120,19 +177,42 @@ static void updateKeyboard(_THIS)
     for (i = 0; i < n; i++) {
       unsigned char c = buf[i] & 0x7f;
       if (c == 224) // special key prefix -- what should we do with it?
-	continue;
+       continue;
       posted += SDL_PrivateKeyboard((buf[i] & 0x80) ? SDL_RELEASED : SDL_PRESSED,
-				    TranslateKey(c, &keysym));
+                                   TranslateKey(c, &keysym));
     }
   }
 }
 
 void WSCONS_PumpEvents(_THIS)
 {
+  static struct timeval zero;
+  int maxfd = 0;
+
+  if (private->fd > maxfd)
+    maxfd = private->fd;
+  if (private->mouseFd > maxfd)
+    maxfd = private->mouseFd;
+
   do {
+    fd_set fds;
+
     posted = 0;
-    updateMouse();
-    updateKeyboard(this);
+
+    FD_ZERO(&fds);
+    if (private->fd != -1)
+      FD_SET(private->fd, &fds);
+    if (private->mouseFd != -1)
+      FD_SET(private->mouseFd, &fds);
+
+    if (select(maxfd+1, &fds, NULL, NULL, &zero) > 0) {
+      if (private->mouseFd != -1 && FD_ISSET(private->mouseFd, &fds)) {
+        updateMouse(this);
+      }
+      if (private->fd != -1 && FD_ISSET(private->fd, &fds)) {
+        updateKeyboard(this);
+      }
+    }
   } while (posted);
 }
 
@@ -146,7 +226,72 @@ void WSCONS_InitOSKeymap(_THIS)
   }
 
   switch (private->kbdType) {
-#ifdef WSKBD_TYPE_ZAURUS
+  case WSKBD_TYPE_USB:
+    for (i=4; i <= 29; i++) {
+      keymap[i] = SDLK_a + (i-4);
+    }
+    for (i=30; i <= 38; i++) {
+      keymap[i] = SDLK_1 + (i-30);
+    }
+    keymap[39] = SDLK_0;
+    keymap[40] = SDLK_RETURN;
+    keymap[41] = SDLK_ESCAPE;
+    keymap[42] = SDLK_BACKSPACE;
+    keymap[43] = SDLK_TAB;
+    keymap[44] = SDLK_SPACE;
+    keymap[45] = SDLK_MINUS;
+    keymap[46] = SDLK_EQUALS;
+    keymap[47] = SDLK_LEFTBRACKET;
+    keymap[48] = SDLK_RIGHTBRACKET;
+    keymap[49] = SDLK_BACKSLASH;
+    keymap[50] = SDLK_BACKSLASH;
+    keymap[51] = SDLK_SEMICOLON;
+    keymap[52] = SDLK_QUOTE;
+    keymap[53] = SDLK_BACKQUOTE;
+    keymap[54] = SDLK_COMMA;
+    keymap[55] = SDLK_PERIOD;
+    keymap[56] = SDLK_SLASH;
+    keymap[57] = SDLK_CAPSLOCK;
+    for (i=58; i <= 69; i++) {
+      keymap[i] = SDLK_F1 + (i-58);
+    }
+    keymap[70] = SDLK_PRINT;
+    keymap[71] = SDLK_SCROLLOCK;
+    keymap[72] = SDLK_PAUSE;
+    keymap[73] = SDLK_INSERT;
+    keymap[74] = SDLK_HOME;
+    keymap[75] = SDLK_PAGEUP;
+    keymap[76] = SDLK_DELETE;
+    keymap[77] = SDLK_END;
+    keymap[78] = SDLK_PAGEDOWN;
+    keymap[79] = SDLK_RIGHT;
+    keymap[80] = SDLK_LEFT;
+    keymap[81] = SDLK_DOWN;
+    keymap[82] = SDLK_UP;
+    keymap[83] = SDLK_NUMLOCK;
+    keymap[84] = SDLK_KP_DIVIDE;
+    keymap[85] = SDLK_KP_MULTIPLY;
+    keymap[86] = SDLK_KP_MINUS;
+    keymap[87] = SDLK_KP_PLUS;
+    keymap[88] = SDLK_KP_ENTER;
+    for (i=89; i <= 97; i++) {
+      keymap[i] = SDLK_KP1 + (i-89);
+    }
+    keymap[98] = SDLK_KP0;
+    keymap[99] = SDLK_KP_PERIOD;
+    keymap[100] = SDLK_LESS;
+    keymap[101] = SDLK_MENU;
+    keymap[102] = SDLK_POWER;
+    keymap[103] = SDLK_KP_EQUALS;
+    keymap[104] = SDLK_F13;
+    keymap[105] = SDLK_F14;
+    keymap[106] = SDLK_F15;
+    keymap[109] = SDLK_POWER;
+    keymap[117] = SDLK_HELP;
+
+    break;
+
+#if defined(WSKBD_TYPE_ZAURUS)
   case WSKBD_TYPE_ZAURUS:
     /* top row */
     keymap[2] = SDLK_1;
@@ -220,7 +365,7 @@ void WSCONS_InitOSKeymap(_THIS)
     keymap[77] = SDLK_RIGHT;
     keymap[80] = SDLK_DOWN;
     break;
-#endif /* WSKBD_TYPE_ZAURUS */
+#endif
 
   default:
     WSCONS_ReportError("Unable to map keys for keyboard type %u", 
