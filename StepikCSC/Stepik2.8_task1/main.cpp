#include <fstream>
#include <iostream>

int main()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::ofstream output("output.txt");
    output << name;

    return 0;
}