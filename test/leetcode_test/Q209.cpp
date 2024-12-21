#include "Q200-Q299/Q209.h"
#include <gtest/gtest.h>

// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.

namespace {
    LeetCode::Q209 s;
    TEST(Q209, Example1) {
        vector<int> nums{2, 3, 1, 2, 4, 3};
        EXPECT_EQ(s.minSubArrayLen(7, nums), 2);
    }

    TEST(Q209, Example2) {
        vector<int> nums{1, 4, 4};
        EXPECT_EQ(s.minSubArrayLen(4, nums), 1);
    }

    TEST(Q209, Example3) {
        vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
        EXPECT_EQ(s.minSubArrayLen(11, nums), 0);
    }
}