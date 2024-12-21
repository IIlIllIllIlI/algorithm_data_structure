#include "Q900-Q999/Q904.h"
#include <algorithm>
#include <gtest/gtest.h>

namespace {
    LeetCode::Q904 s;
    TEST(Q904, Example1) {
        vector<int> fruits{1, 2, 1};
        EXPECT_EQ(s.totalFruit(fruits), 3);
    }

    TEST(Q904, Example2) {
        vector<int> fruits{0, 1, 2, 2};
        EXPECT_EQ(s.totalFruit(fruits), 3);
    }

    TEST(Q904, Example3) {
        vector<int> fruits{1, 2, 3, 2, 2};
        EXPECT_EQ(s.totalFruit(fruits), 4); // 2, 3, 2, 2
    }
}