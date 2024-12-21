#include "Q900-Q999/Q977.h"
#include <gtest/gtest.h>

// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.

namespace
{
    LeetCode::Q977 s;
    TEST(Q977, Example1)
    {
        vector<int> nums{-4, -1, 0, 3, 10};
        vector<int> expected{0, 1, 9, 16, 100};
        vector<int> res = s.sortedSquares(nums);

        ASSERT_EQ(res.size(), expected.size());
        for (int i = 0; i < expected.size(); i++)
        {
            EXPECT_EQ(res[i], expected[i]);
        }
    }

    TEST(Q977, Example2)
    {
        vector<int> nums{-7, -3, 2, 3, 11};
        vector<int> expected{4, 9, 9, 49, 121};
        vector<int> res = s.sortedSquares(nums);

        ASSERT_EQ(res.size(), expected.size());
        for (int i = 0; i < expected.size(); i++)
        {
            EXPECT_EQ(res[i], expected[i]);
        }
    }

}