#include <gtest/gtest.h>
#include <memory>
#include "array.h"
#include "octagon.h"
#include "square.h"
#include "triangle.h"

TEST(MyArrayTest, DefaultConstructor) {
    MyArray<Triangle<double>> arr;
    EXPECT_DOUBLE_EQ(arr.sum(), 0.0);
}

TEST(MyArrayTest, SizeConstructor) {
    MyArray<Triangle<double>> arr(20);
    EXPECT_DOUBLE_EQ(arr.sum(), 0.0);
}

TEST(MyArrayTest, PushBackAndGet) {
    MyArray<Triangle<double>> arr;
    auto triangle = std::make_shared<Triangle<double>>(1.0);
    
    arr.push_back(triangle);
    auto retrieved = arr.get(0);
    
    EXPECT_TRUE(retrieved != nullptr);
    EXPECT_NEAR(static_cast<double>(*retrieved), std::sqrt(3.0)/4.0, 0.001);
}

TEST(MyArrayTest, PushBackMultiple) {
    MyArray<Triangle<double>> arr(2);
    
    for(int i = 0; i < 5; ++i) {
        auto triangle = std::make_shared<Triangle<double>>(1.0);
        arr.push_back(triangle);
    }
    
    EXPECT_DOUBLE_EQ(arr.sum(), 5 * (std::sqrt(3.0)/4.0));
}

TEST(MyArrayTest, PopElement) {
    MyArray<Triangle<double>> arr;
    auto triangle1 = std::make_shared<Triangle<double>>(1.0);
    auto triangle2 = std::make_shared<Triangle<double>>(2.0);
    
    arr.push_back(triangle1);
    arr.push_back(triangle2);
    
    double initialSum = arr.sum();
    auto popped = arr.pop(0);
    
    EXPECT_TRUE(popped != nullptr);
    EXPECT_NEAR(static_cast<double>(*popped), std::sqrt(3.0)/4.0, 0.001);
    EXPECT_NEAR(arr.sum(), static_cast<double>(*triangle2), 0.001);
}

TEST(MyArrayTest, PopInvalidIndex) {
    MyArray<Triangle<double>> arr;
    auto triangle = std::make_shared<Triangle<double>>(1.0);
    arr.push_back(triangle);
    
    auto popped = arr.pop(5);
    EXPECT_TRUE(popped == nullptr);
    
    popped = arr.pop(-1);
    EXPECT_TRUE(popped == nullptr);
}

TEST(MyArrayTest, GetInvalidIndex) {
    MyArray<Triangle<double>> arr;
    auto triangle = std::make_shared<Triangle<double>>(1.0);
    arr.push_back(triangle);
    
    auto result = arr.get(5);
    EXPECT_TRUE(result == nullptr);
    
    result = arr.get(-1);
    EXPECT_TRUE(result == nullptr);
}

TEST(MyArrayTest, MixedFiguresSum) {
    MyArray<Figure<double>> arr;
    
    auto triangle = std::make_shared<Triangle<double>>(1.0);
    auto square = std::make_shared<Square<double>>(1.0);
    auto octagon = std::make_shared<Octagon<double>>(1.0);
    
    arr.push_back(triangle);
    arr.push_back(square);
    arr.push_back(octagon);
    
    double totalArea = arr.sum();
    double expected = (std::sqrt(3.0)/4.0) + 1.0 + (2.0 * (1.0 + std::sqrt(2.0)));
    
    EXPECT_NEAR(totalArea, expected, 0.001);
}