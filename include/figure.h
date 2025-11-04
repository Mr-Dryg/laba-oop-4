#pragma once
#include "point.h"
#include <array>
#include <cmath>
#include <iostream>
#include <memory>

#define EPSILON 0.0001

template<Scalar T>
class Figure;

template<Scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure);

template<Scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure);

template<Scalar T>
class Figure
{
protected:
    int num_vertexes;
    
    T side_length;
    Point<T> center;
    std::unique_ptr<Point<T>[]> vertices;

    Figure() = default;
    Figure(int num_vertexes);
    Figure(int num_vertexes, T side_length);
    Figure(int num_vertexes, T side_length, Point<T> center);

    Point<T> calculate_center();
    T calculate_side_length();
    std::unique_ptr<Point<T>[]> calculate_vertexes() const;

public:
    virtual ~Figure() = default;
      
    Point<T> get_center() const;

    virtual operator double() const = 0;
    bool operator == (const Figure& other) const;

    friend std::ostream& operator<< <T>(std::ostream& os, const Figure<T>& figure);
    friend std::istream& operator>> <T>(std::istream& is, Figure<T>& figure);
};

template<Scalar T>
Figure<T>::Figure(int num_vertexes) : Figure(num_vertexes, T(1)) {}

template<Scalar T>
Figure<T>::Figure(int num_vertexes, T side_length)
    : Figure(num_vertexes, side_length, Point<T>(T(0), T(0))) {}

template<Scalar T>
Figure<T>::Figure(int num_vertexes, T side_length, Point<T> center)
    : num_vertexes(num_vertexes), side_length(side_length), center(center)
{
    vertices = std::make_unique<Point<T>[]>(num_vertexes);
}

template<Scalar T>
Point<T> Figure<T>::calculate_center()
{
    T sum_x = 0, sum_y = 0;
    for (int i = 0; i < num_vertexes; i++)
    {
        sum_x += vertices[i].x;
        sum_y += vertices[i].y;
    }
    return Point<T>(sum_x / num_vertexes, sum_y / num_vertexes);
}

template<Scalar T>
T Figure<T>::calculate_side_length(void)
{
    T dx = vertices[0].x - vertices[1].x;
    T dy = vertices[0].y - vertices[1].y;
    return std::sqrt(dx * dx + dy * dy);
}

template<Scalar T>
std::unique_ptr<Point<T>[]> Figure<T>::calculate_vertexes() const
{
    double R = side_length / (2 * sin(M_PI / num_vertexes));
    double angle = 0.0;
    double d_angle = 2 * M_PI / num_vertexes;
    std::unique_ptr<Point<T>[]> vertices = std::make_unique<Point<T>[]>(num_vertexes);

    for (int i = 0; i < num_vertexes; i++)
    {
        vertices[i] = Point<T>(center.x + R * cos(angle), center.y + R * sin(angle));
        angle += d_angle;
    }
    return vertices;
}

template<Scalar T>
Point<T> Figure<T>::get_center() const
{
    return center;
}

template<Scalar T>
bool Figure<T>::operator == (const Figure<T>& other) const
{
    return std::abs(double(*this) - double(other)) < EPSILON;
}

template<Scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure)
{
    for (int i = 0; i < figure.num_vertexes; i++)
    {
        os << figure.vertices[i];
        if (i < figure.num_vertexes - 1) os << " ";
    }
    return os;
}

template<Scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure)
{
    for (int i = 0; i < figure.num_vertexes; i++)
    {
        is >> figure.vertices[i];
    }
    figure.center = figure.calculate_center();
    figure.side_length = figure.calculate_side_length();
    return is;
}
