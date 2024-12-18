// 367. Valid Perfect Square
#pragma once
namespace LeetCode
{
    class Q367
    {
    public:
        bool isPerfectSquare(int num)
        {
            Solution1 s;
            return s.isPerfectSquare(num);
        }

    private:
        class Solution1
        {
        public:
            bool isPerfectSquare(int num)
            {
                int left = 0;
                int right = num;

                while (left <= right)
                {
                    unsigned long long mid = left + (right - left) / 2;
                    unsigned long long midSquare = mid * mid;
                    if (midSquare > num)
                    {
                        right = mid - 1;
                    }
                    else if (midSquare < num)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        return true;
                    }
                }

                return false;
            }
        };
    };
}