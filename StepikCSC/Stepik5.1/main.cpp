#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, std::vector<double>& v)
{
    os << "size: " << v.size() << " data: ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        os << *it << " ";
    }
    return os;
}

struct Point;

struct Point
{
    Point()
    {
    }
    Point(double x = 0.0, double y = 0.0)
        : x(x)
        , y(y)
    {
    }

    // Point(Vector const& v)
    //     : x(v.x)
    //     , y(v.y)
    // {
    // }
    double x;
    double y;
};

struct Vector
{
    Vector(double x = 0.0, double y = 0.0)
        : x(x)
        , y(y)
    {
    }

    explicit operator bool() const
    {
        return true;
    }

    explicit operator Point() const
    {
        return Point(this->x, this->y);
    }

    double x;
    double y;
};

int main()
{
    Vector v1(3, 5);
    Point p1(3, 5);
    Point p2(3, 5);

    v1.operator Point();

    // p1 = p2;
    p1 = (Point)v1;

    // std::vector<double> v(5, 2);
    // std::cout << v << std::endl;

    return 0;
}