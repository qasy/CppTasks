#include <iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a       = *b;
    *b       = temp;
}

int main()
{
    char str[]            = "12345678";
    char b                = '\0';
    *((uint16_t*)str + 1) = 0;
    printf("%d\n", b);
    // int a = 5;
    // int b = 10;
    // std::cout << a << " " << b << std::endl;
    // swap(&a, &b);
    // std::cout << a << " " << b << std::endl;
    // return 0;
}