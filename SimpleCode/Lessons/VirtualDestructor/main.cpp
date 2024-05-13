#include <iostream>

/*
    Виртуальный деструктор
*/

class A
{
public:
    A()
    {
        std::cout << "A(): выделяем ресурсы" << std::endl;
    }

    // ~A() // Memory leak
    // virtual ~A()
    // {
    //     std::cout << "~A(): освобождаем ресурсы" << std::endl;
    // }

    virtual ~A() = 0;
};

A::~A()
{
}

class B : public A
{
public:
    B()
    {
        std::cout << "B(): выделяем ресурсы" << std::endl;
    }
    ~B() override
    {
        std::cout << "~B(): освобождаем ресурсы" << std::endl;
    }
};

int main()
{
    B* bptr = new B;
    delete bptr;

    // A* aptr = new B;
    // delete aptr;

    return 0;
}