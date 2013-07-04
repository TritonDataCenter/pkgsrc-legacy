# $NetBSD$
#
# Copyright (c) 2013 Joyent, Inc.  All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Jonathan Perkin <jperkin@joyent.com>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
# COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
# OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

#
# Convert ${{BIN,INC,LIB}ARCHSUFFIX} into lines for each supported ABI.
#
# Requires that for each var in MULTIARCH_ABIS there is a corresponding
# {BIN,INC,LIB}ARCHSUFFIX_${var} environment variable set pointing to the
# appropriate directory.
#
BEGIN {
	PLIST_MULTIARCH_ENABLED = ENVIRON["_MULTIARCH"] ? 1 : 0
	PLIST_USE_MULTIARCH = ENVIRON["USE_MULTIARCH"] ? ENVIRON["USE_MULTIARCH"] : ""
	PLIST_MULTIARCH_ABIS = ENVIRON["MULTIARCH_ABIS"]
	split(PLIST_MULTIARCH_ABIS, abis, " ")
	PLIST_MULTIARCH_DIRS_bin = ENVIRON["MULTIARCH_DIRS_bin"] ? ENVIRON["MULTIARCH_DIRS_bin"] : ""
	PLIST_MULTIARCH_DIRS_lib = ENVIRON["MULTIARCH_DIRS_lib"] ? ENVIRON["MULTIARCH_DIRS_lib"] : ""
	split(PLIST_MULTIARCH_DIRS_bin, bindirs, " ")
	split(PLIST_MULTIARCH_DIRS_lib, libdirs, " ")
	PLIST_MULTIARCH_SKIP_DIRS_bin = ENVIRON["MULTIARCH_SKIP_DIRS_bin"] ? ENVIRON["MULTIARCH_SKIP_DIRS_bin"] : ""
	PLIST_MULTIARCH_SKIP_DIRS_lib = ENVIRON["MULTIARCH_SKIP_DIRS_lib"] ? ENVIRON["MULTIARCH_SKIP_DIRS_lib"] : ""
	split(PLIST_MULTIARCH_SKIP_DIRS_bin, skipbindirs, " ")
	split(PLIST_MULTIARCH_SKIP_DIRS_lib, skiplibdirs, " ")
}

function replace_arch_dirs(type, dirs, skipdirs, suffixvar)
{
	matched = 0
	for (dir in dirs) {
		dirmatch = "^" dirs[dir] "/"
		if ($0 ~ dirmatch) {
			skip = 0
			for (skipdir in skipdirs) {
				skipdirmatch = "^" skipdirs[skipdir] "/"
				if ($0 ~ skipdirmatch) {
					skip = 1
				}
			}
			if (skip) {
				continue
			}
			for (abi in abis) {
				line = $0
				matched += gsub(dirmatch, dirs[dir] ENVIRON[suffixvar "_" abis[abi]] "/", line)
				print_entry(line)
			}
		}
	}
	# XXX: Limit to SunOS only
	if (type == "bin" && matched) {
		print_entry("@link lib/abiexec " $0)
	}
	return matched
}

PLIST_MULTIARCH_ENABLED && PLIST_USE_MULTIARCH ~ /bin/ {
	if (replace_arch_dirs("bin", bindirs, skipbindirs, "BINARCHSUFFIX") > 0) {
		next
	}
}

PLIST_MULTIARCH_ENABLED && PLIST_USE_MULTIARCH ~ /lib/ {
	if (replace_arch_dirs("lib", libdirs, skiplibdirs, "LIBARCHSUFFIX") > 0) {
		next
	}
}

# Support manual PLIST entries.
PLIST_MULTIARCH_ENABLED && (/[$][{](BIN|INC|LIB)ARCHSUFFIX[}]/) {
	isalink = 0
	for (abi in abis) {
		binval = ENVIRON["BINARCHSUFFIX_" abis[abi]]
		incval = ENVIRON["INCARCHSUFFIX_" abis[abi]]
		libval = ENVIRON["LIBARCHSUFFIX_" abis[abi]]
		line = $0
		isalink += gsub(/[$][{]BINARCHSUFFIX[}]/, binval, line)
		gsub(/[$][{]INCARCHSUFFIX[}]/, incval, line)
		gsub(/[$][{]LIBARCHSUFFIX[}]/, libval, line)
		print_entry(line)
	}
	# XXX: Limit to SunOS only
	if (isalink) {
		bin = $0
		gsub(/[$][{]BINARCHSUFFIX[}]/, "", bin)
		print_entry("@link lib/abiexec " bin)
	}
	if (/[$][{]INCARCHSUFFIX[}]/) {
		gsub(/[$][{]INCARCHSUFFIX[}]/, "")
		print_entry($0)
	}
	next
}

/[$][{](BIN|INC|LIB)ARCHSUFFIX[}]/ {
	gsub(/[$][{](BIN|INC|LIB)ARCHSUFFIX[}]/, "")
}
