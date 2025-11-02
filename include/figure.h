#pragma once
#include <array>
#include <vector>
#include <iostream>

#define EPSILON 0.0001

class Figure
{
protected:
    int num_vertexes;
    
    double side_length;
    std::array<double, 2> center;
    std::vector<std::array<double, 2>> vertices;

    Figure() = default;
    Figure(int num_vertexes);
    Figure(int num_vertexes, double side_length);
    Figure(int num_vertexes, double side_length, std::array<double, 2> center);

    std::array<double, 2> calculate_center();
    double calculate_side_length();
    std::vector<std::array<double, 2>> calculate_vertexes() const;

public:
    virtual ~Figure() = default;
      
    std::array<double, 2> get_center() const;

    virtual operator double() const = 0;
    bool operator == (const Figure& other) const;
    std::ostream& print(std::ostream& os) const;
    std::istream& read(std::istream& is);
};

std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);