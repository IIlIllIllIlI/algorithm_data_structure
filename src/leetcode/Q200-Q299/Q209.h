
// 209. Minimum Size Subarray Sum
#pragma once
#include "../../mystl/vector.h"
using namespace MySTL;

namespace LeetCode {
    class Q209 {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            Solution1 s;
            return s.minSubArrayLen(target, nums);
        }

    private:
        class Solution1 {
            // Sliding Window O(n)
        public:
            int minSubArrayLen(int target, vector<int>& nums) {
                int numsSize = nums.size();
                int l = 0;
                int r = 0;
                int minSoFar = numsSize + 1;
                int sum = 0;

                while (r < numsSize) {
                    sum += nums[r];
                    while (sum >= target) {
                        if (r - l + 1 < minSoFar) {
                            minSoFar = r - l + 1;
                        }
                        sum -= nums[l];
                        l++;
                    }
                    r++;
                }

                if (minSoFar > numsSize) {
                    return 0;
                } else {
                    return minSoFar;
                }
            }
        };
    };
}