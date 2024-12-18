#include "Q1-Q99/Q69.h"
#include <algorithm>
#include <gtest/gtest.h>

// Constraints:
// 0 <= x <= 231 - 1

namespace
{
    LeetCode::Q69 s;
    TEST(Q69, Example1)
    {
        int res = s.mySqrt(4);
        ASSERT_EQ(res, 2);
    }

    TEST(Q69, Example2)
    {
        int res = s.mySqrt(8);
        ASSERT_EQ(res, 2); // round it down to the nearest integer, 2 is returned.
    }

    TEST(Q69, Example2)
    {
        int res = s.mySqrt(2147395599);
        ASSERT_EQ(res, 2); // round it down to the nearest integer, 2 is returned.
    }
}