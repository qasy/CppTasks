#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string xStr = std::to_string(x);
        std::cout << xStr << std::endl;
        auto left  = xStr.cbegin();
        auto right = --xStr.cend();
        if (left == right)
        {
            return true;
        }

        while (left < right)
        {
            std::cout << *left << " " << *right << std::endl;
            if (*left != *right)
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

int main()
{
    Solution s;
    std::cout << s.isPalindrome(1221) << std::endl;
    return 0;
}