#pragma once
#include <array>
#include "figure.h"

#define NUM_SQUARE_VERTEXES 4

template<Scalar T>
class Square: public Figure<T>
{
protected:
    int num_vertexes = NUM_SQUARE_VERTEXES;

public:
    Square();
    Square(T side_length);
    Square(T side_length, Point<T> center);
    Square(Point<T> vertex_1, Point<T> vertex_2);
    
    ~Square() = default;

    operator double() const override;
};

#include <cmath>

template<Scalar T>
Square<T>::Square() : Square(T(1)) {}

template<Scalar T>
Square<T>::Square(T side_length) : Square(side_length, Point<T>(T(0), T(0))) {}

template<Scalar T>
Square<T>::Square(T side_length, Point<T> center) : Figure<T>(NUM_SQUARE_VERTEXES, side_length, center)
{
    this->vertices = this->calculate_vertexes();
}

template<Scalar T>
Square<T>::Square(Point<T> vertex_1, Point<T> vertex_2) : Figure<T>(NUM_SQUARE_VERTEXES)
{  
    T dx = vertex_1.x - vertex_2.x;
    T dy = vertex_1.y - vertex_2.y;
    T diagonal = std::sqrt(dx * dx + dy * dy);
    this->side_length = diagonal / std::sqrt(2);
    this->vertices[0] = vertex_1;
    this->vertices[1] = vertex_2;
    this->vertices[2] = Point<T>(vertex_1.x + this->side_length, vertex_1.y);
    this->vertices[3] = Point<T>(vertex_1.x, vertex_1.y + this->side_length);
    this->center = this->calculate_center();
}

template<Scalar T>
Square<T>::operator double() const
{
    return this->side_length * this->side_length;
}
