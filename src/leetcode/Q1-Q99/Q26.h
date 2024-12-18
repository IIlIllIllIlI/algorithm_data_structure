// 26. Remove Duplicates from Sorted Array

#pragma once

#include "../../mystl/vector.h"
using namespace MySTL;

namespace LeetCode
{
    class Q26
    {
    public:
        int removeDuplicates(vector<int>& nums)
        {
            Solution1 s;
            return s.removeDuplicates(nums);
        }

    private:
        class Solution1
        {
        public:
            int removeDuplicates(vector<int>& nums)
            {
                int cacheVal = nums[0];

                int read = 1;
                int write = 1;

                while (read < nums.size())
                {
                    if (nums[read] == cacheVal)
                    {
                        read++;
                    }
                    else
                    {
                        cacheVal = nums[read];
                        nums[write] = nums[read];
                        read++;
                        write++;
                    }
                }
                return write;
            }
        };
    };

}