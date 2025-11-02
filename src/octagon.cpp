#include "../include/octagon.h"
#include <cmath>

Octagon::Octagon() : Octagon(1.0) {}

Octagon::Octagon(double side_length) : Octagon(side_length, {0.0, 0.0}) {}

Octagon::Octagon(double side_length, std::array<double, 2> center) : Figure(NUM_OCTAGON_VERTEXES, side_length, center)
{
    vertices = calculate_vertexes();
}

Octagon::operator double() const
{
    return 2.0 * (1.0 + std::sqrt(2.0)) * side_length * side_length;
}
