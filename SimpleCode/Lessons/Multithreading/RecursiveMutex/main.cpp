#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::recursive_mutex rmtx;

void Foo(int a)
{
    rmtx.lock();
    std::cout << a << " ";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    if (a <= 1)
    {
        std::cout << std::endl;
        rmtx.unlock();
        return;
    }

    --a;
    Foo(a);

    rmtx.unlock();
}

int main()
{
    std::thread t1(&Foo, 5);
    std::thread t2(&Foo, 10);

    t1.join();
    t2.join();

    // Foo(5);

    return 0;
}