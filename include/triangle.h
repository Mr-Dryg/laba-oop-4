#pragma once
#include <array>
#include "figure.h"

#define NUM_TRIANGLE_VERTEXES 3

class Triangle: public Figure
{
protected:
    int num_vertexes = NUM_TRIANGLE_VERTEXES;

public:
    Triangle();
    Triangle(double side_length);
    Triangle(double side_length, std::array<double, 2> center);
    Triangle(std::array<double, 2> vertex_1, std::array<double, 2> vertex_2, std::array<double, 2> vertex_3);
    
    ~Triangle() = default;

    operator double() const override;
};

