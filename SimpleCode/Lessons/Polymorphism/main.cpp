#include <iostream>
#include <string>

/*
    Полиморфизм
    Виртуальные функции
    Ключевые слова virtual и override
    Абстрактный класс
    Чистые виртуальные функции
*/

class Weapon
{
public:
    virtual void Shoot() = 0;

    void Foo()
    {
        std::cout << "Foo()" << std::endl;
    }

    virtual ~Weapon()
    {
    }
};

class Gun : public Weapon
{
public:
    void Shoot() override
    {
        std::cout << "BANG!" << std::endl;
    }
};

class SubmachineGun : public Gun
{
public:
    void Shoot() override
    {
        std::cout << "BANG! BANG! BANG!" << std::endl;
    }
};

class Bazooka : public Weapon
{
public:
    void Shoot() override
    {
        std::cout << "BA-DA-BOOOM!" << std::endl;
    }
};

class Knife : public Weapon
{
    void Shoot() override
    {
        std::cout << "VJUH!!!" << std::endl;
    }
};

class Player
{
public:
    void Shoot(Weapon* weapon)
    {
        weapon->Shoot();
    }
};

int main()
{
    Gun gun;
    SubmachineGun sgun;
    Bazooka buzgun;
    Knife knife;

    // Используем реализацию из абстрактного класса, так как не переопеределяли
    buzgun.Foo();
    knife.Foo();

    Player p;
    // Несмотря на то,что Player в методе Shoot принимает указатель на Gun,
    // он может применять этот метод и ко всем наследникам класса Gun,
    // то есть в зависимости от типа, вызывается тот или иной метод - динамический полиморфизм
    p.Shoot(&gun);
    p.Shoot(&sgun);
    p.Shoot(&buzgun);

    // Weapon w;
    return 0;
}