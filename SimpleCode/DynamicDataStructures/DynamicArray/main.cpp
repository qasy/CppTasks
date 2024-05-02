#include <iostream>

void FillArray(int* const p, const size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        p[i] = rand() % 100;
    }
}

void PrintArray(int const* const p, const size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

void push_back(int*& p, size_t& size, const int value)
{
    size_t newSize = size + 1;
    int* newArray  = new int[newSize];

    for (size_t i = 0; i < size; ++i)
    {
        newArray[i] = p[i];
    }
    delete[] p;
    newArray[newSize - 1] = value;
    p                     = newArray;
    size                  = newSize;
}

int pop_back(int*& p, size_t& size)
{
    size_t newSize = size - 1;
    int* newArray  = new int[newSize];

    for (size_t i = 0; i < newSize; ++i)
    {
        newArray[i] = p[i];
    }

    PrintArray(newArray, newSize);
    int returnValue = p[size - 1];
    delete[] p;
    p    = newArray;
    size = newSize;
    return returnValue;
}

int main()
{
    size_t size = 10;
    int* pa     = new int[size];

    FillArray(pa, size);
    PrintArray(pa, size);

    std::cout << "Before: " << pa << std::endl;
    push_back(pa, size, 100);
    std::cout << "After: " << pa << std::endl;
    PrintArray(pa, size);
    std::cout << pop_back(pa, size) << std::endl;
    PrintArray(pa, size);

    delete[] pa;

    return 0;
}