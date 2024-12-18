#include "../../src/mystl/vector.h"
#include <gtest/gtest.h>

namespace
{
    using namespace MySTL;

    TEST(VectorTest, DefaultConstructor)
    {
        vector<int> v;
        EXPECT_TRUE(v.empty());
        EXPECT_EQ(v.size(), 0);
    }

    TEST(VectorTest, InitializerListConstructor)
    {
        vector<int> v{1, 2, 3};
        EXPECT_EQ(v.size(), 3);
        EXPECT_EQ(1, v[0]);
        EXPECT_EQ(2, v[1]);
        EXPECT_EQ(3, v[2]);
    }

    TEST(VectorTest, CopyConstructor)
    {
        vector<int> v{1, 2, 3};
        vector<int> vCopy(v);
        EXPECT_EQ(vCopy.size(), 3);
        EXPECT_EQ(1, vCopy[0]);
        EXPECT_EQ(2, vCopy[1]);
        EXPECT_EQ(3, vCopy[2]);
    }

    TEST(VectorTest, AssignmentOperator)
    {
        vector<int> v{1, 2, 3};
        vector<int> vAssign = v;
        EXPECT_EQ(vAssign.size(), 3);
        EXPECT_EQ(1, vAssign[0]);
        EXPECT_EQ(2, vAssign[1]);
        EXPECT_EQ(3, vAssign[2]);
    }

    TEST(VectorTest, PushBack)
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        EXPECT_EQ(v.size(), 3);
        EXPECT_EQ(v[0], 1);
        EXPECT_EQ(v[1], 2);
        EXPECT_EQ(v[2], 3);
    }

    TEST(VectorTest, PopBack)
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.pop_back();
        v.push_back(3);
        EXPECT_EQ(v.size(), 2);
        EXPECT_EQ(v[0], 1);
        EXPECT_EQ(v[1], 3);
    }

    TEST(VectorTest, Clear)
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        EXPECT_EQ(v.size(), 3);
        v.clear();
        EXPECT_EQ(v.size(), 0);
        EXPECT_THROW(v[1], std::out_of_range);
    }

}
