#include <gtest/gtest.h>
#include "octagon.h"
#include <cmath>

TEST(OctagonTest, DefaultConstructor) {
    Octagon<double> o;
    EXPECT_EQ(o.get_center().x, 0.0);
    EXPECT_EQ(o.get_center().y, 0.0);
}

TEST(OctagonTest, SideLengthConstructor) {
    Octagon<double> o(2.0);
    double expected_area = 2.0 * (1.0 + std::sqrt(2.0)) * 4.0;
    EXPECT_NEAR(static_cast<double>(o), expected_area, 0.0001);
}

TEST(OctagonTest, SideLengthAndCenterConstructor) {
    Octagon<double> o(2.0, {1.0, 1.0});
    Point<double> center = o.get_center();
    EXPECT_EQ(center.x, 1.0);
    EXPECT_EQ(center.y, 1.0);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon<double> o(1.0);
    double expected_area = 2.0 * (1.0 + std::sqrt(2.0));
    EXPECT_NEAR(static_cast<double>(o), expected_area, 0.0001);
}

TEST(OctagonTest, EqualityOperator) {
    Octagon<double> o1(2.0);
    Octagon<double> o2(2.0);
    EXPECT_TRUE(o1 == o2);
}