#include <gtest/gtest.h>
#include "triangle.h"

TEST(TriangleTest, DefaultConstructor) {
    Triangle<double> t;
    EXPECT_EQ(t.get_center().x, 0.0);
    EXPECT_EQ(t.get_center().y, 0.0);
}

TEST(TriangleTest, SideLengthConstructor) {
    Triangle<double> t(2.0);
    EXPECT_NEAR(static_cast<double>(t), std::sqrt(3.0), 0.0001);
}

TEST(TriangleTest, SideLengthAndCenterConstructor) {
    Triangle<double> t(2.0, {1.0, 1.0});
    Point<double> center = t.get_center();
    EXPECT_EQ(center.x, 1.0);
    EXPECT_EQ(center.y, 1.0);
}

TEST(TriangleTest, VerticesConstructor) {
    Triangle<double> t({0.0, 0.0}, {1.0, 0.0}, {0.5, std::sqrt(3.0)/2});
    EXPECT_NEAR(static_cast<double>(t), std::sqrt(3.0)/4, 0.0001);
}

TEST(TriangleTest, AreaCalculation) {
    Triangle<double> t(2.0);
    double expected_area = std::sqrt(3.0);
    EXPECT_NEAR(static_cast<double>(t), expected_area, 0.0001);
}

TEST(TriangleTest, EqualityOperator) {
    Triangle<double> t1(2.0);
    Triangle<double> t2(2.0);
    EXPECT_TRUE(t1 == t2);
}

TEST(TriangleTest, InputOutput) {
    Triangle<double> t1(2.0);
    std::stringstream ss;
    ss << t1;
    
    Triangle<double> t2;
    ss >> t2;
    EXPECT_TRUE(t1 == t2);
}