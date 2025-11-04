#include "figure.h"
#include <array>
#include <memory>

#define DEFAULT_SIZE 10
#define GROW_SIZE 2

template<typename T>
class MyArray
{
private:
    int max_size;
    int size = 0;
    std::shared_ptr<std::shared_ptr<T>[]> buf;

    void grow(int new_max_size);
    
public:
    MyArray();
    MyArray(int max_size);

    ~MyArray() = default;

    void push_back(std::shared_ptr<T> figure);
    std::shared_ptr<T> get(int i);
    std::shared_ptr<T> pop(int i);

    double sum(void);
};

template<typename T>
MyArray<T>::MyArray() : MyArray::MyArray(DEFAULT_SIZE) {}

template<typename T>
MyArray<T>::MyArray(int max_size)
    : max_size(max_size), buf(std::make_shared<std::shared_ptr<T>[]>(max_size)) {}

template<typename T>
void MyArray<T>::grow(int new_max_size)
{
    if (new_max_size <= max_size) return;
    std::shared_ptr<std::shared_ptr<T>[]> new_buf(std::make_shared<std::shared_ptr<T>[]>(new_max_size));
    for (int i = 0; i < size; i++)
    {
        new_buf[i] = std::move(buf[i]);
    }
    buf = std::move(new_buf);
    max_size = new_max_size;
}

template<typename T>
void MyArray<T>::push_back(std::shared_ptr<T> figure)
{
    if (size >= max_size) grow(max_size * GROW_SIZE);
    buf[size++] = figure;
}

template<typename T>
std::shared_ptr<T> MyArray<T>::get(int i)
{
    if (0 <= i && i < size)
        return buf[i];
    return nullptr;
}

template<typename T>
std::shared_ptr<T> MyArray<T>::pop(int i)
{
    if (!(0 <= i && i < size))
        return nullptr;
    std::shared_ptr<T> res = buf[i];
    for (int j = i; j < size; j++)
    {
        buf[j] = buf[j + 1];
    }
    buf[--size] = nullptr;
    return res;
}

template<typename T>
double MyArray<T>::sum(void)
{
    double res = 0.0;
    for (int i = 0; i < size; i++)
        res += double(*buf[i]);
    return res;
}
