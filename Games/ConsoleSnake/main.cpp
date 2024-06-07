// #include "SharedResource.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

// class Map
// {
// public:
//     Map(std::size_t width = 50, std::size_t height = 50, bool withBorder = false)
//         : width(width)
//         , height(height)
//         , map(width * height, '.')
//     {
//         std::string map_filename = "map_0.txt";
//         map_file.open("map_filename");
//         if (!map_file.is_open())
//         {
//             std::cout << "Ошибка. Файл с картой не открыт." << std::endl;
//         }
//     }

//     void DrawMap()
//     {
//         for (size_t r = 0; r != height; ++r)
//         {
//             for (size_t c = 0; c != width; ++c)
//             {
//                 int i = r * width + c;

//                 map_file << map[i];
//             }
//             map_file << std::endl;
//         }
//     }

//     ~Map()
//     {
//         map_file.close();
//     }

// private:
//     std::size_t width;
//     std::size_t height;
//     // std::size_t total_size;

//     char FreeSpaceSymbol = '.';
//     char BorderSymbol    = '#';

//     std::ofstream map_file;
//     std::vector<char> map;

//     // void CreateMap()
//     // {
//     //     for ()
//     // }
// };

// class GameLogic
// {
// public:
//     int max_x = 50;
//     int max_y = 50;

// private:
// };

std::mutex msg_mtx;

void LogMultithreading(const std::string& msg)
{
    std::unique_lock<std::mutex> unique_guard(msg_mtx);
    std::cout << "thread (id:" << std::this_thread::get_id() << ")\t";
    std::cout << msg << std::endl;
    unique_guard.unlock();
}

class Snake
{
public:
    Snake(int start_x = 0, int start_y = 0)
        : SnakeBody{std::pair<int, int>{start_x, start_y}}
    {
    }

    void Move()
    {
        // std::cin.get()
    }

    void printSnakeCoordinates() const
    {
        for (auto& el : this->SnakeBody)
        {
            std::string msg = "(" + std::to_string(el.first) + "," + std::to_string(el.second) + ")";
            LogMultithreading(msg);
        }
    }

    const std::vector<std::pair<int, int>>& GetPositions() const
    {
        return SnakeBody;
    }

private:
    std::vector<std::pair<int, int>> SnakeBody; // index 0 - is a head
};

void GameCycle()
{
    int64_t duration_ms = 10000; // duration of game cycle in seconds
    auto start_time     = std::chrono::system_clock::now();
    auto current_time   = std::chrono::system_clock::now();
    auto delta_time_ms  = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();

    // Game cycle
    std::cout << "Start GameCycle()" << std::endl;
    for (; delta_time_ms < duration_ms;)
    {
        delta_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();

        LogMultithreading("time: " + std::to_string(delta_time_ms));

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        current_time = std::chrono::system_clock::now();
    }
    std::cout << "End GameCycle()" << std::endl;
}

class Frame;

int main()
{
    Snake snake(0, 0);

    // std::cin.get();

    // /////
    std::unique_ptr<int> ptr_a;
    std::unique_ptr<int[]> ptr_arr;
    const int& rref = 5;
    std::cout << rref << std::endl;

    // std::cout << ptr_b << std::endl;

    // /////

    // snake.Move();

    // s.printSnakeCoordinates();
    // Frame frame;

    // std::thread thread_gamecycle(&GameCycle);

    // // std::string a;
    // // std::cin >> a;
    // // std::cout << a << std::endl;

    // int64_t duration_ms = 2000; // duration of game cycle in seconds
    // auto start_time     = std::chrono::system_clock::now();
    // auto current_time   = std::chrono::system_clock::now();
    // auto delta_time_ms  = std::chrono::duration_cast<std::chrono::milliseconds>(current_time -
    // start_time).count();

    // for (; delta_time_ms < duration_ms;)
    // {
    //     delta_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
    //     LogMultithreading("time: " + std::to_string(delta_time_ms));

    //     std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //     current_time = std::chrono::system_clock::now();
    // }

    // thread_gamecycle.join();

    return 0;
}

class Frame
{
public:
    void SetSnakeData(Snake& snake)
    {
        // snake
    }

    /**
     * @brief Use compiler-generated default constructor
     *
     */
    Frame() = default;

    /**
     * @brief Use compiler-generated default destructor
     *
     */
    ~Frame() = default;

    /**
     * @brief The class is non-copyable
     *
     */
    Frame(const Frame& other) = delete;

    /**
     * @brief The class is non-copyable
     *
     */
    Frame& operator=(const Frame& other) = delete;

    /**
     * @brief The class is non-movable
     *
     */
    Frame(Frame&& other) = delete;

    /**
     * @brief The class is non-movable
     *
     */
    Frame& operator=(Frame&& other) = delete;

private:
    std::vector<std::pair<int, int>> snake;
};