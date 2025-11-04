#include <gtest/gtest.h>
#include "square.h"

TEST(SquareTest, DefaultConstructor) {
    Square<double> s;
    EXPECT_EQ(s.get_center().x, 0.0);
    EXPECT_EQ(s.get_center().y, 0.0);
}

TEST(SquareTest, SideLengthConstructor) {
    Square<double> s(2.0);
    EXPECT_EQ(static_cast<double>(s), 4.0);
}

TEST(SquareTest, SideLengthAndCenterConstructor) {
    Square<double> s(2.0, {1.0, 1.0});
    Point<double> center = s.get_center();
    EXPECT_EQ(center.x, 1.0);
    EXPECT_EQ(center.y, 1.0);
}

TEST(SquareTest, TwoVerticesConstructor) {
    Square<double> s({0.0, 0.0}, {1.0, 1.0});
    EXPECT_NEAR(static_cast<double>(s), 1.0, 0.0001);
}

TEST(SquareTest, AreaCalculation) {
    Square<double> s(3.0);
    EXPECT_EQ(static_cast<double>(s), 9.0);
}

TEST(SquareTest, EqualityOperator) {
    Square<double> s1(2.0);
    Square<double> s2(2.0);
    EXPECT_TRUE(s1 == s2);
}