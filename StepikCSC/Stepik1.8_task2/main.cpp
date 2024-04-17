#include <iostream>
using namespace std;

int main()
{
    char c     = '\0';
    char pre_c = '\0';
    while (cin.get(c))
    {
        if (c == ' ')
        {
            if (pre_c == ' ')
            {
                continue;
            }
        }
        cout << c;
        pre_c = c;
    }

    return 0;
}