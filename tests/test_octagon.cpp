#include <gtest/gtest.h>
#include "../include/octagon.h"

TEST(OctagonTest, DefaultConstructor) {
    Octagon oct;
    EXPECT_NEAR(double(oct), 4.8284, 0.0001);
}

TEST(OctagonTest, SideLengthConstructor) {
    Octagon oct(2.5);
    EXPECT_NEAR(double(oct), 30.178, 0.001);
}

TEST(OctagonTest, FullConstructor) {
    std::array<double, 2> center = {1.0, 2.0};
    Octagon oct(3.0, center);
    
    EXPECT_NEAR(double(oct), 43.4558, 0.0001);
    auto result = oct.get_center();
    EXPECT_DOUBLE_EQ(result[0], 1.0);
    EXPECT_DOUBLE_EQ(result[1], 2.0);
}