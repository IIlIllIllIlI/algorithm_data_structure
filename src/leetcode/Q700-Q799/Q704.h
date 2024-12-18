// 704. Binary Search

#pragma once
#define USE_MYSTL

#ifdef USE_MYSTL
#include "../../mystl/vector.h"
using namespace MySTL;
#else
#include <vector>
using namespace std;
#endif

namespace LeetCode
{
    class Q704
    {
    public:
        int search(vector<int>& nums, int target)
        {
            Solution1 s;
            return s.search(nums, target);
        }

    private:
        class Solution1
        {
        public:
            int search(vector<int>& nums, int target)
            {
                int left = 0;
                int right = nums.size() - 1;
                while (left <= right)
                {
                    int midIdx = (left + right) / 2;
                    if (nums[midIdx] == target)
                    {
                        return midIdx;
                    }
                    if (nums[midIdx] > target)
                    {
                        right = midIdx - 1;
                    }
                    else
                    {
                        left = midIdx + 1;
                    }
                }
                return -1;
            }
        };
    };
}
