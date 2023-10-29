#include <iostream>

struct Vector
{
    Vector(double x = 0.0, double y = 0.0)
        : x(x)
        , y(y)
    {
    }

    bool operator()(double d) const
    {
        std::cout << "operator()" << std::endl;
    }
    double x;
    double y;
};

bool v(double d)
{
    std::cout << "function" << std::endl;
}

Vector& operator*(double x, Vector& v)
{
    v.x *= x;
    v.y *= x;
    return v;
}

int main()
{
    Vector v(2, 3);
    ::v(2);

    return 0;
}