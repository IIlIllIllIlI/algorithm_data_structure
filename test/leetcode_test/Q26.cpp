#include "Q1-Q99/Q26.h"
#include <algorithm>
#include <gtest/gtest.h>

// Constraints:
// 0 <= x <= 231 - 1

// Custom Judge:
// The judge will test your solution with the following code:
// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length
// int k = removeDuplicates(nums); // Calls your implementation
// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

namespace
{
    LeetCode::Q26 s;
    TEST(Q26, Example1)
    {
        vector<int> nums{1, 1, 2};
        int k = s.removeDuplicates(nums);
        vector<int> expected{1, 2};
        ASSERT_EQ(k, expected.size());
        for (int i = 0; i < k; i++)
        {
            EXPECT_EQ(nums[i], expected[i]);
        }
    }

    TEST(Q26, Example2)
    {
        vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int k = s.removeDuplicates(nums);
        vector<int> expected{0, 1, 2, 3, 4};
        ASSERT_EQ(k, expected.size());
        for (int i = 0; i < k; i++)
        {
            EXPECT_EQ(nums[i], expected[i]);
        }
    }

}