// 977. Squares of a Sorted Array

#pragma once
#include "../../mystl/vector.h"
#include <algorithm>
using namespace MySTL;

namespace LeetCode {
    class Q977 {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            Solution2 s;
            return s.sortedSquares(nums);
        }

    private:
        class Solution1 {
            // Squaring each element and sorting the new arrays
            // time complexity O(nlogn)
        public:
            vector<int> sortedSquares(vector<int>& nums) {
                for (int i = 0; i < nums.size(); i++) {
                    nums[i] *= nums[i];
                }
                std::sort(nums.begin(), nums.end());
                return nums;
            }
        };

        class Solution2 {
            // 分成负数和非负数两部分，square 后并归排序
            // 二分搜索 O(logn)
            // 并归排序 O(n)
            // total time complexity: O(n)
        public:
            vector<int> sortedSquares(vector<int>& nums) {
                // [0, div-1]  负数  square后 desreasing order
                // [div, nums.size() - 1] 非负数  square后 non-decreaseing order
                int div;
                {
                    int left = 0;
                    int right = nums.size() - 1;
                    while (left <= right) {
                        int mid = left + (right - left) / 2;
                        if (nums[mid] >= 0) {
                            right = mid - 1;
                        } else {
                            left = mid + 1;
                        }
                    }
                    div = right + 1;
                }

                // square
                for (int i = 0; i < nums.size(); i++) {
                    nums[i] *= nums[i];
                }

                // 并归
                vector<int> ans;
                ans.reserve(nums.size());
                {
                    int i = div - 1;
                    int j = div;
                    while (i >= 0 || j <= nums.size() - 1) {
                        if (i < 0) {
                            ans.push_back(nums[j]);
                            j++;
                        } else if (j > nums.size() - 1) {
                            ans.push_back(nums[i]);
                            i--;
                        } else if (nums[i] <= nums[j]) {
                            ans.push_back(nums[i]);
                            i--;
                        } else {
                            // if (nums[i] > nums[j])
                            ans.push_back(nums[j]);
                            j++;
                        }
                    }
                }
                return ans;
            }
        };
    };
}