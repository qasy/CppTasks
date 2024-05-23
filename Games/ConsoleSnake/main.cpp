#include <chrono>
#include <fstream>
#include <iostream>
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

class Snake
{
public:
    Snake(int start_x = 0, int start_y = 0)
        : SnakeBody{std::pair<int, int>{start_x, start_y}}
    {
    }

    void Move()
    {
    }

    void printSnakeCoordinates() const
    {
        for (auto& el : this->SnakeBody)
        {
            std::cout << "(" << el.first << "," << el.second << ")" << std::endl;
        }
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
        std::cout << "thread: " << std::this_thread::get_id() << "\t time: " << delta_time_ms << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        current_time = std::chrono::system_clock::now();
    }
    std::cout << "End GameCycle()" << std::endl;
}

int main()
{
    Snake s(0, 0);
    s.printSnakeCoordinates();

    std::thread thread_gamecycle(&GameCycle);

    // std::string a;
    // std::cin >> a;
    // std::cout << a << std::endl;

    int64_t duration_ms = 20000; // duration of game cycle in seconds
    auto start_time     = std::chrono::system_clock::now();
    auto current_time   = std::chrono::system_clock::now();
    auto delta_time_ms  = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();

    // Game cycle

    std::cout << "Start MainCycle()" << std::endl;
    for (; delta_time_ms < duration_ms;)
    {
        delta_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
        std::cout << "thread: " << std::this_thread::get_id() << "\t time: " << delta_time_ms << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        current_time = std::chrono::system_clock::now();
    }
    std::cout << "End MainCycle()" << std::endl;

    thread_gamecycle.join();

    return 0;
}