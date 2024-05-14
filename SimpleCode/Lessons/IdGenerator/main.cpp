#include <iostream>
#include <string>

class Apple
{

public:
    Apple(int weight, std::string color)
    {
        this->weight = weight;
        this->color  = color;
        this->Id     = Apple::Count;
        ++Apple::Count;
    }

    int GetID()
    {
        return Id;
    }

    static int GetIDClassobj(const Apple& obj)
    {
        return obj.Id;
    }

    static int GetCount()
    {
        return Apple::Count;
    }

private:
    int weight;
    std::string color;
    int Id;
    static int Count;
};

int Apple::Count = 0;

int main()
{

    Apple a1(100, "Red");
    Apple a2(200, "Green");

    std::cout << Apple::GetCount() << std::endl;
    std::cout << a1.GetID() << std::endl;
    std::cout << a2.GetID() << std::endl;
    std::cout << Apple::GetIDClassobj(a1) << std::endl;

    return 0;
}