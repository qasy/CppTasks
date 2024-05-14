#include <iostream>
#include <string>

class Human
{
public:
    Human(std::string name)
    {
        this->Name   = name;
        this->Age    = 0;
        this->Weight = 0;
    }

    Human(std::string name, int age)
        : Human(name)
    {
        this->Age = age;
    }

    Human(std::string name, int age, int weight)
        : Human(name, age)
    {
        this->Weight = weight;
    }

    std::string Name;
    int Age;
    int Weight;
};

int main()
{
    Human h("Alex", 25, 80);
    return 0;
}