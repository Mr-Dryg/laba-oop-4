#include "../include/figure.h"
#include <array>
#include <cmath>

Figure::Figure(int num_vertexes) : Figure(num_vertexes, 1.0) {}

Figure::Figure(int num_vertexes, double side_length) : Figure(num_vertexes, side_length, {0.0, 0.0}) {}

Figure::Figure(int num_vertexes, double side_length, std::array<double, 2> center)
    : num_vertexes(num_vertexes), side_length(side_length), center(center)
{
    vertices.resize(num_vertexes);
}

std::array<double, 2> Figure::calculate_center()
{
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < num_vertexes; i++)
    {
        sum_x += vertices[i][0];
        sum_y += vertices[i][1];
    }
    return {sum_x / num_vertexes, sum_y / num_vertexes};
}

double Figure::calculate_side_length(void)
{
    double dx = vertices[0][0] - vertices[1][0];
    double dy = vertices[0][1] - vertices[1][1];
    return std::sqrt(dx * dx + dy * dy);
}

std::vector<std::array<double, 2>> Figure::calculate_vertexes() const
{
    double R = side_length / (2 * sin(M_PI / num_vertexes));
    double angle = 0.0;
    double d_angle = 2 * M_PI / num_vertexes;
    std::vector<std::array<double, 2>> vertices;
    vertices.resize(num_vertexes);

    for (int i = 0; i < num_vertexes; i++)
    {
        vertices[i] = {center[0] + R * cos(angle), center[1] + R * sin(angle)};
        angle += d_angle;
    }
    return vertices;
}

std::ostream& Figure::print(std::ostream& os) const
{
    for (int i = 0; i < num_vertexes; i++)
    {
        os << vertices[i][0] << " " << vertices[i][1];
        if (i < num_vertexes - 1) os << " ";
    }
    return os;
}

std::istream& Figure::read(std::istream& is)
{
    for (int i = 0; i < num_vertexes; i++)
    {
        is >> vertices[i][0] >> vertices[i][1];
    }
    center = calculate_center();
    side_length = calculate_side_length();
    return is;
}

std::array<double, 2> Figure::get_center() const
{
    return center;
}

bool Figure::operator == (const Figure& other) const
{
    return std::abs(double(*this) - double(other)) < EPSILON;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure)
{
    return figure.print(os);
}

std::istream& operator>>(std::istream& is, Figure& figure)
{
    return figure.read(is);
}