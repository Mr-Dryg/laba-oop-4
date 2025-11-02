#include "figure.h"
#include <array>

#define DEFAULT_SIZE 10

class MyArray
{
private:
    int max_size;
    int size = 0;
    Figure** buf = nullptr;
    
public:
    MyArray();
    MyArray(int max_size);

    ~MyArray();

    bool push_back(Figure* figure);
    Figure* get(int i);
    Figure* pop(int i);

    double sum(void);
};