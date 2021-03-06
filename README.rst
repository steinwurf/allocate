========
allocate
========

.. image:: https://travis-ci.org/steinwurf/allocate.svg?branch=master
    :target: https://travis-ci.org/steinwurf/allocate

Allocate is a library containing an aligned allocator. The aligned allocator
should provide memory allocation for STL containers which are aligned on a
specific byte boundary.

Our use-case for allocate is to ensure that if used with a std::vector then the
buffer will start at the specified byte boundary.

The allocator may be used with a std::vector like this::

    std::vector<uint8_t, allocate::aligned_allocator<uint8_t>> data;

The allocator defaults to 32 bit alignment - the lowest common denominator on
the supported platforms.

The allocator is based on the code example from:
The C++ Standard Library - A Tutorial and Reference
by Nicolai M. Josuttis, Addison-Wesley, 1999

Usage
=====

See unit tests for usage.

Use as Dependency in CMake
--------------------------

To depend on this project when using the CMake build system, add the following
in your CMake build script::

   add_subdirectory("/path/to/allocate" allocate)
   target_link_libraries(<my_target> steinwurf::allocate)

Where ``<my_target>`` is replaced by your target.
