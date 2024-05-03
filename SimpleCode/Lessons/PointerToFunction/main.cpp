#include <iostream>
#include <string>

/*
    Указатели на функции
*/

std::string InfoFromDataBase()
{
    return "InfoFromDataBase()";
}

std::string InfoFromWebServer()
{
    return "InfoFromWebServer()";
}

// тип_функции (*имя_функции)(спецификация_параметров);
void showInfo(std::string (*funcPtr)())
{
    std::cout << funcPtr() << std::endl;
}

int main()
{
    // Foo();
    std::string (*fooPtr1)() = InfoFromDataBase;
    auto fooPtr2             = InfoFromWebServer;
    std::string (&fooPtr3)() = InfoFromWebServer;
    // fooPtr3                  = InfoFromDataBase; // error, because it's reference
    std::string (&fooPtr4)() = fooPtr3;
    std::string (*fooPtr5)() = &InfoFromDataBase; // Same as fooPtr1

    // void (*fooPtr)()         = &Foo;
    // fooPtr();
    // fooPtr2();

    showInfo(fooPtr1);
    showInfo(fooPtr2);
    showInfo(fooPtr3);
    showInfo(fooPtr4);
    showInfo(fooPtr5);

    return 0;
}