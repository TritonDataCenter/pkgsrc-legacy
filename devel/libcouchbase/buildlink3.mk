BUILDLINK_TREE+=	libcouchbase

.if !defined(LIBCOUCHBASE_BUILDLINK3_MK)
LIBCOUCHBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcouchbase+=	libcouchbase>=0.1
BUILDLINK_ABI_DEPENDS.libcouchbase+=	libcouchbase>=0.1
BUILDLINK_PKGSRCDIR.libcouchbase?=	../../devel/libcouchbase
BUILDLINK_LDADD.libcouchbase+=		-lcouchbase
.endif # LIBCOUCHBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcouchbase
