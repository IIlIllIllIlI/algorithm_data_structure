// 844. Backspace String Compare

#pragma once
#include <string>
using std::string;
namespace LeetCode
{
    class Q844
    {
    public:
        bool backspaceCompare(string s, string t)
        {
            Solution1 sol1;
            return sol1.backspaceCompare(s, t);
        }

    private:
        class Solution1
        {
        public:
            bool backspaceCompare(string s, string t)
            {
                int l1 = helper(s);
                int l2 = helper(t);
                if (l1 == l2)
                {
                    for (int i = 0; i < l1; i++)
                    {
                        if (s[i] != t[i])
                        {
                            return false;
                        }
                    }
                    return true;
                }
                else
                {
                    return false;
                }
            }

            // 处理退格号(#)，返回有效的长度
            int helper(string& s)
            {
                int read = 0;
                int write = 0;
                while (read < s.size())
                {
                    if (s[read] == '#')
                    {
                        write = std::max(0, write - 1);
                    }
                    else
                    {
                        s[write] = s[read];
                        write++;
                    }
                    read++;
                }
                return write;
            }
        };
    };
}