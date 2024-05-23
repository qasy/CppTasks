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

    std::string fname = "my_file.txt";

    // write something to file
    std::ofstream fout;
    // outfilestream.open(fname); // Если файл есть - то перезаписываем, если нет - создаем новый
    fout.open(fname, std::fstream::app); // Если файл есть - то добавляем в конец, если нет - создаем новый
    if (!fout.is_open())
    {
        std::cout << "Ошибка открытия файла." << std::endl;
    }
    fout << "Success. File was opened." << std::endl;
    fout.close();

    // read something from file
    std::ifstream fin;
    fin.open(fname);

    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия файла." << std::endl;
        return 1;
    }
    std::cout << "The file is open and readable:" << std::endl;

    return 0;
}