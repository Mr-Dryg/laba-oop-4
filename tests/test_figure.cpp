#include <gtest/gtest.h>
#include "triangle.h"
#include "square.h"
#include "octagon.h"

TEST(FigureTest, TriangleArea) {
    Triangle<double> t(2.0);
    double area = static_cast<double>(t);
    EXPECT_GT(area, 0.0);
}

TEST(FigureTest, SquareArea) {
    Square<double> s(2.0);
    double area = static_cast<double>(s);
    EXPECT_EQ(area, 4.0);
}

TEST(FigureTest, OctagonArea) {
    Octagon<double> o(2.0);
    double area = static_cast<double>(o);
    EXPECT_GT(area, 0.0);
}

TEST(FigureTest, CrossTypeEquality) {
    // Разные фигуры с одинаковой площадью
    Triangle<double> t(std::sqrt(4.0 * 4.0 / std::sqrt(3.0))); // Подбираем сторону для площади = 4
    Square<double> s(2.0); // Площадь = 4
    
    // Из-за погрешности вычислений может потребоваться EPSILON
    EXPECT_NEAR(static_cast<double>(t), static_cast<double>(s), 0.0001);
}