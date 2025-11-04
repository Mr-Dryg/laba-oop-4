#pragma once
#include <array>
#include "figure.h"

#define NUM_TRIANGLE_VERTEXES 3

template<Scalar T>
class Triangle: public Figure<T>
{
protected:
    int num_vertexes = NUM_TRIANGLE_VERTEXES;

public:
    Triangle();
    Triangle(T side_length);
    Triangle(T side_length, Point<T> center);
    Triangle(Point<T> vertex_1, Point<T> vertex_2, Point<T> vertex_3);
    
    ~Triangle() = default;

    operator double() const override;
};

template<Scalar T>
Triangle<T>::Triangle() : Triangle(T(1)) {}

template<Scalar T>
Triangle<T>::Triangle(T side_length) : Triangle(side_length, Point<T>(T(0), T(0))) {}

template<Scalar T>
Triangle<T>::Triangle(T side_length, Point<T> center) : Figure<T>(NUM_TRIANGLE_VERTEXES, side_length, center)
{
    this->vertices = this->calculate_vertexes();
}

template<Scalar T>
Triangle<T>::Triangle(Point<T> vertex_1, Point<T> vertex_2, Point<T> vertex_3)
    : Figure<T>(NUM_TRIANGLE_VERTEXES)
{
    this->vertices[0] = vertex_1;
    this->vertices[1] = vertex_2;
    this->vertices[2] = vertex_3;
    this->center = this->calculate_center();
}

template<Scalar T>
Triangle<T>::operator double() const
{
    return std::sqrt(3.0) / 4.0 * this->side_length * this->side_length;
}
