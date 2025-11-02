#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include "../include/octagon.h"
#include "../include/square.h"
#include "../include/triangle.h"

TEST(IOTest, OctagonStreamOperators) {
    Octagon original(2.0, {1.0, 2.0});
    std::stringstream ss;
    
    // Test output operator
    ss << original;
    
    // Test input operator
    Octagon read_octagon;
    ss >> read_octagon;
    
    // Verify they are equal
    EXPECT_TRUE(original == read_octagon);
    
    // Verify area is the same
    EXPECT_NEAR(double(original), double(read_octagon), 0.0001);
}

TEST(IOTest, SquareStreamOperators) {
    Square original(3.0, {2.0, 3.0});
    std::stringstream ss;
    
    ss << original;
    
    Square read_square;
    ss >> read_square;
    
    EXPECT_TRUE(original == read_square);
    EXPECT_NEAR(double(original), double(read_square), 0.0001);
}

TEST(IOTest, TriangleStreamOperators) {
    Triangle original(4.0, {3.0, 4.0});
    std::stringstream ss;
    
    ss << original;
    
    Triangle read_triangle;
    ss >> read_triangle;
    
    EXPECT_TRUE(original == read_triangle);
    EXPECT_NEAR(double(original), double(read_triangle), 0.0001);
}

TEST(IOTest, FileOperations) {
    // Write to file
    std::ofstream outfile("test_figures.txt");
    Octagon oct(2.0, {1.0, 1.0});
    Square sq(3.0, {2.0, 2.0});
    
    outfile << oct << "\n";
    outfile << sq << "\n";
    outfile.close();
    
    // Read from file
    std::ifstream infile("test_figures.txt");
    Octagon read_oct;
    Square read_sq;
    
    infile >> read_oct >> read_sq;
    infile.close();
    
    // Verify
    EXPECT_TRUE(oct == read_oct);
    EXPECT_TRUE(sq == read_sq);
    
    // Clean up
    remove("test_figures.txt");
}

TEST(IOTest, MultipleFiguresInStream) {
    Octagon oct(1.0);
    Square sq(2.0);
    Triangle tr(3.0);
    
    std::stringstream ss;
    ss << oct << " " << sq << " " << tr;
    
    Octagon read_oct;
    Square read_sq;
    Triangle read_tr;
    
    ss >> read_oct >> read_sq >> read_tr;
    
    EXPECT_TRUE(oct == read_oct);
    EXPECT_TRUE(sq == read_sq);
    EXPECT_TRUE(tr == read_tr);
}