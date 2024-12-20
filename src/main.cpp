#include "mystl/vector.h"
#include <iostream>
#include <vector>

#include "leetcode/Q700-Q799/Q704.h"

int main() {
    LeetCode::Q704 s;
    MySTL::vector<int> nums1;

    MySTL::vector<int> nums{-1, -2};
    std::cout << s.search(nums, 0) << std::endl;
    std::cout << s.search(nums, -1) << std::endl;
    std::cout << s.search(nums, -2) << std::endl;

    // EXPECT_EQ(s.search(nums, 0), -1);
    // EXPECT_EQ(s.search(nums, -1), 0);
    // EXPECT_EQ(s.search(nums, -2), 1);

    std::vector<int> stdv;

    system("pause");
    return 0;
}