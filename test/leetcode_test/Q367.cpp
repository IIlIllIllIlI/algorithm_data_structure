

#include "Q300-Q399/Q367.h"
#include <gtest/gtest.h>

// Constraints:
// 0 <= x <= 231 - 1

namespace
{
    LeetCode::Q367 s;
    TEST(Q367, Example1)
    {
        int res = s.isPerfectSquare(16);
        EXPECT_TRUE(res);
    }

    TEST(Q367, Example2)
    {
        int res = s.isPerfectSquare(14);
        EXPECT_FALSE(res);
    }

}