// Problem Number: 78
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> temp = {};
        result.push_back(temp);
        if (nums.size() == 0)
        {
            return result;
        }
    }
};