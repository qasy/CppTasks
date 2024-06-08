// Надо слинковать с libboost_program_options
// g++ main.cpp -L/lib/x86_64-linux-gnu/ -lboost_program_options -o main
// или если /usr/lib/x86_64-linux-gnu/ уже в PATH:
// g++ main.cpp -lboost_program_options -o main
// Варианты запуска
// ./main --help
// ./main --apples=10 --oranges=10
#include <boost/program_options.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char* argv[])
{
    // Создаем опции, описывающие переменную, и даем ей текстовое описание
    // "All options"
    opt::options_description desc("All options");

    // Когда мы добавляем опции, первый параметр - это имя, которое будет использоваться
    // в командной строке. Второй параметр - это тип данных опции, заключенный в класс
    // value<>. Третий параметр должен быть кратким описанием этой опции.

    // clang-format off
    desc.add_options()
        ("apples", opt::value<int>(), "how many apples do you have")
        ("oranges", opt::value<int>(), "how many oranges do you have")
        ("help", "produce help massage");
    // clang-format on

    // Переменная для хранения аргументов нашей командной строки
    opt::variables_map vm;

    // Парсинг и сохранение аргументов
    opt::store(opt::parse_command_line(argc, argv, desc), vm);

    // Эта функция должна вызываться после парсинга и сохранения
    opt::notify(vm);

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 1;
    }

    std::cout << "Fruits count: " << vm["apples"].as<int>() + vm["oranges"].as<int>() << std::endl;

    return 0;
}