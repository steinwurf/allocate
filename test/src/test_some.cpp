// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <allocate/some.hpp>
#include <gtest/gtest.h>

TEST(test_some, return_value_of_some_method)
{
    allocate::some s;
    EXPECT_TRUE(s.some_method());
}
