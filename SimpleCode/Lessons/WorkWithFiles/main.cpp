#include <fstream>
#include <iostream>
#include <string>

/*
    Работа с файлами
    fstream - общий класс для чтения и записи в файл
    ifstream - только на чтение
    ofstream - только на запись
*/

int main()
{

    std::ofstream outfilestream;
    std::string fname = "my_file.txt";
    // outfilestream.open(fname); // Если файл есть - то перезаписываем, если нет - создаем новый
    outfilestream.open(fname, std::fstream::app); // Если файл есть - то добавляем в конец, если нет - создаем новый
    if (!outfilestream.is_open())
    {
        std::cout << "Error, the file is not open." << std::endl;
    }
    outfilestream << "Success. File was opened." << std::endl;
    outfilestream.close();

    return 0;
}