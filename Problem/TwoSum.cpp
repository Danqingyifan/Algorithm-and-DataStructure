// Problem number: 1
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // using hash map
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            int numberToFind = target - nums[i];
            if (hash.count(numberToFind))
            {
                return {hash[numberToFind], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};