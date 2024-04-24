#include <iostream>

struct IntArray
{
    // IntArray()
    // {
    //     std::cout << "IntArray()" << std::endl;
    // }

    explicit IntArray(size_t size)
        : size(size)
        , data(nullptr)
    {
        std::cout << "IntArray(size_t size)" << std::endl;
    }

    ~IntArray()
    {
        std::cout << "~IntArray()" << std::endl;
        delete[] data;
    }

    size_t size;
    int* data;
};

int main()
{
    IntArray* ia = new IntArray(5);
    delete ia;

    // IntArray* ia2 = new IntArray[5]; // Error, if default constructor doesn't exist
    // delete[] ia2;
    return 0;
}