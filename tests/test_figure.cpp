#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/octagon.h"
#include "../include/square.h"
#include "../include/triangle.h"

TEST(FigureTest, OctagonAreaCalculation) {
    Octagon oct(2.0);
    EXPECT_NEAR(double(oct), 19.3137, 0.0001);
}

TEST(FigureTest, SquareAreaCalculation) {
    Square sq(3.0);
    EXPECT_NEAR(double(sq), 9.0, 0.0001);
}

TEST(FigureTest, TriangleAreaCalculation) {
    Triangle tr(4.0);
    EXPECT_NEAR(double(tr), 6.9282, 0.0001);
}

TEST(FigureTest, CenterGetter) {
    std::array<double, 2> center = {1.0, 1.0};
    Octagon oct(2.0, center);
    
    auto result = oct.get_center();
    EXPECT_DOUBLE_EQ(result[0], 1.0);
    EXPECT_DOUBLE_EQ(result[1], 1.0);
}

TEST(FigureTest, SideLengthCalculation) {
    std::array<double, 2> v1 = {0.0, 0.0};
    std::array<double, 2> v2 = {1.0, 0.0};
    std::array<double, 2> v3 = {0.0, 1.0};
    
    // This would test the calculate_side_length method
    // Note: This requires access to protected methods or a different approach
}