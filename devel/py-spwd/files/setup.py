# $NetBSD: setup.py,v 1.1 2002/03/14 17:58:50 wiz Exp $

import distutils
from distutils.core import setup, Extension

setup(
	ext_modules = [
		Extension(
			'spwd',
			['Modules/spwdmodule.c']
		)
	]
)
