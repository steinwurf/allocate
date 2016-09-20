// Copyright (c) 2012 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <allocate/aligned_allocator.hpp>

#include <gtest/gtest.h>

#include <allocate/is_aligned.hpp>


TEST(TestAlignedAllocator, construct)
{
    allocate::aligned_allocator<uint8_t> alloc;
    EXPECT_EQ(alloc.alignment(), 32U);
}

TEST(TestAlignedAllocator, vector)
{
    typedef std::vector<uint32_t, allocate::aligned_allocator<uint32_t> >
    aligned_vector;

    aligned_vector v;

    v.push_back(42);
    v.push_back(56);
    v.push_back(11);

    EXPECT_TRUE(allocate::is_aligned(&v[0]));

    v.push_back(42);
    v.push_back(56);
    v.push_back(11);

    EXPECT_TRUE(allocate::is_aligned(&v[0]));

    v.push_back(42);
    v.push_back(56);
    v.push_back(11);

    EXPECT_TRUE(allocate::is_aligned(&v[0]));

    aligned_vector v2 = v;

    EXPECT_TRUE(allocate::is_aligned(&v2[0]));

    v2.push_back(42);
    v2.push_back(56);
    v2.push_back(11);

    EXPECT_TRUE(allocate::is_aligned(&v2[0]));

    v2.push_back(42);
    v2.push_back(56);
    v2.push_back(11);

    EXPECT_TRUE(allocate::is_aligned(&v2[0]));
}

TEST(TestAlignedAllocator, vector_resize)
{
    typedef std::vector<uint8_t, allocate::aligned_allocator<uint8_t> >
    aligned_vector;

    aligned_vector v;

    v.resize(100);

    EXPECT_EQ(v.size(), 100U);
    v[10] = 0;
}

TEST(TestAlignedAllocator, vector_zero_size)
{
    typedef std::vector<uint8_t, allocate::aligned_allocator<uint8_t> >
    aligned_vector;

    aligned_vector v(0);
    EXPECT_EQ(v.size(), 0U);
}
