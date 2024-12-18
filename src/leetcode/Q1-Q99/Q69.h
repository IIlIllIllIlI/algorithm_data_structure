// 69. Sqrt(x)

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
    class Q69
    {
    public:
        int mySqrt(int x)
        {
            Solution1 s;
            return s.mySqrt(x);
        }

    private:
        class Solution1
        {

        public:
            int mySqrt(int x)
            {

                int left = 0;
                int right = x;

                while (left <= right)
                {
                    unsigned long long mid = left + (right - left) / 2;
                    unsigned long long midSquare = mid * mid;
                    if (midSquare > x)
                    {
                        right = mid - 1;
                    }
                    else if (midSquare < x)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        return mid;
                    }
                }

                return right;
            }
        };
    };
}