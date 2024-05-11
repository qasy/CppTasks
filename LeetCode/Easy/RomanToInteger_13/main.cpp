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
        // tableOfValues["I"] = 1;
        // tableOfValues["V"] = 5;
        // tableOfValues["X"] = 10;
        // tableOfValues["L"] = 50;
        // tableOfValues["C"] = 100;
        // tableOfValues["D"] = 500;
        // tableOfValues["M"] = 1000;

        // tableOfValues["IV"] = 4;
        // tableOfValues["IX"] = 9;
        // tableOfValues["XL"] = 40;
        // tableOfValues["XC"] = 90;
        // tableOfValues["CD"] = 400;
        // tableOfValues["CM"] = 900;
    }
    // int romanToInt(std::string s)
    // {

    //     int result       = 0;
    //     std::string part = "";
    //     for (auto ch = s.cend() - 1; ch != s.cbegin() - 1; --ch)
    //     {
    //         part = *ch + part;
    //         if (part.length() == 2)
    //         {
    //             if (tableOfValues.find(part) != tableOfValues.cend())
    //             {
    //                 // std::cout << tableOfValues[std::string{part[0]} + std::string{part[1]}];
    //                 result += tableOfValues[std::string{part[0]} + std::string{part[1]}];
    //                 part = "";
    //             }
    //             else
    //             {

    //                 // std::cout << tableOfValues[std::string{part[0]}];
    //                 // std::cout << tableOfValues[std::string{part[1]}];

    //                 result += tableOfValues[std::string{part[1]}];
    //                 part = std::string{part[0]};
    //             }
    //         }
    //         // std::cout << part << std::endl;
    //     }
    //     if (!part.empty())
    //     {
    //         result += tableOfValues[std::string{part[0]}];
    //     }
    //     return result;
    // }

    // std::map<std::string, int> tableOfValues;

    int romanToInt(std::string s)
    {
        std::unordered_map<char, int> tableOfValues(7);
        tableOfValues['I'] = 1;
        tableOfValues['V'] = 5;
        tableOfValues['X'] = 10;
        tableOfValues['L'] = 50;
        tableOfValues['C'] = 100;
        tableOfValues['D'] = 500;
        tableOfValues['M'] = 1000;

        int result = 0;
        int i      = s.length() - 1;
        int prev_i = i;
        for (; i != -1; --i)
        {

            // (tableOfValues[s[i]] < tableOfValues[s[prev_i]]) ? result -= tableOfValues[s[i]]
            //  : result += tableOfValues[s[i]];
            if (tableOfValues[s[i]] < tableOfValues[s[prev_i]])
            {
                result -= tableOfValues[s[i]];
            }
            else
            {
                result += tableOfValues[s[i]];
            }
            prev_i = i;
        }
        return result;
    }
};
int main()
{
    Solution s;
    // std::cout << s.romanToInt("LVIII") << std::endl;
    // std::cout << s.romanToInt("MCMXCIV") << std::endl;
    std::cout << s.romanToInt("MCDLXXVI") << std::endl;

    return 0;
}