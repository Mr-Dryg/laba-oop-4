#include <gtest/gtest.h>
#include <cmath>
#include "../include/octagon.h"
#include "../include/square.h"
#include "../include/triangle.h"

TEST(ComparisonTest, EqualFigures) {
    Octagon oct1(2.0);
    Octagon oct2(2.0);
    Square sq1(3.0);
    Square sq2(3.0);
    Triangle tr1(4.0);
    Triangle tr2(4.0);
    
    EXPECT_TRUE(oct1 == oct2);
    EXPECT_TRUE(sq1 == sq2);
    EXPECT_TRUE(tr1 == tr2);
}

TEST(ComparisonTest, DifferentSizes) {
    Octagon small(1.0);
    Octagon large(2.0);
    Square small_sq(1.0);
    Square large_sq(2.0);
    
    EXPECT_FALSE(small == large);
    EXPECT_FALSE(small_sq == large_sq);
}

TEST(ComparisonTest, DifferentTypesDifferentAreas) {
    Octagon oct(2.0); // Area ≈ 19.3137
    Square sq(2.0);   // Area = 4.0
    Triangle tr(2.0); // Area ≈ 1.732
    
    EXPECT_FALSE(oct == sq);
    EXPECT_FALSE(oct == tr);
    EXPECT_FALSE(sq == tr);
}

TEST(ComparisonTest, SameCenterDifferentSizes) {
    std::array<double, 2> center = {1.0, 1.0};
    Octagon small(1.0, center);
    Octagon large(2.0, center);
    
    EXPECT_FALSE(small == large);
}

TEST(ComparisonTest, DifferentCentersSameSize) {
    Octagon oct1(2.0, {0.0, 0.0});
    Octagon oct2(2.0, {1.0, 1.0});
    
    // Same size should mean same area, so they should be equal
    EXPECT_TRUE(oct1 == oct2);
}

TEST(ComparisonTest, SelfComparison) {
    Octagon oct(2.0);
    Square sq(3.0);
    
    EXPECT_TRUE(oct == oct);
    EXPECT_TRUE(sq == sq);
}

TEST(ComparisonTest, EdgeCaseVerySmallDifference) {
    // Test figures with areas that differ by slightly more than EPSILON
    Square sq1(1.0);        // Area = 1.0
    Square sq2(1.0 + EPSILON * 2); // Area ≈ 1.0 + 2e-7
    
    // Should not be equal since difference > EPSILON
    EXPECT_FALSE(sq1 == sq2);
}