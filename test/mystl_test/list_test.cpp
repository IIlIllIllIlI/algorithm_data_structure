#include "../../src/mystl/list.h"
#include <gtest/gtest.h>

namespace {
using namespace MySTL;

TEST(ListTest, DefaultConstructor) {
    list<int> l;
    EXPECT_TRUE(l.empty());
    EXPECT_EQ(l.size(), 0);
}

TEST(ListTest, InitializerListConstructor) {
    list<int> l{1, 2, 3};
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(1, l[0]);
    EXPECT_EQ(2, l[1]);
    EXPECT_EQ(3, l[2]);
}

TEST(ListTest, CopyConstructor) {
    list<int> l{1, 2, 3};
    list<int> lCopy(l);
    EXPECT_EQ(lCopy.size(), 3);
    EXPECT_EQ(1, lCopy[0]);
    EXPECT_EQ(2, lCopy[1]);
    EXPECT_EQ(3, lCopy[2]);
}

TEST(ListTest, AssignmentOperator) {
    list<int> l{1, 2, 3};
    list<int> lAssign = l;
    EXPECT_EQ(lAssign.size(), 3);
    EXPECT_EQ(1, lAssign[0]);
    EXPECT_EQ(2, lAssign[1]);
    EXPECT_EQ(3, lAssign[2]);
}

TEST(ListTest, PushBack) {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l[0], 1);
    EXPECT_EQ(l[1], 2);
    EXPECT_EQ(l[2], 3);
}

TEST(ListTest, PopBack) {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.pop_back();
    l.push_back(3);
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l[0], 1);
    EXPECT_EQ(l[1], 3);
}

TEST(ListTest, Clear) {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    EXPECT_EQ(l.size(), 3);
    l.clear();
    EXPECT_EQ(l.size(), 0);
    EXPECT_THROW(l[1], std::out_of_range);
}

} // namespace
