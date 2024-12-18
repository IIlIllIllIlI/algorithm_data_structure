// 27. Remove Element

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
    class Q27
    {
    public:
        int removeElement(vector<int>& nums, int val)
        {
            Solution1 s;
            return s.removeElement(nums, val);
        }

    private:
        class Solution1
        {
        public:
            int removeElement(vector<int>& nums, int val)
            {
                int writeIdx = 0;
                int readIdx = 0;

                while (readIdx < nums.size())
                {
                    if (nums[writeIdx] == val)
                    {
                        while (readIdx < nums.size())
                        {
                            if (nums[readIdx] != val)
                            {
                                nums[writeIdx] = nums[readIdx];
                                nums[readIdx] = val;
                                writeIdx++;
                                readIdx++;
                                break;
                            }
                            else
                            {
                                readIdx++;
                            }
                        }
                    }
                    else
                    {
                        writeIdx++;
                        readIdx++;
                    }
                }
                return writeIdx;
            }
        };

        class Solution2
        {
        public:
            // https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html#%E5%8F%8C%E6%8C%87%E9%92%88%E6%B3%95
            int removeElement(vector<int>& nums, int val)
            {
                int slowIndex = 0;
                for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
                {
                    if (val != nums[fastIndex])
                    {
                        nums[slowIndex++] = nums[fastIndex];
                    }
                }
                return slowIndex;
            }
        };
    };
}