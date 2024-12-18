#include "Q700-Q799/Q704.h"
#include <gtest/gtest.h>

// Constraints:
// 1 <= nums.length <= 104
// -104 < nums[i], target < 104
// All the integers in nums are unique.
// nums is sorted in ascending order.

namespace
{
    LeetCode::Q704 s;
    TEST(Q704, Example1)
    {
        vector<int> nums{-1, 0, 3, 5, 9, 12};
        EXPECT_EQ(s.search(nums, 9), 4);
    }

    TEST(Q704, Example2)
    {
        vector<int> nums{-1, 0, 3, 5, 9, 12};
        EXPECT_EQ(s.search(nums, 2), -1);
    }

    TEST(Q704, Length1)
    {
        vector<int> nums{1};
        EXPECT_EQ(s.search(nums, 0), -1);
        EXPECT_EQ(s.search(nums, 1), 0);
    }

    TEST(Q704, Length2)
    {
        vector<int> nums{-2, -1};
        EXPECT_EQ(s.search(nums, 0), -1);
        EXPECT_EQ(s.search(nums, -1), 1);
        EXPECT_EQ(s.search(nums, -2), 0);
    }

    TEST(Q704, Length3)
    {
        vector<int> nums{2, 4, 6};
        EXPECT_EQ(s.search(nums, 1), -1);
        EXPECT_EQ(s.search(nums, 2), 0);
        EXPECT_EQ(s.search(nums, 4), 1);
        EXPECT_EQ(s.search(nums, 6), 2);
    }
}