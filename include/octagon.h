#pragma once
#include <array>
#include "figure.h"

#define NUM_OCTAGON_VERTEXES 8

template<Scalar T>
class Octagon: public Figure<T>
{
protected:
    int num_vertexes = NUM_OCTAGON_VERTEXES;

public:
    Octagon();
    Octagon(T side_length);
    Octagon(T side_length, Point<T> center);
    
    ~Octagon() = default;

    operator double() const override;
};

template<Scalar T>
Octagon<T>::Octagon() : Octagon(T(1)) {}

template<Scalar T>
Octagon<T>::Octagon(T side_length) : Octagon(side_length, Point<T>(T(0), T(0))) {}

template<Scalar T>
Octagon<T>::Octagon(T side_length, Point<T> center) : Figure<T>(NUM_OCTAGON_VERTEXES, side_length, center)
{
    this->vertices = this->calculate_vertexes();
}

template<Scalar T>
Octagon<T>::operator double() const
{
    return 2.0 * (1.0 + std::sqrt(2.0)) * this->side_length * this->side_length;
}
