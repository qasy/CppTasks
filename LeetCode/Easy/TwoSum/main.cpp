#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> res;
        for (auto it_first = nums.cbegin(); it_first != nums.cend(); ++it_first)
        {
            for (auto it_scnd = it_first + 1; it_scnd != nums.cend(); ++it_scnd)
            {
                std::cout << "first: " << *it_first << " second: " << *it_scnd << std::endl;
                if (*it_first + *it_scnd == target)
                {
                    res.resize(2);
                    res[0] = it_first - nums.cbegin();
                    res[1] = it_scnd - nums.cbegin();
                    return res;
                }
            }
        }
        return res;
    }
};

int main()
{
    // std::vector<int> a{2, 7, 11, 15};
    std::vector<int> a{3, 2, 4};
    Solution s;
    std::vector<int> res = s.twoSum(a, 6);

    std::cout << res[0] << " " << res[1] << std::endl;

    return 0;
}