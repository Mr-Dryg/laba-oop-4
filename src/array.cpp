#include "../include/array.h"

MyArray::MyArray() : MyArray::MyArray(DEFAULT_SIZE) {}

MyArray::MyArray(int max_size) : max_size(max_size), buf(new Figure*[max_size])
{
    for (int i = 0; i < max_size; i++) {
        buf[i] = nullptr;
    }
}

MyArray::~MyArray()
{
    for (int i = 0; i < size; i++) {
        delete buf[i];
    }
    delete[] buf;
}

bool MyArray::push_back(Figure* figure)
{
    if (size >= max_size) return false;
    buf[size++] = figure;
    return true;
}

Figure* MyArray::get(int i)
{
    if (0 <= i && i < size)
        return buf[i];
    return nullptr;
}

Figure* MyArray::pop(int i)
{
    if (!(0 <= i && i < size))
        return nullptr;
    Figure* res = buf[i];
    buf[i] = nullptr;
    size--;
    for (int j = i; j < size; j++)
    {
        buf[j] = buf[j + 1];
        buf[j + 1] = nullptr;
    }
    return res;
}

double MyArray::sum(void)
{
    double res = 0.0;
    for (int i = 0; i < size; i++)
        res += double(*buf[i]);
    return res;
}
