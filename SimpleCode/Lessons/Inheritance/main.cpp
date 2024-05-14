#include <iostream>
#include <string>

class A
{
public:
    A()
    {
        msg = "Empty message";
        std::cout << "A()" << std::endl;
    }

    A(std::string msg)
    {
        std::cout << "A(std::string msg)" << std::endl;
        this->msg = msg;
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
    }

    void printMsg()
    {
        std::cout << msg << std::endl;
    }

    // public:
    //     std::string msgOne = "Msg One";

    // protected:
    //     std::string msgTwo = "Msg Two";

private:
    std::string msg;
    //     std::string msgThree = "Msg Three";
};

class B : public A
{
public:
    B()
        : A("New message from B")
    {
        std::cout << "B()" << std::endl;
    }

    ~B()
    {
        std::cout << "~B()" << std::endl;
    }
};

// class C : public B
// {
// public:
//     C()
//     {
//         std::cout << "C()" << std::endl;
//     }

//     ~C()
//     {
//         std::cout << "~C()" << std::endl;
//     }
// };

int main()
{
    // A a;
    // B b;
    // C c;

    A a("New msg");
    a.printMsg();

    std::cout << std::endl;
    B b;
    b.printMsg();

    std::cout << std::endl;

    return 0;
}