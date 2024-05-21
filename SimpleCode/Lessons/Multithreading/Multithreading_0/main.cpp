#include <chrono>
#include <iostream>
#include <thread>

void DoWork()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << std::this_thread::get_id() << " DoWork"
                  << " " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds{700});
    }
}

int main()
{
    std::thread th(DoWork);
    // th.detach();

    for (int i = 0; i < 5; ++i)
    {
        std::cout << std::this_thread::get_id() << " Main"
                  << " " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds{300});
    }

    th.join();

    return 0;
}