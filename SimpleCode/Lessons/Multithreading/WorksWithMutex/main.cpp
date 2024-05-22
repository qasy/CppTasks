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

std::mutex mtx;

void Print(char ch)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    // mtx.lock();
    {
        std::lock_guard<std::mutex> lg(mtx);
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                std::cout << ch << " ";
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }
    // mtx.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
int main()
{
    TimeCounter tc;
    std::thread t1(&Print, '*');
    std::thread t2(&Print, '-');

    t1.join();
    t2.join();

    // Print('*');
    // Print('-');
    return 0;
}