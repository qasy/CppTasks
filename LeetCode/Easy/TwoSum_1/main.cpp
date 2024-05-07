#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    /*
        Simple solution with O(n^2)
    */
    // std::vector<int> twoSum(std::vector<int>& nums, int target)
    // {
    //     std::vector<int> res;
    //     for (auto it_first = nums.cbegin(); it_first != nums.cend(); ++it_first)
    //     {
    //         for (auto it_scnd = it_first + 1; it_scnd != nums.cend(); ++it_scnd)
    //         {
    //             std::cout << "first: " << *it_first << " second: " << *it_scnd << std::endl;
    //             if (*it_first + *it_scnd == target)
    //             {
    //                 res.resize(2);
    //                 res[0] = it_first - nums.cbegin();
    //                 res[1] = it_scnd - nums.cbegin();
    //                 return res;
    //             }
    //         }
    //     }
    //     return res;
    // }

    /*
        Using binary-tree in multimap
    */
    // std::vector<int> twoSum(std::vector<int>& nums, int target)
    // {
    //     std::multimap<int, int> numsAsMap;
    //     // O(n)
    //     for (size_t i = 0; i < nums.size(); ++i)
    //     {
    //         // numsAsMap[nums[i]] = i;
    //         numsAsMap.emplace(nums[i], i);
    //     }

    //     std::vector<int> tmp;
    //     // O(n)
    //     for (auto curr = numsAsMap.cbegin(); curr != numsAsMap.cend(); ++curr)
    //     {
    //         int key      = target - curr->first;
    //         auto founded = numsAsMap.find(key); // O(log(n))
    //         if (founded != numsAsMap.cend() && founded != curr)
    //         {
    //             tmp.push_back(curr->second);
    //             tmp.push_back(founded->second);

    //             // std::cout << curr->second << " " << founded->second << std::endl;
    //             return tmp;
    //         }
    //     }

    //     return tmp;
    // }

    /*
        Try to use hash-table
    */
    // std::vector<int> twoSum(std::vector<int>& nums, int target)
    // {
    //     std::unordered_map<int, int> numsAsMap;
    //     // O(n)
    //     std::size_t size = nums.size();
    //     for (size_t i = 0; i < size; ++i)
    //     {
    //         numsAsMap[nums[i]] = i;
    //     }

    //     for (auto& el : numsAsMap)
    //     {
    //         // std::cout << el.first << " " << el.second << std::endl;
    //         std::cout << numsAsMap.count(el.first) << std::endl;
    //     }

    //     return {};
    // }
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> numsMap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numsMap.count(complement)) // Считает вхождения
            {
                // Если элемент найден, то он находится до текущего.
                return {numsMap[complement], i};
            }
            numsMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};

int main()
{
    // std::vector<int> a{2, 11, 7, 11, 11, 15};
    std::vector<int> a{3, 2, 4};
    // std::vector<int> a{3, 3};
    Solution s;
    std::vector<int> res = s.twoSum(a, 6);

    std::cout << res[0] << " " << res[1] << std::endl;

    return 0;
}