// 35. Search Insert Position

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
    class Q35
    {
    public:
        int searchInsert(vector<int>& nums, int target)
        {
            Solution1 s;
            return s.searchInsert(nums, target);
        }

    private:
        class Solution1
        {
        public:
            int searchInsert(vector<int>& nums, int target)
            {
                int lIdx = 0;
                int rIdx = nums.size() - 1;

                while (lIdx <= rIdx)
                {
                    int midIdx = (lIdx + (rIdx - lIdx) / 2);
                    int val = nums[midIdx];

                    if (target > val)
                    {
                        lIdx = midIdx + 1;
                    }
                    else if (target < val)
                    {
                        rIdx = midIdx - 1;
                    }
                    else
                    {
                        return midIdx;
                    }
                }
                return rIdx + 1;
            }
        };
    };

}