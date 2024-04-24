#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

struct String
{

    /* Реализуйте этот конструктор */
    String(const char* str = "")
        : size{strlen(str)}
    {

        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

    /* Реализуйте этот конструктор */
    String(size_t n, char c)
        : size{n}
    {
        this->str = new char[size + 1];
        for (size_t i = 0; i < size; ++i)
        {
            this->str[i] = c;
        }

        str[size] = '\0';
    }

    /* Реализуйте этот метод. */
    void append(String& other)
    {
        size_t new_size = this->size + other.size;
        char* new_str   = (char*)::operator new[](new_size + 1);

        strcpy(new_str, this->str);
        strcpy(new_str + strlen(str), other.str);

        delete[] str;
        str = new_str;

        size = new_size;
    }

    /* и деструктор */
    ~String()
    {
        delete[] str;
        str = nullptr;
    }

    size_t size;
    char* str;
};

int main()
{
    String s1("");
    String s2("bbb");

    std::cout << s1.str << std::endl;
    s1.append(s2);

    std::cout << s2.str << std::endl;
    std::cout << s1.str << std::endl;
    return 0;
}