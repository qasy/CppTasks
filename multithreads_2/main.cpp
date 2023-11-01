#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <numeric>
#include <string>
#include <thread>
#include <vector>

void printVector(const std::vector<int>& v);

class TimeElapsed
{
public:
    TimeElapsed()
    {
        m_start_time = std::chrono::high_resolution_clock::now();
    }

    ~TimeElapsed()
    {
        m_stop_time = std::chrono::high_resolution_clock::now();
        auto ms     = std::chrono::duration_cast<std::chrono::milliseconds>(m_stop_time - m_start_time);
        std::cout << "TimeElapsed: " << ms.count() << std::endl;
    }
    std::chrono::_V2::system_clock::time_point m_start_time;
    std::chrono::_V2::system_clock::time_point m_stop_time;
};

// std::mutex m;

// struct X
// {
//     void foo(int i, const std::string& str)
//     {
//         std::lock_guard<std::mutex> lk(m);
//         std::cout << str << ' ' << i << '\n';
//     }

//     void bar(const std::string& str)
//     {
//         std::lock_guard<std::mutex> lk(m);
//         std::cout << str << '\n';
//     }

//     int operator()(int i)
//     {
//         std::lock_guard<std::mutex> lk(m);
//         std::cout << i << '\n';
//         return i + 10;
//     }
// };

// int parallel_sum(std::vector<int>::iterator start, std::vector<int>::iterator end)
// {
//     m.lock();

//     m.unlock();
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     auto len = end - start;
//     if (len < 1000)
//     {
//         std::cout << "Call std::accumulate" << std::endl;
//         ++t_counter;
//         return std::accumulate(start, end, 0);
//     }

//     std::vector<int>::iterator mid = start + len / 2;

//     std::future<int> handle = std::async(std::launch::async, parallel_sum, mid, end);
//     int sum                 = parallel_sum(start, mid);
//     ++t_counter;
//     return sum + handle.get();
// }

int increment(const std::vector<int>& v, int idx)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    int num = v[idx];
    for (size_t i = 0; i < 100; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        num = num * num;
    }

    return num;
}

int randomInt()
{
    int a = (((double)rand() / (double)RAND_MAX) * 1000.0);
    return a;
}

int main()
{

    TimeElapsed tm;
    size_t num_threads = 4;
    std::vector<int> v(num_threads, randomInt());
    // std::vector<std::future<int>> results(num_threads);

    // for (size_t t = 0; t < num_threads; ++t)
    // {
    //     results[t] = std::async(std::launch::async, increment, v, t);
    // }
    // for (size_t t = 0; t < num_threads; ++t)
    // {
    //     v[t] = results[t].get();
    // }

    printVector(v);

    // X x;
    // // Calls (&x)->foo(42, "Hello") with default policy:
    // // may print "Hello 42" concurrently or defer execution
    // auto a1 = std::async(&X::foo, &x, 42, "Hello");
    // // Calls x.bar("world!") with deferred policy
    // // prints "world!" when a2.get() or a2.wait() is called
    // auto a2 = std::async(std::launch::deferred, &X::bar, x, "world!");
    // // Calls X()(43); with async policy
    // // prints "43" concurrently
    // auto a3 = std::async(std::launch::async, X(), 43);
    // a2.wait();                     // prints "world!"
    // std::cout << a3.get() << '\n'; // prints "53"

    // size_t tx = 0;
    // size_t nf = 0;
    // size_t rx = 0;
    // size_t ax = 0;
    // int i     = 1;
    // while (getNextRxData(tx, nf, rx, ax))
    // {
    //     std::cout << "i:\t" << i << "\ttx:\t" << tx << "\tnf:\t" << nf << "\trx:\t" << rx << "\tax:\t" << ax <<
    //     "\tAMP"
    //               << std::endl;
    //     ++i;
    //     std::cout << "i:\t" << i << "\ttx:\t" << tx << "\tnf:\t" << nf << "\trx:\t" << rx << "\tax:\t" << ax <<
    //     "\tPHI"
    //               << std::endl;
    //     ++i;
    // }
} // if a1 is not done at this point, destructor of a1 prints "Hello 42" here

// void accumulate(size_t time,
//                 std::vector<int>::iterator first,
//                 std::vector<int>::iterator last,
//                 std::promise<int> accumulate_promise)
// {
//     // std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
//     int sum = std::accumulate(first, last, 0);
//     std::this_thread::sleep_for(std::chrono::milliseconds(time));
//     accumulate_promise.set_value(sum); // Notify future
// }

// // g++ ./main.cpp -o main -pthread -std=c++17
// int main()
// {
//     TimeElapsed tm;
//     std::mutex mtx;
//     // Demonstrate using promise<int> to transmit a result between threads.
//     auto start_time          = std::chrono::high_resolution_clock::now();
//     auto stop_time           = std::chrono::high_resolution_clock::now();
//     std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
//     std::promise<int> accumulate_promise1;
//     std::promise<int> accumulate_promise2;
//     std::future<int> accumulate_future1 = accumulate_promise1.get_future();
//     std::future<int> accumulate_future2 = accumulate_promise2.get_future();

//     std::cout << "create thread 1" << std::endl;
//     std::thread thread1(accumulate, 5000, numbers.begin(), numbers.end(), std::move(accumulate_promise1));

//     std::cout << "create thread 2" << std::endl;
//     std::thread thread2(accumulate, 2000, numbers.begin(), numbers.end(), std::move(accumulate_promise2));

//     // future::get() will wait until the future has a valid result and retrieves it.
//     // Calling wait() before get() is not needed
//     // accumulate_future.wait();  // wait for result
//     {
//         TimeElapsed tm;
//         std::lock_guard lock(mtx);
//         std::cout << "start get thread 1" << std::endl;
//         std::cout << "result=" << accumulate_future1.get() << '\n';
//         std::cout << "stop get thread 1" << std::endl;
//     }
//     {
//         TimeElapsed tm;
//         std::lock_guard lock(mtx);
//         std::cout << "start get thread 2" << std::endl;
//         std::cout << "result=" << accumulate_future2.get() << '\n';
//         std::cout << "stop get thread 2" << std::endl;
//     }

//     {
//         TimeElapsed tm;
//         std::lock_guard lock(mtx);
//         std::cout << "start join 1" << std::endl;
//         thread1.join(); // wait for thread completion
//         std::cout << "stop join 1" << std::endl;
//         std::cout << "start join 2" << std::endl;
//         thread2.join(); // wait for thread completion
//         std::cout << "stop join 2" << std::endl;
//     }
// }

void printVector(const std::vector<int>& v)
{
    std::mutex mtx;
    std::lock_guard lk(mtx);
    std::cout << "vector: ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}