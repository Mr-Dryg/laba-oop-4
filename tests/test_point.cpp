#include <gtest/gtest.h>
#include "point.h"

TEST(PointTest, DefaultConstructor) {
    Point<double> p;
    EXPECT_NEAR(p.x, 0.0, 0.0001);
    EXPECT_NEAR(p.y, 0.0, 0.0001);
}

TEST(PointTest, ParameterizedConstructor) {
    Point<double> p(3.5, 4.2);
    EXPECT_EQ(p.x, 3.5);
    EXPECT_EQ(p.y, 4.2);
}

TEST(PointTest, ArrayConstructor) {
    std::array<double, 2> arr = {1.1, 2.2};
    Point<double> p(arr);
    EXPECT_EQ(p.x, 1.1);
    EXPECT_EQ(p.y, 2.2);
}

TEST(PointTest, OutputOperator) {
    Point<double> p(1.5, 2.5);
    std::stringstream ss;
    ss << p;
    EXPECT_EQ(ss.str(), "1.5 2.5");
}

TEST(PointTest, InputOperator) {
    Point<double> p;
    std::stringstream ss("3.14 2.71");
    ss >> p;
    EXPECT_EQ(p.x, 3.14);
    EXPECT_EQ(p.y, 2.71);
}