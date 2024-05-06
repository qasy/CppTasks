#include <iostream>

int recursive_func(int a)
{
    std::cout << "Call recursive() with value: " << a << std::endl;
    if (a < 1)
        return 0;

    --a;
    return recursive_func(a);
}

int main()
{
    recursive_func(5);
    return 0;
}