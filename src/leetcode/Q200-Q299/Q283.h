// 283. Move Zeroes

#pragma once

#include "../../mystl/vector.h"
using namespace MySTL;

namespace LeetCode
{
    class Q283
    {
    public:
        void moveZeroes(vector<int>& nums)
        {
            Solution1 s;
            s.moveZeroes(nums);
        }

    private:
        class Solution1
        {
        public:
            void moveZeroes(vector<int>& nums)
            {
                int read = 0;
                int write = 0;
                while (read < nums.size())
                {
                    if (nums[read] != 0)
                    {
                        int tmp = nums[read];
                        nums[read] = 0;
                        nums[write] = tmp;

                        write++;
                    }
                    read++;
                }
            }
        };
    };
}