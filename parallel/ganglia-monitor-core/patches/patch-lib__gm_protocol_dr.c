$NetBSD$

--- lib/gm_protocol_xdr.c.orig	2015-07-01 19:49:35.000000000 +0000
+++ lib/gm_protocol_xdr.c
@@ -53,9 +53,9 @@ xdr_Ganglia_metadata_message (XDR *xdrs,
 				 return FALSE;
 
 		} else {
-		IXDR_PUT_U_LONG(buf, objp->slope);
-		IXDR_PUT_U_LONG(buf, objp->tmax);
-		IXDR_PUT_U_LONG(buf, objp->dmax);
+		IXDR_PUT_U_INT32(buf, objp->slope);
+		IXDR_PUT_U_INT32(buf, objp->tmax);
+		IXDR_PUT_U_INT32(buf, objp->dmax);
 		}
 		 if (!xdr_array (xdrs, (char **)&objp->metadata.metadata_val, (u_int *) &objp->metadata.metadata_len, ~0,
 			sizeof (Ganglia_extra_data), (xdrproc_t) xdr_Ganglia_extra_data))
@@ -78,9 +78,9 @@ xdr_Ganglia_metadata_message (XDR *xdrs,
 				 return FALSE;
 
 		} else {
-		objp->slope = IXDR_GET_U_LONG(buf);
-		objp->tmax = IXDR_GET_U_LONG(buf);
-		objp->dmax = IXDR_GET_U_LONG(buf);
+		objp->slope = IXDR_GET_U_INT32(buf);
+		objp->tmax = IXDR_GET_U_INT32(buf);
+		objp->dmax = IXDR_GET_U_INT32(buf);
 		}
 		 if (!xdr_array (xdrs, (char **)&objp->metadata.metadata_val, (u_int *) &objp->metadata.metadata_len, ~0,
 			sizeof (Ganglia_extra_data), (xdrproc_t) xdr_Ganglia_extra_data))
