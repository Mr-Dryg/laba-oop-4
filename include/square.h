#pragma once
#include <array>
#include "figure.h"

#define NUM_SQUARE_VERTEXES 8

class Square: public Figure
{
protected:
    int num_vertexes = NUM_SQUARE_VERTEXES;

public:
    Square();
    Square(double side_length);
    Square(double side_length, std::array<double, 2> center);
    Square(std::array<double, 2> vertex_1, std::array<double, 2> vertex_2);
    
    ~Square() = default;

    operator double() const override;
};

