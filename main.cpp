#include <iostream>
#include <string>

int main()
{
    // const int size = 5;
    // int arr[size]{1, 5, 7, 10};

    int a   = 5;
    int& ra = a;
    std::cout << &a << std::endl;
    std::cout << &ra << std::endl;

    return 0;
}