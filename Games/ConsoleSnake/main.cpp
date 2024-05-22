#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

class Map
{
public:
    Map(std::size_t width = 50, std::size_t height = 50, bool withBorder = false)
        : width(width)
        , height(height)
        , map(width * height, '.')
    {
        std::string map_filename = "map_0.txt";
        map_file.open("map_filename");
        if (!map_file.is_open())
        {
            std::cout << "Ошибка. Файл с картой не открыт." << std::endl;
        }
    }

    void DrawMap()
    {
        for (size_t r = 0; r != height; ++r)
        {
            for (size_t c = 0; c != width; ++c)
            {
                int i = r * width + c;

                map_file << map[i];
            }
            map_file << std::endl;
        }
    }

    ~Map()
    {
        map_file.close();
    }

private:
    std::size_t width;
    std::size_t height;
    // std::size_t total_size;

    char FreeSpaceSymbol = '.';
    char BorderSymbol    = '#';

    std::ofstream map_file;
    std::vector<char> map;

    // void CreateMap()
    // {
    //     for ()
    // }
};

int main()
{
    Map map;
    map.DrawMap();
    return 0;
}