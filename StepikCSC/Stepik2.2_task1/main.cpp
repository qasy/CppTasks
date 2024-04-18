#include <iostream>

using namespace std;

void recursive_func()
{
    unsigned int a;
    std::cin >> a;
    if (a == 0)
    {
        return;
    }
    recursive_func();
    std::cout << a << " ";
}

int main()
{
    recursive_func();
    return 0;
}