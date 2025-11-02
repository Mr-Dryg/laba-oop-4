#pragma once
#include <array>
#include "figure.h"

#define NUM_OCTAGON_VERTEXES 8

class Octagon: public Figure
{
protected:
    int num_vertexes = NUM_OCTAGON_VERTEXES;

public:
    Octagon();
    Octagon(double side_length);
    Octagon(double side_length, std::array<double, 2> center);
    
    ~Octagon() = default;

    operator double() const override;
};

