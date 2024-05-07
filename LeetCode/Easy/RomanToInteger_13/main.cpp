#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution
{
public:
    Solution()
    {
    }
    int romanToInt(std::string s)
    {
        std::map<std::string, int> tableOfValues;
        tableOfValues["I"] = 1;
        tableOfValues["V"] = 5;
        tableOfValues["X"] = 10;
        tableOfValues["L"] = 50;
        tableOfValues["C"] = 100;
        tableOfValues["D"] = 500;
        tableOfValues["M"] = 1000;

        tableOfValues["IV"] = 4;
        tableOfValues["IX"] = 9;
        tableOfValues["XL"] = 40;
        tableOfValues["XC"] = 90;
        tableOfValues["CD"] = 400;
        tableOfValues["CM"] = 900;

        int size         = s.size();
        int i            = size - 1;
        int result       = 0;
        std::string part = "";

        // while (i >= 0)
        // {
        //     if (i > 0)
        //     {
        //         part = s[i - 1] + s[i];
        //         --i;
        //     }
        //     if (i == 0)
        //     {
        //         // part = s[0];
        //         break;
        //     }

        //     std::cout << s[i] << std::endl;
        //     // int tmp = 0;
        //     // if (tableOfValues.find(part) != tableOfValues.cend())
        //     // {
        //     // }

        //     // i = i - step;
        // }
    }
};
int main()
{
    Solution s;
    s.romanToInt("LVIII");
    return 0;
}