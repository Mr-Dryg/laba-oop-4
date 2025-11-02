#include <gtest/gtest.h>
#include "../include/square.h"

TEST(SquareTest, DefaultConstructor) {
    Square sq;
    EXPECT_DOUBLE_EQ(double(sq), 1.0);
}

TEST(SquareTest, SideLengthConstructor) {
    Square sq(2.5);
    EXPECT_DOUBLE_EQ(double(sq), 6.25);
}

TEST(SquareTest, FullConstructor) {
    std::array<double, 2> center = {2.0, 3.0};
    Square sq(4.0, center);
    
    EXPECT_DOUBLE_EQ(double(sq), 16.0);
    auto result = sq.get_center();
    EXPECT_DOUBLE_EQ(result[0], 2.0);
    EXPECT_DOUBLE_EQ(result[1], 3.0);
}

TEST(SquareTest, TwoVertexConstructor) {
    std::array<double, 2> v1 = {0.0, 0.0};
    std::array<double, 2> v2 = {2.0, 2.0};
    Square sq(v1, v2);
    
    EXPECT_NEAR(double(sq), 4.0, 0.0001);
}