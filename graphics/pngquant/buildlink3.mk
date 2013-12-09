# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.pngquant?=	build

BUILDLINK_TREE+=	pngquant

.if !defined(PNGQUANT_BUILDLINK3_MK)
PNGQUANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pngquant+=	pngquant>=2.0.1
BUILDLINK_PKGSRCDIR.pngquant?=	../../graphics/pngquant

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
.endif	# PNGQUANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pngquant
