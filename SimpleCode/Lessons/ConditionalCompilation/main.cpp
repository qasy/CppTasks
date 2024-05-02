#include <iostream>
#define DEBUG

int main()
{

#ifdef DEBUG
    std::cout << "Debug: Start of cycle For" << std::endl;
#endif // DEBUG

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

#ifdef DEBUG
    std::cout << "Debug: End of cycle For" << std::endl;
#endif // DEBUG

    return 0;
}