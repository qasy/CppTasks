#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution
{
public:
    Solution()
    {
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
    }
    int romanToInt(std::string s)
    {
    }

    std::map<std::string, int> tableOfValues;
};
int main()
{
    Solution s;
    s.romanToInt("LVIII");
    return 0;
}