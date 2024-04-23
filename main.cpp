#include <iostream>
#include <string>

class Person
{
private:
    static Person* p_instance;

    Person()
    {
    }

    Person(const Person&);

    Person& operator=(Person&);

public:
    static Person* getInstance()
    {
        if (!p_instance)
        {
            p_instance = new Person();
        }
        return p_instance;
    }
};

Person* Person::p_instance = nullptr;

void swap(int& a, int& b)
{
    int temp = a;
    a        = b;
    b        = temp;
}

int* func()
{
    int a = 5;
    return &a;
}

int main()
{

    int* p = func();
    *p     = 5;
    // int a  = 5;
    // int& r = a;
    // int* p = &r;

    // std::cout << &a << std::endl;
    // std::cout << p << std::endl;

    // int* a = new int[3];
    // for (size_t i = 0; i < 3; ++i)
    // {
    //     std::cout << *(a + i) << " ";
    // }
    // std::cout << std::endl;
    // // a[30000] = 5;

    // uint32_t a  = 0b00000000000001010000000011111111;
    // uint32_t* p = &a;
    // void* pp    = (void*)p;

    // std::cout << a << std::endl;
    // std::cout << *p << std::endl;
    // std::cout << *((unsigned short*)pp + 1) << std::endl;

    // int* p = nullptr;

    // const int& r = 0; // Error

    // Person* p = Person::getInstance();
    // int* p = nullptr;
    // std::cout << *p << std::endl;
    // int x = 10;
    // int y = 20;
    // std::cout << "x = " << x << " y = " << y << std::endl;
    // swap(x, y);
    // std::cout << "x = " << x << " y = " << y << std::endl;

    // std::string str1 = "Aleksey";
    // for (auto it = str1.begin(); it != str1.end(); ++it)
    // {
    //     std::cout << str1[it - str1.begin()] << " ";
    // }
    return 0;
}