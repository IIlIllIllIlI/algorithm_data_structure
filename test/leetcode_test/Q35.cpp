#include "Q1-Q99/Q35.h"
#include <gtest/gtest.h>

// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

namespace
{
    LeetCode::Q35 s;
    TEST(Q35, Example1)
    {
        vector<int> nums{1, 3, 5, 6};
        int result = s.searchInsert(nums, 5);
        EXPECT_EQ(result, 2);
    }

    TEST(Q35, Example2)
    {
        vector<int> nums{1, 3, 5, 6};
        int result = s.searchInsert(nums, 2);
        EXPECT_EQ(result, 1);
    }

    TEST(Q35, Example3)
    {
        vector<int> nums{1, 3, 5, 6};
        int result = s.searchInsert(nums, 7);
        EXPECT_EQ(result, 4);
    }

    TEST(Q35, InsertAtIdx0)
    {
        vector<int> nums{1, 3, 5, 6};
        int result = s.searchInsert(nums, 0);
        EXPECT_EQ(result, 0);
    }

    TEST(Q35, InsertLeft)
    {
        vector<int> nums{1, 3};
        int result = s.searchInsert(nums, 0);
        EXPECT_EQ(result, 0);
    }

    TEST(Q35, InsertRight)
    {
        vector<int> nums{1, 3};
        int result = s.searchInsert(nums, 2);
        EXPECT_EQ(result, 1);
    }
}