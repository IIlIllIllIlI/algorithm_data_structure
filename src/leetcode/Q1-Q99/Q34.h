// 34. Find First and Last Position of Element in Sorted Array

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
    class Q34
    {
    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            Solution1 s;
            return s.searchRange(nums, target);
        }

    private:
        class Solution1
        {
            // “归约”（Reduction）将一个未知解决方法的问题（即目标问题）转化
            // 为一个已知问题，并利用已知问题的解决方案来解决目标问题。 这里将问题转化为 Q35 Search Insert Position.
            // 搜索 target-0.5 和 target+0.5 的位置
        public:
            vector<int> searchRange(vector<int>& nums, int target)
            {

                int lIdx = searchPlaceToInsert(nums, target - 0.5);
                int rIdx = searchPlaceToInsert(nums, target + 0.5) - 1;

                // 搜索target-0.5和target+0.5的位置
                if (lIdx < 0 || lIdx >= nums.size() || rIdx < 0 || rIdx >= nums.size() || nums[lIdx] != target ||
                    nums[rIdx] != target)
                {
                    // 找到的答案无效
                    return vector<int>{-1, -1};
                }
                else
                {
                    return vector<int>{lIdx, rIdx};
                }
            }

            int searchPlaceToInsert(vector<int>& nums, float target)
            {
                int leftIdx = 0;
                int rightIdx = nums.size() - 1;
                while (leftIdx <= rightIdx)
                {
                    int midIdx = leftIdx + (rightIdx - leftIdx) / 2;
                    int midVal = nums[midIdx];
                    if (midVal > target)
                    {
                        rightIdx = midIdx - 1;
                    }
                    else if (midVal < target)
                    {
                        leftIdx = midIdx + 1;
                    }
                    else
                    {
                        return midIdx;
                    }
                }
                return rightIdx + 1;
            }
        };
    };
}