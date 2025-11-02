#include "../include/square.h"
#include <cmath>
#include <stdexcept>

Square::Square() : Square(1.0) {}

Square::Square(double side_length) : Square(side_length, {0.0, 0.0}) {}

Square::Square(double side_length, std::array<double, 2> center) : Figure(NUM_SQUARE_VERTEXES, side_length, center)
{
    vertices = calculate_vertexes();
}

Square::Square(std::array<double, 2> vertex_1, std::array<double, 2> vertex_2) : Figure(NUM_SQUARE_VERTEXES)
{  
    double dx = vertex_1[0] - vertex_2[0];
    double dy = vertex_1[1] - vertex_2[1];
    double diagonal = std::sqrt(dx * dx + dy * dy);
    side_length = diagonal / std::sqrt(2);
    vertices = {
        vertex_1,
        vertex_2,
        {vertex_1[0] + side_length, vertex_1[1]},
        {vertex_1[0], vertex_1[1] + side_length}
    };
    center = calculate_center();
}

Square::operator double() const
{
    return side_length * side_length;
}
