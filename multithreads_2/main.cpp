#include <algorithm>
#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

// double Sum(double a, double b)
// {

//     std::cout << "=====\t"
//               << "DoWork() START thread (ID: " << std::this_thread::get_id() << ")\t=====" << std::endl;

//     // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//     auto start_time = std::chrono::high_resolution_clock::now();
//     auto stop_time  = std::chrono::high_resolution_clock::now();
//     double res;
//     while (std::chrono::duration_cast<std::chrono::seconds>(stop_time - start_time).count() < 35.0)
//     {
//         res       = res * a / b;
//         stop_time = std::chrono::high_resolution_clock::now();
//     }

//     std::cout << std::chrono::duration_cast<std::chrono::seconds>(stop_time - start_time).count() << std::endl;
//     std::cout << "=====\tDoWork() STOP thread\t=====" << std::endl;

//     return res;
// }

// class Data
// {
// public:
//     Data()
//     {
//     }

//     void ProcessFrame(size_t numThreads, std::vector<double>& v1, std::vector<double>& v2)
//     {
//         if (v1.size() != v2.size())
//         {
//             std::cout << "Error: v1.size() != v2.size()" << std::endl;
//             exit(1);
//         }
//         auto time_start = std::chrono::high_resolution_clock::now();

//         // for (size_t i = 0; i < v1.size(); ++i)
//         // {
//         //     Power(v1[i], v2[i]);
//         // }

//         std::vector<std::thread> threads;
//         threads.resize(numThreads);

//         for (size_t i = 0; i < numThreads; ++i)
//         {
//             threads[i] = std::thread(&Data::Power, this, std::ref(v1[i]), std::ref(v2[i]));
//             // threads[i] = std::thread([&]() { Power(v1[i], v2[i]); });
//             // std::this_thread::sleep_for(std::chrono::milliseconds(10));
//         }
//         for (size_t i = 0; i < numThreads; ++i)
//         {
//             threads[i].join();
//         }

//         auto time_stop = std::chrono::high_resolution_clock::now();
//         auto ms        = std::chrono::duration_cast<std::chrono::milliseconds>(time_stop - time_start);

//         std::cout << "Elapsed time in ms: " << ms.count() << std::endl;
//         // std::vector<std::thread> threads;
//         // threads.resize(numThreads);
//     }

//     void Power(double& number, double& power)
//     {

//         std::mutex mtx;
//         mtx.lock();
//         std::this_thread::sleep_for(std::chrono::milliseconds(500));

//         std::cout << "ID: " << std::this_thread::get_id() << " number: " << number << " power: " << power <<
//         std::endl;

//         number += power;
//         mtx.unlock();
//     }
// };

void Sum()
{
}

void printVector(const std::vector<double>& v)
{
    std::mutex mtx;
    std::scoped_lock lock;
    std::cout << "vector: ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// g++ ./main.cpp -o main -pthread -std=c++17
int main()
{
    size_t num_threads = 10;
    std::vector<double> v1;
    std::vector<double> v2;
    v1.resize(5);
    // v2.resize(num_threads);
    printVector(v1);

    switch (num_threads)
    {
        case 4:
            v1[3] = 4;
        case 3:
            v1[2] = 3;
        case 2:
            v1[1] = 2;
        case 1:
            v1[0] = 1;
        default:
            break;
    }

    // for (size_t i = 0; i < num_threads; ++i)
    // {
    //     v1[i] = 10 - i;
    //     v2[i] = 10;
    // }

    printVector(v1);
    // auto it_min = std::min_element(v1.begin(), v1.end());

    // std::cout << *it_min << std::endl;
    // std::cout << (it_min - v1.begin()) << std::endl;

    // printVector(v1);
    // printVector(v2);

    // d.ProcessFrame(num_threads, v1, v2);

    // printVector(v1);
    // printVector(v2);

    // auto start_time = std::chrono::high_resolution_clock::now();
    // auto end_time   = std::chrono::high_resolution_clock::now();
    // auto ms         = std::chrono::duration_cast<std::chrono::milliseconds>(start_time - end_time).count();

    return 0;
}