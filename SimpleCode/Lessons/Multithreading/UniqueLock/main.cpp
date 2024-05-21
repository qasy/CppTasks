#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

/*
    Многопоточность
    Разделяемые ресурсы - в данном случае это консоль
    std::unique_lock
*/

std::mutex mtx;
// void Print(char ch)
// {
//     std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // имитация долгой логики

//     {
//         std::lock_guard guard(mtx); // mtx.lock()
//         {
//             for (int i = 0; i < 5; ++i)
//             {
//                 for (int j = 0; j < 5; ++j)
//                 {
//                     std::this_thread::sleep_for(std::chrono::milliseconds(20));
//                     std::cout << ch << " ";
//                 }
//                 std::cout << std::endl;
//             }
//         }
//     } // mtx.unlock()

//     std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // имитация долгой логики
// }

void Print(char ch)
{

    std::unique_lock<std::mutex> ul(mtx, std::defer_lock);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // имитация долгой логики

    ul.lock(); // mtx.lock() - синхронизация доступа к ресурсам

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }

    ul.unlock(); // mtx.unlock()

    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // имитация долгой логики
}

int main()
{
    std::thread t1(&Print, '*');
    std::thread t2(&Print, '-');

    t1.join();
    t2.join();

    return 0;
}