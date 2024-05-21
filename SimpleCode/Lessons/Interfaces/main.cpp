#include <iostream>
#include <string>

/*
    Интерфейсы
*/

class IBicycle
{
public:
    virtual void TwistTheWheel() = 0;
    virtual void Ride()          = 0;
    virtual ~IBicycle()
    {
    }
};

class SimpleBicycle : public IBicycle
{
public:
    void TwistTheWheel() override
    {
        std::cout << "Крутим руль и педали простого велика." << std::endl;
    }

    void Ride() override
    {
        std::cout << "Едем." << std::endl;
    }
};

class SportBicycle : public IBicycle
{
public:
    void TwistTheWheel() override
    {
        std::cout << "Крутим руль и педали спортивного велика." << std::endl;
    }

    void Ride() override
    {
        std::cout << "Едем на спортивном велике." << std::endl;
    }
};

class Human
{
public:
    void RideOn(IBicycle& bicycle)
    {
        bicycle.TwistTheWheel();
        bicycle.Ride();
    }
};

int main()
{
    Human h;
    SimpleBicycle bike;
    SportBicycle sbike;
    h.RideOn(bike);
    h.RideOn(sbike);
    return 0;
}
