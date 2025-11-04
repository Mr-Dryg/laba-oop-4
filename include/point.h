#include <array>
#include <iostream>
#include <concepts>

template <typename T>
concept Scalar = requires(T t){
	requires std::is_scalar_v<T>;
};

template<Scalar T>
class Point;

template<Scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point)
{
    os << point.x << ' ' << point.y;
    return os;
}

template<Scalar T>
std::istream& operator>>(std::istream& is, Point<T>& point)
{
    is >> point.x >> point.y;
    return is;
}

template <Scalar T>
class Point
{
public:
    T x;
    T y;

    Point() = default;
	Point(T x, T y) : x(x), y(y) {}
    Point(std::array<T, 2> point) : x(point[0]), y(point[1]) {}

    friend std::ostream& operator<< <T>(std::ostream& os, const Point<T>& figure);
    friend std::istream& operator>> <T>(std::istream& is, Point<T>& figure);
};
