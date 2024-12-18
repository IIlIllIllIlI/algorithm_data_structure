#include "Q1-Q99/Q27.h"
#include <algorithm>
#include <gtest/gtest.h>

// Constraints:
// 0 <= nums.length <= 100
// 0 <= nums[i] <= 50
// 0 <= val <= 100

// Custom Judge:
// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int val = ...; // Value to remove
// int[] expectedNums = [...]; // The expected answer with correct length.
//                             // It is sorted with no values equaling val.
// int k = removeElement(nums, val); // Calls your implementation
// assert k == expectedNums.length;
// sort(nums, 0, k); // Sort the first k elements of nums
// for (int i = 0; i < actualLength; i++) {
//     assert nums[i] == expectedNums[i];
// }

namespace
{
    LeetCode::Q27 s;
    TEST(Q27, Example1)
    {
        vector<int> nums{3, 2, 2, 3};
        int k = s.removeElement(nums, 3);
        EXPECT_EQ(k, 2);
        EXPECT_EQ(nums[0], 2);
        EXPECT_EQ(nums[1], 2);
    }

    TEST(Q27, Example2)
    {
        vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
        vector<int> expectedNums{0, 0, 1, 3, 4};
        int k = s.removeElement(nums, 2);
        EXPECT_EQ(k, expectedNums.size());
        std::sort(nums.begin(), nums.begin() + k);
        for (int i = 0; i < expectedNums.size(); i++)
        {
            EXPECT_EQ(nums[i], expectedNums[i]) << "i: " << i;
        }
    }
}