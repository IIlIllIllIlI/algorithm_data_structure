// 977. Squares of a Sorted Array

#pragma once
#include "../../mystl/vector.h"
#include <algorithm>
using namespace MySTL;

namespace LeetCode {
    class Q977 {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            Solution3 s;
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

        class Solution3 {
            // 双指针排序，从两端到中间
            // https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html#%E6%80%9D%E8%B7%AF
        public:
            vector<int> sortedSquares(vector<int>& nums) {
                int k = nums.size() - 1;
                vector<int> result(nums.size(), 0);
                for (int i = 0, j = nums.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
                    if (nums[i] * nums[i] < nums[j] * nums[j]) {
                        result[k--] = nums[j] * nums[j];
                        j--;
                    } else {
                        result[k--] = nums[i] * nums[i];
                        i++;
                    }
                }
                return result;
            }
        };
    };
}