#! /usr/bin/env python
# encoding: utf-8

APPNAME = 'allocate'
VERSION = '3.1.0'


def build(bld):

    bld.env.append_unique(
        'DEFINES_STEINWURF_VERSION',
        'STEINWURF_ALLOCATE_VERSION="{}"'.format(
            VERSION))

    bld(name='allocate_includes',
        includes='./src',
        export_includes='./src')

    if bld.is_toplevel():

        # Only build tests when executed from the top-level wscript,
        # i.e. not when included as a dependency
        bld.recurse('test')
