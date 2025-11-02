#include <concepts>

template <typename T>
concept Scalar = requires(T t){
	requires std::is_scalar_v<T>;
};

template <OutputStreamable T>
class Point
{
    T x;
    T y;

    Point() = default;
	
	Point(T x, T y) : x(x), y(y) {}
};