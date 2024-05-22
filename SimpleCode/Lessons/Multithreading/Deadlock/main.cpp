#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

class TimeCounter
{
public:
    TimeCounter()
    {
        begin_time = std::chrono::steady_clock::now();
    }
    ~TimeCounter()
    {
        end_time = std::chrono::steady_clock::now();
        std::cout << "Time elapsed: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count() << std::endl;
    }

private:
    std::chrono::steady_clock::time_point begin_time{};
    std::chrono::steady_clock::time_point end_time{};
};

std::mutex mtx1;
std::mutex mtx2;

void Print1(char ch)
{
    mtx2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mtx1.lock();

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cout << ch << " ";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << std::endl;
    }

    mtx1.unlock();
    mtx2.unlock();
}

void Print2(char ch)
{
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mtx2.lock();

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cout << ch << " ";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << std::endl;
    }

    mtx1.unlock();
    mtx2.unlock();
}
int main()
{
    TimeCounter tc;
    std::thread t1(&Print1, '*');
    std::thread t2(&Print2, '-');

    t1.join();
    t2.join();

    // Print('*');
    // Print('-');
    return 0;
}