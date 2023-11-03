#include <cstddef> // size_t
#include <cstring>
#include <iostream>

struct String
{
    struct ProxyString;
    String(const char* str = "")
    {
        size = strlen(str);

        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

    ~String()
    {
        delete[] str;
    }

    String(const String& other)
        : size(other.size)
    {
        str = new char[size + 1];
        for (size_t i = 0; i != size; ++i)
        {
            str[i] = other.str[i];
        }
        str[size] = '\0';
    }

    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] str;
            str = nullptr;

            size = other.size;
            str  = new char[size + 1];
            for (size_t i = 0; i != size; ++i)
            {
                str[i] = other.str[i];
            }
            str[size] = '\0';
        }
        return *this;
    }

    String substring(size_t start_i) const
    {
        if (start_i < 0 || start_i >= size)
        {
            return "";
        }

        size_t new_size = size - start_i;
        char s_char[new_size + 1];
        for (size_t i = 0; i < new_size; ++i)
        {
            s_char[i] = this->str[i + start_i];
        }
        s_char[new_size] = '\0';

        return s_char;
    }

    ProxyString operator[](size_t i) const
    {
        ProxyString ps(this->substring(i), i);
        return ps;
    }

    size_t size;
    char* str;

    struct ProxyString
    {
        ~ProxyString()
        {
            delete[] proxy_str;
        }

        ProxyString(const String& other, size_t start_i = 0)
            : proxy_size(other.size)
        {
            proxy_str = new char[proxy_size + 1];
            for (size_t i = 0; i != proxy_size; ++i)
            {
                proxy_str[i] = other.str[i];
            }
            proxy_str[proxy_size] = '\0';
            this->start_i         = start_i;
        }

        String substring(size_t end_i) const
        {
            if (end_i < 0 || end_i >= proxy_size)
            {
                return "";
            }

            size_t new_size = end_i;
            char s_char[new_size + 1];
            for (size_t i = 0; i < new_size; ++i)
            {
                s_char[i] = this->proxy_str[i];
            }
            s_char[new_size] = '\0';

            return s_char;
        }

        String operator[](size_t i) const
        {
            i = i - start_i;
            return this->substring(i);
        }

        size_t proxy_size;
        char* proxy_str;
        size_t start_i;
    };
};

std::ostream& operator<<(std::ostream& os, const String& s)
{
    for (size_t i = 0; i < s.size; ++i)
    {
        os << s.str[i];
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const String::ProxyString& s)
{
    for (size_t i = 0; i < s.proxy_size; ++i)
    {
        os << s.proxy_str[i];
    }
    return os;
}

int main()
{
    const String s("hello");
    std::cout << s << std::endl;
    // std::cout << s.substring(4) << std::endl;
    std::cout << s[0][4] << std::endl;

    return 0;
}