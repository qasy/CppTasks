#include <iostream>

#define DEBUG
#ifdef DEBUG
#define DEBUG_LEVEL 5
#endif

int main()
{

#ifdef DEBUG
#if DEBUG_LEVEL > 2
    std::cout << "Debug level is: " << DEBUG_LEVEL << " Start of cycle For" << std::endl;
#elif DEBUG_LEVEL > 1
    std::cout << "Debug level is: " << DEBUG_LEVEL << " Start of cycle For" << std::endl;
#else
    std::cout << "Debug is off:" << std::endl;
#endif
#endif // DEBUG

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

#ifdef DEBUG
    std::cout << "Debug is on: End of cycle For" << std::endl;
#else
    std::cout << "Debug is off:" << std::endl;
#endif // DEBUG

    return 0;
}