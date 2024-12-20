#include "Q800-Q899/Q844.h"
#include <gtest/gtest.h>

namespace
{
    LeetCode::Q844 solution;
    TEST(Q844, Example1)
    {
        EXPECT_TRUE(solution.backspaceCompare("ab#c", "ad#c"));
    }

    TEST(Q844, Example2)
    {
        EXPECT_TRUE(solution.backspaceCompare("ab##", "c#d#"));
    }

    TEST(Q844, Example3)
    {
        EXPECT_FALSE(solution.backspaceCompare("a#c", "b"));
    }

    TEST(Q844, Example4)
    {
        EXPECT_TRUE(solution.backspaceCompare("###", "##"));
    }
}