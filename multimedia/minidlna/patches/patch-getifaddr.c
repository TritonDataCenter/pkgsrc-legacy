$NetBSD$

Check if IFF_SLAVE is defined or not

--- getifaddr.c.orig	2013-04-30 21:09:30.000000000 +0000
+++ getifaddr.c
@@ -175,8 +175,10 @@ getsysaddrs(void)
 		if (p->ifa_addr && p->ifa_addr->sa_family == AF_INET)
 		{
 			addr_in = (struct sockaddr_in *)p->ifa_addr;
+			#ifdef IFF_SLAVE
 			if (p->ifa_flags & (IFF_LOOPBACK | IFF_SLAVE))
 				continue;
+			#endif
 			memcpy(&lan_addr[n_lan_addr].addr, &addr_in->sin_addr, sizeof(lan_addr[n_lan_addr].addr));
 			if (!inet_ntop(AF_INET, &addr_in->sin_addr, lan_addr[n_lan_addr].str, sizeof(lan_addr[0].str)) )
 			{
