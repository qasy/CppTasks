#include <chrono>
#include <iostream>
#include <mutex>
#include <ranges>
#include <string>
#include <thread>

int Sum(int a, int b)
{
    std::cout << "thread id: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    int result = a + b;
    return result;
}

int main()
{

    int result;
    std::thread t([&result]() { result = Sum(10, 20); });

    for (int i = 0; i < 20; ++i)
    {
        std::cout << "thread id: " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    t.join();
    std::cout << result << std::endl;
    return 0;
}