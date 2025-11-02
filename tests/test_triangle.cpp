#include <gtest/gtest.h>
#include "../include/triangle.h"

TEST(TriangleTest, DefaultConstructor) {
    Triangle tr;
    EXPECT_NEAR(double(tr), 0.4330, 0.0001);
}

TEST(TriangleTest, SideLengthConstructor) {
    Triangle tr(3.0);
    EXPECT_NEAR(double(tr), 3.8971, 0.0001);
}

TEST(TriangleTest, FullConstructor) {
    std::array<double, 2> center = {1.0, 1.0};
    Triangle tr(2.0, center);
    
    EXPECT_NEAR(double(tr), 1.732, 0.001);
    auto result = tr.get_center();
    EXPECT_DOUBLE_EQ(result[0], 1.0);
    EXPECT_DOUBLE_EQ(result[1], 1.0);
}

TEST(TriangleTest, ThreeVertexConstructor) {
    std::array<double, 2> v1 = {0.0, 0.0};
    std::array<double, 2> v2 = {1.0, 0.0};
    std::array<double, 2> v3 = {0.5, 0.866};
    Triangle tr(v1, v2, v3);
    
    EXPECT_NEAR(double(tr), 0.433, 0.001);
}