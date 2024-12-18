#include "Q200-Q299/Q283.h"
#include <gtest/gtest.h>

namespace
{
    LeetCode::Q283 s;
    TEST(Q283, Example1)
    {
        vector<int> nums{0, 1, 0, 3, 12};
        vector<int> expected{1, 3, 12, 0, 0};
        s.moveZeroes(nums);
        ASSERT_EQ(nums.size(), expected.size());
        for (int i = 0; i < nums.size(); i++)
        {
            EXPECT_EQ(nums[i], expected[i]);
        }
    }

    TEST(Q283, Example2)
    {
        vector<int> nums{0};
        vector<int> expected{0};
        s.moveZeroes(nums);
        ASSERT_EQ(nums.size(), expected.size());
        for (int i = 0; i < nums.size(); i++)
        {
            EXPECT_EQ(nums[i], expected[i]);
        }
    }

    TEST(Q283, Example3)
    {
        vector<int> nums{1};
        vector<int> expected{1};
        s.moveZeroes(nums);
        ASSERT_EQ(nums.size(), expected.size());
        for (int i = 0; i < nums.size(); i++)
        {
            EXPECT_EQ(nums[i], expected[i]);
        }
    }

}