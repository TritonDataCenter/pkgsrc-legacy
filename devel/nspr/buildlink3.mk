# $NetBSD: buildlink3.mk,v 1.24 2014/10/13 09:14:29 wiz Exp $

BUILDLINK_TREE+=	nspr

.if !defined(NSPR_BUILDLINK3_MK)
NSPR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.9.3.2
BUILDLINK_PKGSRCDIR.nspr?=	../../devel/nspr

BUILDLINK_FILES.nspr+=          lib${LIBARCHSUFFIX}/nspr/*
BUILDLINK_FILES.nspr+=          include/nspr/*
BUILDLINK_FILES.nspr+=          include/nspr/obsolete/*

BUILDLINK_LIBDIRS.nspr+=	lib${LIBARCHSUFFIX}/nspr
BUILDLINK_RPATHDIRS.nspr+=	lib${LIBARCHSUFFIX}/nspr

BUILDLINK_INCDIRS.nspr+=	include/nspr

.endif	# NSPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-nspr
