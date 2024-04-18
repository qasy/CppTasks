#include <iostream>

unsigned strlen(const char* str)
{
    unsigned len = 0;
    for (; *str != '\0'; ++str, ++len)
    {
    }
    return len;
}

int strstr(const char* text, const char* pattern)
{
    if (strlen(pattern) == 0)
        return 0;
    if (strlen(text) == 0)
        return -1;

    for (unsigned int i = 0; i < strlen(text); ++i)
    {
        unsigned int matching_count = 0;
        for (unsigned int j = 0; j < strlen(pattern); ++j)
        {
            if (text[i + j] == pattern[j])
            {
                ++matching_count;
            }
            else
            {
                break;
            }
            if (matching_count == strlen(pattern))
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    std::cout << strstr("abcd", "cd") << std::endl;
    return 0;
}