========
allocate
========

Allocate is a library containing an aligned allocator. The aligned allocator
should provide memory allocation for STL containers which are aligned on a
specific byte boundary.

Our use-case for allocate is to ensure that if used with a std::vector then the
buffer will start at the specified byte boundary.

The allocator may be used with a std::vector like this::

    std::vector<uint8_t, allocate::aligned_allocator<uint8_t>> data;

The allocator defaults to 32 bit alignment - the lowest common denominotor on
the supported platforms.

The allocator is based on the code example from:
The C++ Standard Library - A Tutorial and Reference
by Nicolai M. Josuttis, Addison-Wesley, 1999

Usage
=====

See unit tests for usage.
