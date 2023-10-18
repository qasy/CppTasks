#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

double Sum(double a, double b)
{

    std::cout << "=====\t"
              << "DoWork() START thread (ID: " << std::this_thread::get_id() << ")\t=====" << std::endl;

    // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    auto start_time = std::chrono::high_resolution_clock::now();
    auto stop_time  = std::chrono::high_resolution_clock::now();
    double res;
    while (std::chrono::duration_cast<std::chrono::seconds>(stop_time - start_time).count() < 35.0)
    {
        res       = res * a / b;
        stop_time = std::chrono::high_resolution_clock::now();
    }

    std::cout << std::chrono::duration_cast<std::chrono::seconds>(stop_time - start_time).count() << std::endl;
    std::cout << "=====\tDoWork() STOP thread\t=====" << std::endl;

    return res;
}

// g++ ./main.cpp -o main -pthread -std=c++17
int main()
{
    auto start_time = std::chrono::high_resolution_clock::now();

    size_t num_threads = 6;
    std::vector<double> results;
    std::vector<std::thread> threads;
    results.resize(num_threads, 100);
    threads.resize(num_threads);

    for (size_t i = 0; i < num_threads; ++i)
    {
        double& result = results[i];
        threads[i]     = std::thread([&result]() { result = Sum(2, 5); });
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }

    // std::thread th(Sum, 5, 10);

    // auto start_time = std::chrono::high_resolution_clock::now();
    // for (size_t i = 0; i < 10; ++i)
    // {
    //     std::cout << "main()" << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time).count() << std::endl;

    // t.join();
    for (size_t i = 0; i < num_threads; ++i)
    {
        threads[i].join();
    }
}