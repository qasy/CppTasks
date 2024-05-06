#include <iostream>

int factorial(int a)
{
    if (a == 0)
        return 1;

    return a * factorial(a - 1);
}

int main()
{
    std::cout << factorial(5) << std::endl;

    return 0;
}