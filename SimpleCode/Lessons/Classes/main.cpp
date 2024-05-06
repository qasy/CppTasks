#include <iostream>
#include <string>

/*
    Классы
    Методы
    Спецификаторы доступа
    Геттеры и сеттеры
    Инкапсуляция
    Конструктор
    Перегрузка конструктора
    Деструктор
    Конструктор копирования
    Перегрузка оператора присваивания
    Перегрузка операторов равенства и неравенства
*/

class Human
{

private:
    std::string name;
    int age;
    int weight;

public:
    void print() const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Weight: " << weight << std::endl;
    }
};

class Point
{

private:
    int x;
    int y;

public:
    Point()
    {
        std::cout << "Point()" << std::endl;
        x = 0;
        y = 0;
    }
    Point(int x, int y)
    {
        std::cout << "Point(int x, int y)" << std::endl;
        this->x = x;
        this->y = y;
    }

    Point(const Point& p)
    {
        std::cout << "Point(const Point& p)" << std::endl;
    }

    ~Point()
    {
        std::cout << "~Point()" << std::endl;
    }

    int GetX() const
    {
        return x;
    }
    void SetX(int new_x)
    {
        x = new_x;
    }

    void Print()
    {

        std::cout << "x: " << x << " "
                  << "y: " << y << std::endl;
    }
};

class MyClass
{
private:
    size_t size;
    int* data;

public:
    MyClass()
    {
        this->data = nullptr;
        this->size = 0;
    }
    MyClass(size_t size)
    {
        std::cout << "MyClass(): " << this << std::endl;
        data       = new int[size];
        this->size = size;
        for (size_t i = 0; i != size; ++i)
        {
            data[i] = rand() % 10;
        }
    }

    MyClass(const MyClass& other)
    {
        std::cout << "MyClass(const MyClass& other): " << this << std::endl;
        size = other.size;
        data = new int[size];
        for (size_t i = 0; i != size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    MyClass& operator=(const MyClass& other)
    {
        std::cout << "MyClass& operator=(const MyClass& other): " << this << " " << &other << std::endl;
        if (this == &other)
        {
            return *this;
        }

        delete[] this->data;
        this->size = other.size;
        this->data = new int[this->size];

        for (size_t i = 0; i < size; ++i)
        {
            this->data[i] = other.data[i];
        }
        return *this;
    }

    bool operator==(const MyClass& other)
    {
        bool isEqual = false;
        if (!(this->data && other.data && this->size == other.size))
        {
            return false;
        }

        for (size_t i = 0; i < size; ++i)
        {
            if (this->data[i] != other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const MyClass& other)
    {
        return !(*this == other);
    }

    void print() const
    {
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    ~MyClass()
    {
        std::cout << "~MyClass(): " << this << std::endl;
        delete[] data;
    }
};

int main()
{
    // Human firstHuman;
    // firstHuman.print();

    // Point a(0, 0);
    // Point b(0, 0);

    MyClass ma(10);
    MyClass mb(4);
    MyClass mc(ma);
    ma.print();
    mb.print();
    mc.print();
    mc = mb = ma;

    ma.print();
    mb.print();
    mc.print();

    return 0;
}