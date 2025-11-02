#include <gtest/gtest.h>
#include "../include/array.h"
#include "../include/octagon.h"
#include "../include/square.h"
#include "../include/triangle.h"

TEST(ArrayTest, DefaultConstructor) {
    MyArray arr;
    EXPECT_EQ(arr.sum(), 0.0);
}

TEST(ArrayTest, CustomSizeConstructor) {
    MyArray arr(5);
    EXPECT_EQ(arr.sum(), 0.0);
}

TEST(ArrayTest, PushBackAndSum) {
    MyArray arr(3);
    
    Octagon* oct = new Octagon(1.0);
    Square* sq = new Square(2.0);
    Triangle* tr = new Triangle(3.0);
    
    arr.push_back(oct);
    arr.push_back(sq);
    arr.push_back(tr);
    
    double total = double(*oct) + double(*sq) + double(*tr);
    EXPECT_NEAR(arr.sum(), total, 0.0001);
}

TEST(ArrayTest, GetMethod) {
    MyArray arr(2);
    Square* sq = new Square(2.0);
    arr.push_back(sq);
    
    Figure* retrieved = arr.get(0);
    EXPECT_EQ(retrieved, sq);
    EXPECT_EQ(arr.get(1), nullptr);
}

TEST(ArrayTest, PopMethod) {
    MyArray arr(3);
    
    Octagon* oct = new Octagon(1.0);
    Square* sq = new Square(2.0);
    Triangle* tr = new Triangle(3.0);
    
    arr.push_back(oct);
    arr.push_back(sq);
    arr.push_back(tr);
    
    Figure* popped = arr.pop(1);
    EXPECT_EQ(popped, sq);
    EXPECT_EQ(arr.get(1), tr);
    EXPECT_EQ(arr.get(2), nullptr);
}

TEST(ArrayTest, OverflowHandling) {
    MyArray arr(2);
    
    Octagon* oct1 = new Octagon(1.0);
    Octagon* oct2 = new Octagon(2.0);
    Octagon* oct3 = new Octagon(3.0);
    
    EXPECT_TRUE(arr.push_back(oct1));
    EXPECT_TRUE(arr.push_back(oct2));
    EXPECT_FALSE(arr.push_back(oct3));
}