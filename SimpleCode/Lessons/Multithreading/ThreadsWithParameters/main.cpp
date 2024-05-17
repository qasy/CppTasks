#include <chrono>
#include <iostream>
#include <mutex>
#include <ranges>
#include <string>
#include <thread>

/*
    Многопоточное программирование
    Передача параметров в поток
    Получение результата из потока по ссылке
*/

void SumOnRef(int a, int b, int& result)
{

    std::cout << "thread id: " << std::this_thread::get_id() << " Start calculation..."
              << " Sum() " << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    result = a + b;
    std::cout << "thread id: " << std::this_thread::get_id() << " End calculation!" << std::endl;
}

void SumOnPtr(int a, int b, int* result)
{

    std::cout << "thread id: " << std::this_thread::get_id() << " Start calculation..."
              << " Sum() " << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    *result = a + b;
    std::cout << "thread id: " << std::this_thread::get_id() << " End calculation!" << std::endl;
}

int main()
{
    int result;
    std::thread th1(SumOnRef, 1, 1, std::ref(result));
    // std::thread th2(SumOnPtr, 1, 1, &result);

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "thread id: " << std::this_thread::get_id() << " main() " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    th1.join();
    // th1.detach();
    // th2.join();
    std::cout << "Result from another thread: " << result << std::endl;

    return 0;
}