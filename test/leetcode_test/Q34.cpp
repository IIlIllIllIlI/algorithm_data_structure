#include "Q1-Q99/Q34.h"
#include <algorithm>
#include <gtest/gtest.h>

// Constraints:
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109

namespace
{
    LeetCode::Q34 s;
    TEST(Q34, Example1)
    {
        vector<int> nums{5, 7, 7, 8, 8, 10};
        vector<int> res = s.searchRange(nums, 8);
        ASSERT_EQ(res.size(), 2);
        EXPECT_EQ(res[0], 3);
        EXPECT_EQ(res[1], 4);
    }

    TEST(Q34, Example2)
    {
        vector<int> nums{5, 7, 7, 8, 8, 10};
        vector<int> res = s.searchRange(nums, 6);
        ASSERT_EQ(res.size(), 2);
        EXPECT_EQ(res[0], -1);
        EXPECT_EQ(res[1], -1);
    }

    TEST(Q34, Example3)
    {
        vector<int> nums{};
        vector<int> res = s.searchRange(nums, 0);
        ASSERT_EQ(res.size(), 2);
        EXPECT_EQ(res[0], -1);
        EXPECT_EQ(res[1], -1);
    }

    TEST(Q34, Example4)
    {
        vector<int> nums{2, 2};
        vector<int> res = s.searchRange(nums, 2);
        ASSERT_EQ(res.size(), 2);
        EXPECT_EQ(res[0], 0);
        EXPECT_EQ(res[1], 1);
    }

    TEST(Q34, Example5)
    {
        vector<int> nums{2, 2};
        vector<int> res = s.searchRange(nums, 3);
        ASSERT_EQ(res.size(), 2);
        EXPECT_EQ(res[0], -1);
        EXPECT_EQ(res[1], -1);
    }
}