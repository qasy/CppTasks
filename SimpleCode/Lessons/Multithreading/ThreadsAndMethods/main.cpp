#include <chrono>
#include <iostream>
#include <mutex>
#include <ranges>
#include <string>
#include <thread>

class TwoValuesSummator
{
public:
    TwoValuesSummator() = delete;
    TwoValuesSummator(int a, int b)
    {
        frstValue = a;
        scndValue = b;
    }
    ~TwoValuesSummator() = default;
    // TwoValuesSummator(const TwoValuesSummator& m)                = delete;
    // TwoValuesSummator& operator=(const TwoValuesSummator& m)     = delete;
    // TwoValuesSummator(TwoValuesSummator&& m) noexcept            = delete;
    // TwoValuesSummator& operator=(TwoValuesSummator&& m) noexcept = delete;

    void Sum(int* result)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "Thread Id: " << std::this_thread::get_id() << " start Sum()" << std::endl;
        *result = frstValue + scndValue;
        std::cout << *result << std::endl;
    }

private:
    int frstValue;
    int scndValue;
};

int main()
{
    int result1;
    int result2;
    TwoValuesSummator s1(10, 20);
    TwoValuesSummator s2(20, 30);

    std::thread t(&TwoValuesSummator::Sum, s2, &result2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    s1.Sum(&result1);

    std::cout << "In main result1:" << result1 << std::endl;
    std::cout << "In main result2:" << result2 << std::endl;
    t.join();

    return 0;
}